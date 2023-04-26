#ifndef COLOUR_H
#define COLOUR_H

#include "vector3.h"
#include <stdint.h>
#include "vars.h"

typedef struct pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel;

// Float pixel to uint8_t pixel
pixel vec3ToPixel(vec3 pix)
{
    pixel result = {
        (uint8_t)(pix.x * 255),
        (uint8_t)(pix.y * 255),
        (uint8_t)(pix.z * 255),
    };
    return result;
}

// Add pixel to frame with input as a pixel
void addPixel(pixel frame[WIDTH][HEIGHT], int i, int j, pixel pix)
{
    frame[i][j].red += pix.red;
    frame[i][j].green += pix.green;
    frame[i][j].blue += pix.blue;
}

// Print pixel
void printPixel(pixel pix)
{
    printf("Pixel: %d %d %d\n", pix.red, pix.green, pix.blue);
}

#endif