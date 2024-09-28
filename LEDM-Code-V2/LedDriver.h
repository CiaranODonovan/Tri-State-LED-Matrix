#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <Arduino.h>

// Define the size of the 6x6 matrix
#define MATRIX_SIZE 6



// Function declarations
void ledHIGH(uint8_t ledIndex);
void ledLOW (uint8_t ledIndex);
void runForInterval(unsigned long interval, void (*func)());
void renderShape(const uint8_t* shape, uint8_t shapeSize, int8_t offsetX, int8_t offsetY);
void  decode_bitpack(const uint8_t *bitpack);
uint8_t decodeWidth(const uint8_t* bitpack);

// External array declarations for LED matrix
extern const uint8_t ledPOS[];
extern const uint8_t ledPinPairs[][2];
extern uint8_t led_count;
extern uint8_t led_indexes[36];



#endif // LEDDRIVER_H
