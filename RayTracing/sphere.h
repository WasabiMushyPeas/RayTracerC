#include "vector3.h"
#include "ray.h"
#include <stdbool.h>

typedef struct sphere
{
    double radius;
    vec3 center;
} sphere;

bool sphereIntersection(sphere s, ray r);