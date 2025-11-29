# **🎹 Simple Touch Piano: Capacitive Sensor Musical Keypad**

Simple Touch Piano transforms three inexpensive capacitive touch sensors into a miniature musical instrument and memory game. The system uses the touch inputs to play musical notes via a buzzer and incorporates logic to check if the user plays a specific melody correctly.

### **🔥 What It Does**

•	**🎶 Touch Input:** Uses three _TTP223 capacitive touch sensors_ to act as piano keys for the notes C, D, and E.<br>
•	**🔊 Audio Feedback:** A piezo buzzer plays a distinct tone (frequency) for each sensor that is touched.<br>
•	**🧠 Sequence Check:** The code stores the sequence of notes played by the user and checks it against a correct, predefined melody (e.g., "Mary Had a Little Lamb").<br>
•	**✅ Validation:** Provides feedback (via Serial monitor) and plays the full, correct tune upon a successful match.<br>

### **🧰 Components**

•	**Microcontroller:** Arduino Uno / Nano<br>
• **Sensors:** Three TTP223 Capacitive Touch Sensor Modules<br>
• **Actuator:** Passive or Active Buzzer<br>
•	**Other:** Breadboard & Jumper Wires<br>

### **🎮 Pin Assignments**
<pre>
     Components	        Arduino Pin         Function
Buzzer	                9 (Digital OUT)  	Generates the musical tone
Touch Sensor (E Note) 	 2 (Digital IN)	      Key 1
Touch Sensor (D Note)    3 (Digital IN)	      Key 2
Touch Sensor (C Note)	 4 (Digital IN)	      Key 3
</pre>

### **🧠 How It Works**

1.	**Sensing:** The TTP223 touch sensors output a digital _HIGH_ signal when touched (capacitance change detected).<br>
2.	**Tone Generation:** When an input pin reads HIGH, the _recordNote()_ function is called, which uses the _tone()_ function to play the corresponding frequency (262 Hz for C4, 294 Hz for D4, 330 Hz for E4) on the buzzer pin.<br>
3.	**Sequence Recording:** Each played note is simultaneously stored in the _userSequence[]_ array.<br>
4.	**Validation:** Once the sequenceLength (7 notes) is reached, the checkSequence() function compares the userSequence[] against the correctSequence[].<br>
5.	**Feedback:** If the sequences match, the full tune is played. If they don't, the system prints an error message to the serial monitor and resets the index for a new attempt.<br>
   
### **🌐 Tech & Learning Relevance**

•	**🧩 Capacitive Sensing:** Working with highly sensitive digital input to detect human touch without mechanical switches.<br>
•	**🎵 Frequency Control:** Using the tone() function to generate specific musical frequencies (notes), a key component of sound generation.<br>
•	**💻 Array/Sequence Logic:** Implementing and managing arrays for sequence comparison and state tracking—foundational for memory games and control systems.<br>
•	**⚙️ Game Logic:** Designing a basic finite state machine to record input and trigger a comparison check.<br>

### **📚 Learning Alignment**

•	**📘 Mapping Input to Frequency:** Translating a physical touch event into a precise audible frequency.<br>
•	**⚡ Logic Gates in Software:** Using comparison (==) and boolean logic (match = true/false) to validate complex user input.<br>
•	**🕒 Time and Duration:** Utilizing delay() to control note duration, pulse length, and debounce the touch sensors.<br>

### **💡 Personal Note**

Building the Simple Touch Piano was rewarding because it brought a fun, interactive musical element into hardware. Creating a system that not only plays sounds but also validates a sequence was a great challenge in software logic, showing the power of combining simple inputs with smart code.

### **🎬 Demo**

Watch the working demo here:<br>
<a href = "https://drive.google.com/file/d/1q1ZCbFTofU4dBxx7U0Cj-MKzcnaAyYoc/view?usp=drivesdk">Simple Touch Piano</a>

### **🚀 Next Iterations**

•	**🔊 Add Display:** Use an LCD or OLED to show the user's progress or the name of the note currently being played.<br>
•	**🎹 More Notes:** Expand to include more touch sensors or use a different sensor type (e.g., analog keypad) to get a wider range of notes.<br>
•	**🎼 Difficulty Levels:** Add logic to allow the user to select different tunes or increase the length/speed of the required melody.<br>
