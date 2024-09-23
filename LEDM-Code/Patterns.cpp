#include "Patterns.h"
#include <stdint.h>
// Using uint8_t since values don't exceed 66 to save on memory

// Whitespace (2 columns wide, full height)
const uint8_t letterSpace[] PROGMEM = {};

// Null shape
const uint8_t symbolNullShape[] PROGMEM = {22, 32, 42, 52, 53, 54, 55, 45, 35, 25, 24, 23, 16, 34, 43, 61};

// Letter A
const uint8_t letterA[] PROGMEM = {13, 14, 22, 25, 31, 36, 41, 42, 43, 44, 45, 46, 51, 56, 61, 66};

// Letter B
const uint8_t letterB[] PROGMEM = {11, 12, 13, 14, 15, 21, 26, 31, 32, 33, 34, 41, 46, 51, 56, 61, 62, 63, 64, 65};

// Letter C
const uint8_t letterC[] PROGMEM = {12, 13, 14, 15, 21, 31, 41, 51, 62, 63, 64, 65};

// Letter D
const uint8_t letterD[] PROGMEM = {11, 12, 13, 14, 15, 21, 26, 31, 36, 41, 46, 51, 56, 62, 63, 64, 65};

// Letter E
const uint8_t letterE[] PROGMEM = {11, 12, 13, 14, 15, 16, 21, 31, 41, 42, 43, 44, 51, 61, 62, 63, 64, 65, 66};

// Letter F
const uint8_t letterF[] PROGMEM = {11, 12, 13, 14, 15, 16, 21, 31, 41, 42, 43, 44, 51, 61};

// Letter G
const uint8_t letterG[] PROGMEM = {12, 13, 14, 15, 21, 31, 41, 51, 62, 63, 64, 65, 56, 46, 45, 44};

// Letter H
const uint8_t letterH[] PROGMEM = {11, 16, 21, 26, 31, 36, 41, 42, 43, 44, 45, 46, 51, 56, 61, 66};

// Letter I
const uint8_t letterI[] PROGMEM = {12, 13, 14, 15, 23, 24, 33, 34, 43, 44, 53, 54, 62, 63, 64, 65};

// Letter J
const uint8_t letterJ[] PROGMEM = {14, 15, 16, 25, 35, 45, 51, 55, 62, 63, 64};

// Letter K
const uint8_t letterK[] PROGMEM = {11, 16, 21, 26, 31, 36, 41, 45, 51, 54, 61, 63, 66};

// Letter L
const uint8_t letterL[] PROGMEM = {11, 21, 31, 41, 51, 61, 62, 63, 64, 65, 66};

// Letter M
const uint8_t letterM[] PROGMEM = {11, 16, 21, 22, 26, 31, 33, 36, 41, 34, 46, 51, 56, 61, 66};

// Letter N
const uint8_t letterN[] PROGMEM = {11, 16, 21, 22, 26, 31, 33, 36, 41, 44, 46, 51, 55, 56, 61, 66};

// Letter O
const uint8_t letterO[] PROGMEM = {12, 13, 14, 15, 21, 26, 31, 36, 41, 46, 51, 56, 62, 63, 64, 65};

// Letter P
const uint8_t letterP[] PROGMEM = {11, 12, 13, 14, 15, 21, 26, 31, 36, 41, 42, 43, 44, 45, 51, 61};

// Letter Q
const uint8_t letterQ[] PROGMEM = {12, 13, 14, 15, 21, 26, 31, 36, 41, 46, 51, 54, 56, 62, 63, 64, 65, 66};

// Letter R
const uint8_t letterR[] PROGMEM = {11, 12, 13, 14, 15, 21, 26, 31, 36, 41, 42, 43, 44, 45, 51, 54, 61, 66};

// Letter S
const uint8_t letterS[] PROGMEM = {12, 13, 14, 15, 21, 31, 42, 43, 44, 56, 62, 63, 64, 65};

// Letter T
const uint8_t letterT[] PROGMEM = {11, 12, 13, 14, 15, 16, 23, 24, 33, 34, 43, 44, 53, 54, 63, 64};

// Letter U
const uint8_t letterU[] PROGMEM = {11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 62, 63, 64, 65};

// Letter V
const uint8_t letterV[] PROGMEM = {11, 16, 21, 26, 31, 36, 42, 45, 53, 54};

// Letter W
const uint8_t letterW[] PROGMEM = {11, 16, 21, 26, 31, 36, 41, 44, 46, 51, 53, 55, 56, 62, 65};

// Letter X
const uint8_t letterX[] PROGMEM = {11, 16, 22, 25, 33, 34, 43, 44, 52, 55, 61, 66};

// Letter Y
const uint8_t letterY[] PROGMEM = {11, 16, 22, 25, 33, 34, 43, 44, 53, 54, 63, 64};

// Letter Z
const uint8_t letterZ[] PROGMEM = {11, 12, 13, 14, 15, 16, 25, 34, 43, 52, 61, 62, 63, 64, 65, 66};

// Array of LetterShape structures containing each letter's shape, size, and width
const LetterShape letterShapes[] PROGMEM = {
    {letterA, sizeof(letterA) / sizeof(letterA[0]), 6},  // A
    {letterB, sizeof(letterB) / sizeof(letterB[0]), 6},  // B
    {letterC, sizeof(letterC) / sizeof(letterC[0]), 6},  // C
    {letterD, sizeof(letterD) / sizeof(letterD[0]), 6},  // D
    {letterE, sizeof(letterE) / sizeof(letterE[0]), 6},  // E
    {letterF, sizeof(letterF) / sizeof(letterF[0]), 6},  // F
    {letterG, sizeof(letterG) / sizeof(letterG[0]), 6},  // G
    {letterH, sizeof(letterH) / sizeof(letterH[0]), 6},  // H
    {letterI, sizeof(letterI) / sizeof(letterI[0]), 6},  // I
    {letterJ, sizeof(letterJ) / sizeof(letterJ[0]), 6},  // J
    {letterK, sizeof(letterK) / sizeof(letterK[0]), 6},  // K
    {letterL, sizeof(letterL) / sizeof(letterL[0]), 6},  // L
    {letterM, sizeof(letterM) / sizeof(letterM[0]), 6},  // M
    {letterN, sizeof(letterN) / sizeof(letterN[0]), 6},  // N
    {letterO, sizeof(letterO) / sizeof(letterO[0]), 6},  // O
    {letterP, sizeof(letterP) / sizeof(letterP[0]), 6},  // P
    {letterQ, sizeof(letterQ) / sizeof(letterQ[0]), 6},  // Q
    {letterR, sizeof(letterR) / sizeof(letterR[0]), 6},  // R
    {letterS, sizeof(letterS) / sizeof(letterS[0]), 6},  // S
    {letterT, sizeof(letterT) / sizeof(letterT[0]), 6},  // T
    {letterU, sizeof(letterU) / sizeof(letterU[0]), 6},  // U
    {letterV, sizeof(letterV) / sizeof(letterV[0]), 6},  // V
    {letterW, sizeof(letterW) / sizeof(letterW[0]), 6},  // W
    {letterX, sizeof(letterX) / sizeof(letterX[0]), 6},  // X
    {letterY, sizeof(letterY) / sizeof(letterY[0]), 6},  // Y
    {letterZ, sizeof(letterZ) / sizeof(letterZ[0]), 6},  // Z
    {symbolNullShape, sizeof(symbolNullShape) / sizeof(symbolNullShape[0]), 6},  // Null symbol
    {letterSpace, 0, 2}  // Space (2 columns wide)
};

// Getter function for Letter shapes
const LetterShape* getLetterShape(char letter) {
    if (letter == ' ') {
        return &letterShapes[27];  // Index of the space character
    } else if (letter >= 'A' && letter <= 'Z') {
        return &letterShapes[letter - 'A'];
    }
    return &letterShapes[26];  // Return null shape if not found
}
