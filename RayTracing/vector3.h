#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "vars.h"

typedef struct vector3D
{
    double x;
    double y;
    double z;
} vec3;

// Vector3 functions
vec3 neg(vec3 v);
vec3 add(vec3 v1, vec3 v2);
vec3 sub(vec3 v1, vec3 v2);
vec3 mul(vec3 v1, vec3 v2);
vec3 divide(vec3 v1, vec3 v2);
vec3 mulScalar(vec3 v, double s);
vec3 divScalar(vec3 v, double s);
double magnitude(vec3 v);
vec3 normalize(vec3 v);
double dot(vec3 v1, vec3 v2);
vec3 cross(vec3 v1, vec3 v2);
void printVector(vec3 v);

#endif