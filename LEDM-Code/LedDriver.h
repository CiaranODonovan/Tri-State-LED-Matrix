#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <Arduino.h>

// Define the size of the 6x6 matrix
#define MATRIX_SIZE 6

// Direction enum for scrolling
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Function declarations
void ledHIGH(uint8_t ledPosition);
void ledLOW(uint8_t ledPosition);
void runForInterval(unsigned long interval, void (*func)());
void renderShape(const uint8_t* shape, uint8_t shapeSize, int8_t offsetX, int8_t offsetY);

// External array declarations for LED matrix
extern const uint8_t ledPOS[];
extern const uint8_t ledPinNoAnode[];
extern const uint8_t ledPinNoCathode[];



#endif // LEDDRIVER_H
