#include "ray.h"
#include <stdio.h>
#include "sphere.h"

// Multiply ray by scalar and add to origin
vec3 rayAt(ray rayFind, float t)
{
    vec3 origin = rayFind.origin;
    vec3 direction = rayFind.direction;
    return add(origin, mulScalar(direction, t));
}

// Get colour of ray
pixel rayColour(ray r)
{
    sphere s = {0.5, {0.0, 0.0, -1.0}};
    if (sphereIntersection(s, r))
    {
        vec3 red = {1.0, 0.0, 0.0};
        return vec3ToPixel(red);
    }

    vec3
        unitDirection = normalize(r.direction);
    float a = 0.5 * (unitDirection.y + 1.0);
    vec3 white = {1.0, 1.0, 1.0};
    vec3 blue = {0.5, 0.7, 1.0};
    return vec3ToPixel(add(mulScalar(white, (1.0 - a)), mulScalar(blue, a)));
}

// Print ray
void printRay(ray r)
{
    printf("Ray: %f, %f, %f / %f, %f, %f\n", r.origin.x, r.origin.y, r.origin.z, r.direction.x, r.direction.y, r.direction.z);
}