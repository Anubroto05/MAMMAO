#ifndef IR_H
#define IR_H

#define irL 5
#define irR 12
#include "headers/ULTRASONIC.h"
#include "headers/MOTOR.h"
#include "headers/PINS.h"
int results[numUltrasonicSensors];

void irSetup()
{
  pinMode(irL, INPUT);
  pinMode(irR, INPUT);
}

void lineTracking()
{
  ultrasonicSensorsCheck(results, ultrasonicSensorsPins[], numUltrasonicSensors, numUltrasonicSamples);
  if (isClose(results[0], results[1], results[2]))
  {
    stop();
  }
  else if (!isClose(results[0], results[1], results[2]) && digitalRead(irL) == HIGH)
  {
    left();
  }
  else if (!isClose(results[0], results[1], results[2]) && digitalRead(irR) == HIGH)
  {
    right();
  }
  else
  {
    forward();
  }
}

bool isClose(float a, float b, float c)
{
  if (a > 10 && b > 10 && c > 10)
  {
    return false;
  }
  else
    return true;
}

#endif