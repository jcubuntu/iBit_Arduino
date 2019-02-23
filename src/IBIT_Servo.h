#include "mbitServo.h"
#ifndef IBIT_SERVO_H_
#define IBIT_SERVO_H_

Servo iBitServo1;
Servo iBitServo2;

void servo(uint8_t ch, signed int angle){
    if (ch == 1){
        if (angle == -1) iBitServo1.detach();{
            if(!iBitServo1.attached()) iBitServo1.attach(8);
            iBitServo1.write(angle);
        }
    }else{
        if (angle == -1) iBitServo2.detach();{
            if(!iBitServo2.attached()) iBitServo2.attach(12);
            iBitServo2.write(angle);
        }
    }
}

#endif