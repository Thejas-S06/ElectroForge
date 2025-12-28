# 🔐**Servo Secure: Bluetooth-Controlled Access System**

Servo Secure is an embedded security prototype that uses Bluetooth wireless communication to control a lock or box mechanism driven by a servo motor. Access is granted only when a specific, pre-defined password command is received from a custom mobile application, demonstrating fundamental principles of remote command and control.
<hr>
### **🔥What It Does**

•	📱 **Remote Command:** Controls the lock mechanism wirelessly via a custom application on a mobile device using the HC-05 Bluetooth module.<br>
•	🔑**Password Protection:** The "_open_" or "_unlock_" action is conditional—it only executes when the microcontroller receives the correct, hardcoded password ("Password" in the code).<br>
•	⚙️**Mechanical Action:** A servo motor performs the physical actions of locking (_CLOSE_ANGLE_) and unlocking (_OPEN_ANGLE_).<br>
•	💡**Active Feedback:** Uses red and green LEDs, along with a buzzer, to provide immediate feedback on the system's status (locked, unlocked, or failed attempt).<br>
<hr>
### **🧰Components**

•	**Microcontroller:** Arduino Uno / Nano<br>
•	**Communication:** HC-05 Bluetooth Module<br>
•	**Actuator:** Servo Motor (SG90 or similar)<br>
•	**Indicators:**<br>
o	Green LED (for Unlocked/Open status)<br>
o	Red LED (for Locked/Close status)<br>
o	Buzzer (for audio feedback)<br>
•	**Software:** Custom MIT App Inventor application (or similar Bluetooth terminal app)<br>
•	**Other:** Breadboard & Jumper Wires<br>
<hr>
### **🎮Pin Assignments**
<pre>
 Components	    Arduino Pin	     Function
HC-05 RX Pin	     10	        Connected to HC-05 TX
HC-05 TX Pin	     11	        Connected to HC-05 RX
Servo Motor	        9	        PWM Output for Servo Control
Green LED	          3     	  Digital Output
Red LED	            4	        Digital Output
Buzzer	            5	        Digital Output
</pre>
<hr>
### **🧠How It Works**

1.	**Wireless Setup:** The Arduino communicates with the HC-05 module using the SoftwareSerial library, dedicating digital pins 10 (RX) and 11 (TX) for communication.<br>
2.	**Listening:** The system continuously checks if data is available (bluetooth.available()) from the Bluetooth module via the mobile app.<br>
3.	**Command Processing:** When a command is received, the code performs a string comparison after trimming invisible characters.<br>
  o	If the command is "_Password_", the Green LED lights up, the Red LED turns off, the buzzer beeps, and the servo moves to the OPEN_ANGLE (100°).<br>
  o	If the command is "_0_", the box is secured, the Red LED lights up, and the servo moves to the _CLOSE_ANGLE_ (0°).<br>
  o	Any other command triggers a "_fail_" response: the Red LED lights up, and the buzzer sounds a long alert tone (buzz(500)).<br>
4.	**Action:** The _Servo.write()_ function is used to precisely position the servo motor to lock or unlock the physical mechanism.<br>
<hr>
### **🌐Tech & Learning Relevance**

•	🧩 **Wireless Interfacing:** Implementing SoftwareSerial to communicate with external wireless modules (HC-05) when the hardware serial port is unavailable.<br>
•	💻 **String Handling:** Utilizing readStringUntil('\n') and trim() to reliably capture and process full string commands over serial/Bluetooth.<br>
•	⚙️ **Actuator Control:** Applying the Servo library to execute precise angular motion based on remote logic.<br>
•	🛡️ **Basic Security:** Implementing a foundational password-check mechanism for access control.<br>
<hr>
### **📚Learning Alignment**

•	📘 **Serial Communication:** Understanding data flow between the microcontroller and a wireless module.<br>
•	⚡ **Conditional Logic:** Using if-else if-else structures for decision-making based on external data.<br>
•	🕒 **Feedback Systems:** Coordinating visual (LEDs) and audio (buzzer) feedback with mechanical action (servo).<br>
<hr>
### **💡Personal Note**

Servo Secure was a crucial step in moving from wired sensors to wireless communication. The process of setting up the custom mobile app (via MIT App Inventor) to reliably send strings that the Arduino could interpret and act upon felt like building a true command-and-control system.
<hr>
### **🎬Demo**

Watch the working demo here:<br>
<a href = "https://drive.google.com/file/d/1MrsOpce0rqrUBFKPdUz7ukmFy60nKqcx/view?usp=drivesdk">Servo Secure</a>
<hr>
### **🚀Next Iterations**

•	**Advanced Security:** Replace the simple hardcoded string with a _HMAC or SHA-256_ hash comparison for more secure authentication (similar to your Swipe Link security foundation).<br>
•	**IoT Upgrade:** Replace the HC-05 with the ESP32 to enable Wi-Fi-based control (from anywhere in the world) instead of limited-range Bluetooth.<br>
•	**User Interface:** Integrate an LCD/OLED to display status messages (e.g., "Awaiting Command," "Access Denied").<br>
