#include <Arduino.h>
#include "motor.h"

void initializeIrModule(int LeftIR, int CenterIR, int RightIR){
  pinMode(LeftIR, INPUT);
  pinMode(CenterIR, INPUT);
  pinMode(RightIR, INPUT);
}

void Linemode(int LeftIR, int CenterIR, int RightIR){
  if(digitalRead(LeftIR) == 1 && digitalRead(CenterIR) == 0 && digitalRead(RightIR) == 0){
    forward_left();
  }
  else if(digitalRead(LeftIR) == 0 && digitalRead(CenterIR) == 1 && digitalRead(RightIR) == 0){
    forward();
  }
  else if(digitalRead(LeftIR) == 0 && digitalRead(CenterIR) == 0 && digitalRead(RightIR) == 1){
    right();
  }
}