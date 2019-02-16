#ifndef     IBIT_MOTOR_H_
#define     IBIT_MOTOR_H_
#include <Arduino.h>

#ifndef 	ALL
#define 	ALL     100
#endif

#define 	PWM1	14
#define 	DIR1	13
#define 	PWM2	16
#define 	DIR2	15

void motor(char ch, int Pow){
    bool dir  = (Pow >= 0 ? true : false);
    Pow = abs(Pow);
    if (ch == 1){
        digitalWrite(DIR1,dir);
        analogWrite(PWM1,Pow);
    }
    else if (ch == 2){
        digitalWrite(DIR2,!dir);
        analogWrite(PWM2,Pow);
    }
    else if (ch == 12){
        digitalWrite(DIR1,dir);
        analogWrite(PWM1,Pow);
        digitalWrite(DIR2,!dir);
        analogWrite(PWM2,Pow);
    }
}

void motor_stop(uint8_t ch){
    if (ch == 1){
        analogWrite(PWM1, 0);
    }
    else if (ch == 2){
        analogWrite(PWM2, 0);
    }
    else if (ch == ALL || ch == 12){
        analogWrite(PWM1, 0);
        analogWrite(PWM2, 0);
    }
}

void motor1(int Pow){
    bool dir  = (Pow >= 0 ? true : false);
    Pow = abs(Pow);
    digitalWrite(DIR1,dir);
    analogWrite(PWM1,Pow);
}

void motor2(int Pow){
    bool dir  = (Pow >= 0 ? true : false);
    Pow = abs(Pow);
    digitalWrite(DIR2,!dir);
    analogWrite(PWM2,Pow);
}

void fd2(int speed1,int speed2){

  digitalWrite(DIR1,1);analogWrite(PWM1,speed1);
  digitalWrite(DIR2,0);analogWrite(PWM2,speed2);    
}
void bk2(int speed1,int speed2){
 
  digitalWrite(DIR1,0);analogWrite(PWM1,speed1);
  digitalWrite(DIR2,1);analogWrite(PWM2,speed2);    
}
void sl(int speeds){
  
  digitalWrite(DIR1,0);analogWrite(PWM1,speeds);
  digitalWrite(DIR2,0);analogWrite(PWM2,speeds);    
}
void sr(int speeds){
  
  digitalWrite(DIR1,1);analogWrite(PWM1,speeds);
  digitalWrite(DIR2,1);analogWrite(PWM2,speeds);    
}

void motorControl(int speedL, int speedR){
    motor1(speedL);
    motor2(speedR);
}


#endif
