#ifndef FUNCTIONS_H_ /* Include guard */
#define FUNCTIONS_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Include functions and structs from utils.c

struct Pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

void writeToPPMFile(int width, int height, char *fileName, int rgbValue, struct Pixel (*array)[height]);

// Include functions and structs from 3Dvector.c

#endif