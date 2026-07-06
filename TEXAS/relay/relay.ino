/*
Relay + Buzzer (TI LaunchPad - Energia)
*/

#define RELAY_PIN 39     // your relay pin
#define BUZZER_PIN 38    // change if your buzzer is on another pin

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH);   // Relay ON
  digitalWrite(BUZZER_PIN, HIGH);  // Buzzer ON
  delay(1000);

  digitalWrite(RELAY_PIN, LOW);    // Relay OFF
  digitalWrite(BUZZER_PIN, LOW);   // Buzzer OFF
  delay(1000);
}
