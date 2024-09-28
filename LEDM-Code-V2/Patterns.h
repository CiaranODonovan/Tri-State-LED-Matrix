#ifndef PATTERNS_H
#define PATTERNS_H

#include <Arduino.h>

#define MATRIX_SIZE 6
#define MAX_SHAPE_SIZE 36


const uint8_t* getCharacterShape(char c);
extern const uint8_t letterSpace[] PROGMEM;
#endif // PATTERNS_H
