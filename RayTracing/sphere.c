#include "sphere.h"

// Sphere intersection
bool sphereIntersection(sphere s, ray r)
{
    vec3 oc = sub(r.origin, s.center);
    float a = dot(r.direction, r.direction);
    float b = 2.0 * dot(oc, r.direction);
    float c = dot(oc, oc) - s.radius * s.radius;
    float discriminant = b * b - 4 * a * c;
    printf("Discriminant: %f\n", discriminant);
    return (discriminant >= 0);
}