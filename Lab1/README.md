# Switch-Controlled LED Logic — Embedded Systems Project

This project was developed as part of the **Software Embedded Systems** course. It demonstrates the implementation of control logic using a Microchip-based microcontroller board (e.g., Basys MX3) and was written in the C programming language.

## Objective

To write a C program that controls 8 onboard LEDs based on the state of 8 digital input switches. The program showcases decision-making in embedded systems based on real-time digital inputs and produces corresponding visual and audible outputs.

## Experiment Overview

Each switch (SW0 to SW7) triggers a different operation:

- **SW0** – Hexadecimal counter displayed on the LEDs.
- **SW1** – Bit shifting animation (right to left).
- **SW2** – Fan-like LED pattern (opens outward from center).
- **SW3** – Reverses the last performed LED animation.
- **SW4** – Adjusts speed (slow when OFF, fast when ON).
- **SW5** – Pauses the current LED activity.
- **SW6** – Activates a buzzer with intermittent sound.
- **SW7** – Exits the program loop.

> **Priority Note:** If multiple switches (SW0–SW2) are pressed simultaneously, the higher-numbered switch takes precedence.

## Technologies

- **Language:** C
- **Platform:** Microchip microcontroller board (e.g., Basys MX3)
- **Tools:** MPLAB X IDE / XC32 Compiler

## Learning Outcomes

- Understand digital input/output operations in embedded systems.
- Implement logic-based decision structures in C.
- Use hardware timers and delays to control animation speed.
- Manage state transitions and priority logic in real time.

---

**Author:** Yuval Hoffman  
**Course:** Software Embedded Systems  
