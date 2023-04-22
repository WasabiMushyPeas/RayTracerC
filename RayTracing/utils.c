#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

struct Pixel
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

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
            fprintf(file, "%d", array[j][i].red);
            fprintf(file, " %d", array[j][i].green);
            fprintf(file, " %d\n", array[j][i].blue);
        }
    }

    fclose(file);

    printf("File written to %s \n", fileName);
}