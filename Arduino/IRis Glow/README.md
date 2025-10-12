# 🌈📡 IRis Glow: Multi-Mode IR Remote LED Show

IRis Glow transforms an everyday IR remote into a dynamic LED controller.<br>
Press number keys to toggle individual LEDs, use the power button to light them all, or trigger special blinking patterns — _all coded from scratch by me!_ 💪
________________________________________
### 🔥 What It Does

•	1️⃣ Button 1 → Toggle LED 1<br>
•	2️⃣ Button 2 → Toggle LED 2<br>
•	3️⃣ Button 3 → Toggle LED 3<br>
•	🔘 Power Button → Turn all LEDs ON/OFF together<br>
•	▶️ Play Button → Alternate Blink pattern<br>
•	⏩ Right Arrow → Right-to-Left chasing blink<br>
•	⏪ Left Arrow → Left-to-Right chasing blink<br>
•	🕹️ Expandable for more custom functions with extra buttons!<br>
________________________________________
### 🧰 Components

•	Arduino Uno / Nano<br>
•	IR Receiver Module (TSOP1838 or similar)<br>
•	IR Remote (any with number & arrow buttons)<br>
•	3× LEDs (any colors)<br>
•	3× Resistors (220 Ω)<br>
•	Breadboard & Jumper Wires<br>
________________________________________
### 🎮 Pin Assignments
<pre>
Device	           Arduino Pin
📡 IR Receiver      	2
🔴 LED 1          	  3
🟡 LED 2	            4
🟢 LED 3	            5
</pre>
________________________________________
### 🧠 How It Works

•	The IRremote library decodes signals from the remote into unique HEX codes.<br>
•	Each code triggers a specific action: toggle individual LEDs, power all on/off, or run blinking animations.<br>
•	Loops like rightBlink(), leftBlink(), and alternateBlink() create moving-light effects with timed delay() sequences.<br>
________________________________________
### 🌐 Tech & Learning Relevance

•	🎛️ Remote Control Integration: Reading and interpreting IR signals<br>
•	🧩 State Machines & Pattern Logic: Mapping codes to multiple behaviors<br>
•	💡 Custom C++ Functions: Modular, reusable code structure<br>
•	🔍 Serial Debugging: Printing received HEX codes for easy expansion<br>
________________________________________
### 📚 Learning Alignment

•	📘 Working with external libraries (IRremote.hpp)<br>
•	⚡ Digital input/output control<br>
•	🔄 Using arrays & loops to manage multiple outputs<br>
________________________________________
### 💡 Personal Note

_I designed and coded the entire project myself_ — from capturing HEX codes to crafting the blinking animations.<br>
It was an exciting deep dive into remote interfacing and writing clean, modular Arduino code.<br>
________________________________________
### 🎬 Demo

Watch the working demo here:<br>
<a href = "https://drive.google.com/file/d/141xf-gQXNV9LvTlSb959_BJH-enMt4HP/view?usp=drivesdk">Clap Spark</a>
________________________________________
### 🚀 Next Iterations

•	🔧 Add more LEDs or RGB strips for richer patterns<br>
•	🎶 Sync lights with music beats using a sound sensor<br>
•	🌐 Integrate Wi-Fi/Bluetooth for hybrid remote & app control<br>
