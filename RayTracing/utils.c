#include "functions.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void writeToPPMFile(int width, int height, char *fileName, int rgbValue, struct Pixel (*array)[height])
{

    FILE *file = fopen(("./", fileName), "w");

    fprintf(file, "P3\n");
    fprintf(file, "%d", width);
    fprintf(file, " %d\n", height);
    fprintf(file, "%d\n", rgbValue);

    for (int j = height - 1; j >= 0; j--)
    {
        for (int i = 0; i < width; i++)
        {
            fprintf(file, "%d", array[i][j].red);
            fprintf(file, " %d", array[i][j].green);
            fprintf(file, " %d", array[i][j].blue);
            fprintf(file, "\n");
        }

        fclose(file);
    }
}