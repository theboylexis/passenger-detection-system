#define SEAT_PIN 5
#define BAUD     115200

void setup() {
  Serial.begin(BAUD);
  pinMode(SEAT_PIN, INPUT_PULLDOWN);
  Serial.println("=== Seat detection test started ===");
}

void loop() {
  int state = digitalRead(SEAT_PIN);

  if (state == HIGH) {
    Serial.println("Seat 1 — OCCUPIED");
  } else {
    Serial.println("Seat 1 — EMPTY");
  }

  delay(500);
}