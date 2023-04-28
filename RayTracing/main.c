#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "utils.h"
#include "vector3.h"
#include "ray.h"
#include "colour.h"
#include "vars.h"

// setup variables from vars.h
const uint8_t RGBVALUE = 255;
const char fileName[] = "test.ppm";

bool writeToPPMFile(char *fileName, int RGBVALUE, pixel frame[WIDTH][HEIGHT]);

int main()
{

    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        printf("\rScanlines remaining: %d ", j);
        fflush(stdout);

        for (int i = 0; i < WIDTH; i++)
        {

            pixel pixColour = {doubleToUint8Colour((double)(i) / (WIDTH - 1)), doubleToUint8Colour((double)(j) / (HEIGHT - 1)), doubleToUint8Colour(0.25)};

            frame[i][j].red += pixColour.red;
            frame[i][j].green += pixColour.green;
            frame[i][j].blue += pixColour.blue;
        }
    }

    writeToPPMFile(fileName, RGBVALUE, frame);

    return 0;
}
