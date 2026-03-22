/*

// ─── Pin Definition ───────────────────────────
#define LED_PIN      2       // D2 → GPIO 2 (Onboard LED)

// ─── Timing ───────────────────────────────────
#define BLINK_ON     1000    // LED ON duration  (ms)
#define BLINK_OFF    1000    // LED OFF duration (ms)

// ─── Setup ────────────────────────────────────
void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);   // Start with LED off

  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println("==============================");
  Serial.println("  ESP32 LED Blink — Started  ");
  Serial.println("  Pin : D2 (GPIO 2)          ");
  Serial.println("==============================");
}

// ─── Main Loop ────────────────────────────────
void loop() {
  // Turn LED ON
  digitalWrite(LED_PIN, HIGH);
  Serial.println("[ON]  LED → HIGH");
  delay(BLINK_ON);

  // Turn LED OFF
  digitalWrite(LED_PIN, LOW);
  Serial.println("[OFF] LED → LOW");
  delay(BLINK_OFF);
}
