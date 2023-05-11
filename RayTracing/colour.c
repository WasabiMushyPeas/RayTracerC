#include "colour.h"

// double 0.0 - 1.0 to uint8_t 0 - 255
uint8_t doubleToUint8Colour(double d)
{
    return (uint8_t)(d * 255.999);
}

// Print pixel
void printPixel(pixel pix)
{
    printf("Pixel: %d %d %d\n", pix.red, pix.green, pix.blue);
}