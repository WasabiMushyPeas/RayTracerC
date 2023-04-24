#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "utils.c"

int main()
{
    const int width = 256;
    const int height = 256;
    const int rgbValue = 255;
    struct Pixel frame[width][height];

    for (int j = height - 1; j >= 0; j--)
    {
        printf("\rScanlines remaining: %d ", j);
        fflush(stdout);

        for (int i = 0; i < width; i++)
        {
            float r = (float)i / (float)width;
            float g = (float)j / (float)height;
            float b = 0.2f;

            int ir = (int)(255.99f * r);
            int ig = (int)(255.99f * g);
            int ib = (int)(255.99f * b);

            frame[i][j].red = ir;
            frame[i][j].green = ig;
            frame[i][j].blue = ib;
        }
    }

    writeToPPMFile(width, height, "test.ppm", rgbValue, frame);

    return 0;
}