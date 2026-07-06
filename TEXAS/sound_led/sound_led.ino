#define SOUND_PIN A0
#define LED_PIN RED_LED

int threshold = 400;        // ignore values below this
int minBlinkDelay = 50;     // minimum LED blink delay (ms)
int maxBlinkDelay = 500;    // maximum LED blink delay (ms)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int soundLevel = analogRead(SOUND_PIN);
  Serial.println(soundLevel);

  if(soundLevel > threshold) {
    // Map sound level to blink speed, constrain to avoid super-fast blinking
    int blinkDelay = map(soundLevel, threshold, 1023, maxBlinkDelay, minBlinkDelay);
    blinkDelay = constrain(blinkDelay, minBlinkDelay, maxBlinkDelay);

    digitalWrite(LED_PIN, HIGH);
    delay(blinkDelay);
    digitalWrite(LED_PIN, LOW);
    delay(blinkDelay);
  } else {
    digitalWrite(LED_PIN, LOW);  // LED OFF if sound below threshold
  }
}
