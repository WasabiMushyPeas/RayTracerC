#include "ray.h"
#include "vector3.h"

// Multiply ray by scalar and add to origin
vec3 rayAt(ray rayFind, float t)
{
    vec3 origin = rayFind.origin;
    vec3 direction = rayFind.direction;
    return add(origin, mulScalar(direction, t));
}