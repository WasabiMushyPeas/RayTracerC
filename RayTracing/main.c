#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "vector3.h"
#include "ray.h"
#include "colour.h"

const int WIDTH = 256;
const int HEIGHT = 256;
const int RGBVALUE = 255;

int main()
{

    pixel frame[WIDTH][HEIGHT];

    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        printf("\rScanlines remaining: %d ", j);
        fflush(stdout);

        for (int i = 0; i < WIDTH; i++)
        {

            struct Vector3 pix = {(double)(i) / (WIDTH - 1), (double)(j) / (HEIGHT - 1), 0.25};

            addPixel(frame, i, j, vec3ToPixel(pix));
        }
    }

    writeToPPMFile(WIDTH, HEIGHT, "test.ppm", RGBVALUE, frame);

    return 0;
}