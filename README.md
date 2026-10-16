# Arduino Countdown Timer

A beginner-friendly countdown timer built using an Arduino Uno, a 16×2 LCD, a push button, and a buzzer. The timer accepts a duration through the Serial Monitor, displays the remaining time, and alerts the user when the countdown finishes.

## Features

- Accepts minutes and seconds through the Serial Monitor
- Displays the remaining countdown on a 16×2 LCD
- Supports button-based pause and resume control
- Activates a buzzer when the countdown finishes
- Displays a completion message on the LCD

## Components Used

- Arduino Uno
- 16×2 LCD
- Active buzzer module
- Push button
- Breadboard and jumper wires
- USB cable and required power connections

## Pin Connections

| Component | Arduino Pin |
|---|---|
| LCD RS | 12 |
| LCD Enable | 11 |
| LCD D4 | 5 |
| LCD D5 | 4 |
| LCD D6 | 3 |
| LCD D7 | 2 |
| Buzzer signal | 8 |
| Pause/resume button | 6 |

The LCD uses the `LiquidCrystal` library. The pause/resume button uses `INPUT_PULLUP` and connects between digital pin 6 and GND.

## How It Works

1. The Arduino prompts the user to enter the countdown duration through the Serial Monitor.
2. The user enters the number of minutes and then the number of seconds.
3. The LCD displays the remaining time in minutes and seconds.
4. The push button provides pause and resume control.
5. When the countdown reaches zero, the LCD displays a completion message and the buzzer activates.

## Getting Started

1. Open `countdown_timer.ino` in the Arduino IDE.
2. Connect the LCD, buzzer, and push button according to the pin connections above.
3. Select your Arduino board and port.
4. Upload the sketch.
5. Open the Serial Monitor at **9600 baud**.
6. Follow the prompts to enter the minutes and seconds for your countdown.

