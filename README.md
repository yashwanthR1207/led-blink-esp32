# ESP32 LED Blink

<div align="center">

![ESP32](https://img.shields.io/badge/ESP32-Dev%20Module-blue?style=for-the-badge&logo=espressif&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino-IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Language-C%2B%2B-f34b7d?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Working-brightgreen?style=for-the-badge)

**Blinks the onboard LED on an ESP32 (D2 / GPIO 2) using the Arduino framework.**

</div>

---

## Table of Contents

- [Requirements](#requirements)
- [Final Code](#final-code)
- [Circuit Wiring](#circuit-wiring-d2-pin)
- [Upload Steps](#upload-steps)
- [Expected Output](#expected-output)
- [Troubleshooting](#troubleshooting)

---

## Requirements

| Tool | Details |
|------|---------|
| Board | ESP32 Dev Module |
| IDE | Arduino IDE 1.8+ or 2.x |
| Board Package | Espressif ESP32 |

### Install ESP32 Board Support

Go to **File > Preferences > Additional Boards Manager URLs** and add:
```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

Then: **Tools > Board > Boards Manager** > search `esp32` > Install by **Espressif Systems**

---

## Final Code
```cpp
/*
 * ============================================
 *  ESP32 LED Blink
 * ============================================
 *  Board   : ESP32 Dev Module
 *  LED Pin : D2 (GPIO 2) - Onboard LED
 *  Author  : Your Name
 *  Version : 1.0.0
 *  License : MIT
 * ============================================
 */

#define LED_PIN      2       // D2 -> GPIO 2 (Onboard LED)
#define BLINK_ON     1000    // LED ON  duration (ms)
#define BLINK_OFF    1000    // LED OFF duration (ms)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  delay(100);
  Serial.println("==============================");
  Serial.println("  ESP32 LED Blink - Started  ");
  Serial.println("  Pin : D2 (GPIO 2)          ");
  Serial.println("==============================");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("[ON]  LED -> HIGH");
  delay(BLINK_ON);

  digitalWrite(LED_PIN, LOW);
  Serial.println("[OFF] LED -> LOW");
  delay(BLINK_OFF);
}
```

---

## Circuit Wiring (D2 Pin)
```
                    +---------------------------------+
                    |         ESP32 Dev Board        |
                    |                                 |
                    |  D2 (GPIO 2) ----------------> |---- 220 Ohm ---- LED(+) Anode
                    |                                 |                        |
                    |  GND <------------------------ |-------------------  LED(-) Cathode
                    +---------------------------------+
```

### Pin Connections

| ESP32 Pin     | Wire   | Component          | Component Pin             |
|---------------|--------|--------------------|---------------------------|
| D2 (GPIO 2)   | Orange | 220 Ohm Resistor   | Leg 1                     |
| -             | Orange | 220 Ohm Resistor   | Leg 2 -> LED Anode (+)    |
| GND           | Black  | LED Cathode (-)    | -                         |

> **Tip:** Anode (+) = longer leg. Cathode (-) = shorter leg (flat side of LED body)

> **Warning:** Always use a 220 Ohm resistor — without it you risk damaging the LED or the ESP32 GPIO pin.

---

## Upload Steps
```
Step 1 -> Connect ESP32 to PC via USB cable
Step 2 -> Tools > Board > ESP32 Dev Module
Step 3 -> Tools > Port > Select your COM port
Step 4 -> Click Upload
Step 5 -> Open Serial Monitor at 115200 baud
```

> If upload fails, hold the **BOOT** button on the ESP32 while clicking Upload, release after upload starts.

---

## Expected Output
```
==============================
  ESP32 LED Blink - Started  
  Pin : D2 (GPIO 2)          
==============================
[ON]  LED -> HIGH
[OFF] LED -> LOW
[ON]  LED -> HIGH
[OFF] LED -> LOW
...
```

---

## Troubleshooting

| Problem | Solution |
|---------|----------|
| Board not detected | Install CP2102 or CH340 USB driver for your OS |
| Upload fails | Hold BOOT button while uploading |
| LED not blinking | Verify LED_PIN 2 matches your board's onboard LED |
| No serial output | Set baud rate to 115200 in Serial Monitor |
| LED too dim | Check resistor value — use 220 Ohm |
| LED always ON | Check digitalWrite logic in loop() |

---

## File Structure
```
esp32-led-blink/
├── esp32_led_blink/
│   └── esp32_led_blink.ino   <- Main Arduino sketch
└── README.md                 <- This file
```

---
