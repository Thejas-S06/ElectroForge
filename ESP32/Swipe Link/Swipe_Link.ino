
// ---* Swipe-Link *--- //

#include <SPI.h>
#include <Adafruit_PN532.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the SPI pins for your ESP32
#define PN532_SCK (18)
#define PN532_MISO (19)
#define PN532_MOSI (23)
#define PN532_SS (5)

#define LED_RED 15
#define LED_WHITE 4
#define BUZZER_PIN 2 // Use a passive buzzer with a 220-ohm resistor in series

// Create an instance of the Adafruit PN532 class
Adafruit_PN532 nfc(PN532_SCK, PN532_MISO, PN532_MOSI, PN532_SS);

// Set the LCD address to 0x27 for a 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pre-stored password to match
const String password = "password";

// Variables for non-blocking timing
unsigned long lastEventTime = 0;
const long displayDuration = 3000; // 3 seconds for displaying result

void setup(void) {
  Serial.begin(115200);
  while (!Serial);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_WHITE, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scanning...");

  Serial.println("Initializing PN532...");
  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.print("Didn't find PN53x board :(");
    while (1); // halt
  }

  Serial.print("Found chip PN5");
  Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.');
  Serial.println((versiondata >> 8) & 0xFF, DEC);

  // Configure board to read NFC tags
  nfc.setPassiveActivationRetries(0xFF);
  nfc.SAMConfig();

  Serial.println("Waiting for an NFC card or phone...");
}

void loop(void) {
  // Check if the display duration has passed and reset the state
  if (millis() - lastEventTime > displayDuration) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_WHITE, LOW);
    noTone(BUZZER_PIN);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scanning...");
  }

  uint8_t success;
  uint8_t uid[] = {0, 0, 0, 0, 0, 0, 0};
  uint8_t uidLength;

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    Serial.println("\n--- Found a Tag! ---");
    Serial.print("UID Length: ");
    Serial.print(uidLength, DEC);
    Serial.println(" bytes");

    uint8_t data[64];
    bool readSuccess = true;
    for (int i = 0; i < 16; i++) {
      readSuccess &= nfc.ntag2xx_ReadPage(i, data + (i * 4));
    }

    if (readSuccess) {
      Serial.println("Reading NDEF message...");
      int ndefStartIndex = -1;

      for (int i = 0; i < 64; i++) {
        if (data[i] == 0x03) {
          ndefStartIndex = i;
          break;
        }
      }

      if (ndefStartIndex != -1) {
        uint8_t ndefLength = data[ndefStartIndex + 1];
        Serial.print("NDEF Message Length: ");
        Serial.println(ndefLength);

        uint8_t languageCodeLength = data[ndefStartIndex + 4];
        int textStartIndex = ndefStartIndex + 2 + 3 + languageCodeLength;

        int charsToRead = 8 + 5;    // Restricted the password length to 8 characters. 5 is added because the reading starts from the 5th character 
        String text = "";
        for (int i = 5; i < charsToRead; i++) {     // Made i to start from 5 to avoid reading the junk characters
          int dataIndex = textStartIndex + i;
          if (dataIndex < 64) {
            text += (char)data[dataIndex];
          }
        }

        Serial.print("Text Found: ");
        Serial.println(text);

        // Check if the extracted text matches the password
        if (text.equals(password)) {
          Serial.println("Password Match!");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Access Granted!");
          digitalWrite(LED_WHITE, HIGH);
          digitalWrite(LED_RED, LOW);
          tone(BUZZER_PIN, 1000, 200);
        } else {
          Serial.println("Password Mismatch!");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Access Denied!");
          digitalWrite(LED_RED, HIGH);
          digitalWrite(LED_WHITE, LOW);
          tone(BUZZER_PIN, 500, 200);
          delay(300); // Small delay between beeps. This is the only intentional delay.
          tone(BUZZER_PIN, 500, 200);
        }

        lastEventTime = millis(); // Record the time the event happened

      } else {
        Serial.println("Could not find NDEF header (0x03).");
      }
    } else {
      Serial.println("Could not read tag data.");
    }
  }
}