#include "Motor.h"
#include "Sensor.h"
#include "Display.h"

#include <Wire.h>

#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3

#define LEFT_GREEN A4
#define LEFT_RED A5
#define LEFT_BLUE A6

#define RIGHT_RED A8
#define RIGHT_GREEN A9
#define RIGHT_BLUE A10

#define RIGHT_LDR A7
#define LEFT_LDR A11

char color1_right;
char color2_left;

// |--- VALORES DAS LEDS ESQUERDAS NO BRANCO ---|
int LEFT_RED_WHITE_VALUE; 
int LEFT_GREEN_WHITE_VALUE; 
int LEFT_BLUE_WHITE_VALUE;

// |--- VALORES DAS LEDS DIREITAS NO BRANCO ---|
int RIGHT_RED_WHITE_VALUE;
int RIGHT_GREEN_WHITE_VALUE; 
int RIGHT_BLUE_WHITE_VALUE; 


Motor motor;
Sensor sensor;
Display display("LIXO");

void setup() {

  Serial.begin(9600);
  Wire.begin();
  display.startDisplay(4);

  CalibratingLeds();
  delay(1000);
  CalibratingLeds();


}

void loop() {

 
// // readIRS();

  if(sensor.readtSensor() <= 17) {
    motor.stop();
    delay(1000);
    motor.back(200);
    delay(800);
    motor.right(200, 200);
    delay(505);
    motor.go(200, 200);
    delay(2800);
    motor.left(200,200);
    delay(2000);
  }

if (analogRead(IR1) > 300 && analogRead(IR2) > 300 && analogRead(IR3) > 400 && analogRead(IR4) > 400) {
  motor.stop();

  LendoVerde();
  delay(1000);

  if(color1_right == 'G' && color2_left == 'G' ) {
    motor.left(65, 70);
    delay(6000);
  }
  else if(color1_right == 'G') {
    motor.right(110, 120);
    delay(2100);
  
  }

  else if(color2_left == 'G') {
    motor.left(110, 120);
    delay(2100);
  }

    else if(color1_right == 'B') {
  motor.go(65, 70);
  }

  else if(color2_left == 'B')  {
  motor.go(65, 70);
  }
 }

  //curva fechada pra esquerda (linha só do lado direito)
//  else if (analogRead(IR1) > 300 && analogRead(IR2) > 300) {
//     motor.left(110, 120);
//     delay(2100);
//   }

    //curva fechada pra direita (linha só do lado esquerdo)
  // else if (analogRead(IR3) > 500 && analogRead(IR4) > 500 || analogRead(IR1) < 100 && analogRead(IR3) > 500 && analogRead(IR4) > 500 ) {
  //   motor.right(110, 120);
  //   delay(2100);
  // }

  //curva leve pra esquerda
  else if (analogRead(IR1) > 300 || analogRead(IR2) > 300) {
    motor.left(110, 120);
    delay(110);
  }
  
    //curva leve pra direita
  else if (analogRead(IR3) > 500 || analogRead(IR4) > 500) {
    motor.right(110, 120);
    delay(150);
  }

  else if (analogRead(IR4) > 300 && 
           analogRead(IR1) < 150 && 
           analogRead(IR2) < 150 && 
           analogRead(IR3) < 150) {
  motor.right(90, 90);
  delay(80);
}

  else if (
  analogRead(IR4) > 400 &&
  analogRead(IR3) > 400 &&
  analogRead(IR2) > 400 &&
  analogRead(IR1) < 250
  ){
    motor.right(90, 90);
    delay(100);
  }

  //nenhum sensor vê preto: segue em frente
 else 
motor.go(55, 60);
}

 void readIRS() {
     Serial.print("IR1: ");
      Serial.println(analogRead(IR1));

   Serial.print("IR2: ");
      Serial.println(analogRead(IR2));

   Serial.print("IR3: ");
      Serial.println(analogRead(IR3));
     
   Serial.print("IR4: ");
      Serial.println(analogRead(IR4));
}

void CalibratingLeds() {

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


// valor da LDR no branco < 700 
// valor da LDR na fita verde > 700
void LendoVerde() {
  analogWrite(LEFT_RED, 0);
  analogWrite(RIGHT_RED, 0);
  delay(100);
  int valorLED1RC = analogRead(LEFT_LDR);
  int valorLED2RC = analogRead(RIGHT_LDR);
  delay(10);
  analogWrite(RIGHT_RED, 255);
  analogWrite(RIGHT_RED, 255);

  analogWrite(LEFT_GREEN, 0);
  analogWrite(RIGHT_GREEN, 0);
  delay(100);
 int valorLED1GC = analogRead(LEFT_LDR);
 int valorLED2GC = analogRead(RIGHT_LDR);
  delay(10);
  analogWrite(LEFT_GREEN, 255);
  analogWrite(LEFT_GREEN, 255);

  analogWrite(LEFT_BLUE, 0);
  analogWrite(RIGHT_BLUE, 0);
  delay(100);
  int valorLED1BC = analogRead(LEFT_LDR);
 int valorLED2BC = analogRead(RIGHT_LDR);
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
      color1_right = 'G';
    }
  }
  else {
    color1_right = 'B';
  }
  if (valorDiferencaLED2G < valorDiferencaLED2R && valorDiferencaLED2G < valorDiferencaLED2B) {

    //**************************COMPARANDO VALORES DO LED2**********************
   int DiferencaDaDiferenca1E = valorDiferencaLED2R - valorDiferencaLED2G;
   int DiferencaDaDiferenca2E = valorDiferencaLED2B - valorDiferencaLED2G;
   int MEDIA2 = (DiferencaDaDiferenca1E + DiferencaDaDiferenca2E) / 2;

    if (MEDIA2 > 20) {
      color2_left = 'G';
   }
  }
  else {
    color2_left = 'B';
  }
}
