# **🚗🔊 Echo Gate: Ultrasonic Toll-Gate Replica**

Echo Gate is a mini automated toll gate system.<br>
When a vehicle approaches, an ultrasonic sensor detects its presence, a servo motor raises the gate, and an LED with a buzzer provides active feedback — all in a neat Arduino package.
________________________________________
### **🔥 What It Does**

•	📡 Detects a car/object within **~20 cm** using an ultrasonic sensor<br>
•	🚦 Opens the gate by **rotating a servo motor to 90°**<br>
•	💡 LED lights and buzzer sounds to indicate gate activation<br>
•	⏳ Holds the gate **open for 1 second**, then closes automatically<br>
________________________________________
### **🧰 Components**

•	Arduino Uno / Nano<br>
•	HC-SR04 Ultrasonic Sensor<br>
•	Servo Motor (SG90)<br>
•	LED (any color)<br>
•	Buzzer (passive)<br>
•	Breadboard & Jumper Wires<br>
________________________________________
### **🎮 Pin Assignments**
<pre>
      Component           Arduino Pin
📤 Servo Motor	              9
📡 Ultrasonic Trigger	      10
📡 Ultrasonic Echo	          11
💡 LED	                      6
🔊 Buzzer                	  7
</pre>
________________________________________
### **🧠 How It Works**

1.	The ultrasonic sensor sends a pulse and measures the echo time to calculate distance.<br>
2.	If distance ≤ 20 cm, Arduino:<pre>
      o	Rotates the servo to 90° (gate open)
      o	Turns LED & buzzer ON
</pre>
4.	After 1 second, the servo returns to 0° and the LED & buzzer turn OFF.<br>
5.	The loop repeats every 200 ms for continuous monitoring.<br>
________________________________________

### **🌐 Tech & Learning Relevance**

•	🧩 Distance Measurement with HC-SR04 and **pulseIn()**<br>
•	⚙️ Servo Control via the Servo library<br>
•	🔄 Conditional Logic for real-time automation<br>
•	💡 Feedback Systems: combining multiple outputs (LED & buzzer)<br>
________________________________________
### **📚 Learning Alignment**

•	📘 Reading and converting sensor timing into physical distance<br>
•	⚡ Coordinating sensor input with multiple actuators<br>
•	🕒 Managing delays for smooth, predictable motion<br>
________________________________________
### **💡 Personal Note**

Building Echo Gate felt like creating a scaled-down smart toll system.<br>
It combined sensors, motion control, and multi-output feedback — a fun step toward real-world embedded automation.<br>
________________________________________
### **🚀 Next Iterations**

•	🚦 Add traffic lights to simulate a full toll plaza<br>
•	📶 Integrate RFID for vehicle identification<br>
•	📊 Display distance or status on an LCD/OLED screen<br>
