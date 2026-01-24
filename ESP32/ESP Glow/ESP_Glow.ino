
// ---* ESP Glow *--- //

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Thejas's ESP32";
const char* password = "12345678";

const int ledPin = 32;
WebServer server(80);

// ---------- Separate CSS ----------
const char styleCSS[] PROGMEM = R"rawliteral(
body {
  font-family: Arial;
  text-align: center;
  margin-top: 50px;
  background: #000000;
}
.headings {
  color: yellow;
  font-weight: 500;
}
button {
  padding: 20px;
  font-size: 20px;
  background-color: #05d5ff;
  color: #000000;
  font-weight: 650;
  margin: 20px;
  border-radius: 10px;
}
)rawliteral";

// ---------- HTML ----------
const char indexHTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>ESP Glow</title>
  <link rel="stylesheet" href="/style.css">
</head>
<body>
  <h1 class = "headings">ESP Glow</h1>
  <h3 class = "headings">Controlling an LED using the built-in Wifi of the ESP32 board</h3>
  <button onclick="fetch('/on')">ON</button>
  <button onclick="fetch('/off')">OFF</button>
</body>
</html>
)rawliteral";

// Handlers
void handleRoot()    { server.send_P(200, "text/html", indexHTML); }
void handleStyle()   { server.send_P(200, "text/css", styleCSS); }
void handleLedOn()   { digitalWrite(ledPin, HIGH); server.send(200, "text/plain", "LED ON"); }
void handleLedOff()  { digitalWrite(ledPin, LOW);  server.send(200, "text/plain", "LED OFF"); }

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/style.css", handleStyle);   // <-- separate CSS route
  server.on("/on", handleLedOn);
  server.on("/off", handleLedOff);
  server.begin();
}

void loop() {
  server.handleClient();
}
