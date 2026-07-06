#define PIR_PIN  P2_0      // Digital input from PIR sensor
#define LED_PIN  RED_LED    // Onboard LED

void setup() {
  pinMode(PIR_PIN, INPUT);   // PIR sensor input
  pinMode(LED_PIN, OUTPUT);  // LED output
}

void loop() {
  int motionDetected = digitalRead(PIR_PIN);

  if (motionDetected == HIGH) {
    // Blink LED when motion detected
    digitalWrite(LED_PIN, HIGH);
    delay(300);               // LED ON for 300 ms
    digitalWrite(LED_PIN, LOW);
    delay(300);               // LED OFF for 300 ms
  } else {
    digitalWrite(LED_PIN, LOW); // LED OFF if no motion
  }
}
