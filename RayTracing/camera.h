#ifndef CAMERA_H
#define CAMERA_H

#include "vector3.h"

typedef struct camera
{
    double viewport_height;
    double viewport_width;
    double focal_length;
    vec3 origin;
    vec3 horizontal;
    vec3 vertical;
    vec3 lower_left_corner;

} camera;

#endif