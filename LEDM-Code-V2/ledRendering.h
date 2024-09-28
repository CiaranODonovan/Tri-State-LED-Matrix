#ifndef LEDRENDERING_H
#define LEDRENDERING_H

#include "Patterns.h"
#include "LedDriver.h"

// Calculate the total width of a text string
int calculateTextWidth(const char* text, int length);

// Render a shape on the LED matrix
void renderShape(const uint8_t* shape, int offsetX, int offsetY);

// Scroll text to the left
void scrollTextLeft(const char* text, int length, int* offsetX);

// Render text on the LED matrix
void renderText(const char* text, int length, int offsetX);


#endif // LEDRENDERING_H
