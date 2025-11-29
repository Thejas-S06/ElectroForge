
 // ---* Simple Touch Piano *---//

// Define the pins for the three touch sensors
const int sensorPin1 = 2; // E note
const int sensorPin2 = 3; // D note
const int sensorPin3 = 4; // C note

// Define the pin for the buzzer
const int buzzerPin = 9;

// Define the frequencies (notes) for the piano keys
const int C4_note = 262;
const int D4_note = 294;
const int E4_note = 330;

// The correct sequence of notes to play "Mary Had a Little Lamb"
const int correctSequence[] = {E4_note, D4_note, C4_note, D4_note, E4_note, E4_note, E4_note};
// The length of the correct sequence
const int sequenceLength = 7;

// Array to store the user's sequence
int userSequence[sequenceLength];
// Index to keep track of the current position in the user's sequence
int sequenceIndex = 0;

void setup() {
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // For debugging purposes
}

void loop() {
  // Check for touch on each sensor
  if (digitalRead(sensorPin1) == HIGH) {
    recordNote(E4_note);
  } else if (digitalRead(sensorPin2) == HIGH) {
    recordNote(D4_note);
  } else if (digitalRead(sensorPin3) == HIGH) {
    recordNote(C4_note);
  }

  // Check if the user has completed the sequence
  if (sequenceIndex >= sequenceLength) {
    checkSequence();
  }

  // Small delay to prevent multiple inputs from a single touch
  delay(100);
}

void recordNote(int note) {
  // Play the note
  tone(buzzerPin, note);
  delay(150);
  noTone(buzzerPin);
  
  // Store the note in the user's sequence
  if (sequenceIndex < sequenceLength) {
    userSequence[sequenceIndex] = note;
    sequenceIndex++;
  }
}

void checkSequence() {
  bool match = true;
  for (int i = 0; i < sequenceLength; i++) {
    if (userSequence[i] != correctSequence[i]) {
      match = false;
      break;
    }
  }

  if (match) {
    Serial.println("Correct! Playing the tune...");
    playTune();
  } else {
    Serial.println("Incorrect sequence. Try again.");
  }
  
  // Reset the sequence index for the next attempt
  sequenceIndex = 0;
}

void playTune() {
  for (int i = 0; i < sequenceLength; i++) {
    tone(buzzerPin, correctSequence[i]);
    delay(300); // Duration of the note
    noTone(buzzerPin);
    delay(50); // Pause between notes
  }
}