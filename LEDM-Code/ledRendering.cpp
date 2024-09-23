#include "Patterns.h"
#include "LedDriver.h"

int calculateTextWidth(const char* text, int length) {
    int totalWidth = 0;
    for (int i = 0; i < length; i++) {
        const LetterShape* letterShape = getLetterShape(text[i]);
        uint8_t width = pgm_read_byte(&letterShape->width);
        totalWidth += width;
    }
    return totalWidth;
}


void scrollTextLeft(const char* text, int length, int* offsetX) {
    (*offsetX)--;

    // Calculate total text width
    int totalTextWidth = calculateTextWidth(text, length);
    if (*offsetX < -totalTextWidth) {
        *offsetX = 6;  // Reset based on matrix width
    }
}

void renderShape(const uint8_t* shape, uint8_t shapeSize, int offsetX, int offsetY) {
    for (uint8_t i = 0; i < shapeSize; i++) {
     
        uint8_t logicalPos = pgm_read_byte(&shape[i]);
        // Extract Y and X from the logical position (1-based)
        int y = logicalPos / 10;  // Extract row (as an int)
        int x = logicalPos % 10;  // Extract column (as an int)
        
        // Adjust x and y with the offsets
        y += offsetY;
        x += offsetX;

        // Ensure x and y are within the valid range of the matrix (1 to MATRIX_SIZE)
        if (x >= 1 && x <= MATRIX_SIZE && y >= 1 && y <= MATRIX_SIZE) {
            uint8_t newPos = (y * 10) + x;
            ledHIGH(newPos);
        }
    }
}


void renderText(const char* text, int length, int offsetX) {
    unsigned long startTime = millis();
    const unsigned long FRAME_TIME = 40; // Frame time
    const unsigned long LED_ON_TIME = 100; // 100µs per LED

    while (millis() - startTime < FRAME_TIME) {
        int currentX = offsetX;
        for (int i = 0; i < length; i++) {
            const LetterShape* letterShapePtr = getLetterShape(text[i]);
            if (!letterShapePtr) continue;

            const uint8_t* shapeData = (const uint8_t*)pgm_read_word(&(letterShapePtr->shape));
            uint8_t shapeSize = pgm_read_byte(&(letterShapePtr->size));
            uint8_t width = pgm_read_byte(&(letterShapePtr->width));

            
            for (uint8_t j = 0; j < shapeSize; j++) {
                uint8_t logicalPos = pgm_read_byte(&shapeData[j]);
                int y = logicalPos / 10;
                int x = logicalPos % 10;
                
                x += currentX;
                if (x >= 1 && x <= MATRIX_SIZE && y >= 1 && y <= MATRIX_SIZE) {
                    uint8_t newPos = (y * 10) + x;
                    ledHIGH(newPos);
                    delayMicroseconds(LED_ON_TIME);
                    ledLOW(newPos);
                }
            }
            currentX += width;  
        }
    }
}
