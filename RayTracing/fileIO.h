#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "colour.h"
#include "vars.h"

// Write a function to write the frame to a PPM file (P3) that returns a bool
bool writeToPPMFile(char *fileName, int RGBVALUE, pixel frame[WIDTH][HEIGHT])
{
    FILE *file = fopen(fileName, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf(file, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, RGBVALUE);

    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            fprintf(file, "%d %d %d\n", frame[i][j].red, frame[i][j].green, frame[i][j].blue);
        }
    }

    fclose(file);

    return true;
}