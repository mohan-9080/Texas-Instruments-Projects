#include <WiFi.h>

// -------- USER CONFIG --------
char ssid[] = "HITECHCMD-15";        // WiFi SSID
char password[] = "wifi@123"; // WiFi Password

char server[] = "api.thingspeak.com";
String apiKey = "N4K2RRAOH503PALU";
const int updateThingSpeakInterval = 15*1000;
// -----------------------------

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

  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  // Example data (replace with sensor reading)
  int sensorValue = analogRead(A0);

  if (client.connect(server, 80)) {

    String url = "/update?api_key=";
    url += apiKey;
    url += "&field1=";
    url += String(sensorValue);

    Serial.println("Sending data to ThingSpeak...");
    Serial.println(url);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: api.thingspeak.com\r\n" +
                 "Connection: close\r\n\r\n");

  } else {
    Serial.println("Connection to ThingSpeak failed");
  }

  client.stop();

  // ThingSpeak requires minimum 15 sec delay
  delay(15000);
}

