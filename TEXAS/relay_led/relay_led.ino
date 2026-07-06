#define RELAY_PIN P2_0
#define LED_PIN   RED_LED

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Turn relay ON
  digitalWrite(RELAY_PIN, HIGH);

  // Blink LED while relay is ON
  digitalWrite(LED_PIN, HIGH);
  delay(300);  // LED ON duration
  digitalWrite(LED_PIN, LOW);
  delay(300);  // LED OFF duration

  // Optional: Turn relay OFF after some time
  // digitalWrite(RELAY_PIN, LOW);
  // delay(1000);
}
