# **🔒 Swipe Link: Secure NFC Access Control System**
Swipe Link is a high-level embedded security system that uses _Near Field Communication (NFC)_ technology to grant or deny access based on secure data stored on an external tag. This project leverages the ESP32 and the PN532 module to read and parse the **NDEF** (NFC Data Exchange Format) payload from tags, making it a robust prototype for authenticated entry systems.

### **🔥 What It Does**

•	**💳 NFC Tag Key:** Utilizes a PN532 NFC Module to scan physical NTAG213 tags as access credentials.<br>
•	**📄 Data Parsing:** Reads and decodes the NDEF message (specifically the text record) from the tag to extract the stored password/credential.<br>
•	**🛡️ Credential Validation:** Compares the extracted tag data against a pre-stored password on the ESP32 for authentication.<br>
•	**💻 Non-Blocking Timing:** Uses the _millis()_ function to control the duration of status display without halting the tag scanning process.<br>
•	**💡 Multi-Feedback System:** Displays access status on a 16x2 LCD and provides immediate audio/visual feedback via Red/White LEDs and a Buzzer.<br>

### **🧰 Components**

•	**Microcontroller:** ESP32 Development Board<br>
•	**NFC Module:** Adafruit PN532 NFC/RFID Controller Breakout<br>
•	**Display:** 16x2 I2C LCD Module<br>
•	**Tags:** NTAG213 Stickers or similar NDEF-compatible NFC tags<br>
•	**Indicators:** Red LED (Denied), White LED (Granted), Passive Buzzer<br>
•	**Libraries:** SPI.h, Adafruit_PN532.h, Wire.h, LiquidCrystal_I2C.h<br>
•	**Software:** NFC Tools (or similar mobile app) for writing NDEF data to tags.<br>

### **🎮 Pin Assignments (ESP32)**
<pre>
Components	        Pin Assignment	       Interface
PN532                SCK	GPIO 18	           SPI
PN532                MISO	GPIO 19	           SPI
PN532                MOSI	GPIO 23	           SPI
PN532                SS (CS)	GPIO 5	       SPI (Chip Select)
I2C LCD              SDA	GPIO 21 (Default)	 I2C
I2C LCD              SCL	GPIO 22 (Default)	 I2C
Access Granted LED	 GPIO 4 (GREEN)	         Digital Out
Access Denied LED	   GPIO 15 (RED)	       Digital Out
Buzzer	             GPIO 2	                 Digital Out
</pre>

### **🧠 How It Works**

1.	**Init & Ready:** The PN532 is initialized, and the LCD displays "Scanning...". The system is set up to continuously read for tags.<br>
2.	**Tag Detection:** nfc.readPassiveTargetID() detects a tag, reading its unique identifier (UID).<br>
3.	**Data Extraction:** The code attempts to read all necessary data pages from the NTAG213 tag. It then searches for the NDEF header byte (0x03) to locate the start of the NDEF message.<br>
4.	**Text Parsing:** Advanced logic is used to calculate the starting index and length of the actual text payload, skipping the NDEF headers and language code information.<br>
5.	**Authentication:** The extracted text string is compared using text.equals(password) against the hardcoded password.<br>
6.	**Action & Feedback:** <br>
o	Granted: LCD shows "Access Granted!", WHITE LED ON, and a high-frequency confirmation beep is played.<br>
o	Denied: LCD shows "Access Denied!", RED LED ON, and two low-frequency error beeps are played.<br>
7.	**Auto-Reset:** A non-blocking millis() check ensures that after 3 seconds (displayDuration), the feedback is cleared, and the system automatically returns to the "Scanning..." state.<br>

### **🌐 Tech & Learning Relevance**

•	**🧩 NFC/RFID Protocol:** Deep interfacing with the PN532 module using the SPI protocol and working at the level of raw tag data blocks.<br>
•	**📄 NDEF Standard:** Implementing complex logic to parse the NFC Data Exchange Format to extract application-level data (the password string) rather than just the tag's unique ID.<br>
•	**💻 String Manipulation:** Using techniques to accurately extract and compare strings from a raw byte array.<br>
•	**⚙️ Non-Blocking Timing:** Employing millis() for time management, ensuring the core tag-reading function remains responsive while providing user feedback.<br>

### **📚 Learning Alignment**

•	**📘 Serial Communication:** Mastering fast, multi-line communication via SPI to the NFC reader.<br>
•	**⚡ Security Implementation:** Building a real-world prototype for credential-based electronic access.<br>
•	**🕒 Real-Time System Design:** Designing the system to handle background tasks (timing) while waiting for external hardware events (tag tap).<br>

### **💡 Personal Note**

Swipe Link was the pinnacle of integrating advanced peripheral hardware with strong logical processing. Successfully decoding the NDEF payload—which is what commercial NFC access systems rely on—and building a responsive authentication loop using the ESP32 felt like creating a legitimate, production-ready security component.

### **🎬 Demo**

Watch the working demo here:<br>
<a href = "https://drive.google.com/file/d/1iRtsO3p0wx2W6drKAmYhfK3037M04qNL/view?usp=drivesdk">Swipe Link</a>

### **🚀 Next Iterations**
•	**Enhanced Security:** Implement AES encryption on the tag data or use HMAC to verify tag integrity against a server-side secret key.<br>
•	**Wi-Fi Integration:** Add a feature to log all successful and failed access attempts to an external cloud database (Firebase or similar) using the ESP32's built-in Wi-Fi.<br>
•	**Multiple Users:** Modify the system to store a list of multiple valid passwords/credentials, allowing access for different authorized users.<br>
