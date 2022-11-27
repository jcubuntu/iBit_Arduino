#include "IBIT_Analog.h"

int analog(uint8_t ch){
    if (ch <=2 ){
        pinMode(ch, INPUT);
        return analogRead(ch);
    }else{
        return readADC(ch);
    }
}

int in(uint8_t ch){
    pinMode(ch, INPUT);
    return digitalRead(ch);
}

int readADC(uint8_t chanel){ 
    uint8_t data[2];
    Wire.beginTransmission(72);
    Wire.write(chanel);
    Wire.endTransmission();
    Wire.requestFrom(72, 2);
    if(Wire.available() == 2){
        data[0] = Wire.read();
        data[1] = Wire.read();
    }
    int raw_adc = ((data[0] & 0x0F) * 256) + data[1];
    return raw_adc;
}
