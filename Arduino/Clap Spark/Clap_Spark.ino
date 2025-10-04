
// ---* Clap Spark *--- //

int soundSensor = 7;
int ledPin = 6;
int clapCount = 0;
unsigned long firstClapTime = 0;
bool ledState = false;

void setup() {
  pinMode(soundSensor, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int soundDetected = digitalRead(soundSensor);

  if (soundDetected == 0) { // Sound detected
    if (clapCount == 0) {
      firstClapTime = millis();
      clapCount++;
    } else if (millis() - firstClapTime < 400) {
      clapCount++;
    }
    delay(50); // Debounce delay
  }

  if (clapCount == 2) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    clapCount = 0;
  }

  if (millis() - firstClapTime > 400) {
    clapCount = 0;
  }
}