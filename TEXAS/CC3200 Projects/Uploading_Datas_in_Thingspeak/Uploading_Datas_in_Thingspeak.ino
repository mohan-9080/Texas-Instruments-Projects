#include <WiFi.h>

// WiFi credentials
char ssid[] = "HITECHCMD-15";
char password[] = "wifi@123";

// ThingSpeak settings
char server[] = "api.thingspeak.com";
String apiKey = "VT169YK6N0XLAGRY";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
}

void loop() {

  int sensorValue = analogRead(A0);   // Read sensor (or dummy value)
  float voltage = sensorValue * (3.3 / 4095.0);

  if (client.connect(server, 80)) {

    String url = "/update?api_key=" + apiKey + "&field1=" + String(voltage);

    client.print("GET " + url + " HTTP/1.1\r\n");
    client.print("Host: api.thingspeak.com\r\n");
    client.print("Connection: close\r\n\r\n");

    Serial.println("Data sent to ThingSpeak");
  }
  else {
    Serial.println("Connection failed");
  }

  client.stop();

  // ThingSpeak requires minimum 15 seconds delay
  delay(10000);
}
