#include <esp_now.h>
#include <WiFi.h>

// Define joystick pins
const int joyPinX = 16;  // Analog pin for X-axis
const int joyPinX2 = 2;  // (Optional) Analog pin for Y-axis if you want to use it

// Peer device MAC address (receiver's MAC)
uint8_t receiverAddress[] = {0xEC, 0xDA, 0x3B, 0x61, 0x1B, 0x28}; //find you device Mac address 

typedef struct struct_message {
    int joyX;
    int joyX2;
} struct_message;

struct_message joystickData;

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);  // Set ESP32 to Wi-Fi station mode

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Register peer
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, receiverAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
        return;
    }
}

void loop() {
    // Read joystick X and Y values
    joystickData.joyX = analogRead(joyPinX);  // Read X-axis
   //joystickData.joyX2 = analogRead(joyPinX2);  // (Optional) Read Y-axis if used

    // Send joystick data via ESP-NOW
    esp_err_t result = esp_now_send(receiverAddress, (uint8_t *) &joystickData, sizeof(joystickData));

    if (result == ESP_OK) {
        Serial.println("Sent successfully");
    } else {
        Serial.println("Error sending the data");
    }

    delay(100);  // Adjust delay as needed
}