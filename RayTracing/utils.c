#include "functions.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

<<<<<<< HEAD
void writeToPPMFile(int width, int height, char *fileName, int rgbValue, struct Pixel (*array)[height])
=======
void newPPMFile(int width, int height, char *fileName, int rgbValue)
>>>>>>> parent of 4b507fb (Still has segment fualt)
{

    FILE *file = fopen(("./", fileName), "w");

    fprintf(file, "P3\n");
    fprintf(file, "%d", width);
    fprintf(file, " %d\n", height);
    fprintf(file, "%d\n", rgbValue);

    fclose(file);
}

void addPixeltoPPMFile(int red, int green, int blue, char *fileName)
{

    FILE *file = fopen(("./", fileName), "a");

    fprintf(file, "%d %d %d\n", red, green, blue);

    fclose(file);
}