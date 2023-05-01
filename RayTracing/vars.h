#ifndef VARS_H
#define VARS_H

#include <stdint.h>
#include "colour.h"

#define WIDTH 256
#define HEIGHT 256
extern const uint8_t RGBVALUE;
extern const char fileName[];
extern struct pixel frame[WIDTH][HEIGHT];

#endif