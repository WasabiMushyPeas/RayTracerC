#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "structs.h"

bool writeToPPMFile(int width, int height, char *fileName, int rgbValue, struct Pixel frame[width][height])
{
    FILE *file = fopen(fileName, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf(file, "P3\n%d %d\n%d\n", width, height, rgbValue);

    for (int j = height - 1; j >= 0; j--)
    {
        for (int i = 0; i < width; i++)
        {
            fprintf(file, "%d %d %d\n", frame[i][j].red, frame[i][j].green, frame[i][j].blue);
        }
    }

    fclose(file);

    return true;
}
