// extract.c
// funtions and types used to extract x,y,z values from a
// string containing a url of the form
// "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5"
// initially by richard buckland
// 13 April 2014
// your name here:
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"

#define OFF 0
#define ON 1 

int main (int argc, char *argv[]) {
    
    char * message = "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5";
 
    triordinate dat = extract (message);
 
    // printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);
 
    // assert (dat.x == 3.14);
    // assert (dat.y == -0.141);
    // assert (dat.z == 5);
 
    return EXIT_SUCCESS;
}

// double myAtoD (char *message) {

// }
 
// long myAtoL (char *message) {

// }

triordinate extract (char *message) {
    int counter = 0;
    int counterTwo = 0;
    int stringCounter = 0;

    int lengthX = 0;
    int lengthY = 0;
    int lengthZ = 0;

    while(message[counter] != '\0') {
        if (message[counter] == '_') {
            counter++;
            if (message[counter++] == 'x') {
                while (message[counter] != '_') {
                    lengthX++;
                    counter++;
                }
            }
            counter++;
            if (message[counter++] == 'y') {
                while (message[counter] != '_') {
                    lengthY++;
                    counter++;
                }
            }
            counter++;
            if (message[counter++] == 'z') {
                while (message[counter] != '\0') {
                    lengthZ++;
                    counter++;
                }
            }
        }
        counter++;
    }

    char *stringX[lengthX + 1];
    char *stringY[lengthY + 1];
    char *stringZ[lengthZ + 1];
    
    while(message[counterTwo] != '\0') {
        if (message[counterTwo] == '_') {
            counterTwo++;
            if (message[counterTwo++] == 'x') {
                while (message[counterTwo] != '_') {
                    printf("%c", message[counterTwo]);
                    *stringX[stringCounter] = message[counterTwo];
                    counterTwo++;
                    stringCounter++;
                }
                stringCounter = 0;
            }
            counterTwo++;
            if (message[counterTwo++] == 'y') {
                while (message[counterTwo] != '_') {
                    *stringY[stringCounter] = message[counterTwo];
                    counterTwo++;
                    stringCounter++;
                }
                stringCounter = 0;
            }
            counterTwo++;
            if (message[counterTwo++] == 'z') {
                while (message[counterTwo] != '_') {
                    *stringZ[stringCounter] = message[counterTwo];
                    counterTwo++;
                    stringCounter++;
                }
                stringCounter = 0;
            }
            counterTwo++;
        }
        counterTwo++;
    }
    printf("lengthX : %d\n", lengthX);
    printf("lengthY : %d\n", lengthY);
    printf("lengthZ : %d\n", lengthZ);
    printf("stringX : %s\n", *stringX);
    printf("stringY : %s\n", *stringY);
    printf("stringZ : %s\n", *stringZ);
    triordinate cat;
    cat.x = 1;
    cat.y = 2;
    cat.z = 3;
    return cat;
}