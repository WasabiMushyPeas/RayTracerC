#include <stdbool.h>
#include "colour.h"
#include "vars.h"

// Write a function to write the frame to a PPM file (P3) that returns a bool
bool writeToPPMFile(const char *fileName, int RGBVALUE, pixel frame[WIDTH][HEIGHT]);