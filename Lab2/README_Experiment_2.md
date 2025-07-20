# LCD Display Activation – Experiment 2

**Author:** Dr. Menachem Epstein  
**Platform:** Microchip Microcontroller  
**Language:** C

## Overview

This experiment continues from Experiment 1 and demonstrates the use of an LCD display to provide real-time feedback based on user input via switches on a microcontroller development board.

The board includes:
- Switch inputs (SW0–SW7)
- LED outputs
- 2-line, 15-character per line Liquid Crystal Display (LCD)

---

## Part A: LCD Feedback for Switch Actions

The LCD displays messages based on the state of the switches. The functionality for each switch is as follows:

- **SW0 – Counter Activation**  
  - Mode 0: `Counter Up Slow`

- **SW1 – Shift Operation**  
  - Mode 1: `Shift Right Slow`

- **SW2 – Swing Operation**  
  - Mode 2: `Swing Up Slow`

- **SW3 – Direction Change**  
  - Mode 0: `Counter Down Slow`  
  - Mode 1: `Shift Left Slow`  
  - Mode 2: `Swing Down Slow`

- **SW4 – Speed Change**  
  Changes final word from `Slow` to `Fast` for all modes:
  - Mode 0: `Counter Down Fast`
  - Mode 1: `Shift Left Fast`
  - Mode 2: `Swing Left Fast`

- **SW5 – Halt Operation**  
  - Mode 5: `Halt`

- **SW6 – Beep Activation**  
  - Mode 6: `Beep Mode`  
  Triggers a beeping sound through the board's buzzer.

- **SW7 – Program Exit**  
  - Mode 7: `Exit`  
  Terminates the current program routine.

---

## Part B: Custom Font and Object Motion

This part of the experiment focuses on writing a new font (graphic) to the LCD and controlling its movement.

- **Goal:** Design a custom object on the LCD.
- **SW0:** Controls horizontal motion (left/right).
- **SW1:** Selects the LCD row for movement.
- **SW7:** Triggers an audio signal (buzzer).

---

## Notes

- This experiment is programmed in C using Microchip development tools.
- The interaction between switches, LEDs, and LCD provides a complete demonstration of embedded user interfaces.