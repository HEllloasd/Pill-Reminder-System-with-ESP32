# 💊 ESP32 Medicine Reminder System

This project is an **IoT-based Medicine Reminder** built using the **ESP32**.  
It allows users to set medication times through a **web interface**, and when the set time is reached, the system **plays an audio alert** via a DFPlayer module and activates **LED indicators**.
*The Captive Portal dosent pop-up for Samsing devices

---

## 🚀 Features
- 🕒 Real-time clock and schedule checking  
- 🌐 WiFi configuration via web interface  
- 💾 Saves medicine schedules in non-volatile memory (Preferences)  
- 🔊 Audio reminders using **DFRobot DFPlayer Pro v1**  
- 💡 LED indicators for visual alerts  
- 🔧 Easy setup and configuration

---

## 🧠 How It Works
1. Connect the ESP32 to power and access its web page to set reminder times.  
2. The ESP32 saves your settings and monitors the time.  
3. When a scheduled time is reached, it plays a sound and lights an LED.  

---

## 🔌 Hardware Used
- **ESP32 Dev Board**  
- **DFRobot DFPlayer Pro v1**
- **Button**  
- **LEDs (x3)**  
- **ST7789 240x240 Screen** 
- **Speaker**


## 🧩 Wiring Diagram
Below is the full schematic of the system:

Schematic Diagram For Wiring.png

## 🧰 Software Requirements
- **Arduino IDE**
- Libraries:
  - `DFRobot_DF1201S`
  - `WiFi`
  - `WebServer`
  - `Preferences`
  - `Adafruit_GFX`
  - `DNSServer`
  - `Adafruit_ST7789`

---
