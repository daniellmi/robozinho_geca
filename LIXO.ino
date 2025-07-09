#include "Motor.h"
#include "Sensor.h"
#include "Leds.h"
#include "Display.h"
#include <Wire.h>

#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3

Motor motor;
Sensor sensor;
Leds leds;
Display display("LIXO");

void setup() {

  Serial.begin(9600);
  Wire.begin();
  display.startDisplay(4);

  leds.calibratingLeds();
  delay(1000);
  leds.calibratingLeds();
}

void loop() {

  if(sensor.readtSensor() <= 17) {
    motor.stop();
    delay(1000);
    motor.back(205, 200);
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
  delay(100);
  motor.back(65, 60);
  delay(150);
  leds.ReadLdrOnGreen();
  delay(1000);

//  // caso detecte o cruzamento -- 2 FITAS VERDES
//   if(leds.getColorRight() == 'G' && leds.getColorLeft() == 'G' ) {
//     motor.left(65, 70);
//     delay(6000);
//   }

   if(leds.getColorLeft() == 'G') {
    motor.left(110, 120);
    delay(2100);
  }
 else if(leds.getColorRight() == 'G') {
    motor.right(110, 120);
    delay(2100);
  
  }
  else
  motor.go(60, 55);
 }

 // curva fechada pra esquerda (linha só do lado direito)
 else if (analogRead(IR1) > 300 && analogRead(IR2) > 300) {
    motor.left(110, 120);
    delay(2100);
  }

   // curva fechada pra direita (linha só do lado esquerdo)
  else if (analogRead(IR3) > 500 && analogRead(IR4) > 500 || analogRead(IR1) < 100 && analogRead(IR3) > 500 && analogRead(IR4) > 500 ) {
    motor.right(110, 120);
    delay(2100);
  }

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
motor.go(65, 60);
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
