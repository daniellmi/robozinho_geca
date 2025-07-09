#ifndef LEDS_H
#define LEDS_H

#define LEFT_GREEN A4
#define LEFT_RED A5
#define LEFT_BLUE A6

#define RIGHT_RED A8
#define RIGHT_GREEN A9
#define RIGHT_BLUE A10

#define RIGHT_LDR A7
#define LEFT_LDR A11

class Leds {

// |--- VALORES DAS LEDS ESQUERDAS NO BRANCO ---|
int LEFT_RED_WHITE_VALUE; 
int LEFT_GREEN_WHITE_VALUE; 
int LEFT_BLUE_WHITE_VALUE;

// |--- VALORES DAS LEDS DIREITAS NO BRANCO ---|
int RIGHT_RED_WHITE_VALUE;
int RIGHT_GREEN_WHITE_VALUE; 
int RIGHT_BLUE_WHITE_VALUE; 

char colorRight;
char colorLeft;

public: 

void Leds::calibratingLeds() {

  analogWrite(LEFT_RED, 0);
  analogWrite(RIGHT_RED, 0);
  delay(100);
  LEFT_RED_WHITE_VALUE = analogRead(LEFT_LDR);
  RIGHT_RED_WHITE_VALUE = analogRead(RIGHT_LDR);
  delay(1000);
  analogWrite(LEFT_RED, 255);
  analogWrite(RIGHT_RED, 255);

  analogWrite(LEFT_GREEN, 0);
  analogWrite(RIGHT_GREEN, 0);
  delay(100);
  LEFT_GREEN_WHITE_VALUE = analogRead(LEFT_LDR);
  RIGHT_GREEN_WHITE_VALUE = analogRead(RIGHT_LDR);
  delay(1000);
  analogWrite(LEFT_GREEN, 255);
  analogWrite(RIGHT_GREEN, 255);

  analogWrite(LEFT_BLUE, 0);
  analogWrite(RIGHT_BLUE, 0);
  delay(100);
  LEFT_BLUE_WHITE_VALUE = analogRead(LEFT_LDR);
  RIGHT_BLUE_WHITE_VALUE = analogRead(RIGHT_LDR);
  delay(1000);
  analogWrite(LEFT_BLUE, 255);
  analogWrite(RIGHT_BLUE, 255);
}

void Leds::ReadLdrOnGreen() {
  analogWrite(LEFT_RED, 0);
  analogWrite(RIGHT_RED, 0);
  delay(100);
  int valueLED1RC = analogRead(RIGHT_LDR);
  int valueLED2RC = analogRead(LEFT_LDR);
  delay(10);
  analogWrite(LEFT_RED, 255);
  analogWrite(RIGHT_RED, 255);

  analogWrite(LEFT_GREEN, 0);
  analogWrite(RIGHT_GREEN, 0);
  delay(100);
  int valueLED1GC = analogRead(RIGHT_LDR);
  int valueLED2GC = analogRead(LEFT_LDR);
  delay(10);
  analogWrite(LEFT_GREEN, 255);
  analogWrite(RIGHT_GREEN, 255);

  analogWrite(LEFT_BLUE, 0);
  analogWrite(RIGHT_BLUE, 0);
  delay(100);
  int valueLED1BC = analogRead(RIGHT_LDR);
  int valueLED2BC = analogRead(LEFT_LDR);
  delay(10);
  analogWrite(LEFT_BLUE, 255);
  analogWrite(RIGHT_BLUE, 255);

  //**************************COMPARANDO VALORES DO LED1**********************
 int valueSubtractionLED1R = valueLED1RC - RIGHT_RED_WHITE_VALUE;
 int valueSubtractionLED1G = valueLED1GC - RIGHT_GREEN_WHITE_VALUE;
 int valueSubtractionLED1B = valueLED1BC - RIGHT_BLUE_WHITE_VALUE;
 //**************************COMPARANDO VALORES DO LED2**********************
 int valueSubtractionLED2R = valueLED2RC - LEFT_RED_WHITE_VALUE;
 int valueSubtractionLED2G = valueLED2GC - LEFT_GREEN_WHITE_VALUE;
 int valueSubtractionLED2B = valueLED2BC - LEFT_BLUE_WHITE_VALUE;

  if (valueSubtractionLED1G < valueSubtractionLED1R && valueSubtractionLED1G < valueSubtractionLED1B) {

    //**************************COMPARANDO VALORES DOS VALORES DO LED1**********************
   int Subtraction_Subtraction1D = valueSubtractionLED1R - valueSubtractionLED1G;
   int Subtraction_Subtraction2D = valueSubtractionLED1B - valueSubtractionLED1G;
   int average1 = (Subtraction_Subtraction1D + Subtraction_Subtraction2D) / 2;

    if (average1 > 20)
      colorRight = 'G';
    
  else 
    colorRight = 'B';
  
  if (valueSubtractionLED2G < valueSubtractionLED2R && valueSubtractionLED2G < valueSubtractionLED2B) {

    //**************************COMPARANDO VALORES DO LED2**********************
   int Subtraction_Subtraction1E = valueSubtractionLED2R - valueSubtractionLED2G;
   int Subtraction_Subtraction2E = valueSubtractionLED2B - valueSubtractionLED2G;
   int average2 = (Subtraction_Subtraction1E + Subtraction_Subtraction2E) / 2;

    if (average2 > 20) 
      colorLeft = 'G';
   
  else 
    colorLeft = 'B';
  
}

char Leds::getColorRight() {
  return colorRight;
}
char Leds::getColorLeft() {
  return colorLeft;
}

};
#endif