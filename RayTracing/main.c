#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "utils.c"

int main()
{
    const int width = 256;
    const int height = 256;
    char *fileName = "test.ppm";
    const uint8_t rgbValue = 255;

    struct Pixel frame[width][height];

    for (int j = 0; j < height; j++)
    {
        printf("Scanlines remaining: %d\n", (height - j));

        for (int i = 0; i < width; i++)
        {
            float r = (float)i / (float)width;
            float g = (float)j / (float)height;
            float b = 0.2f;

            uint8_t ir = (int)(255.99f * r);
            uint8_t ig = (int)(255.99f * g);
            uint8_t ib = (int)(255.99f * b);

            frame[height][width].red = ir;
            frame[height][width].green = ig;
            frame[height][width].blue = ib;
        }
    }

    writeToPPMFile(width, height, fileName, rgbValue, frame);

    printf("Render complete");
    return 0;
}