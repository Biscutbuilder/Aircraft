#include <Servo.h>

Servo myESC;
const int escPin = 9; 

void setup() {
  myESC.attach(escPin);
  
  // 1. Arm the ESC at factory zero
  myESC.writeMicroseconds(950); 
  delay(6000); // Wait for the initialization beeps to finish completely
  
  // 2. RAMPMING START: Slowly climb from 1000 to 1250 to prevent stalling
  for (int speed = 1000; speed <= 1250; speed += 5) {
    myESC.writeMicroseconds(speed);
    delay(40); // Gives the motor time to physically catch up to the electrical phase
  }
}

void loop() {
  // 3. Keep running smoothly at the target test speed
  myESC.writeMicroseconds(2000); 
 
}
