#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "utils.c"

int main()
{
    const int width = 256;
    const int height = 256;

    newPPMFile(width, height, "test.ppm", 255);

    for (int j = height - 1; j >= 0; j--)
    {
        for (int i = 0; i < width; i++)
        {
            float r = (float)i / (float)width;
            float g = (float)j / (float)height;
            float b = 0.2f;

            int ir = (int)(255.99f * r);
            int ig = (int)(255.99f * g);
            int ib = (int)(255.99f * b);

            addPixeltoPPMFile(ir, ig, ib, "test.ppm");
        }
    }

    return 0;
}