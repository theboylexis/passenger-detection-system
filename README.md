# Passenger Detection System

An ESP32-based seat occupancy detection and passenger accounting system for Ghanaian trotros (Toyota HiAce minibuses). Proof of concept for tamper-resistant revenue tracking in commercial minibuses.

Built under the supervision of Prof. Benjamin Kommey, Department of Computer Engineering, KNUST.

---

## The Problem

Trotro owners have no reliable way to verify how many passengers boarded on a given day or what revenue was collected. Drivers and mates handle cash manually with no independent record — creating opportunities for underreporting.

This system addresses that by detecting seat occupancy automatically via physical switches, logging every boarding event with a timestamp, and producing an accounting record the owner can trust independently of the driver or mate.

---

## How It Works

Each seat has a tactile switch wired to a unique GPIO pin on the ESP32. When a passenger sits, the switch closes and the pin reads HIGH. When they leave, it opens and reads LOW. The ESP32 maps each pin to a seat ID and logs state changes in real time.

Passenger sits   → switch closes → GPIO reads HIGH → seat marked OCCUPIED
Passenger leaves → switch opens  → GPIO reads LOW  → seat marked EMPTY

The system uses a **pull-down resistor circuit** per seat to ensure clean HIGH/LOW readings with no floating pins.

---

## Repository Structure

passenger-detection-system/
├── firmware/
│   └── single-seat-test/
│       └── single_seat_test.ino   # Single seat physical test — verified on hardware
├── simulation/
│   └── wokwi/
│       ├── sketch.ino             # 5-seat simulation sketch
│       └── diagram.json           # Wokwi circuit diagram
└── docs/

---

## Circuit — Per Seat

3.3V ── Switch ──┬── GPIO pin (seat N)
│
10kΩ resistor
│
GND
Switch OPEN   → GPIO reads LOW  → EMPTY
Switch CLOSED → GPIO reads HIGH → OCCUPIED

**Safe GPIO pins used (ESP32 DevKit V1):**

| Seat | GPIO |
|------|------|
| 1    | 4    |
| 2    | 5    |
| 3    | 13   |
| 4    | 14   |
| 5    | 16   |
| 6    | 17   |
| 7    | 18   |
| 8    | 19   |
| 9    | 21   |
| 10   | 22   |
| 11   | 23   |
| 12   | 25   |
| 13   | 26   |
| 14   | 27   |

Avoid GPIO 0, 2, 6–11, 12, 15 (strapping pins or internal flash).

---

## Simulation

The 5-seat Wokwi simulation is available here:
[wokwi.com/projects/466026059232964609](https://wokwi.com/projects/466026059232964609)

Open the link, press any switch button, and watch the Serial Monitor output update with the seat ID, GPIO pin, and occupancy state.

---

## Hardware (Prototype)

| Component | Quantity |
|-----------|----------|
| ESP32 DevKit V1 | 1 |
| Tactile push switches | 14 |
| 10kΩ resistors | 14 |
| Full-size breadboard | 1 |
| Jumper wires | ~40 |

---

## Development Phases

- [x] **Phase 1 — Single seat prototype:** One switch, one resistor, one GPIO pin — verified on physical hardware
- [ ] **Phase 2 — Scale to 14 seats:** Wire all 14 switches to their respective GPIO pins on one breadboard
- [ ] **Phase 3 — Bus model installation:** Mount switches on carpenter-built bus model, full wiring harness
- [ ] **Phase 4 — Wireless transmission:** MQTT over WiFi, real-time dashboard on local server

---

## Built With

`C++` `Arduino IDE` `ESP32` `Wokwi`

---

## Author

**Alex Marfo Appiah** — [@theboylexis](https://github.com/theboylexis)
