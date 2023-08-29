#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "utils.h"
#include "vector3.h"
#include "ray.h"
#include "colour.h"
#include "vars.h"
#include "fileIO.h"

// setup variables from vars.h
const uint8_t RGBVALUE = 255;
const char fileName[] = "test.ppm";
struct pixel frame[WIDTH][HEIGHT];
double viewportHeight = 2.0;
double viewportWidth = 4.0;

int main()
{

    // Viewport / Camera instantiation
    double viewportHeight = 2.0;
    double viewportWidth = viewportHeight * (int)(WIDTH / HEIGHT);
    double focalLength = 1.0;
    vec3 cameraOrigin = {0.0, 0.0, 0.0};

    // Viewport
    vec3 viewport_u = {viewportWidth, 0.0, 0.0};
    vec3 viewport_v = {0.0, -viewportHeight, 0.0};

    // Pixel spacing
    vec3 pixel_u_delta = divScalar(viewport_u, (double)(WIDTH));
    vec3 pixel_v_delta = divScalar(viewport_v, (double)(-HEIGHT));

    // Upper Left Pixel
    vec3 focalLengthVec = {0.0, 0.0, focalLength};
    vec3 viewportUpperLeft = sub(cameraOrigin, sub(focalLengthVec, sub(divScalar(viewport_u, 2.0), divScalar(viewport_v, 2.0))));
    vec3 pixel100location = add(viewportUpperLeft, add(mulScalar(pixel_u_delta, 0.5), mulScalar(pixel_v_delta, 0.5)));

    // Render
    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        printf("\rScanlines remaining: %d ", j);

        for (int i = 0; i < WIDTH; i++)
        {
            vec3 pixelCenter = add(pixel100location, add(mulScalar(pixel_u_delta, (double)(i)), mulScalar(pixel_v_delta, (double)(j))));
            vec3 rayDir = sub(pixelCenter, cameraOrigin);
            ray r = {cameraOrigin, rayDir};

            pixel pixColour = rayColour(r);

            frame[i][j].red += pixColour.red;
            frame[i][j].green += pixColour.green;
            frame[i][j].blue += pixColour.blue;
        }
        // fflush(stdout);
    }

    if (writeToPPMFile(fileName, RGBVALUE, frame))
    {
        printf("\nSuccessfully wrote to file %s\n", fileName);
    }
    else
    {
        printf("\nFailed to write to file %s\n", fileName);
    }

    return 0;
}
