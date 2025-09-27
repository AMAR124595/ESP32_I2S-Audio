#include <Arduino.h>
#include "SPIFFS.h"



void printFlashInfo() {
  Serial.printf("Flash Chip Size: %u bytes\n", ESP.getFlashChipSize());
  Serial.printf("Sketch Size: %u bytes\n", ESP.getSketchSize());
  Serial.printf("Free Sketch Space: %u bytes\n", ESP.getFreeSketchSpace());
  Serial.printf("FS Used: %u bytes\n", SPIFFS.usedBytes()); // If using SPIFFS/LittleFS
  Serial.printf("FS Total: %u bytes\n", SPIFFS.totalBytes());
}
void printPsramInfo() {
  if (psramFound()) {
    Serial.printf("Total PSRAM: %u bytes\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM: %u bytes\n", ESP.getFreePsram());
  } else {
    Serial.println("PSRAM Not Available");
  }
}

// Detailed heap analysis (includes PSRAM if enabled)
void printHeapInfo() {
  Serial.printf("Internal Free Heap: %u bytes\n", ESP.getFreeHeap());
  Serial.printf("Minimum Free Heap: %u bytes\n", ESP.getMinFreeHeap());
  Serial.printf("Max Alloc Heap: %u bytes\n", ESP.getMaxAllocHeap());
}
void setup()
{
  Serial.begin(115200);
  printFlashInfo();
  printPsramInfo();
  printHeapInfo();
}
void loop()
{

}