# Software Embedded Systems Course – Lab Series and Final Project

## Overview

This repository contains all the laboratory experiments and the final project developed throughout the **Software Embedded Systems** course (2025). The course focused on embedded programming using a PIC32-based Microchip development board, where students progressively learned to integrate hardware interfaces, handle timers and interrupts, and design real-time systems.

All code is written in **C**, and most experiments include interaction with physical components such as **LEDs, switches, 7-segment displays, LCDs, buzzers, RGB LEDs, and keypads**.

---

## Labs Breakdown

### 🔹 Experiment 1 – Switch-Controlled LEDs
Implements LED behavior based on digital switch inputs. Supports:
- Hexadecimal counter
- Bit shifting
- Fan-out LED animation
- Direction reversal and speed control
- Beep sound and exit routine

### 🔹 Experiment 2 – LCD Display Activation
Enhances feedback from Experiment 1 using a **2-line LCD**. Displays the current mode of operation based on switch input.

### 🔹 Experiment 2 (Part B) – Custom LCD Font
Designs and animates a **custom character** on the LCD that moves horizontally based on switch input. The user can choose the row and activate sound.

### 🔹 Experiment 3 – Keyboard Matrix
Introduces a **4x4 matrix keyboard**, scanning inputs manually and linking them to mode display and actions:
- Keypress detection with LCD feedback
- Interrupt-driven and timer-based scanning
- Replacement of digital switches with external keyboard

### 🔹 Experiment 4 – Timers and Interrupts
Implements real-time multi-tasking using **Timer1, Timer2-3, and Timer4**:
- RGB LED blinking at different frequencies
- 2-digit counter displayed on LCD updated every second

### 🔹 Experiment 5 – 7-Segment Clock Control
Builds a digital clock interface:
- Set time with user buttons
- View current time on a 7-segment display
- Timer-driven second updates

### 🔹 Experiment 6 – Analog to Digital Conversion (ADC)
Reads analog input from a **potentiometer** and a **microphone**:
- Converts analog voltage to digital value
- Displays voltage on the LCD in real time

---

## Final Project – “The Bomboklat Machine”

The final assignment integrates all course concepts into a complex and entertaining interactive game:

- **Scenario**: Two characters, controlled by switches, walk toward each other on a 2-line LCD.
- **Mechanics**: Each character can walk on a different line. If they meet exactly at the center of the top line:
  - They **disappear**
  - An **18+ image** is drawn on the LCD
  - The **speaker emits a high-pitched sound**
  - **RGB LEDs** cycle through red, green, and blue
- Features also include:
  - Countdown timer using 7-segment display
  - Sound signals and failure modes
  - RGB visual effects
  - Passcode logic and verification

This final project showcases complete mastery over embedded design by combining logic, real-time control, interrupts, user input, and creativity.

---

## Notes

- All experiments and the final project were compiled using MPLAB X and XC32 compiler.
- Hardware was simulated and tested on a Microchip development board with full peripheral support.