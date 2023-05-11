#ifndef COLOUR_H
#define COLOUR_H

#include <stdint.h>
#include <stdio.h>
// #include "vector3.h"
//  #include "vars.h"

typedef struct pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel;

uint8_t doubleToUint8Colour(double d);

void printPixel(pixel pix);

#endif