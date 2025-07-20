# Final Project – Software Embedded Systems Course

## Overview

This project was developed as the final assignment in the **Software Embedded Systems** course. It represents the culmination of all prior experiments and required the integration of various hardware components (LCD, timers, interrupts, switches, RGB LEDs, 7-segment display, and buzzer) into a fully functioning real-time embedded system.

---

## Project Description

The system simulates an interactive and humorous scenario where **two characters appear on an LCD screen and walk towards each other**. Each character is **controlled by switches** and can walk independently on either of the two available LCD lines. Their movement is displayed in real time on the LCD.

### Special Interaction:
When **both characters reach the center of the LCD on the top row at the same time**, the following events occur simultaneously:
- Both characters **disappear from the screen**
- An **explicit (18+) image** is drawn on the LCD using custom characters. The image then starts to move left to right on the screen (as if it were dancing).
- The **speaker emits a high-pitched sound**
- The **RGB LED begins cycling** through red → green → blue continuously

---

## Technical Highlights

- **Switch Inputs**: Used for controlling each character's movement independently.
- **LCD Screen**: Used for visualizing the characters' positions and final image.
- **Timers (T1 & T2)**: Used to drive timed events, countdowns, and delays.
- **Interrupts**: Enable concurrent tasks like audio playback and animation updates.
- **RGB LED Control**: Implements a cycling effect when a match occurs.
- **Buzzer**: Emits sound effects based on system state.
- **7-Segment Display**: Countdown or other visual feedback mechanisms.
- **Code Verification**: Optional code-entry game that either leads to success or “explosion” if failed.

---

## Notes

- All code was written in C for the PIC32-based Microchip development board.
- The system was designed and debugged using low-level register manipulation and timer configuration.
- This project combines real-time embedded programming with creativity and interactive behavior.

> This final project demonstrates complete mastery over embedded system design by integrating input/output, time-sensitive events, and playful logic.
