
// ---* Echo Gate *--- //

#include <Servo.h>

Servo gateServo;

const int trigPin = 10;
const int echoPin = 11;
const int ledPin = 6;
const int buzzerPin = 7;

long duration;
int distance;

void setup() {
  gateServo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo duration
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert to cm

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 20) {  // Threshold distance to open gate
    gateServo.write(90);  // Open gate
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(1000);  // Keep gate open for 1 second
  } else {
    gateServo.write(0);  // Close gate
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(200);  // Short delay before next reading
}