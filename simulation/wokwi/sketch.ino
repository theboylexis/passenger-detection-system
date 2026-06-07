// ============================================================
// Passenger Seat Detection — 5 Seat Test
// ESP32 DevKit V1
// Only prints when a seat state changes — clean Serial output.
// ============================================================

#define BAUD 115200
#define NUM_SEATS 5

const int SEAT_PINS[NUM_SEATS] = {
  4,   // Seat 1 — Red switch
  5,   // Seat 2 — Yellow switch
  13,  // Seat 3 — Blue switch
  14,  // Seat 4 — Green switch
  16   // Seat 5 — Grey switch
};

int prevStates[NUM_SEATS] = {0, 0, 0, 0, 0};

void setup() {
  Serial.begin(BAUD);
  for (int i = 0; i < NUM_SEATS; i++) {
    pinMode(SEAT_PINS[i], INPUT_PULLDOWN);
  }
  Serial.println("========================================");
  Serial.println("  Trotro Seat Detection — 5 Seat Test  ");
  Serial.println("========================================");
  Serial.println("Seat ID | GPIO | Status");
  Serial.println("--------|------|----------");
}

void loop() {
  int occupied = 0;
  bool changed = false;

  for (int i = 0; i < NUM_SEATS; i++) {
    int state = digitalRead(SEAT_PINS[i]);
    if (state == HIGH) occupied++;

    if (state != prevStates[i]) {
      changed = true;
      prevStates[i] = state;
      Serial.print(">> Seat ");
      Serial.print(i + 1);
      Serial.print(" (GPIO ");
      Serial.print(SEAT_PINS[i]);
      Serial.print(") -> ");
      Serial.println(state == HIGH ? "OCCUPIED" : "empty");
    }
  }

  if (changed) {
    Serial.println("--------|------|----------");
    for (int i = 0; i < NUM_SEATS; i++) {
      Serial.print("Seat  ");
      Serial.print(i + 1);
      Serial.print("  | GPIO ");
      if (SEAT_PINS[i] < 10) Serial.print(" ");
      Serial.print(SEAT_PINS[i]);
      Serial.print(" | ");
      Serial.println(prevStates[i] == HIGH ? "OCCUPIED" : "empty");
    }
    Serial.println("--------|------|----------");
    Serial.print("Occupied: ");
    Serial.print(occupied);
    Serial.print(" / ");
    Serial.println(NUM_SEATS);
    Serial.println();
  }

  delay(100);
}