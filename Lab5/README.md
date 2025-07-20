# 7-Segment Display Control – Experiment 5

**Author:** Dr. Menachem Epstein  
**Platform:** Microchip Microcontroller  
**Language:** C

## Overview

This experiment focuses on controlling a 7-segment display using user buttons. The goal is to simulate a digital clock interface, where the user can set and run the time using physical buttons connected to a Microchip microcontroller.

The system includes:
- A 7-segment display
- 5 user buttons (`BTN`)
- Microcontroller with a timer for real-time operation

---

## Objectives

- Display a starting time of `00:00` on the 7-segment display.
- Enable the user to update the display values using buttons:
  - **BTNL / BTNR**: Navigate between digits for editing
  - **BTNU / BTND**: Increment or decrement the selected digit
  - **BTNC**: Start the clock, which will begin counting seconds using a timer

---

## System Behavior

- Once started, the clock updates every second based on the microcontroller's timer.
- The user interface provides full control over clock setup and activation using the 5-button input.

---

## Notes

- The code for this experiment is written in C.
- Designed for educational purposes on Microchip development boards.
- Emphasizes event-driven programming, timer usage, and user interface design on embedded systems.