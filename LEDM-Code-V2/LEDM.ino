#include "ledRendering.h"



//assigning arduino pin number to logical number in a 7 pin system
const int pin1 = 3; //Arduino D3 to logic pin 1 in matrix
const int pin2 = 4; //Arduino D4 to logic pin 2 in matrix
const int pin3 = 5; //Arduino D5 to logic pin 3 in matrix
const int pin4 = 6; //Arduino D6 to logic pin 4 in matrix
const int pin5 = 7; //Arduino D7 to logic pin 5 in matrix
const int pin6 = 8; //Arduino D8 to logic pin 6 in matrix
const int pin7 = 9; //Arduino D9 to logic pin 7 in matrix

char text[] = "TEXT DEMO";  // The text we want to scroll (left in ram for dynamic input controls; to be added later.)

int textLength = sizeof(text) - 1;  // Length of the text (5 characters in this case)

int offsetX = MATRIX_SIZE;  // Start with the text just off the right side of the matrix

void setup() {
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
  pinMode(pin3,INPUT);
  pinMode(pin4,INPUT);
  pinMode(pin5,INPUT);
  pinMode(pin6,INPUT);
  pinMode(pin7,INPUT);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  digitalWrite(pin5,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,LOW);
}

void loop() {
    renderText(text, textLength, offsetX);
    scrollTextLeft(text, textLength, &offsetX);
}
