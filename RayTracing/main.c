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

// Ray to pixel colour
pixel rayToColour(ray r)
{
    vec3 unit_direction = normalize((vec3)*r.direction);
    double t = 0.5 * (unit_direction.y + 1.0);
    vec3 white;
    white.x = 1.0;
    white.y = 1.0;
    white.z = 1.0;
    vec3 blue;
    blue.x = 0.5;
    blue.y = 0.7;
    blue.z = 1.0;
    vec3 colour = add(mulScalar(white, 1.0 - t), mulScalar(blue, t));
    pixel pix;
    pix.red = doubleToUint8Colour(colour.x);
    pix.green = doubleToUint8Colour(colour.y);
    pix.blue = doubleToUint8Colour(colour.z);
    return pix;
}

// setup variables from vars.h
const int RGBVALUE = 255;
const char fileName[] = "test.ppm";

int main()
{

    // Image
    const double aspect_ratio = 16.0 / 9.0;

    // Camera

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    vec3 orig;
    orig.x = 0.0;
    orig.y = 0.0;
    orig.z = 0.0;

    vec3 horizontal;
    horizontal.x = viewport_width;
    horizontal.y = 0.0;
    horizontal.z = 0.0;

    vec3 vertical;
    vertical.x = 0.0;
    vertical.y = viewport_height;
    vertical.z = 0.0;

    vec3 temp;
    temp.x = 0.0;
    temp.y = 0.0;
    temp.z = focal_length;

    double lower_left_corner_x = sub(sub(sub(orig, divScalar(horizontal, 2)), divScalar(vertical, 2)), temp).x;
    double lower_left_corner_y = sub(sub(sub(orig, divScalar(horizontal, 2)), divScalar(vertical, 2)), temp).y;
    double lower_left_corner_z = sub(sub(sub(orig, divScalar(horizontal, 2)), divScalar(vertical, 2)), temp).z;

    vec3 lower_left_corner;
    lower_left_corner.x = lower_left_corner_x;
    lower_left_corner.y = lower_left_corner_y;
    lower_left_corner.z = lower_left_corner_z;

    pixel frame[WIDTH][HEIGHT];

    for (int j = 0; j < HEIGHT; j++)
    {
        printf("Scanline: %d\n", j);

        for (int i = 0; i < WIDTH; i++)
        {

            double u = (double)((i) / (WIDTH - 1));
            double v = (double)((j) / (HEIGHT - 1));

            printf("u: %f v: %f\n", u, v);

            ray r;
            r.origin = &orig;
            vec3 dir = sub(add(add(lower_left_corner, mulScalar(horizontal, u)), mulScalar(vertical, v)), (vec3)orig);
            r.direction = &dir;

            pixel pix;
            pix = rayToColour(r);

            frame[i][j] = pix;

            // printPixel(pix);
        }
    }

    // printFrame(frame);

    if (writeToPPMFile(frame))
    {
        printf("\nSuccessfully wrote to file %s\n", fileName);
    }
    else
    {
        printf("\nFailed to write to file %s\n", fileName);
    }

    fflush(stdout);

    return 0;
}
