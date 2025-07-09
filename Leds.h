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
  int valorLED1RC = analogRead(RIGHT_LDR);
  int valorLED2RC = analogRead(LEFT_LDR);
  delay(10);
  analogWrite(LEFT_RED, 255);
  analogWrite(RIGHT_RED, 255);

  analogWrite(LEFT_GREEN, 0);
  analogWrite(RIGHT_GREEN, 0);
  delay(100);
 int valorLED1GC = analogRead(RIGHT_LDR);
 int valorLED2GC = analogRead(LEFT_LDR);
  delay(10);
  analogWrite(LEFT_GREEN, 255);
  analogWrite(RIGHT_GREEN, 255);

  analogWrite(LEFT_BLUE, 0);
  analogWrite(RIGHT_BLUE, 0);
  delay(100);
  int valorLED1BC = analogRead(RIGHT_LDR);
 int valorLED2BC = analogRead(LEFT_LDR);
  delay(10);
  analogWrite(LEFT_BLUE, 255);
  analogWrite(RIGHT_BLUE, 255);

  //**************************COMPARANDO VALORES DO LED1**********************
 int valorDiferencaLED1R = valorLED1RC - RIGHT_RED_WHITE_VALUE;
 int valorDiferencaLED1G = valorLED1GC - RIGHT_GREEN_WHITE_VALUE;
 int valorDiferencaLED1B = valorLED1BC - RIGHT_BLUE_WHITE_VALUE;
 //**************************COMPARANDO VALORES DO LED2**********************
 int valorDiferencaLED2R = valorLED2RC - LEFT_RED_WHITE_VALUE;
 int valorDiferencaLED2G = valorLED2GC - LEFT_GREEN_WHITE_VALUE;
 int valorDiferencaLED2B = valorLED2BC - LEFT_BLUE_WHITE_VALUE;

  if (valorDiferencaLED1G < valorDiferencaLED1R && valorDiferencaLED1G < valorDiferencaLED1B) {

    //**************************COMPARANDO VALORES DOS VALORES DO LED1**********************
   int DiferencaDaDiferenca1D = valorDiferencaLED1R - valorDiferencaLED1G;
   int DiferencaDaDiferenca2D = valorDiferencaLED1B - valorDiferencaLED1G;
   int MEDIA1 = (DiferencaDaDiferenca1D + DiferencaDaDiferenca2D) / 2;

    if (MEDIA1 > 20)
    {
      colorRight = 'G';
    }
  }
  else {
    colorRight = 'B';
  }
  if (valorDiferencaLED2G < valorDiferencaLED2R && valorDiferencaLED2G < valorDiferencaLED2B) {

    //**************************COMPARANDO VALORES DO LED2**********************
   int DiferencaDaDiferenca1E = valorDiferencaLED2R - valorDiferencaLED2G;
   int DiferencaDaDiferenca2E = valorDiferencaLED2B - valorDiferencaLED2G;
   int MEDIA2 = (DiferencaDaDiferenca1E + DiferencaDaDiferenca2E) / 2;

    if (MEDIA2 > 20) {
      colorLeft = 'G';
   }
  }
  else {
    colorLeft = 'B';
  }
}

char Leds::getColorRight() {
  return colorRight;
}
char Leds::getColorLeft() {
  return colorLeft;
}

};
#endif