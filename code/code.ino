#include "L298NX2.h"
#include "Button.h"

const unsigned int IN1 = 7;
const unsigned int IN2 = 8;
const unsigned int IN3 = 9;
const unsigned int IN4 = 10;
const unsigned int Button1 = 3;
const unsigned int Button2 = 4;
bool pressed1 = 0;
bool pressed2 = 0;

L298NX2 motor(IN1, IN2, IN3, IN4);

unsigned short theSpeed = 255;
int work_time = 1000;


void setup()
{
  motor.setSpeed(theSpeed);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
}

void loop()
{
  
  bool b1state = digitalRead(Button1); // without alcohol
  if (b1state && !pressed1) {
    motor.forwardA();
    delay(60000);
    motor.stopA();
    pressed1 = 1;
  } else if (pressed1) {
    motor.stopA();
  } 
  if (!b1state) {
    pressed1 = 0;
  }

  bool b2state = digitalRead(Button2); // with alcohol
  if (b2state && !pressed2) {
    motor.forwardB();
    motor.forwardA();
    delay(15000);
    motor.stopB();
    delay(45000);
    motor.stopA();
    pressed2 = 1;
  } else if (pressed2) {
    motor.stopB();
  } 
  if (!b2state) {
    pressed2 = 0;
  }
}

/*void callback()
{
  motor.reset();
  motor.setSpeed(theSpeed);
}*/