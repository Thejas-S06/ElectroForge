
// ---* IRis Glow *--- //

#include <IRremote.hpp>

// Pin Definitions
const int RECV_PIN = 2;       // IR receiver connected to digital pin 2

const int LED1_PIN = 3;       // LED1 on pin 3
const int LED2_PIN = 4;       // LED2 on pin 4
const int LED3_PIN = 5;       // LED3 on pin 5

const int LED_COUNT = 3; 
int LEDS[LED_COUNT] = {LED1_PIN, LED2_PIN, LED3_PIN};

// HEX Codes from remote
const uint32_t CODE_LED1 = 0xF50A7F80;
const uint32_t CODE_LED2 = 0xE41B7F80;
const uint32_t CODE_LED3 = 0xE01F7F80;
const uint32_t CODE_OFF_ON = 0xED127F80;
const uint32_t CODE_PLAY = 0xFE017F80;
const uint32_t CODE_RIGHT = 0xFC037F80;
const uint32_t CODE_LEFT = 0xFD027F80;

int LED_STATE = 0;
int iterations = 5;

void powerOnOff(){
  if(LED_STATE == 0){
    for(int on=0; on<=LED_COUNT; on++){
      digitalWrite(LEDS[on], HIGH);
    }
    LED_STATE = 1;
  }
  else{
    for(int off=0; off<=LED_COUNT; off++){
      digitalWrite(LEDS[off], LOW);
    }
    LED_STATE = 0;
  }
}

void rightBlink(){
  for(int blink=0; blink<iterations; blink++){

    for(int initialOff=0; initialOff<=LED_COUNT; initialOff++){
    digitalWrite(LEDS[initialOff], LOW);
    }
    for(int right=0; right<LED_COUNT; right++){
    digitalWrite(LEDS[right], HIGH);
    delay(200);
    digitalWrite(LEDS[right], LOW);
    }
    delay(100);
  }
}

void leftBlink(){
  for(int blink=0; blink<iterations; blink++){

    for(int initialOff=0; initialOff<=LED_COUNT; initialOff++){
    digitalWrite(LEDS[initialOff], LOW);
    }
    for(int left=(LED_COUNT-1); left>=0; left--){
    digitalWrite(LEDS[left], HIGH);
    delay(200);
    digitalWrite(LEDS[left], LOW);
    }
    delay(100);
  }
}

void alternateBlink(){
  for(int blink=0; blink<iterations ;blink++){

    for(int initialOff=0; initialOff<=LED_COUNT; initialOff++){
      digitalWrite(LEDS[initialOff], LOW);
    }
    for(int onState=0; onState<=LED_COUNT; onState++){
      digitalWrite(LEDS[onState], HIGH);
    }
    delay(350);
    for(int offState=0; offState<=LED_COUNT; offState++){
      digitalWrite(LEDS[offState], LOW);
    }
    delay(300);
  }
}

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start IR receiver

  // Set LED pins as output
  for(int setState=0; setState<LED_COUNT; setState++){
    pinMode(LEDS[setState], OUTPUT);
  }
  // Initialize LEDs to OFF
  for(int initialization=0; initialization<LED_COUNT; initialization++){
    digitalWrite(LEDS[initialization], LOW);
  }
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t receivedCode = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("Received HEX: 0x");
    Serial.println(receivedCode, HEX);

    switch (receivedCode) {
      case CODE_OFF_ON:{
        powerOnOff();
        break;
      }
      case CODE_RIGHT:{
        rightBlink();
        break;
      }
      case CODE_LEFT:{
        leftBlink();
        break;
      }
      case CODE_PLAY:{
        alternateBlink();
        break;
      }
      case CODE_LED1:
        digitalWrite(LED1_PIN, !digitalRead(LED1_PIN)); // Toggle LED1
        break;
      case CODE_LED2:
        digitalWrite(LED2_PIN, !digitalRead(LED2_PIN)); // Toggle LED2
        break;
      case CODE_LED3:
        digitalWrite(LED3_PIN, !digitalRead(LED3_PIN)); // Toggle LED3
        break;
      default:
        Serial.println("Unknown code");
        break;
    }

    IrReceiver.resume(); // Ready to receive next signal
  }
}
