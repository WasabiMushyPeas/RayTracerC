#include "colour.h"
#include <stdio.h>

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

// Convert vec3 to pixel
pixel vec3ToPixel(vec3 v)
{
    pixel pix = {doubleToUint8Colour(v.x), doubleToUint8Colour(v.y), doubleToUint8Colour(v.z)};
    return pix;
}