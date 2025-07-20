# Timer and Interrupt Handling – Experiment 4

**Author:** Dr. Menachem Epstein  
**Platform:** Microchip Microcontroller  
**Language:** C

## Overview

This experiment demonstrates real-time task management using the internal timer and interrupt mechanisms of a Microchip microcontroller. It shows how a serial processor can simulate multitasking by using hardware interrupts.

The system includes:
- Internal timers (Timer 1, Timer 2-3, Timer 4)
- RGB LED for visual feedback
- 2-line LCD display for counter output

---

## Objective

Enable a real-time, multitask-like system that performs different actions based on timer interrupts using:

- **Timer 1**: 16-bit  
  - Interrupt every **10 milliseconds**  
  - Toggles the **red** color of the RGB LED

- **Timer 2-3**: 32-bit  
  - Interrupt every **2 seconds**  
  - Toggles the **green** color of the RGB LED

- **Timer 4**: 16-bit  
  - Interrupt every **1 second**  
  - Displays a **2-digit counter** (00 to 99) on the **second line of the LCD** (far-right position)

---

## Notes

- This experiment demonstrates how to perform pseudo-multitasking in a single-threaded embedded system using interrupts.
- Implemented using the C programming language on Microchip's development environment.
- Helps understand timing precision and interrupt prioritization in real-time embedded systems.