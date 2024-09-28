#include "Patterns.h"
#include "LedDriver.h"

int calculateTextWidth(const char* text, int length) {
    int totalWidth = 0;
    for (int i = 0; i < length; i++) {
        totalWidth += 6;
    }
    return totalWidth;
}


void scrollTextLeft(const char* text, int length, int* offsetX) {
    (*offsetX)--;

    // Calculate total text width
    int totalTextWidth = calculateTextWidth(text, length);
    if (*offsetX < -totalTextWidth) {
        *offsetX = 6;  
    }
}


//For later shape renders (unused)
void renderShape(const uint8_t* shape, int offsetX, int offsetY) {
    for (uint8_t byteIndex = 0; byteIndex < 5; byteIndex++) {
        uint8_t currentByte = pgm_read_byte(&shape[byteIndex]);
        
        for (uint8_t bitIndex = 0; bitIndex < 8; bitIndex++) {
            if (currentByte & (1 << (7 - bitIndex))) {
                int x = (byteIndex * 8 + bitIndex) % 6;
                int y = (byteIndex * 8 + bitIndex) / 6;
                
                
                x += offsetX;
                y += offsetY;
                
                if (x >= 0 && x < 6 && y >= 0 && y < 6) {
                    uint8_t ledIndex = y * 6 + x;
                    ledHIGH(ledIndex);
                }
            }
        }
    }
}

void renderText(const char* text, int length, int offsetX) {
    unsigned long startTime = millis();
    const unsigned long FRAME_TIME = 45; // Frame time in milliseconds
    const unsigned long LED_ON_TIME = 100; // 100µs per LED
    
    while (millis() - startTime < FRAME_TIME) {
        int currentX = offsetX;
        for (int i = 0; i < length; i++) {
            const uint8_t* shape = getCharacterShape(text[i]);
            uint8_t letterWidth = decodeWidth(shape);
            
            if (text[i] != ' ') {
                decode_bitpack(shape);
                
                for (uint8_t j = 0; j < 36; j++) {
                    if (led_indexes[j] == 255) break;  
                    
                    int x = led_indexes[j] % 6;
                    int y = led_indexes[j] / 6;
                    
                    x += currentX;
                    
                    if (x >= 0 && x < MATRIX_SIZE && y >= 0 && y < MATRIX_SIZE) {
                        uint8_t ledIndex = y * MATRIX_SIZE + x;
                        ledHIGH(ledIndex);
                        delayMicroseconds(LED_ON_TIME);
                        ledLOW(ledIndex);
                    }
                }
            } 
            currentX += letterWidth; 
        }
    }
}
