# **💡✨ ESP Glow: Wi-Fi Controlled LED Switch (SoftAP)**

ESP Glow is a fundamental Internet of Things (IoT) project that utilizes the built-in Wi-Fi capabilities of the ESP32 to create a simple, local web server. It allows a user to toggle an LED (or any connected appliance) ON and OFF using a custom webpage accessed from a smartphone or computer.
<hr>
### 🔥 What It Does

•	**🌐 Self-Hosting:** Configures the ESP32 as a Wi-Fi Access Point (_SoftAP_) named "_Thejas's ESP32_", allowing direct device connection without a router.<br>
•	**💻 Web Control:** Hosts a simple HTML webpage that displays _ON_ and _OFF_ buttons.<br>
•	**💡 Remote Toggle:** Clicking the buttons sends an HTTP request to the ESP32, which toggles the state of an LED connected to **GPIO 32**.<br>
•	**🎨 Styling:** Uses separate CSS to style the webpage, demonstrating best practices in web development.<br>
<hr>
### **🧰 Components**

•	**Microcontroller:** ESP32 Development Board (NodeMCU, WROOM, or similar)<br>
•	**Actuator:** LED (any color)<br>
•	**Other:** 220 Ω Resistor, Breadboard & Jumper Wires<br>
•	**Software:** Web browser on a smartphone or computer<br>
<hr>
### **🎮 Pin Assignments**
<pre>
Components	      ESP32 Pin Assignment	  Function
Control LED	      GPIO 32	                Digital Output
Wi-Fi	Internal	  Built-in Wi-Fi          Transceiver
Web Server	      Port 80	                Standard HTTP Port
</pre>
<hr>
### **🧠 How It Works**

1.	**AP Initialization:** In setup(), the ESP32 creates a local Wi-Fi network using WiFi.softAP(ssid, password). The IP address (WiFi.softAPIP()) is printed to the Serial monitor (_typically 192.168.4.1_).<br>
2.	**Server Start:** The WebServer is started on port 80.<br>
3.	**Client Connection:** A user connects their device to the "Thejas's ESP32" network and navigates to the ESP32's IP address (e.g., http://192.168.4.1/).<br>
4.	**HTML Handling:** The _handleRoot()_ function serves the primary indexHTML page, which includes buttons linked to the /on and /off routes.<br>
5.	**Command Execution:** <br>
o	Clicking ON sends a request to the /on route, triggering the handleLedOn() function, which sets digitalWrite(ledPin, HIGH).<br>
o	Clicking OFF sends a request to the /off route, triggering handleLedOff(), which sets digitalWrite(ledPin, LOW).<br>
6.	**Loop:** The loop() function continuously calls server.handleClient() to process incoming HTTP requests in real-time.<br>
<hr>
### **🌐 Tech & Learning Relevance**

•	**🧩 Embedded Networking:** Establishing the ESP32 as both a network interface and a central server (SoftAP mode).<br>
•	**💻 HTTP Protocol:** Understanding request handling and routing (server.on("/",...))—the foundation of all web communication.<br>
•	**💡 Web Stacks:** Incorporating simple HTML for structure and CSS for presentation (using the handleStyle() route).<br>
•	**⚙️ IoT Command:** A direct, practical example of how hardware is controlled remotely over the internet/network.<br>
<hr>
### **📚 Learning Alignment**

•	**📘 Wi-Fi Management:** Initializing and configuring the ESP32's wireless module.<br>
•	**⚡ Function Mapping:** Directly linking specific URL paths (routes) to embedded C++ functions.<br>
•	**🕒 Asynchronous Handling:** Learning the importance of continuously calling _server.handleClient()_ to manage multiple simultaneous network connections.<br>
<hr>
### **💡 Personal Note**
ESP Glow was the first project to unlock the massive potential of the ESP32's Wi-Fi capability. It moved me beyond simple wired logic to building truly networked devices, laying the groundwork for more complex IoT and web-integrated projects like the DHT11 Monitor.
<hr>
### **🎬 Demo**
Watch the working demo here:<br>
ESP Glow
<hr>
### **🚀 Next Iterations**
•	**STA Mode:** Modify the code to operate in STA (Station) mode so the ESP32 connects to an existing home router (connecting to the wider internet).<br>
•	**Feedback:** Update the webpage to show the current state of the LED (ON/OFF) without requiring a button press.<br>
•**	Multiple Outputs:** Add more buttons and pins to control multiple LEDs or different appliances simultaneously.<br>
