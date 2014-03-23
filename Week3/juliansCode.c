// Julian Saknussemm
// Tests whether or not point is inside a triange

// Porgram takes in three given points of a triangle, and one other
// arbitrary point. It then calculates whether or not the arbitrary
// point lies in the triangle.

// This is determined by satisfying the following rule:
// A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
// if
// P is on the same side of the line AB as C
// P is on the same side of the line BC as A
// and
// P is on the same side of the line AC as B
//
// A special case exits for a vertical line (inf gradient) when testing the side of the line

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_EXPECTED_INPUTS 8

#define UNDER_LINE (-1)
#define ON_LINE 0
#define ABOVE_LINE 1

int testSideOfLine (double px, double py, double m, double b);
int testIsSameSide (double px, double py, double m,double b, double lx,double ly);
int testIsInTriangle(double x0,double y0,double x1,double y1,double x2,double y2,double px, double py);


int main (int argc, char * argv[]) {
    double x0,y0,x1,y1,x2,y2,px,py;

    int numOfInputs = 0;

    // Taking in user input of triangle verticies
    printf ("Triangle Vertex A (x,y): ");
    numOfInputs += scanf ("%lf,%lf", &x0,&y0);

    printf ("Triangle Vertex  B (x,y): "); 
    numOfInputs += scanf ("%lf,%lf", &x1,&y1);

    printf ("Triangle Vertex  C (x,y): "); 
    numOfInputs += scanf ("%lf,%lf", &x2,&y2);

    // Takeing in user input of the points to test
    printf ("Test Point (x,y): "); 
    numOfInputs += scanf ("%lf,%lf", &px,&py);

    // Logic to check and then print error
    // IF number of inputs are not expected
    if (numOfInputs != NUMBER_OF_EXPECTED_INPUTS) {
        printf ("You're stupid and didn't put in the right inputs!\n");
        return EXIT_FAILURE;
    }
 
    // Print whether or not point is inside the triangle
    printf ("Point (%.2lf,%.2lf) is ", px,py);

    if (testIsInTriangle (x0,y0,x1,y1,x2,y2,px,py)) {
        printf ("Inside");
    } else {
        printf ("Outside");
    }
    printf (" the triangle\n");
 
    return EXIT_SUCCESS;
}

// Tests whether point is under, above or on the line
int testSideOfLine (double px, double py, double m, double b) {
    int sideOfLineResult;

    if( py < m * px + b ) {
        sideOfLineResult = UNDER_LINE;
    } else if (py == m * px + b){
        sideOfLineResult = ON_LINE;
    } else {
        sideOfLineResult = ABOVE_LINE;
    }

    return sideOfLineResult;
}

// Function to test whether or not two points lie on the same line
int testIsSameSide (double px, double py, double m,double b, double lx,double ly) {
    return (testSideOfLine( px,py, m,b) == testSideOfLine (lx,ly,m,b));
}

// Final check to test if point is in the triangle
int testIsInTriangle(double x0,double y0,double x1,double y1,double x2,double y2,double px, double py) {
    // Line equations / logic
    int line1;
    int line2;
    int line3;
    
    double m01, m02, m12, b01, b02, b12;
    m01 = (y1-y0)/(x1-x0);
    m02 = (y2-y0)/(x2-x0);
    m12 = (y2-y1)/(x2-x1);
    // Equation : b: y - y1 = m( x - x1 ), x = 0
    b01 = m01 * -x1 + y1;
    b02 = m02 * -x2 + y2;
    b12 = m12 * -x2 + y2;
 
    // Vertical line checks
    if (x1 == x0) {
        line1 = ((px <= x0) == (x2 <= x0));
    } else {
        line1 = testIsSameSide (px, py, m01, b01,x2,y2);
    }
 
    if (x1 == x2) {
        line2 = ((px <= x2) == (x0 <= x2));
    } else {
        line2 = testIsSameSide (px,py, m12, b12,x0,y0);
    }
 
    if (x2 == x0) {
        line3 = ((px <= x0 ) == (x1 <= x0));
    } else {
        line3 = testIsSameSide (px, py, m02,b02,x1,y1);
    }
 
    return line1 && line2 && line3;
}
