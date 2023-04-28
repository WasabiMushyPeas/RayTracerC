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

// double 0.0 - 1.0 to uint8_t 0 - 255
uint8_t doubleToUint8Colour(double d)
{
    return (uint8_t)(d * 255.0);
}

// Print pixel
void printPixel(pixel pix)
{
    printf("Pixel: %d %d %d\n", pix.red, pix.green, pix.blue);
}

#endif