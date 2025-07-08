#ifndef MOTOR_H
#define MOTOR_H

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

#endif
