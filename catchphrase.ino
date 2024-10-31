#include <LiquidCrystal.h>

// LCD pin configuration
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Button pin configuration
const int upButton = 8;
const int downButton = 9;
const int selectButton = 10;

// Game data
const String categories[] = {"Cinema", "Sports", "DSM-5"};
const int categoryCount = sizeof(categories) / sizeof(categories[0]);

const String cinemaPhrase[] = {"The Godfather", "Star Wars", "Forrest Gump", "Pulp Fiction", "Matrix Reloaded"};
const String sportsPhrase[] = {"Shaq", "Lionel Messi", "Wimbledon", "Masters' Jacket", "Freestyle"};
const String dsmPhrase[] = {"BPD", "Schizophrenia", "Tourette’s", "Autism", "Agoraphobia"};

const String* phrases[] = {cinemaPhrase, sportsPhrase, dsmPhrase};
const int phraseCounts[] = {5, 5, 5};  // Number of phrases in each category

// Game state variables
int currentCategory = 0;
int currentPhrase = 0;
bool gameRunning = false;
unsigned long gameStartTime = 0;
const unsigned long gameDuration = 30000;  // 30 seconds

void setup() {
  lcd.begin(16, 2);  // Initialize 16x2 LCD
  
  // Set up button pins
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  
  randomSeed(analogRead(0));  // Initialize random seed
}

void loop() {
  if (!gameRunning) {
    showMenu();
  } else {
    playGame();
  }
}

void showMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select category:");
  lcd.setCursor(0, 1);
  lcd.print(categories[currentCategory]);
  
  if (digitalRead(upButton) == HIGH) {
    delay(50);  // Simple debounce
    currentCategory = (currentCategory + 1) % categoryCount;
  }
  
  if (digitalRead(downButton) == HIGH) {
    delay(50);  // Simple debounce
    currentCategory = (currentCategory - 1 + categoryCount) % categoryCount;
  }
  
  if (digitalRead(selectButton) == HIGH) {
    delay(50);  // Simple debounce
    startGame();
  }
  
  delay(100);  // Small delay to prevent rapid cycling
}

void startGame() {
  gameRunning = true;
  currentPhrase = 0;
  gameStartTime = millis();
  randomizePhrase();
}

void randomizePhrase() {
  for (int i = 0; i < phraseCounts[currentCategory]; i++) {
    int j = random(i, phraseCounts[currentCategory]);
    String temp = phrases[currentCategory][i];
    phrases[currentCategory][i] = phrases[currentCategory][j];
    phrases[currentCategory][j] = temp;
  }
}

void playGame() {
  unsigned long elapsedTime = millis() - gameStartTime;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(phrases[currentCategory][currentPhrase]);
  
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print((gameDuration - elapsedTime) / 1000);
  
  if (elapsedTime >= gameDuration) {
    endGame();
  }
  
  if (digitalRead(selectButton) == HIGH) {
    delay(50);  // Simple debounce
    currentPhrase = (currentPhrase + 1) % phraseCounts[currentCategory];
  }
  
  delay(100);  // Small delay to prevent rapid cycling
}

void endGame() {
  gameRunning = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Over!");
  lcd.setCursor(0, 1);
  lcd.print("Press to restart");
  
  while (digitalRead(selectButton) == LOW) {
    // Wait for button press
  }
  delay(50);  // Simple debounce
}