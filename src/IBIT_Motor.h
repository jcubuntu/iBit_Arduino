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

void fd2(int _speed1,int _speed2){

  digitalWrite(DIR1,1);analogWrite(PWM1,_speed1);
  digitalWrite(DIR2,0);analogWrite(PWM2,_speed2);    
}
void bk2(int _speed1,int _speed2){
 
  digitalWrite(DIR1,0);analogWrite(PWM1,_speed1);
  digitalWrite(DIR2,1);analogWrite(PWM2,_speed2);    
}

void fd(int _speed1){

  digitalWrite(DIR1,1);analogWrite(PWM1,_speed1);
  digitalWrite(DIR2,0);analogWrite(PWM2,_speed1);    
}
void bk(int _speed1){
  digitalWrite(DIR1,0);analogWrite(PWM1,_speed1);
  digitalWrite(DIR2,1);analogWrite(PWM2,_speed1);    
}

void sl(int _speeds){
  digitalWrite(DIR1,0);analogWrite(PWM1,_speeds);
  digitalWrite(DIR2,0);analogWrite(PWM2,_speeds);    
}
void sr(int _speeds){
  
  digitalWrite(DIR1,1);analogWrite(PWM1,_speeds);
  digitalWrite(DIR2,1);analogWrite(PWM2,_speeds);    
}

void tl(int _speeds){
  
  digitalWrite(DIR1,1);analogWrite(PWM1,0);
  digitalWrite(DIR2,0);analogWrite(PWM2,_speeds);    
}
void tr(int _speeds){
  
  digitalWrite(DIR1,1);analogWrite(PWM1,_speeds);
  digitalWrite(DIR2,1);analogWrite(PWM2,0);    
}

void motorControl(int _speedL, int _speedR){
    motor1(_speedL);
    motor2(_speedR);
}


#endif
