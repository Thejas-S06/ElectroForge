#🔒🔐 Servo Secure: Bluetooth-Controlled Access System

Servo Secure is an embedded security prototype that uses Bluetooth wireless communication to control a lock or box mechanism driven by a servo motor. Access is granted only when a specific, pre-defined password command is received from a custom mobile application, demonstrating fundamental principles of remote command and control.

###🔥 What It Does

•	📱 Remote Command: Controls the lock mechanism wirelessly via a custom application on a mobile device using the HC-05 Bluetooth module.
•	🔑 Password Protection: The "open" or "unlock" action is conditional—it only executes when the microcontroller receives the correct, hardcoded password ("Password" in the code).
•	⚙️ Mechanical Action: A servo motor performs the physical actions of locking (CLOSE_ANGLE) and unlocking (OPEN_ANGLE).
•	💡 Active Feedback: Uses red and green LEDs, along with a buzzer, to provide immediate feedback on the system's status (locked, unlocked, or failed attempt).

###🧰 Components

•	Microcontroller: Arduino Uno / Nano
•	Communication: HC-05 Bluetooth Module
•	Actuator: Servo Motor (SG90 or similar)
•	Indicators:
o	Green LED (for Unlocked/Open status)
o	Red LED (for Locked/Close status)
o	Buzzer (for audio feedback)
•	Software: Custom MIT App Inventor application (or similar Bluetooth terminal app)
•	Other: Breadboard & Jumper Wires

###🎮 Pin Assignments

Components	Arduino Pin	Function
HC-05 RX Pin	10	Connected to HC-05 TX
HC-05 TX Pin	11	Connected to HC-05 RX
Servo Motor	9	PWM Output for Servo Control
Green LED	3	Digital Output
Red LED	4	Digital Output
Buzzer	5	Digital Output

###🧠 How It Works

1.	Wireless Setup: The Arduino communicates with the HC-05 module using the SoftwareSerial library, dedicating digital pins 10 (RX) and 11 (TX) for communication.
2.	Listening: The system continuously checks if data is available (bluetooth.available()) from the Bluetooth module via the mobile app.
3.	Command Processing: When a command is received, the code performs a string comparison after trimming invisible characters.
o	If the command is "Password", the Green LED lights up, the Red LED turns off, the buzzer beeps, and the servo moves to the OPEN_ANGLE (100°).
o	If the command is "0", the box is secured, the Red LED lights up, and the servo moves to the CLOSE_ANGLE (0°).
o	Any other command triggers a "fail" response: the Red LED lights up, and the buzzer sounds a long alert tone (buzz(500)).
4.	Action: The Servo.write() function is used to precisely position the servo motor to lock or unlock the physical mechanism.

###🌐 Tech & Learning Relevance

•	🧩 Wireless Interfacing: Implementing SoftwareSerial to communicate with external wireless modules (HC-05) when the hardware serial port is unavailable.
•	💻 String Handling: Utilizing readStringUntil('\n') and trim() to reliably capture and process full string commands over serial/Bluetooth.
•	⚙️ Actuator Control: Applying the Servo library to execute precise angular motion based on remote logic.
•	🛡️ Basic Security: Implementing a foundational password-check mechanism for access control.

###📚 Learning Alignment

•	📘 Serial Communication: Understanding data flow between the microcontroller and a wireless module.
•	⚡ Conditional Logic: Using if-else if-else structures for decision-making based on external data.
•	🕒 Feedback Systems: Coordinating visual (LEDs) and audio (buzzer) feedback with mechanical action (servo).

###💡 Personal Note

Servo Secure was a crucial step in moving from wired sensors to wireless communication. The process of setting up the custom mobile app (via MIT App Inventor) to reliably send strings that the Arduino could interpret and act upon felt like building a true command-and-control system.

###🎬 Demo

Watch the working demo here:
Servo Secure

###🚀 Next Iterations

•	Advanced Security: Replace the simple hardcoded string with a HMAC or SHA-256 hash comparison for more secure authentication (similar to your Swipe Link security foundation).
•	IoT Upgrade: Replace the HC-05 with the ESP32 to enable Wi-Fi-based control (from anywhere in the world) instead of limited-range Bluetooth.
•	User Interface: Integrate an LCD/OLED to display status messages (e.g., "Awaiting Command," "Access Denied").
