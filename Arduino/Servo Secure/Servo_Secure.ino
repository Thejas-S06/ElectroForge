
// ---* Servo Secure *--- //

#include <SoftwareSerial.h>
#include <Servo.h>

// Define pins for Bluetooth, LEDs, and Buzzer
#define RX_PIN 10
#define TX_PIN 11
#define GREEN_LED 3
#define RED_LED 4
#define BUZZER 5
#define SERVO_PIN 9

// Define servo angles for open and closed positions
#define OPEN_ANGLE 100 // Adjust this value to your desired open position
#define CLOSE_ANGLE 0  // Adjust this value to your desired close position

// Initialize SoftwareSerial for Bluetooth communication
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
Servo myServo;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("Arduino is ready.");

  // Set pin modes for LEDs and Buzzer
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Attach the servo to its pin
  myServo.attach(SERVO_PIN);
  myServo.write(CLOSE_ANGLE); // Start in the closed position

  // Start the Bluetooth module with a baud rate of 9600
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    String receivedCommand = bluetooth.readStringUntil('\n');
    receivedCommand.trim(); // This is the fix: it removes invisible characters

    Serial.print("Received (trimmed): '");
    Serial.print(receivedCommand);
    Serial.println("'");

    if (receivedCommand == "0") {
      // Command to CLOSE the box
      Serial.println("Closing...");
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      myServo.write(CLOSE_ANGLE);
      buzz(100);
    } 
    else if (receivedCommand == "Password") { // Password is set here
      Serial.println("Password correct. Opening...");
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      myServo.write(OPEN_ANGLE);
      buzz(100);
    } 
    else {
      Serial.println("Incorrect command or password.");
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      buzz(500);
    }
  }
}

// Function to make the buzzer sound
void buzz(int duration) {
  digitalWrite(BUZZER, HIGH);
  delay(duration);
  digitalWrite(BUZZER, LOW);
}