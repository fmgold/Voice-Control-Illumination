# 🔊 Voice-Controlled LED Illumination System using ESP32 + Firebase

This project enables controlling an LED's brightness level using voice commands like "bright", "mid", "low", or "off" via an MIT App connected to Firebase. The ESP32 reads these commands and adjusts light intensity using PWM.

---

## 🛠️ Hardware Components
- 🧠 ESP32 Dev Module
- 💡 5V LED strip or high-bright LED
- 🔁 NPN Transistor (e.g., TIP120, 2N2222) for PWM control
- 🔼 Boost Converter (e.g., MT3608) to power both ESP32 and LEDs
- 🔌 Power Source (e.g., 3.7V battery or USB)

---

## 📱 Features
- Voice control via MIT App Inventor
- Real-time updates using Firebase RTDB
- Four brightness levels: `OFF`, `LOW`, `MID`, `BRIGHT`
- Smooth PWM control via transistor

---

## 🔧 Software Stack
- [Arduino Framework](https://www.arduino.cc/)
- [Firebase Realtime Database](https://firebase.google.com/products/realtime-database)
- [Firebase ESP Client Library](https://github.com/mobizt/Firebase-ESP-Client)
- [MIT App Inventor](https://appinventor.mit.edu/)
- PlatformIO or Arduino IDE

---
