# Keyboard Interface – Experiment 3

**Author:** Dr. Menachem Epstein  
**Platform:** Microchip Microcontroller  
**Language:** C

## Overview

This experiment demonstrates how to interface a 4x4 matrix keyboard with a microcontroller using direct scanning. It also integrates visual and audio feedback through an LCD display and buzzer.

The system includes:
- 4x4 matrix keyboard (16 keys)
- 2-line LCD display
- Microcontroller (Microchip)
- LEDs and switches

---

## Part A: Basic Keyboard Activation

- A key press triggers:
  - A short beep sound
  - A message on the LCD indicating the pressed key:
    ```
    Mode <Pressed Key> -
    ```
  - The top line of the LCD remains unchanged

**Example:** Pressing key `3` results in the LCD showing:
```
Mode 3 -
```

---

## Part B: External Keyboard Control with Scanning

- Replaces physical switches from Experiment 2 with external keyboard input.
- Keyboard inputs trigger actions:
  - LEDs and LCD update based on the received key
  - Behaves identically to the previous experiment but uses keyboard scanning instead of physical switches

---

## Part C: Timer-Based Keyboard Scanning

- Uses microcontroller's timer interrupt to scan the external keyboard periodically.
- On key press:
  - Triggers corresponding actions on the LCD and LEDs
  - Fully emulates digital switch functionality from previous experiments

---

## Notes

- This experiment is written in C and designed for Microchip-based development boards.
- Combines external input handling, timing mechanisms, and user feedback via display and sound.