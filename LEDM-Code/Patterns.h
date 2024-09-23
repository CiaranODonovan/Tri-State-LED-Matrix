#ifndef PATTERNS_H
#define PATTERNS_H

#include <Arduino.h>

#define MATRIX_SIZE 6
#define MAX_SHAPE_SIZE 36

struct LetterShape {
    const uint8_t* shape;
    uint8_t size;
    uint8_t width;
};

extern const LetterShape letterShapes[] PROGMEM;
const LetterShape* getLetterShape(char letter);

#endif // PATTERNS_H
