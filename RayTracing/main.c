#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "utils.h"
#include "vector3.h"
#include "ray.h"
#include "colour.h"
#include "vars.h"
#include "fileIO.h"

// setup variables from vars.h
const int RGBVALUE = 255;
const char fileName[] = "test.ppm";

int main()
{
    pixel frame[WIDTH][HEIGHT];

    for (int j = 0; j < HEIGHT; j++)
    {
        printf("Scanline: %d\n", j);

        for (int i = 0; i < WIDTH; i++)
        {

            double r = (double)(i) / (WIDTH - 1);
            double g = (double)(j) / (HEIGHT - 1);
            double b = 0.25;

            frame[i][j].red = doubleToUint8Colour(r);
            frame[i][j].green = doubleToUint8Colour(g);
            frame[i][j].blue = doubleToUint8Colour(b);
        }
    }

    printFrame(frame);

    if (writeToPPMFile(frame))
    {
        printf("\nSuccessfully wrote to file %s\n", fileName);
    }
    else
    {
        printf("\nFailed to write to file %s\n", fileName);
    }

    fflush(stdout);

    return 0;
}
