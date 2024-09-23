#include "LedDriver.h"

// Arrays defining logical LED matrix positions and corresponding pin numbers
const uint8_t ledPOS[] = {
    11, 12, 13, 14, 15, 16,
    21, 22, 23, 24, 25, 26,
    31, 32, 33, 34, 35, 36,
    41, 42, 43, 44, 45, 46,
    51, 52, 53, 54, 55, 56,
    61, 62, 63, 64, 65, 66,
    0
};

// Corresponding anode pin numbers
const uint8_t ledPinNoAnode[] = {
    4, 1, 3, 1, 2, 1,
    7, 1, 6, 1, 5, 1,
    5, 7, 5, 6, 7, 6,
    3, 4, 3, 5, 4, 5,
    6, 3, 2, 3, 7, 3,
    2, 4, 4, 6, 6, 2,
    0
};

// Corresponding cathode pin numbers
const uint8_t ledPinNoCathode[] = {
    1, 4, 1, 3, 1, 2,
    1, 7, 1, 6, 1, 5,
    7, 5, 6, 5, 6, 7,
    4, 3, 5, 3, 5, 4,
    3, 6, 3, 2, 3, 7,
    4, 2, 6, 4, 2, 6,
    0
};

void ledHIGH(uint8_t ledPosition) {
    static uint8_t lastAnode = 255;
    static uint8_t lastCathode = 255;
    uint8_t anode = 255;
    uint8_t cathode = 255;

    for (uint8_t i = 0; i < 37; i++) {
        if (ledPOS[i] == ledPosition) {
            anode = ledPinNoAnode[i] + 2;
            cathode = ledPinNoCathode[i] + 2;
            break;
        }
    }

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

void ledLOW(uint8_t ledPosition) {
    uint8_t anode = 255;
    uint8_t cathode = 255;

    for (uint8_t i = 0; i < 37; i++) {
        if (ledPOS[i] == ledPosition) {
            anode = ledPinNoAnode[i] + 2;
            cathode = ledPinNoCathode[i] + 2;
            break;
        }
    }

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
