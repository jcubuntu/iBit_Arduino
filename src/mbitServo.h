/*
  This is modify of Servo.h library for BBC micro:bit board on Arduino Platfrom
  Support NRF5 MCU & BBC mirco:bit Tested on iBIT Board is Work
  Modify by 
    Phuwasit Eiamsouyngam
    P-Robot
    Thailand
  date  23/12/2018
*/

#ifndef MBITSERVO_H_
#define MBITSERVO_H_

#include <inttypes.h>
#include "Arduino.h"

//you could set how many timers can be used, which timer start.
//for example, now you have three timers to be used, first use timer2.
//typedef enum { _timer2, _timer1, _timer0, _Nbr_16timers } timer16_Sequence_t;
typedef enum { _timer0, _Nbr_16timers } timer16_Sequence_t;


#define MIN_PULSE_WIDTH       544     // the shortest pulse sent to a servo  544
#define MAX_PULSE_WIDTH      2400     // the longest pulse sent to a servo   2400
#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define REFRESH_INTERVAL    20000     // minumim time to refresh servos in microseconds

#define SERVOS_PER_TIMER       10     // the maximum number of servos controlled by one timer
#define MAX_SERVOS             (_Nbr_16timers  * SERVOS_PER_TIMER)  //the maximum servos

#define INVALID_SERVO         255     // flag indicating an invalid servo index


typedef struct  {
  uint8_t nbr        :6 ;             // a pin number from 0 to 31
  uint8_t isActive   :1 ;             // true if this channel is enabled, pin not pulsed if false
} ServoPin_t   ;

typedef struct {
  ServoPin_t Pin;
  uint16_t ticks;
} servo_t;



class Servo{
  private:
    uint8_t  servoIndex;
    uint16_t min_ticks;
    uint16_t max_ticks;

  public:
    Servo();
    uint8_t attach(uint32_t pin);
    uint8_t attach(uint32_t pin, uint16_t min, uint16_t max);
    void detach();

    void write(uint16_t value);
    void writeMicroseconds(uint16_t value);

    uint16_t read();
    uint16_t readMicroseconds();

    bool attached();    // return true if this servo is attached, otherwise false
};

#endif
