#ifndef MOTOR_H
#define MOTOR_H

#define ENA 2 
#define IN1 3 
#define IN2 4 
#define IN3 5 
#define IN4 6
#define ENB 7  

#define ENAL 13 
#define IN1L 11 
#define IN2L 12 

#define ENBL 8 //LOW HIGH
#define IN3L 9 
#define IN4L 10 


class Motor {

public:

  Motor() {

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    pinMode(IN1L, OUTPUT);
    pinMode(IN2L, OUTPUT);
    pinMode(IN3L, OUTPUT);
    pinMode(IN4L, OUTPUT);
    pinMode(ENAL, OUTPUT);
    pinMode(ENBL, OUTPUT);
  }
  
  void go(int right_speed, int left_speed) {

    //primeiro da direita 
    analogWrite(ENA, right_speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //segundo da direita 
    analogWrite(ENB, right_speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

   // primeiro da esquerda
    analogWrite(ENAL, left_speed);
    digitalWrite(IN1L, HIGH);
    digitalWrite(IN2L, LOW);

    //segundo da esquerda
    analogWrite(ENBL, left_speed);
    digitalWrite(IN3L, LOW);
    digitalWrite(IN4L, HIGH);
  }

  void stop() {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);

    digitalWrite(IN1L, HIGH);
    digitalWrite(IN2L, HIGH);

    digitalWrite(IN3L, HIGH);
    digitalWrite(IN4L, HIGH);
  }

  void right(int right_speed, int left_speed) {

    analogWrite(ENAL, left_speed);
    digitalWrite(IN1L, HIGH);
    digitalWrite(IN2L, LOW);

    analogWrite(ENBL, left_speed);
    digitalWrite(IN3L, LOW);
    digitalWrite(IN4L, HIGH);

     // motores da direita giram pra tras
    analogWrite(ENA, right_speed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    
    analogWrite(ENB, right_speed);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  void left(int right_speed, int left_speed) {

    analogWrite(ENA, right_speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, right_speed);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    //motores da esquerda giram para tras
    analogWrite(ENAL, left_speed);
    digitalWrite(IN1L, LOW);
    digitalWrite(IN2L, HIGH);

    analogWrite(ENBL, left_speed);
    digitalWrite(IN3L, HIGH);
    digitalWrite(IN4L, LOW);

  }
  void back(int right_speed, int left_speed) {

    analogWrite(ENA, right_speed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    analogWrite(ENB, right_speed);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENAL, left_speed);
    digitalWrite(IN1L, LOW);
    digitalWrite(IN2L, HIGH);

    analogWrite(ENBL, left_speed);
    digitalWrite(IN3L, HIGH);
    digitalWrite(IN4L, LOW);
  }
};

#endif
