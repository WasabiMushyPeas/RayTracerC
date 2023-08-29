#ifndef RAY_H
#define RAY_H

#include "vector3.h"
#include "vars.h"

typedef struct Lightray
{
    struct vector3D *origin;
    struct vector3D *direction;

} ray;

struct vector3D rayAt(ray rayFind, float t);

#endif