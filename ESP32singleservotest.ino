#include <ESP32Servo.h>
// sL is the Left servo and is attached to pin 18

Servo sL;
Servo sR;
Servo sC;
void setup(){
  // put your setup code here, to run once:
  sL.attach(18);
  sR.attach(19);
  sC.attach(5);
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  sL.write(60);
  sR.write(120);
  sC.write(90);
  delay(1000);
  sL.write(90);
  sR.write(90);
  sC.write(179);
  delay(1000);
  sL.write(115);
  sR.write(75);
  sC.write(90);
  delay(1000);  
}
