#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "utils.h"
#include "vector3.h"
#include "ray.h"
#include "colour.h"
#include "vars.h"

// setup variables from vars.h
int WIDTH = 256;
int HEIGHT = 256;
uint8_t RGBVALUE = 255;

int main()
{

    struct pixel frame[WIDTH][HEIGHT];

    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        printf("\rScanlines remaining: %d ", j);
        fflush(stdout);

        for (int i = 0; i < WIDTH; i++)
        {

            vec3 pix = {(double)(i) / (WIDTH - 1), (double)(j) / (HEIGHT - 1), 0.25};

            addPixel(frame, i, j, vec3ToPixel(pix));
        }
    }

    writeToPPMFile(WIDTH, HEIGHT, "test.ppm", RGBVALUE, frame[HEIGHT]);

    return 0;
}