#ifndef LEDRENDERING_H
#define LEDRENDERING_H

#include "Patterns.h"
#include "LedDriver.h"

// Calculate the total width of a text string
int calculateTextWidth(const char* text, int length);

// Render text on the LED matrix
void renderText(const char* text, int length, int offsetX);

// Scroll text to the left
void scrollTextLeft(const char* text, int length, int* offsetX);

// Render a shape on the LED matrix
void renderShape(const uint8_t* shape, uint8_t shapeSize, int offsetX, int offsetY);

#endif // LEDRENDERING_H
