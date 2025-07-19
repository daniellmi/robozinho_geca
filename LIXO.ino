#include "Motor.h"
#include "Sensor.h"
#include "Leds.h"

#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3

Motor motor;
Leds leds;
Sensor sensor;

void setup() {
  Serial.begin(9600);
  
  leds.calibratingLeds();
  delay(1000);
  leds.calibratingLeds();

}


void loop() {

  if(analogRead(IR1) > 500 && analogRead(IR2) > 500 && analogRead(IR3) > 500 && analogRead(IR4) > 500) {

      motor.stop();
      delay(200);
      motor.back(40, 40);
      leds.ReadLdrOnGreen();
      delay(1000);
      leds.ReadLdrOnGreen();

      if(leds.colorLeft == 'G' && leds.colorRight == 'G') {
        motor.left(120,150);
        delay(2900); // 2300 quando bateria carregada
      }

    else if(leds.colorLeft == 'G') {
      motor.left(100, 100);
      delay(900);
      }

     else if(leds.colorRight == 'G') {
     motor.right(100, 100);
      delay(900);
     }

     else 
     motor.go(75,75);

  } 

   else if (analogRead(IR2) > 500) {
    motor.left(100, 100);
    delay(60);
  }
  
  else if (analogRead(IR3) > 500) {
    motor.right(100, 100);
    delay(60);
  }

  else 
  motor.go(65, 65);

}

