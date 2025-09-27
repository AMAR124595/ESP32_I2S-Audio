/*
   Project: ESP32 SPIFFS File Deletion Example
   Author:  (Amar Gangadhar / Delete A specific File)
   Description:
     This program initializes the SPIFFS filesystem on the ESP32,
     checks if "Audio.wav" exists, and deletes it if found.
     Useful for managing or updating audio files stored in flash memory.
*/

// -------------------- Libraries --------------------
#include "Arduino.h"   // Core Arduino functions
#include "SPIFFS.h"    // SPI Flash File System library

// -------------------- Setup Function --------------------
void setup() {
    // Start serial communication for debugging
    Serial.begin(115200);

    // Initialize SPIFFS (format if mounting fails)
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS Mount Failed"); 
        return; // Stop execution if SPIFFS cannot be mounted
    }

    // Check if the file "Audio.wav" exists in SPIFFS
    if (SPIFFS.exists("/Audio.wav")) {
        // Try to delete the file
        if (SPIFFS.remove("/Audio.wav")) {
            Serial.println("Audio.wav deleted successfully!");
        } else {
            Serial.println("Failed to delete Audio.wav");
        }
    } else {
        // File does not exist
        Serial.println("Audio.wav does not exist");
    }
}

// -------------------- Loop Function --------------------
void loop() {
    // Nothing here - file deletion is handled only once in setup()
}
