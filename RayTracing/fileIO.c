#include "fileIO.h"

// Write a function to write the frame to a PPM file (P3) that returns a bool
bool writeToPPMFile(pixel f[WIDTH][HEIGHT])
{
    FILE *file = fopen(fileName, "w");

    if (file == NULL)
    {
        return false;
    }

    fprintf(file, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, RGBVALUE);

    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            fprintf(file, "%d %d %d\n", f[i][j].red, f[i][j].green, f[i][j].blue);
        }
    }

    fclose(file);

    return true;
}

// Print frame
void printFrame(pixel f[WIDTH][HEIGHT])
{
    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            printf("Place in array %d %d\n", i, j);
            printPixel(f[i][j]);
        }
    }
}