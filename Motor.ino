#include <Ultrasonic.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define trigger 49
#define echo 22

#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

#define ENA 2
#define ENB 7

#define IN1T 9
#define IN2T 10
#define IN3T 11
#define IN4T 12

#define ENAT 8
#define ENBT 13

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

#define LEFT_LDR A11

class Motor {

public:

  Motor() {

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    pinMode(IN1T, OUTPUT);
    pinMode(IN2T, OUTPUT);
    pinMode(IN3T, OUTPUT);
    pinMode(IN4T, OUTPUT);
    pinMode(ENAT, OUTPUT);
    pinMode(ENBT, OUTPUT);
  }

  void Motor::go(int speed, int speed2) {

    analogWrite(ENA, speed2);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    // ao contrario
    analogWrite(ENAT, speed);
    digitalWrite(IN1T, LOW);
    digitalWrite(IN2T, HIGH);

    analogWrite(ENB, speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENBT, speed);
    digitalWrite(IN3T, HIGH);
    digitalWrite(IN4T, LOW);
  }

  void Motor::stop() {

    //motor 1
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    //motor 2
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);

    //motor 3
    digitalWrite(IN1T, HIGH);
    digitalWrite(IN2T, HIGH);


    //motor 4
    digitalWrite(IN3T, HIGH);
    digitalWrite(IN4T, HIGH);
  }

  void Motor::left(int speed, int speed2) {

    //motor 1 da esquerda
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);

    //motor 2 da esquerda
    digitalWrite(IN3T, HIGH);
    digitalWrite(IN4T, HIGH);

    //motor 1 da direita
    analogWrite(ENA, speed2);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //motor 2 da direita
    analogWrite(ENAT, speed);
    digitalWrite(IN1T, LOW);
    digitalWrite(IN2T, HIGH);
  }

  void Motor::right(int speed, int speed2) {
    //motor 1 da esquerda
    analogWrite(ENB, speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    //motor 2 da esquerda
    analogWrite(ENBT, speed);
    digitalWrite(IN3T, HIGH);
    digitalWrite(IN4T, LOW);

    //motor 1 da direita
    analogWrite(ENA, speed2);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    //motor 2 da direita
    digitalWrite(IN1T, LOW);
    digitalWrite(IN2T, LOW);
  }
  void Motor::back(int speed) {

    analogWrite(ENA, speed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    // ao contrario
    analogWrite(ENAT, speed);
    digitalWrite(IN1T, HIGH);
    digitalWrite(IN2T, LOW);

    analogWrite(ENB, speed);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENBT, speed);
    digitalWrite(IN3T, HIGH);
    digitalWrite(IN4T, LOW);
  }
};

class Sensor {

  Ultrasonic ultra;
  int distance;

public:

  Sensor()
    : ultra(trigger, echo) {
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
  }

  int readtSensor() {
    distance = ultra.read(CM);
    return distance;
  }
};

class Display {

private:
  Adafruit_SSD1306 display;
  char message[7];
  int x;
  int y;
  int i;

  int length() {
    return sizeof(this->message) / sizeof(char);
  }
public:

  Display(const char* message) {
    x = 15;
    y = 2;
    i = 0;
    strncpy(this->message, message, sizeof(this->message));
  }

  void Display::startDisplay(int size) {
    display.begin();
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(size);
    display.setCursor(x, y);
    display.display();
  }

  void Display::showMessageOnDisplay() {

display.clearDisplay();
display.print(message);
display.setCursor(x, 5);
display.display();
    // display.print(message[i]);
    // i++;
    // display.display();
    // delay(300);

    // if (i == this->length()) {
    //   display.clearDisplay();
    //   i = 0;
    //   display.display();
    // }
  }
  
};


Motor motor;
Sensor sensor;
Display display("LIXO");


void setup() {
  Wire.begin();
  display.startDisplay(4);
  Serial.begin(9600);

}

void loop() {

analogWrite(LEFT_GREEN, HIGH);
// Serial.println(analogRead(A12));
// analogWrite(LEFT_RED, HIGH);

readIRS();

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

  //curva fechada pra esquerda (linha só do lado direito)
  if (analogRead(IR1) > 300 && analogRead(IR2) > 300) {
    motor.left(110, 120);
    delay(2100);
  }

    //curva fechada pra direita (linha só do lado esquerdo)
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