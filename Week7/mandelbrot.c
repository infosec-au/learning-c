/*
 *
 * This server serves a BMP image of the Mandelbrot set at 
 * at user defined x and y values, as well as zoom.
 * If no coordinates are defined, an interactive viewer is
 * served.
 *
 * Created by Tim Lambert on 02/04/12.
 * Containing code created by Richard Buckland on 28/01/11.
 * Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "mandelbrot.h"
#include "pixelColor.h"

#define TRUE 1
#define FALSE 0

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 7191

#define SERVE_BMP  1
#define SERVE_HTML 0

#define SIZE 512

#define BMP_HEADER_SIZE 54
#define BYTES_PER_PIXEL  3

#define MAX_ITERATIONS 256
#define ESCAPE_DISTANCE  4

typedef struct _toServe {
    int serve;
    double x;
    double y;
    int z;
} toServe;

typedef struct _coordinates {
    double x;
    double y;
} coordinates;

typedef struct _rgb {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} rgb;


int waitForConnection(int serverSocket);
int makeServerSocket(int portno);

toServe serveType(char *request);

static void serveHTML(int socket);
void serveBMPHeader(int socket);
void serveBMPPixels(int socket, double xCentre, double yCentre,
                    int zoom);

double power(double base, int exponent);

int escapeSteps(double x, double y); // This may be taken out, discuss.

double findPixelSize(int zoom);

coordinates findCorner(double xCentre, double yCentre, 
                       double pixelSize);
coordinates findFinal(double xCentre, double yCentre, 
                      double pixelSize);

coordinates findPixelCentre(double x, double y, double pixelSize);

int main(int argc, char *argv[]) {
    int serverSocket = makeServerSocket(DEFAULT_PORT);
    char request[REQUEST_BUFFER_SIZE];

    int numberServed = 0;

    printf("************************************\n");
    printf("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
    printf("Access this server at http://localhost:%d/\n", 
            DEFAULT_PORT);
    printf("************************************\n");

    while (TRUE) {
        printf ("*** So far served %d pages ***\n", numberServed);

        // Wait for a request to be sent from a web browser, open a new
        // connection for this conversation.
        int connectionSocket = waitForConnection(serverSocket);

        // Ensure data is read from the connection.
        int bytesRead;
        bytesRead = read(connectionSocket, request, 
                         (sizeof request) - 1);
        assert(bytesRead >= 0);

        printf(" *** Count of first line of HTTP Request *** : %d\n",
               bytesRead);

        // Print entire request to the console.
        printf(" *** Received HTTP request ***\n %s\n", request);

        printf(" *** Sending HTTP response ***\n");
        printf(" *** Connection Socket *** : %d\n", connectionSocket);

        toServe currentServe = serveType(request);

        // Make sure that both upper and lower case input is accepted.
        if (currentServe.serve == SERVE_BMP) {
            serveBMPHeader(connectionSocket);
            serveBMPPixels(connectionSocket, currentServe.x,
                           currentServe.y, currentServe.z);
        } else {
            serveHTML(connectionSocket);
        }

        // Close the connection after sending the page.
        close(connectionSocket);

        numberServed++;
    }
   
    // Close the server connection after we are done.
    printf("** Shutting down the server **\n");
    close(serverSocket);

    return EXIT_SUCCESS;
}


toServe serveType(char *request) {
    double xRequest;
    double yRequest;
    int zRequest;

    char xRequestCheck;
    char yRequestCheck;
    char zRequestCheck;

    sscanf(request, "GET /tile_%c%lf_%c%lf_%c%d.bmp", 
           &xRequestCheck, &xRequest, &yRequestCheck, &yRequest,
           &zRequestCheck, &zRequest);

    toServe currentServe;

    currentServe.x = xRequest;
    currentServe.y = yRequest;
    currentServe.z = zRequest;

    // Makes sure that both upper and lower case input is accepted.
    if ((xRequestCheck == 'X' || xRequestCheck == 'x')
        && (yRequestCheck == 'Y' || yRequestCheck == 'y')
        && (zRequestCheck == 'Z' || zRequestCheck == 'z')) {
        currentServe.serve = SERVE_BMP;
    } else {
        currentServe.serve = SERVE_HTML;
    }

    return currentServe;
}

static void serveHTML (int socket) {
    char* message;
 
    // First send the HTTP response header.
    message =
        "HTTP/1.0 200 Found\n"
        "Content-Type: text/html\n"
        "\n";
    printf("about to send=> %s\n", message);
    write(socket, message, strlen (message));
 
    message =
        "<!DOCTYPE html>\n"
        "<script src=\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>"
        "\n";
    write(socket, message, strlen (message));
}

void serveBMPHeader(int socket) {
    char* message;

    // Send the HTTP response header.
    message = 
        "HTTP/1.0 200 OK\r\n"
        "Content-Type: image/bmp\r\n"
        "\r\n";
    printf("About to send: %s\n", message);
    write(socket, message, strlen(message));

    unsigned char bmpHeader[BMP_HEADER_SIZE] = {
        0x42,0x4d,0x5a,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,
        0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,
        0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,
        0x00,0x00,0x24,0x00,0x00,0x00,0x13,0x0b,
        0x00,0x00,0x13,0x0b,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00};

    write(socket, bmpHeader, sizeof(bmpHeader));
}

void serveBMPPixels(int socket, double xCentre, double yCentre, 
                    int zoom) {
    unsigned char bmpPixels[SIZE * SIZE * BYTES_PER_PIXEL];
    // Position within the pixel array.
    int position = 0; 

    rgb pixelColor;

    int iterations;

    double pixelSize = findPixelSize(zoom);

    coordinates corner = findCorner(xCentre, yCentre, pixelSize);

    coordinates final = findFinal(xCentre, yCentre, pixelSize);

    coordinates current = corner;

    while (current.y <= final.y - pixelSize) {
        coordinates pixelCentre = findPixelCentre(current.x, current.y,
                                                  pixelSize);

        iterations = escapeSteps(pixelCentre.x, pixelCentre.y);

        pixelColor.blue = stepsToBlue(iterations);
        pixelColor.green = stepsToGreen(iterations);
        pixelColor.red = stepsToRed(iterations);

        bmpPixels[position] = pixelColor.blue;
        bmpPixels[position + 1] = pixelColor.green;
        bmpPixels[position + 2] = pixelColor.red;

        position += BYTES_PER_PIXEL;

        if (current.x == final.x - pixelSize) {
            // End of line. Reset x and move up a line.
            current.x = corner.x;
            current.y += pixelSize; 
        } else {
            current.x += pixelSize;
        }
    }

    write(socket, bmpPixels, sizeof(bmpPixels));
}

// Start the server listening on the specified port number.

int makeServerSocket(int portNumber) {
    // Create socket.
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    assert(serverSocket >= 0);
    // Error opening socket.
 
    // Bind socket to listening port.
    struct sockaddr_in serverAddress;
    memset((char *) &serverAddress, 0, sizeof(serverAddress));
 
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(portNumber);
 
    // Let the server start immediately after a previous shutdown.
    int optionValue = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &optionValue,
                sizeof(int));

    int bindSuccess =
        bind (serverSocket, (struct sockaddr *) &serverAddress, 
              sizeof(serverAddress));

    assert(bindSuccess >= 0);
    // If this assert fails wait a short while to let the operating
    // system clear the port before trying again.
 
    return serverSocket;
}

// Returns a socket for conversations to and from on browser request.
 
int waitForConnection(int serverSocket) {
    // Listen for a connection.
    const int serverMaxBacklog = 10;
    listen(serverSocket, serverMaxBacklog);

    // Accept the connection.
    struct sockaddr_in clientAddress;
    socklen_t clientLen = sizeof(clientAddress);
    int connectionSocket =
        accept(serverSocket, (struct sockaddr *) &clientAddress,
               &clientLen);

    assert(connectionSocket >= 0);
    // Ensure a valid connectionSocket.
 
    return(connectionSocket);
}

double power(double base, int exponent) {
    int powerCount = 0;
    double power = base;

    if (exponent >= 1) {
        while (powerCount < exponent - 1) {
            power *= base;

            powerCount++;
        }
    } else if (exponent == 0) {
        power = 1;
    } else {  
        // Negative.
        while (powerCount > exponent + 1) {
            power *= base;

            powerCount--;
        }

        power = 1 / power;
    }

    return power;
}

// Iterations before the point escapes the set (if it does).

int escapeSteps(double x, double y) {
    int iterations = 0;
    int distance = 0;

    double xTest = 0;
    double yTest = 0;
    double xCurrent;

    while (distance < ESCAPE_DISTANCE && iterations < MAX_ITERATIONS) {
        // Cannot use new x below to find y.
        xCurrent = xTest; 

        xTest = power(xTest, 2) - power(yTest, 2) + x;
        yTest = 2 * xCurrent * yTest + y;

        distance = power(xTest, 2) + power(yTest, 2);

        iterations++;
    }

    return iterations;
}

// The distance between the points on the plane.

double findPixelSize(int zoom) {
    double pixelSize = power(2, -zoom);

    return pixelSize;
}

// The bottom left of the plane.

coordinates findCorner(double xCentre, double yCentre, 
                       double pixelSize) {
    coordinates corner;

    corner.x = xCentre - (SIZE * (pixelSize / 2));
    corner.y = yCentre - (SIZE * (pixelSize / 2));

    return corner;
}

// The top right of the plane.

coordinates findFinal(double xCentre, double yCentre, 
                      double pixelSize) {
    coordinates final;

    final.x = xCentre + (SIZE * (pixelSize / 2));
    final.y = yCentre + (SIZE * (pixelSize / 2));

    return final;
}

// Finds the point to test if the point is in the set.

coordinates findPixelCentre(double x, double y, double pixelSize) {
    coordinates pixelCentre;

    pixelCentre.x = x + (pixelSize / 2);
    pixelCentre.y = y + (pixelSize / 2);

    return pixelCentre;
}
