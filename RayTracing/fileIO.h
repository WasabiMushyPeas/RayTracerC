#ifndef IO_H
#define IO_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "colour.h"
#include "vars.h"

// Write a function to write the frame to a PPM file (P3) that returns a bool
bool writeToPPMFile(pixel f[WIDTH][HEIGHT]);
void printFrame(pixel f[WIDTH][HEIGHT]);

#endif