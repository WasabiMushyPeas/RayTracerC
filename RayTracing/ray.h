#ifndef RAY_H
#define RAY_H

#include "vector3.h"
#include "vars.h"

typedef struct ray
{
    vec3 origin;
    vec3 direction;
} ray;

// Multiply ray by scalar and add to origin
vec3 rayAt(ray rayFind, float t)
{
    vec3 origin = rayFind.origin;
    vec3 direction = rayFind.direction;
    return add(origin, mulScalar(direction, t));
}

#endif