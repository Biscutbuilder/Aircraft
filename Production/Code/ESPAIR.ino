#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>

// Define two servo objects for X and Y axes
Servo servo1;
Servo servo2;

// Data structure to receive from sender
typedef struct struct_message {
    int joyX;
    int joyX2;
} struct_message;

struct_message incomingData;

// Callback function to receive data
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len) {
    if (len == sizeof(incomingData)) {
        memcpy(&incomingData, data, sizeof(incomingData));  

        // Debugging: Print received data
        Serial.print("Received X: ");
        Serial.print(incomingData.joyX);
        Serial.print(" | Y: ");
        Serial.println(incomingData.joyX2);

        // Map joystick X and Y values to servo angles
        int servoAngleX = map(incomingData.joyX, 0, 2047, 0, 180);
        int servoAngleX2 = map(incomingData.joyX2, 2048, 4095, 0, 180);

        // Constrain the servo angles within valid range (0 to 180 degrees)
        servoAngleX = constrain(servoAngleX, 0, 180);
        //servoAngleY = constrain(servoAngleY, 0, 180);

        // Debugging: Print servo angles
        Serial.print("Servo X Angle: ");
        Serial.println(servoAngleX);
        //Serial.print("Servo Y Angle: ");
        //Serial.println(servoAngleY);

        // Move the servos
        servo1.write(servoAngleX);
        servo2.write(servoAngleX2);
    } else {
        Serial.println("Received data length mismatch.");
    }
}

void setup() {
    Serial.begin(115200);

    // Set device as a Wi-Fi station
    WiFi.mode(WIFI_STA);

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Register for a callback function to receive data
    esp_now_register_recv_cb(OnDataRecv);

    // Initialize the two servos
    servo2.attach(16);  // Attach servo X to GPIO 1
    servo1.attach(17);  // Attach servo Y to GPIO 2 (or another available pin)

    Serial.println("Receiver is ready to receive data.");
}

void loop() {

    delay(100);  // Adjust delay as needed
}