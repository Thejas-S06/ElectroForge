# **📲💡 Bluetooth Controlled LED: MIT App + Arduino**

Bluetooth Controlled LED lets you switch an LED ON/OFF wirelessly using a smartphone app built in _MIT App Inventor_.<br>
This project was my first Bluetooth experiment and also where I learned to create a custom Android app with code blocks for control.<br>
________________________________________
### **🔥 What It Does**

•	📡 Pairs an HC-05 Bluetooth module with your smartphone.<br>
•	📲 Sends commands “1” or “0” from a custom MIT app.<br>
•	💡 Arduino receives the command over Serial and turns the LED ON (1) or OFF (0).<br>
________________________________________
### **🧰 Components**

•	Arduino Uno / Nano<br>
•	HC-05 Bluetooth Module<br>
•	LED (any color)<br>
•	Resistor (220 Ω)<br>
•	Breadboard & Jumper Wires<br>
•	Smartphone with a custom MIT App Inventor app<br>
________________________________________
### **🎮 Pin Connections**
<pre>
  Component	     Arduino Pin
📡 HC-05 TX   → 	RX (0)
📡 HC-05 RX   → 	TX (1) (use voltage divider if needed)
💡 LED	          13 (Digital OUT)
 GND/VCC         	Common 5 V & GND
</pre>
________________________________________
### **🧠 How It Works**

•	The MIT App Inventor app sends ASCII characters ('1' or '0') via Bluetooth.<br>
•	Arduino reads data from the Serial port with Serial.read().<br>
•	A simple if statement sets the LED HIGH or LOW based on the received character.<br>
________________________________________
### **🌐 Tech & Learning Relevance**

•	📡 Wireless Communication using Bluetooth serial profiles<br>
•	🧩 App Development with MIT App Inventor<br>
•	⚡ Real-time device-to-device communication<br>
________________________________________
### **📚 Learning Alignment**

•	📘 Understanding Bluetooth pairing and serial data handling<br>
•	🕹️ Integrating hardware control with a custom mobile interface<br>
•	🧑💻 Handling MIT App Inventor code blocks for UI + logic<br>
________________________________________
### **💡 Personal Note**

This was my first project with Bluetooth, and it introduced me to wireless control and app design.<br>
Creating the MIT App Inventor interface and linking it with Arduino code was a big confidence booster!<br>
________________________________________
### 🎬 Demo

Watch the working demo here:<br>
<a href = "https://drive.google.com/file/d/1-FIFqDZIydpBtGY9LPfz_CqnWWE_bbhC/view?usp=drivesdk">Bluetooth Controlled LED</a>
________________________________________
### **🚀 Next Iterations**

•	💡 Control multiple LEDs or RGB strips<br>
•	🔊 Add voice commands via smartphone<br>
•	🌐 Expand to ESP32 for Wi-Fi + Bluetooth dual control
