# Arduino Catchphrase Game

An Arduino Uno R3 version of the electronic party game Catchphrase. Players have to make their teammates guess words from different categories before time runs out. This is only a prototype, I have components otw to build a complete version housed in (plastic/wood/something else?) with a speaker and bluetooth connectivity for the addition of new categories. Stay tuned!

## Hardware Requirements

- Arduino Uno R3
- 16x2 LCD Display
- 3 Push Buttons
- Jumper Wires
- 10kΩ Resistor (for LCD contrast)
- Breadboard

## Pin Configuration

### LCD Display
- RS: Pin 12
- EN: Pin 11
- D4: Pin 5
- D5: Pin 4
- D6: Pin 3
- D7: Pin 2

### Buttons
- Up Button: Pin 8
- Down Button: Pin 9
- Select Button: Pin 10

## Game Features

- Three basic categories for prototyping:
  - Cinema
  - Sports
  - DSM-5 (Mental Health Terms)
- 30-second timer
- Random word selection
- Easy navigation through categories
- Simple button controls

## How to Play

1. Power on the device
2. Use Up/Down buttons to select a category
3. Press Select to start the game
4. A word/phrase will appear on the screen
5. Try to make your teammates guess the word
6. Press Select to skip to the next word
7. Keep playing until the timer runs out
8. Press Select to start a new game

## Circuit Setup

1. Connect the LCD display according to the pin configuration above
2. Connect the buttons to their respective pins with pull-up resistors
3. Adjust LCD contrast using the 10kΩ potentiometer
4. Power the Arduino using USB or external power supply

## Installation

1. Clone this repository
2. Open `catchphrase.ino` in the Arduino IDE
3. Connect your Arduino Uno R3
4. Upload the code to your board

## License

This project is open source and available under the MIT License.
