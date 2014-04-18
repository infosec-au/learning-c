#include <math.h>
#include <stdlib.h>

#include "pixelColor.h"

#define MAX_ITERATIONS 256

//tile_x-0.2205352783203125_y0.6919708251953125_z24
//tile_x-0.220567_y0.691985_z24.bmp  or z23

unsigned char stepsToRed(int steps) {
    unsigned char color;

    if (steps == MAX_ITERATIONS) {
        color = 0;
    } else {
        color = abs(pow(steps, 5)) % 256;
    }

    return color;
}

unsigned char stepsToBlue(int steps) {
    unsigned char color;

    if (steps == MAX_ITERATIONS) {
        color = 0;
    } else {
        color = abs(log(pow(steps, 11))) % 256;
    }

    return color;
}

unsigned char stepsToGreen(int steps) {
    unsigned char color;

    if (steps == MAX_ITERATIONS) {
        color = 0;
    } else {
        color = abs(sqrt(pow(steps, 2))) % 256;
    }

    return color;
}
