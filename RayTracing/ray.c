#include "ray.h"

// Multiply ray by scalar and add to origin
struct vector3D rayAt(ray rayFind, float t)
{
    vec3 origin = *rayFind.origin;
    vec3 direction = *rayFind.direction;
    return add(origin, mulScalar(direction, t));
}