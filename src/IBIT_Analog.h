#include <Wire.h>
#include <Arduino.h>
#ifndef IBIT_Analog_H_
#define IBIT_Analog_H_
#define     P0      0
#define     P1      1
#define     P2      2
#define     A0      0x84
#define     A1      0xC4
#define     A2      0x94
#define     A3      0xD4
#define     A4      0xA4
#define     A5      0xE4
#define     A6      0xB4
#define     A7      0xF4

int analog(uint8_t ch);
int readADC(uint8_t chanel);
int in(uint8_t ch);

#endif
