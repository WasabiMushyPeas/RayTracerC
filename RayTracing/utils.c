#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void newPPMFile(int width, int height, char *fileName, int rgbValue, int (*array)[height])
{

    FILE *file = fopen(("./", fileName), "w");

    fprintf(file, "P3\n");
    fprintf(file, "%d", width);
    fprintf(file, " %d\n", height);
    fprintf(file, "%d\n", rgbValue);

    fclose(file);
}

void addtoPPMFile(int width, int height, char *fileName, int rgbValue, int (*array)[height])
{

    FILE *file = fopen(("./", fileName), "a");

    fclose(file);
}