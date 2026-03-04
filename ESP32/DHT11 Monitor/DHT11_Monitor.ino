
// ---* DHT11 Monitor *--- //

#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// -------- Wi-Fi Access Point ----------
const char* ssid     = "Thejas's ESP32";
const char* password = "12345678";

// -------- DHT11 Setup ----------
#define DHTPIN 15
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

// -------- Web Server ----------
WebServer server(80);

// -------- HTML ----------
const char htmlPage[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>ESP32 DHT11 Monitor</title>
  <link rel="stylesheet" href="/style.css">
</head>
<body>
  <h1>ESP32 DHT11 Monitor</h1>
  <div id="data">Loading…</div>
  <script>
    async function update(){
      const r = await fetch('/readings');
      const j = await r.json();
      document.getElementById('data').innerHTML =
        `Temperature: ${j.temp} °C<br>Humidity: ${j.hum} %`;
    }
    setInterval(update,2000);
    update();
  </script>
  <p id = "update">Readings updated every 2s</p>
</body>
</html>
)HTML";

// -------- CSS ----------
const char cssPage[] PROGMEM = R"CSS(
body {font-family: Arial, sans-serif; background: #000000; text-align:center; margin-top:50px;}
h1   {color:yellow; text-weight: 500;}
#data{margin-top:25px; font-size:25px; text-weight: 500; color: #05d5ff;}
#update{margin-top: 40px; font-size:20px; text-weight:400; color: yellow;}
)CSS";

// -------- Handlers ----------
void handleRoot()    { server.send_P(200, "text/html", htmlPage); }
void handleStyle()   { server.send_P(200, "text/css",  cssPage); }

void handleReadings(){
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) { t = h = -1; }
  String json = "{\"temp\":" + String(t,1) + ",\"hum\":" + String(h,1) + "}";
  server.send(200, "application/json", json);
}

// -------- Setup & Loop ----------
void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.softAP(ssid, password);
  Serial.print("Connect to WiFi: "); Serial.println(ssid);
  Serial.print("Access Point IP: "); Serial.println(WiFi.softAPIP());

  server.on("/",          handleRoot);
  server.on("/style.css", handleStyle);
  server.on("/readings",  handleReadings);
  server.begin();
}

void loop() {
  server.handleClient();
}
