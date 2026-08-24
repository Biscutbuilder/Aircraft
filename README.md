# ESP32 Aircraft
This project is a fixed-winged aircraft that will be controlled by 2 ESP32's using ESPNOW to communicate, one ESP32 wil be a input and communicate with the ESP32 in the air, telling it what to do.

# FILE GUIDE!!!
The production folder contains 2 more folders, code and CAD, CAD contains .step files and code contains my code.

## Electronic parts:
Using ESPNOW the ESP32 inside of the aircraft will receive and execute inputs from the ESP32 on the ground that will act as a controller. The ESP32 on the ground will take inputs from a Joystick and a Linear potentiometer before relaying those inputs to the Aircraft. The ESP32 inside of the aircraft will use 4 servos to control the axis of flight. 2 servos will control the allerions allowing the aircraft to control roll, 1 servo will control the rudder allowing the aircraft to control yaw, and 1 servo will control the elevators allowing the aircraft to control pitch. The ESP32 will also have a ESC and BLDC motor connected which will act as the engine. The BLDC motor will have a 12 inch in diameter propeller connected. The entire Aircraft will be powered by a 3 cell Lipo battery, which should give the Aircraft 45 minutes of continues flight at full throttle.

## Airframe Parts:
Almost the entire aircraft will be made out of frame segments than can then be fitted together to create sections of the plane that can be fitted together. I have only designed the wings so far, as I am still designing the main sections of the airframe. The wing is designed to be lightweight, so i opted for a simple frame that will then be covered with a layer of a thin and light material. For example, the right wing will be built by connecting 8 of the Wing SparR.step files together, then connecting a Wing Spar ending file to the end, then running the 2 wingbar files into their respective holes in the frame, then covering the entire thing the material listed earlier. That will look like this 

<img width="100%" height="369" alt="Screenshot 2026-08-17 110059" src="https://github.com/user-attachments/assets/79cd103d-838d-46fc-9fd4-89e46fc3668b" />

## Prototyping and Testing:
I tested 3 of 4 servos, as I don't have a fourth servo, in the very misleading name of ESP32singleservotest.ino file. Where i connected all the servos to the ESP32 before testing them by running to the max rotation that they be commanded to do, and then running them down to the minimum as fast as possible. I also tested the BLDC motor and the ESC by running the code in ESCtest.ino where the code did work for other people but didn't work for me due to my ESC being burned out and needs to be replaced, without me knowing it. The code is supposed to set up the ESC then run it at full throttle for 15 seconds before shutting down. The ESC and BLDC motor were connected to a Arduino uno R3 because I wasn't ready to connect them to the ESP32. I also tested if ESPNOW will work with my ESP32's so i used the ESPNOW example in the Arduino IDE. They did work and I am currently trying to interface them with the Servo Motors (That's why they aren't in the github yet).

<img width="743" height="252" alt="Screenshot 2026-08-15 200015" src="https://github.com/user-attachments/assets/a62f4b1a-0a8a-4b28-8e83-25eaef3b2361" />


## Software used:
I used Fusion for students and the Arduino IDE

## Credits for some bits of code, and a single library
The following credits are for bits of code that are and aren't completed currently.
I used https://www.youtube.com/watch?v=fHxZaHJgW34 to learn how to use a servo with a joystick.


I used https://www.youtube.com/watch?v=qOzE5F5vFGs&t=24s to learn how to use a bldc motor with arduino.


Because you cannot use the normal servo library with a ESP32, i used https://github.com/jkb-git/ESP32Servo to control the servos.






