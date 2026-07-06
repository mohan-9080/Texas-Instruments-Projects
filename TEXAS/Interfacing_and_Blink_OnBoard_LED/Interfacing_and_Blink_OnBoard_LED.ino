// CC3200 LED Blink Example

#define LED RED_LED   // Onboard Red LED

void setup() {
  pinMode(LED, OUTPUT);   // Set LED pin as output
}

void loop() {
  digitalWrite(LED, HIGH);   // Turn LED ON
  delay(1000);               // Wait 1 second
  digitalWrite(LED, LOW);    // Turn LED OFF
  delay(1000);               // Wait 1 second
}
