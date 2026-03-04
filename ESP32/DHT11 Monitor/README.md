# **🌡️☁️ DHT11 Monitor: Real-Time Web-Based Sensor Data**

DHT11 Monitor is an IoT monitoring system that uses the ESP32 to read live environmental data (_Temperature and Humidity_) from a DHT11 sensor and stream it wirelessly to a dedicated webpage. This project demonstrates crucial skills in sensor interfacing, asynchronous web communication (AJAX), and JSON data formatting.
<hr>

### **🔥 What It Does**

•	**📡 Sensor Reading:** Accurately reads Temperature (in °C) and Humidity (in %) from the DHT11 digital sensor.<br>
•	**🌐 Self-Hosted Web App:** Configures the ESP32 as a Wi-Fi Access Point (SoftAP) and hosts a webpage for data display.<br>
•	**💻 Dynamic Updates:** The webpage uses JavaScript's fetch API (AJAX) to call the /readings endpoint and update the data every 2 seconds without refreshing the entire page.<br>
•	**💾 JSON Format:** Data is transmitted from the ESP32 to the web client using the JSON (JavaScript Object Notation) format, a universal standard for web data exchange.<br>
<hr>

### **🧰 Components**

•	**Microcontroller:** ESP32 Development Board<br>
•	**Sensor:** DHT11 Temperature and Humidity Sensor Module<br>
•	**Software:** Web browser on a smartphone or computer<br>
•	**Libraries:** WiFi.h, WebServer.h, Adafruit_Sensor.h, DHT.h<br>
•	**Other:** Breadboard & Jumper Wires<br>
<hr>

### **🎮 Pin Assignments**
<pre>
  Components      	ESP32 Pin Assignment      	  Function
DHT11 Data Pin	        GPIO 15                  Digital Input
Wi-Fi AP            SSID	"Thejas's ESP32"	    Local Network Name
Web Server        	Port 80	Standard HTTP Port
</pre>
<hr>

### **🧠 How It Works**

1.	**Sensor & AP Init:** In setup(), the DHT sensor is initialized (dht.begin()), and the ESP32 starts its SoftAP mode (WiFi.softAP()).<br>
2.	**Webpage Request:** When a client connects to the AP and navigates to the IP, the handleRoot() function serves the main htmlPage which includes a small JavaScript script.<br>
3.	**Asynchronous Data Call:** The JavaScript script uses setInterval(update, 2000) to trigger the update() function every 2 seconds.<br>
4.	**Data Endpoint:** The update() function makes an asynchronous call to the /readings route, which is handled by handleReadings() on the ESP32.<br>
5.	**Data Generation:** Inside handleReadings(), the ESP32 reads the sensor (dht.readTemperature(), dht.readHumidity()), formats the live data into a JSON string (e.g., {"temp":25.5,"hum":50.0}), and sends it back to the client.<br>
6.	**Client Update:** The JavaScript receives the JSON data and uses it to update the content inside the div id="data" element without reloading the entire page.<br>
<hr>

### **🌐 Tech & Learning Relevance**

•	**🧩 Sensor Interfacing:** Correctly utilizing the DHT library and handling potential sensor read errors (isnan()).<br>
•	**💻 AJAX/Asynchronous Communication:** Implementing dynamic, real-time data updates using client-side JavaScript (fetch) and server-side JSON formatting.<br>
•	**💾 Data Serialization:** Converting microcontroller floating-point variables into structured, readable JSON strings for web transfer.<br>
•	**⚙️ IoT Data Stream:** Building a complete, end-to-end system for monitoring and visualization—a critical skill for any IoT platform.<br>
<hr>

### **📚 Learning Alignment**

•	**📘 API Design:** Creating a clean, dedicated API endpoint (/readings) specifically for data retrieval.<br>
•	**⚡ Mixed-Language Development:** Integrating hardware code (C++) with networking code and client-side web code (HTML/CSS/JavaScript).<br>
•	**🕒 Time Management:** Using client-side timing (setInterval) to regulate the data update frequency.<br>
<hr>

### **💡 Personal Note**

The DHT11 Monitor felt like a major upgrade from simple button control. Getting the ESP32 to successfully generate JSON data and seeing the webpage update seamlessly in real-time proved the power of the AJAX pattern. This is the foundation for logging and analyzing data from any remote sensor.<br>
<hr>

### **🎬 Demo**
Watch the working demo here:<br>
<a href = "https://drive.google.com/file/d/15cMBNdN--BWgXpJGCn-3-9oW6FRrb-R1/view?usp=drivesdk">DHT11 Monitor</a>
<hr>

### **🚀 Next Iterations**
•	**Data Logging:** Integrate an SD card module or push the JSON data to a cloud service (like ThingSpeak or Firebase) for historical logging.<br>
•	**Alert System:** Implement logic to send a notification (e.g., via email or MQTT) if temperature or humidity exceeds a specific high or low threshold.<br>
•	**STA Mode:** Connect the ESP32 to a home router (STA mode) so the data is accessible from any device on the local network, not just devices connected directly to the ESP32's AP.<br>
<hr>
