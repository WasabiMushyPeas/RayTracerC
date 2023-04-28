#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "colour.h"
#include "vars.h"

void writeToPPMFile()
{
    FILE *file = fopen(fileName, "w");

    fprintf(file, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, RGBVALUE);

    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            fprintf(file, "%d %d %d\n", frame[i][j].red, frame[i][j].green, frame[i][j].blue);
        }
    }

    fclose(file);
}
