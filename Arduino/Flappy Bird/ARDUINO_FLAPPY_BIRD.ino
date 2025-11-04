/***********************************************************************
 *                       FLAPPY BIRD on OLED for Arduino              *
 *                         © 2025 by @ardu_projects                   *
 *                      Developed with Adafruit SSD1306               *
 ***********************************************************************/

/*
  ┌───────────────────────────────────────────────────────────────┐
  │                        WIRING DIAGRAM                         │
  └───────────────────────────────────────────────────────────────┘

  Arduino        | Component         | Connection
  ---------------------------------------------------------
  PIN 2          | Push Button       | One side to GND
                 |                   | Uses INPUT_PULLUP internally

  PIN 4          | Buzzer            | Other side to GND

  A4 (SDA)       | OLED SSD1306      | SDA pin
  A5 (SCL)       | OLED SSD1306      | SCL pin

  Power          | OLED + Button     | 5V and GND accordingly
*/

/*
  ┌───────────────────────────────────────────────────────────────┐
  │       GAMEPLAY SETTINGS — ADJUST TO CHANGE DIFFICULTY        │
  └───────────────────────────────────────────────────────────────┘

  float gravity = 0.4;            // Controls how fast the bird falls
  float jumpStrength = -2;        // How high the bird jumps when button is pressed
  int pipeSpacing = 50;           // Horizontal distance between pipes
  int gapSize = 20;               // Vertical gap between top and bottom pipes
  int pipeWidth = 15;             // Width of each pipe
  int birdSize = 4;               // Size of the bird (square)

  Increase difficulty by:
    - Increasing gravity
    - Reducing jumpStrength (closer to zero)
    - Reducing gapSize
    - Decreasing pipeSpacing
*/

// Required libraries for OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin configuration
#define BUTTON_PIN 2
#define BUZZER_PIN 4

// Bird variables
int birdX = 20;
int birdY = SCREEN_HEIGHT / 2;
int birdSize = 4;
float birdVelocity = 0;
float gravity = 0.4;
float jumpStrength = -2;

// Pipes
const int NUM_PIPES = 3;
int pipeX[NUM_PIPES];
int gapY[NUM_PIPES];
int pipeWidth = 15;
int pipeSpacing = 50;
int gapSize = 20;

// Game state variables
bool isGameOver = false;
bool isStarted = false;
int score = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  resetGame(); // Initialize game
}

void loop() {
  if (!isStarted) {
    showStartScreen();
    if (digitalRead(BUTTON_PIN) == LOW) {
      isStarted = true;
      birdY = SCREEN_HEIGHT / 2;
      birdVelocity = 0;
      isGameOver = false;
      delay(200);
      playStartTone();
    }
    return;
  }

  if (digitalRead(BUTTON_PIN) == LOW && !isGameOver) {
    birdVelocity = jumpStrength;
    playFlapTone();
  }

  if (!isGameOver) {
    updateGame(); // Game logic only runs if game is active
  }

  drawGame(); // Redraw screen
  delay(30);
}

// Resets the game to initial state
void resetGame() {
  birdY = SCREEN_HEIGHT / 2;
  birdVelocity = 0;
  isGameOver = false;
  score = 0;

  for (int i = 0; i < NUM_PIPES; i++) {
    pipeX[i] = SCREEN_WIDTH + i * pipeSpacing;
    gapY[i] = random(5, SCREEN_HEIGHT - gapSize - 5);
  }
}

// Handles bird movement and collision logic
void updateGame() {
  birdVelocity += gravity;
  birdY += birdVelocity;

  for (int i = 0; i < NUM_PIPES; i++) {
    pipeX[i] -= 2; // Move pipes left

    // If pipe goes off screen, reposition it to the right
    if (pipeX[i] + pipeWidth < 0) {
      int maxPrev = 0;
      for (int j = 0; j < NUM_PIPES; j++) {
        if (pipeX[j] > maxPrev) maxPrev = pipeX[j];
      }
      pipeX[i] = maxPrev + pipeSpacing + random(0, 20);
      gapY[i] = random(5, SCREEN_HEIGHT - gapSize - 5);
      score++;
    }

    // Check collision with pipes
    if (birdX + birdSize > pipeX[i] && birdX < pipeX[i] + pipeWidth &&
        (birdY < gapY[i] || birdY + birdSize > gapY[i] + gapSize)) {
      gameOver();
    }
  }

  // Check collision with screen edges
  if (birdY <= 0 || birdY + birdSize >= SCREEN_HEIGHT) {
    gameOver();
  }
}

// Draws the bird, pipes and score on the OLED
void drawGame() {
  display.clearDisplay();

  // Draw bird
  display.fillRect(birdX, birdY, birdSize, birdSize, SSD1306_WHITE);

  // Draw pipes
  for (int i = 0; i < NUM_PIPES; i++) {
    display.fillRect(pipeX[i], 0, pipeWidth, gapY[i], SSD1306_WHITE);
    display.fillRect(pipeX[i], gapY[i] + gapSize, pipeWidth, SCREEN_HEIGHT - (gapY[i] + gapSize), SSD1306_WHITE);
  }

  // Draw score
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Score: ");
  display.print(score);
  display.display();
}

// Handles game over logic
void gameOver() {
  isGameOver = true;
  showGameOverScreen();  // Display "Game Over"
  playGameOverTone();    // Play buzzer tone

  // Wait for button press to restart
  while (digitalRead(BUTTON_PIN) == HIGH) {
    delay(10);
  }

  resetGame();       // Restart game state
  playStartTone();   // Sound effect
}

// ------------------------ SOUND FUNCTIONS ------------------------

void playStartTone() {
  tone(BUZZER_PIN, 400, 100);
  delay(120);
  tone(BUZZER_PIN, 600, 100);
  delay(120);
  tone(BUZZER_PIN, 800, 100);
  delay(120);
  noTone(BUZZER_PIN);
}

void playFlapTone() {
  tone(BUZZER_PIN, 1200, 40);
  delay(50);
  noTone(BUZZER_PIN);
}

void playGameOverTone() {
  tone(BUZZER_PIN, 600, 200);
  delay(250);
  tone(BUZZER_PIN, 400, 300);
  delay(350);
  noTone(BUZZER_PIN);
}

// ------------------------ SCREEN FUNCTIONS ------------------------

void showStartScreen() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30, 20);
  display.println("Flappy");
  display.setCursor(40, 40);
  display.println("Bird");
  display.setTextSize(1);
  display.setCursor(20, 57);
  display.println("Press to start");
  display.display();
}

void showGameOverScreen() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.println("Game Over");
  display.setTextSize(1);
  display.setCursor(15, 40);
  display.println("Press to restart");
  display.setCursor(15, 50);
  display.print("Score: ");
  display.print(score);
  display.display();
}


