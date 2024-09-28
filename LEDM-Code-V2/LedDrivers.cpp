#include "LedDriver.h"

uint8_t led_indexes[36];  // Maximum 36 LEDs in a 6x6 matrix
uint8_t led_count;

// Anode | Cathode composite key pairs (for driver addressing)
const uint8_t PROGMEM ledPinPairs[][2] = {
    {4, 1}, {1, 4}, {3, 1}, {1, 3}, {2, 1}, {1, 2},
    {7, 1}, {1, 7}, {6, 1}, {1, 6}, {5, 1}, {1, 5},
    {5, 7}, {7, 5}, {5, 6}, {6, 5}, {7, 6}, {6, 7},
    {3, 4}, {4, 3}, {3, 5}, {5, 3}, {4, 5}, {5, 4},
    {6, 3}, {3, 6}, {2, 3}, {3, 2}, {7, 3}, {3, 7},
    {2, 4}, {4, 2}, {4, 6}, {6, 4}, {6, 2}, {2, 6}
      
};

uint8_t mapLedPosToIndex(uint8_t byteIndex, uint8_t bitPosition) {
  
    if (byteIndex >= 5 || bitPosition >= 8) {
        return 255;  // Return invalid index
    }

   
    uint8_t ledIndex = byteIndex * 8 + (7 - bitPosition);

    if (ledIndex >= 36) {
        return 255;  
    }

    return ledIndex;
}


void ledHIGH(uint8_t ledIndex) {
    static uint8_t lastAnode = 255;
    static uint8_t lastCathode = 255;

    if (ledIndex >= 36) return;  

    uint8_t anode = pgm_read_byte(&ledPinPairs[ledIndex][0]) + 2;
    uint8_t cathode = pgm_read_byte(&ledPinPairs[ledIndex][1]) + 2;

    if (lastAnode != 255 && lastCathode != 255) {
        pinMode(lastAnode, INPUT);
        pinMode(lastCathode, INPUT);
    }

    pinMode(anode, OUTPUT);
    pinMode(cathode, OUTPUT);
    digitalWrite(cathode, LOW);
    digitalWrite(anode, HIGH);

    lastAnode = anode;
    lastCathode = cathode;
}

void ledLOW(uint8_t ledIndex) {
    if (ledIndex >= 36) return;  

    uint8_t anode = pgm_read_byte(&ledPinPairs[ledIndex][0]) + 2;
    uint8_t cathode = pgm_read_byte(&ledPinPairs[ledIndex][1]) + 2;

    pinMode(anode, INPUT);
    pinMode(cathode, INPUT);
}


// Function to run a specific pattern for a given time interval
void runForInterval(unsigned long interval, void (*func)()) {
    unsigned long startTime = millis();
    while (millis() - startTime < interval) {
        func();
    }
}


// Decodes bit-packed shape values into readable array addresses
void decode_bitpack(const uint8_t *bitpack) {
    uint8_t index = 0;
 
    for (uint8_t byte = 0; byte < 5; byte++) { // Loop through 5 bytes
      
        for (uint8_t bit = 0; bit < 8; bit++) { // Loop through each bit in the byte
            // Calculate the current bit position from MSB to LSB
            uint8_t current_bit = (1 << (7 - bit)); // Reverse the bit order
            
            
            if (pgm_read_byte(&bitpack[byte]) & current_bit) {
                if (index < 36) {
                    
                    
                    led_indexes[index] = byte * 8 + bit; // Add the index value of bit
                    
                    index++;
                } else {
                  
                    return; 
                }
                
            }
        }
    }

    if (index < 36) {
        led_indexes[index] = 255; // End marker
    }
   
}

//Decodes shape width from bitpacks
uint8_t decodeWidth(const uint8_t* bitpack) {
    // Extract the last 4 bits from the 5th byte
    return pgm_read_byte(&bitpack[4]) & 0x0F;
   
  
}
