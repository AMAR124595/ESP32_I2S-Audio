#include "Arduino.h"
#include "Audio.h"
#include "SPIFFS.h"

#define I2S_DOUT 25 
#define I2S_BCLK 26
#define I2S_LRC  27

Audio audio;

void setup() {
  Serial.begin(115200);
  delay(1000);

  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Mount Failed");
    return;
  }

  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(21);

  if (SPIFFS.exists("/Audio.wav")) {
    Serial.println("Audio.wav found, playing audio...");
    audio.connecttoFS(SPIFFS, "/Audio.wav");
  } else {
    Serial.println("Audio.wav not found!");
  }
}

void loop() {
  audio.loop();
  delay(10);
}

void audio_info(const char *info) {
  Serial.print("Audio Info: ");
  Serial.println(info);
}

void audio_eof_mp3(const char *info) {
  Serial.println("Audio playback finished");
}
