/*
  Project: ESP32 DevKit V1 Audio Playback with MAX98357A
  Author:  Amar Gangadhar / Audio Playback Through SPIFFS

  Description:
    This program plays a WAV audio file ("Audio.wav") stored in the ESP32's SPIFFS (flash memory).
    It uses the I2S protocol to stream audio data to a MAX98357A digital amplifier.
    The amplifier outputs the audio to a connected speaker.
    For Upload the Audio File . Make a "data" Folder Store the Audio , Click Platform io Icon --> Board ---> Upload FileSystem Image

*/

#include "Arduino.h"     // Core Arduino functions (setup, loop, etc.)
#include "Audio.h"       // ESP32 Audio library (decodes audio + handles I2S streaming)
#include "SPIFFS.h"      // SPI Flash File System support for accessing audio files

// -------------------- I2S Pin Definitions --------------------
// Define the I2S connection between the ESP32 and the MAX98357A amplifier

#define I2S_DOUT 25  // GPIO25 → Data Out (connects to DIN on MAX98357A)
#define I2S_BCLK 26  // GPIO26 → Bit Clock (connects to BCLK on MAX98357A)
#define I2S_LRC  27  // GPIO22 → Left-Right Clock / Word Select (connects to LRC on MAX98357A)

// -------------------- Global Audio Object --------------------
// Create an instance of the Audio class to control playback
Audio audio;

/**
 * @brief Arduino setup function - runs once on boot
 *        Initializes serial, mounts SPIFFS, sets up I2S, and starts audio playback.
 */
void setup() {
  // Initialize the serial monitor at 115200 baud (for debug output)
  Serial.begin(115200);
  delay(1000); // Give time for serial monitor to initialize before output

  // Attempt to mount the SPIFFS filesystem
  // The 'true' argument formats the filesystem if mounting fails
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Mount Failed - cannot read audio file");
    return; // Exit setup if SPIFFS cannot be mounted
  }

  // Set the I2S pinout for audio output to the MAX98357A
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);

  // Set the audio playback volume
  // Valid range: 0 (mute) to 21 (maximum volume)
  audio.setVolume(21);  // Max volume

  // Check whether the "Audio.wav" file exists in SPIFFS
  if (SPIFFS.exists("/Audio.wav")) {
    Serial.println("Audio.wav found, beginning audio playback...");
    
    // Begin streaming the WAV file from SPIFFS to I2S
    audio.connecttoFS(SPIFFS, "/Audio.wav");
  } else {
    Serial.println("Audio.wav not found in SPIFFS!");
  }
}

/**
 * @brief Arduino loop function - runs continuously after setup()
 *        Feeds audio data to the I2S interface to maintain playback.
 */
void loop() {
  // Feed audio data to the I2S output
  // Must be called frequently (non-blocking)
  audio.loop();

  // Small delay prevents watchdog timer resets
  delay(10);
}

/**
 * @brief Callback function for debug info during playback (optional).
 *        This function is automatically called by the Audio library.
 * 
 * @param info - Text information about playback state or file details.
 */
void audio_info(const char *info) {
  Serial.print("Audio Info: ");
  Serial.println(info);
}

/**
 * @brief Callback function triggered when playback finishes (optional).
 *        This function is automatically called when the file reaches EOF.
 * 
 * @param info - Filename or playback status message.
 */
void audio_eof_mp3(const char *info) {
  Serial.println("Audio playback finished");
}
