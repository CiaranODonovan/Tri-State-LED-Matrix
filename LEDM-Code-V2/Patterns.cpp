#include "Patterns.h"
#include <stdint.h>
// 36 Bits encode pixel values, (left to right)
// Last 4 bits encode width : 0010 (width 2), 0110 (width 6)

// Whitespace (2 columns wide)
const uint8_t letterSpace[] PROGMEM = {0b00000000,0b00000000,0b00000000, 0b00000000, 0b00000010}; 

// Capital letters (6 columns wide)
const uint8_t letterATest[] PROGMEM = { 0b00110001,0b00101000,0b01111111, 0b10000110, 0b00010110 }; 

const uint8_t letterBTest[] PROGMEM = { 0b11111010, 0b00011111, 0b00100001, 0b11111110, 0b00000110 }; 

const uint8_t letterCTest[] PROGMEM = { 0b01111010, 0b00001000, 0b00100000, 0b10000001, 0b11100110 };

const uint8_t letterDTest[] PROGMEM = { 0b11111010, 0b00011000, 0b01100001, 0b10000101, 0b11100110 }; 

const uint8_t letterETest[] PROGMEM = { 0b11111110, 0b00001000, 0b00111100, 0b10000011, 0b11110110 }; 

const uint8_t letterFTest[] PROGMEM = { 0b11111110, 0b00001000, 0b00111100, 0b10000010, 0b00000110 }; 

const uint8_t letterGTest[] PROGMEM = { 0b01111010, 0b00001000, 0b00100000, 0b11110101, 0b11100110 }; 

const uint8_t letterHTest[] PROGMEM = { 0b10000110, 0b00011000, 0b01111111, 0b10000110, 0b00010110 }; 

const uint8_t letterITest[] PROGMEM = { 0b01111000, 0b11000011, 0b00001100, 0b00110001, 0b11100110 }; 

const uint8_t letterJTest[] PROGMEM = { 0b00011100, 0b00100000, 0b10000010, 0b10001001, 0b11000110 }; 

const uint8_t letterKTest[] PROGMEM = { 0b10000110, 0b00011000, 0b01100010, 0b10010010, 0b10010110 }; 

const uint8_t letterLTest[] PROGMEM = { 0b10000010, 0b00001000, 0b00100000, 0b10000011, 0b11110110 }; 

const uint8_t letterMTest[] PROGMEM = { 0b10000111, 0b00011011, 0b01100001, 0b10000110, 0b00010110 }; 

const uint8_t letterNTest[] PROGMEM = { 0b10000111, 0b00011010, 0b01100101, 0b10001110, 0b00010110 }; 

const uint8_t letterOTest[] PROGMEM = { 0b01111010, 0b00011000, 0b01100001, 0b10000101, 0b11100110 }; 

const uint8_t letterPTest[] PROGMEM = { 0b11111010, 0b00011000, 0b01111110, 0b10000010, 0b00000110 }; 

const uint8_t letterQTest[] PROGMEM = { 0b01111010, 0b00011000, 0b01100001, 0b10010101, 0b11110110 }; 

const uint8_t letterRTest[] PROGMEM = { 0b11111010, 0b00011000, 0b01111110, 0b10010010, 0b00010110 }; 

const uint8_t letterSTest[] PROGMEM = { 0b01111010, 0b00001000, 0b00011100, 0b00000101, 0b11100110 }; 

const uint8_t letterTTest[] PROGMEM = { 0b11111100, 0b11000011, 0b00001100, 0b00110000, 0b11000110 }; 

const uint8_t letterUTest[] PROGMEM = { 0b10000110, 0b00011000, 0b01100001, 0b10000101, 0b11100110 }; 

const uint8_t letterVTest[] PROGMEM = { 0b10000110, 0b00011000, 0b01010010, 0b00110000, 0b00000110 }; 

const uint8_t letterWTest[] PROGMEM = { 0b10000110, 0b00011000, 0b01100101, 0b10101101, 0b00100110 }; 

const uint8_t letterXTest[] PROGMEM = { 0b10000101, 0b00100011, 0b00001100, 0b01001010, 0b00010110 }; 

const uint8_t letterYTest[] PROGMEM = { 0b10000101, 0b00100011, 0b00001100, 0b00110000, 0b11000110 }; 

const uint8_t letterZTest[] PROGMEM = { 0b11111100, 0b00100001, 0b00001000, 0b01000011, 0b11110110 }; 


const uint8_t* getCharacterShape(char c) {
    switch(toupper(c)) {  
        case 'A': return letterATest;
        case 'B': return letterBTest;
        case 'C': return letterCTest;
        case 'D': return letterDTest;
        case 'E': return letterETest;
        case 'F': return letterFTest;
        case 'G': return letterGTest;
        case 'H': return letterHTest;
        case 'I': return letterITest;
        case 'J': return letterJTest;
        case 'K': return letterKTest;
        case 'L': return letterLTest;
        case 'M': return letterMTest;
        case 'N': return letterNTest;
        case 'O': return letterOTest;
        case 'P': return letterPTest;
        case 'Q': return letterQTest;
        case 'R': return letterRTest;
        case 'S': return letterSTest;
        case 'T': return letterTTest;
        case 'U': return letterUTest;
        case 'V': return letterVTest;
        case 'W': return letterWTest;
        case 'X': return letterXTest;
        case 'Y': return letterYTest;
        case 'Z': return letterZTest;
        case ' ': return letterSpace;
        default: return letterSpace;  
    }
}
