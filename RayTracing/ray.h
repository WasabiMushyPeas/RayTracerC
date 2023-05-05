#ifndef RAY_H
#define RAY_H

#include "vector3.h"
#include "vars.h"

typedef struct ray
{
    vec3 origin;
    vec3 direction;

} ray;

vec3 rayAt(ray rayFind, float t);

#endif