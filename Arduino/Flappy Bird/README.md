# **🐦🎮 Flappy Bird on OLED: Arduino Nano Edition**

A handheld Flappy Bird clone built with an Arduino Nano, an OLED display, a push button, and a buzzer for sound effects.<br>
I built this just for fun after spotting it on YouTube — but ended up learning a ton about graphics, timing, and game loops on Arduino.
________________________________________
### **🔥 What It Does**

•	🕹️ Push button makes the bird flap to stay airborne<br>
•	🚧 Pipes move across the screen; avoid collisions to score points<br>
•	🔊 Buzzer provides flap and game-over sound effects<br>
•	📊 OLED screen shows live score and game-over messages<br>
________________________________________
### **🧰 Components**

•	Arduino Nano / Uno<br>
•	0.96" OLED Display (SSD1306, I2C)<br>
•	Push Button<br>
•	Buzzer <br>
•	Breadboard & Jumper Wires<br>
________________________________________
### **🎮 Pin Connections**
<pre>
    Component	      Arduino Pin
🕹️ Push Button	      2 (uses INPUT_PULLUP)
🔊 Buzzer           	4
🖥️ OLED (SDA)        A4
🖥️ OLED (SCL)        A5
5 V & GND	Power & Ground for all
</pre>
________________________________________
### **🧠 How It Works**

•	The push button triggers a jump by changing the bird’s velocity.<br>
•	Gravity constantly pulls the bird downward.<br>
•	Randomly generated pipes scroll from right to left; collision checks end the game.<br>
•	The Adafruit GFX and SSD1306 libraries handle all OLED graphics.<br>
•	A buzzer plays short tones for flaps, starts, and game overs.<br>
________________________________________
### **🌐 Tech & Learning Relevance**

•	🖥️ Graphics on Microcontrollers using Adafruit GFX<br>
•	🕹️ Game Loop Logic: frame updates, collision detection, scoring<br>
•	🎶 Tone Generation for real-time sound effects<br>
•	⏱️ Timing and physics simulation on limited hardware<br>
________________________________________
### **📚 Learning Alignment**

•	📘 Managing multiple game states (start, play, game over)<br>
•	⚡ Drawing sprites & text to an OLED display<br>
•	🕹️ Handling button input with debouncing<br>
•	🧩 Combining visuals and sound in Arduino sketches<br>
________________________________________
### **💡 Personal Note**

I copied this project from YouTube just for fun, _not as a formal build_ —<br>
but it unexpectedly taught me about timing loops, basic physics, and game design on microcontrollers.<br>
A pure “_learn while you play_” experience!
________________________________________
🚀 Next Iterations
•	🏆 Add high-score memory using EEPROM
•	🌈 Introduce different themes or characters
•	📶 Port to ESP32 for wireless score sharing
