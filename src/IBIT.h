#include "IBIT_Servo.h"
#include "IBIT_Analog.h"
#include "IBIT_Motor.h"

#ifndef IBIT_H_
#define IBIT_H_


void IBIT(){
    Wire.begin();
    analogReadResolution(12);
    pinMode(DIR1,OUTPUT);   pinMode(DIR2,OUTPUT);
    pinMode(PWM1,OUTPUT);   pinMode(PWM2,OUTPUT);
    pinMode(5, INPUT_PULLUP); pinMode(11, INPUT_PULLUP);
}

bool bottonA(){
    return digitalRead(5);
}

bool bottonB(){
    return digitalRead(11);
}

void bottonA_press(){
    while(bottonA);
    while(!bottonA);
}

void bottonB_press(){
    while(bottonB);
    while(!bottonB);
}

#endif
