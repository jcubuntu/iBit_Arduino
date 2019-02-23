#include <IBIT.h>

void setup() {
  IBIT();  // initial ibit system
  Serial.begin(115200);

  motor(1, 255);  // motor 1 forward maximun speed is 255
  motor(2, 255);  // motor 2 forward maximun speed is 255
  delay(1000);

  motor(1, -255);  // motor 1 backward maximun speed is -255
  motor(2, -255);  // motor 2 backward maximun speed is -255
  delay(1000);

  fd(255);        // motor 1  & 2 forward maximun speed is 255
  delay(1000);

  bk(255);        // motor 1  & 2 backward maximun speed is 255
  delay(1000);

  fd2(255,255);        // motor 1  & 2 forward maximun speed is 255
  delay(1000);

  bk2(255,255);        // motor 1  & 2 backward maximun speed is 255
  delay(1000);

  sl(255);        // spin left maximun speed is 255
  delay(1000);

  sr(255);        // spin right maximun speed is 255
  delay(1000);

  tl(255);        // turn left maximun speed is 255
  delay(1000);

  tr(255);        // turn right maximun speed is 255
  delay(1000);

  servo(1, 90);   // set servo 1 to 90 degree
  servo(2, 90);   // set servo 2 to 90 degree
  
}

void loop() {
  int pinValue, adcValue;
  pinValue = analog(P0);  // read analog value form pin P0 on microbit (pins name P0, P1, P2)
  adcValue = analog(A0);  // read analog value form pin ADC0 on iBit (pins name A0,A1,A2 ... A7)
  Serial.print(pinValue);
  Serial.print("\t");
  Serial.println(adcValue);
}