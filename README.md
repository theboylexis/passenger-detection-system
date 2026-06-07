# Passenger Detection System

![ESP32](https://img.shields.io/badge/ESP32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![Arduino](https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Wokwi](https://img.shields.io/badge/Wokwi-FF6B6B?style=for-the-badge&logo=wokwi&logoColor=white)
![Status](https://img.shields.io/badge/Status-In%20Progress-yellow?style=for-the-badge)

An ESP32-based seat occupancy detection and passenger accounting system for Ghanaian trotros (Toyota HiAce minibuses). Proof of concept for tamper-resistant revenue tracking in commercial minibuses.

> Built under the supervision of Prof. Benjamin Kommey, Department of Computer Engineering, KNUST.

---

## The Problem

Trotro owners have no reliable way to verify how many passengers boarded on a given day or what revenue was collected. Drivers and mates handle cash manually with no independent record — creating opportunities for underreporting.

This system addresses that by detecting seat occupancy automatically via physical switches, logging every boarding event with a timestamp, and producing an accounting record the owner can trust — independent of the driver or mate.

---

## How It Works

Each seat has a tactile switch wired to a unique GPIO pin on the ESP32. When a passenger sits, the switch closes and the pin reads `HIGH`. When they leave, it opens and reads `LOW`. The ESP32 maps each pin to a seat ID and reports state changes in real time via Serial Monitor.

```
Passenger sits   → switch closes → GPIO reads HIGH → OCCUPIED
Passenger leaves → switch opens  → GPIO reads LOW  → EMPTY
```

A **pull-down resistor** per seat ensures clean `HIGH`/`LOW` readings with no floating pins.

---

## Repository Structure

```
passenger-detection-system/
│
├── firmware/
│   └── single-seat-test/
│       └── single_seat_test.ino    # Single seat test — verified on physical hardware
│
├── simulation/
│   └── wokwi/
│       ├── sketch.ino              # 5-seat Wokwi simulation sketch
│       └── diagram.json            # Wokwi circuit wiring diagram
│
└── docs/                           # Circuit diagrams and documentation
```

---

## Circuit — Per Seat

```
3.3V ──── Switch ────┬──── GPIO pin (Seat N)
                     │
                  10kΩ resistor
                     │
                    GND

Switch OPEN   →  GPIO reads LOW   →  EMPTY
Switch CLOSED →  GPIO reads HIGH  →  OCCUPIED
```

### GPIO Pin Assignments (ESP32 DevKit V1 — 30 pin)

| Seat | GPIO | Seat | GPIO |
|------|------|------|------|
| 1    | 4    | 8    | 19   |
| 2    | 5    | 9    | 21   |
| 3    | 13   | 10   | 22   |
| 4    | 14   | 11   | 23   |
| 5    | 16   | 12   | 25   |
| 6    | 17   | 13   | 26   |
| 7    | 18   | 14   | 27   |

> **Avoid:** GPIO 0, 2, 6–11, 12, 15 — strapping pins or connected to internal flash.

---

## Simulation

🔗 **[Open 5-seat Wokwi simulation](https://wokwi.com/projects/466026059232964609)**

Press any switch button to simulate a passenger boarding. The Serial Monitor prints each seat's ID, GPIO pin, and occupancy state — updating only when a state changes.

---

## Hardware

| Component | Qty |
|-----------|-----|
| ESP32 DevKit V1 (30-pin) | 1 |
| Tactile push switches | 14 |
| 10kΩ resistors | 14 |
| Full-size breadboard | 1 |
| Jumper wires (F-M + M-M) | ~40 |

---

## Development Phases

- [x] **Phase 1 — Single seat prototype:** One switch · one resistor · one GPIO pin — verified on physical hardware
- [ ] **Phase 2 — Scale to 14 seats:** All 14 switches wired to respective GPIO pins on one breadboard
- [ ] **Phase 3 — Bus model installation:** Switches mounted on carpenter-built bus model with full wiring harness
- [ ] **Phase 4 — Wireless transmission:** MQTT over WiFi · real-time dashboard on local server

---

## Author

**Alex Marfo Appiah** — [@theboylexis](https://github.com/theboylexis)
````
