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

void setup()
{
  motor.setSpeed(theSpeed);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
}

void loop()
{
  if (digitalRead(Button1) == 1 && !pressed1) {
    motor.forwardA();
    delay(5000);
    motor.stopA();
    pressed1 = 1;
  } if (digitalRead(Button2) == 1 && !pressed2) {
    motor.forwardB();
    delay(5000);
    motor.stopB();
    pressed2 = 1;
  } if (digitalRead(Button1) == 0) {
    pressed1 = 0;
  } if (digitalRead(Button2) == 0) {
    pressed2 = 0;
  }
}

/*void callback()
{
  motor.reset();
  motor.setSpeed(theSpeed);
}*/