#include <stdlib.h>
#include <stdio.h>
#include "colour.h"
#include "vars.h"

// const int height = HEIGHT;
// const int width = WIDTH;

bool writeToPPMFile(int height, char *fileName, int RGBVALUE, pixel *frame)
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
