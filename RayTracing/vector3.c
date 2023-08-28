#include "vector3.h"
#include <stdio.h>

// Make vector negative
vec3 neg(vec3 v)
{
    vec3 result = {-v.x, -v.y, -v.z};
    return result;
}

// Add two vectors
vec3 add(vec3 v1, vec3 v2)
{
    vec3 result = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    return result;
}

// Subtract two vectors
vec3 sub(vec3 v1, vec3 v2)
{
    vec3 result = {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
    return result;
}

// Multiply two vectors
vec3 mul(vec3 v1, vec3 v2)
{
    vec3 result = {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
    return result;
}

// Divide two vectors
vec3 divide(vec3 v1, vec3 v2)
{
    vec3 result = {v1.x / v2.x, v1.y / v2.y, v1.z / v2.z};
    return result;
}

// Multiply vector by scalar
vec3 mulScalar(vec3 v, double s)
{
    vec3 result = {v.x * s, v.y * s, v.z * s};
    return result;
}

// Divide vector by scalar
vec3 divScalar(vec3 v, double s)
{
    vec3 result = {v.x / s, v.y / s, v.z / s};
    return result;
}

// Get vector magnitude
double magnitude(vec3 v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Normalize vector
vec3 normalize(vec3 v)
{
    double mag = magnitude(v);
    vec3 result = {v.x / mag, v.y / mag, v.z / mag};
    return result;
}

// Dot product of two vectors
double dot(vec3 v1, vec3 v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Cross product of two vectors
vec3 cross(vec3 v1, vec3 v2)
{
    vec3 result = {v1.y * v2.z - v1.z * v2.y,
                   v1.z * v2.x - v1.x * v2.z,
                   v1.x * v2.y - v1.y * v2.x};
    return result;
}

// Print vector
void printVector(vec3 v)
{
    printf("Vector3(%f, %f, %f)\n", v.x, v.y, v.z);
}