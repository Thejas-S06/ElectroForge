# 👏⚡ CLAP SPARK: Sound-Activated LED Switch

**Clap Spark** lets you control an LED simply by clapping your hands twice!

A sound sensor detects the claps and toggles the **LED ON or OFF** — a fun way to explore digital inputs and event timing with Arduino.
________________________________________
### 🔥 What It Does

•	🎤 Detects **two quick claps** within **400 ms** <br>
•	💡 Toggles LED ON ↔ OFF each time the clap pattern is recognized <br>
•	♻️ Keeps listening for the next double-clap <br>
________________________________________
### 🧰 Components

•	Arduino Uno <br>
•	Sound Sensor Module (digital output) <br>
•	LED (any color) <br>
•	Resistor (220 Ω) <br>
•	Breadboard & Jumper Wires <br>
________________________________________
### 🎮 Pin Assignments
<pre>
    **Component**	      **Arduino Pin**
🎤 Sound Sensor   	7 (Digital IN)
💡 LED	            6 (Digital OUT)
</pre>
________________________________________
### 🧠 How It Works

•	**digitalRead()** monitors the sound sensor’s digital output. <br>
•	First clap starts a timer (**millis()**); the second clap within 400 ms counts as a _“double-clap.”_ <br>
•	When a valid double-clap is detected, the LED’s state is toggled using **digitalWrite()**. <br>
•	A small **delay(50)** acts as a _debounce_ to ignore sensor chatter. <br>
________________________________________
### 🌐 Tech & Learning Relevance

•	🧩 **Event-Driven Logic**:  Reacting to external sound events <br>
•	⏱️ **Timing with millis()**:  Measuring short intervals <br>
•	💡 **IoT & Home Automation Basics:**  Gesture-style light control <br>
________________________________________
### 📚 Learning Alignment

•	📘 Digital input handling and debouncing <br>
•	⚡ Using conditional logic for pattern recognition <br>
•	🕒 Non-blocking time measurement <br>
________________________________________
### 💡 Personal Note

This project showed me how simple sensors can create interactive experiences. <br>
Clap Spark is a playful step into event-driven programming and responsive hardware design.
________________________________________
### 🚀 Next Iterations

•	🔊 Adjust sensitivity or add a _potentiometer_ to fine-tune detection <br>
•	💡 Replace LED with a _relay to control a lamp or appliance_ <br>
•	📶 Add _Bluetooth/Wi-Fi_ to trigger smart-home actions <br>
