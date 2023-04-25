#ifndef RAY_H
#define RAY_H

#include "vector3.h"

typedef struct Ray
{
    struct Vector3 origin;
    struct Vector3 direction;
} ray;

// Multiply ray by scalar and add to origin
struct Vector3 rayAt(ray rayFind, float t)
{
    struct Vector3 origin = rayFind.origin;
    struct Vector3 direction = rayFind.direction;
    return add(origin, mulScalar(direction, t));
}

#endif