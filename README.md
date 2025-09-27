# 🎧 ESP32 DevKit V1 – WAV Audio Playback via I2S and MAX98357A

This project demonstrates how to use the **ESP32 DevKit V1** to play `.wav` audio files stored in the ESP32's internal flash memory (SPIFFS). The audio is streamed via the **I2S protocol** to a **MAX98357A Class D amplifier** (Adafruit breakout board), which then drives a speaker.

The project is built using **PlatformIO in Visual Studio Code**, making it modular, scalable, and easy to maintain.

---

## 🧩 Features

- 🎵 **WAV File Playback** from internal flash memory
- 🔊 **Digital Audio Output via I2S** to MAX98357A
- 💾 **SPIFFS File System** for storing audio files
- 📟 **Serial Logging** for playback and debug info
- ✅ Clean and beginner-friendly PlatformIO implementation

---

## 🧰 Components Used

| Component                          | Description                                  |
|-----------------------------------|----------------------------------------------|
| **ESP32 DevKit V1**               | Wi-Fi/BLE-capable microcontroller             |
| **MAX98357A I2S Amplifier**       | Mono, 3W Class D amp (Adafruit breakout)      |
| **Speaker (4Ω or 8Ω, 3W)**        | Outputs audio from the amp                    |
| **Power **                        | 5v Power supply                               |
| **Jumper Wires / Breadboard**     | For prototyping and connections               |

---

## 🛠️ Circuit Diagram

Here’s the circuit diagram showing how the components are connected:

Circuit Diagram : https://github.com/user-attachments/assets/7e0a3793-9b71-407d-8976-6bf2ac3a7b4e

> 💡 Make sure to connect the speaker to the MAX98357A breakout board’s + and - terminals.

> The MAX98357A accepts either 3.3V or 5V from the ESP32.

---

## 🚀 Getting Started

### 1. 📦 Prerequisites

- VS Code with PlatformIO extension installed
- ESP32 platform installed in PlatformIO
- `esphome/ESP32-audioI2S@^2.3.0` library installed via `lib_deps`
- Valid `.wav` file (16-bit PCM, 22kHz or 44.1kHz)

### 2. 📁 Upload WAV File to SPIFFS

1. Place your `Start.wav` inside the `/data` folder.
2. Upload it using:   Click Platform io Icon --> Select The Board ---> Platrorm --->Upload FileSystem Image

## ▶️ Usage

After flashing and uploading the WAV file:

1. Power on the ESP32
2. Speaker connected to the MAX98357A will start playing the WAV file
3. Use the Serial Monitor to track playback status

---

## 🧠 Learnings

This project helped me:

* Understand how to use **SPIFFS** on the ESP32 to store and retrieve media files
* Learn the basics of the **I2S audio protocol** and its practical use with embedded audio
* Interface and control a **MAX98357A I2S amplifier** using GPIO pins
* Use **PlatformIO** for embedded development, improving build and dependency management
* Optimize real-time audio streaming in resource-constrained environments

It was a great deep dive into embedded audio and working with real-time media on microcontrollers!

---

---

## 👤 Author
**Amar Gangadhar A (SenseAbility innovations pvt.ltd)**  
Electronics Engineer | Embedded Systems Designer |   Embedded Firmware Developer

---



