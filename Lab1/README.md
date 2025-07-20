# Switch-Controlled LED Display – Experiment 1

**Author:** Dr. Menachem Epstein  
**Platform:** Microchip Microcontroller  
**Language:** C

## Overview

This experiment introduces the basic concept of digital input and output by controlling LEDs based on the state of physical switches. It is the first in a series of embedded systems experiments and focuses on logical decision-making using switch input.

The system includes:
- 8 digital input switches (`SW0` to `SW7`)
- 8 output LEDs
- Optional buzzer for audio feedback

---

## Objectives

Create a C program that performs specific actions based on the switch states:

- **SW0 – Counter Mode**  
  - LEDs display an 8-bit hexadecimal counter (2 digits)

- **SW1 – Shift Operation**  
  - LEDs perform a right-to-left shifting animation

- **SW2 – Fan Operation**  
  - LEDs light in a "fan-out" pattern, starting from the center

> **Priority Note**: Among `SW0`–`SW2`, the switch with the highest number takes priority  
> (e.g., if both `SW1` and `SW2` are ON, the fan operation from `SW2` is executed)

- **SW3 – Reverse Direction**  
  - Reverses the last LED operation

- **SW4 – Speed Control**  
  - `SW4 = 0`: Slow speed  
  - `SW4 = 1`: Fast speed

- **SW5 – Halt**  
  - Stops LED activity

- **SW6 – Beep**  
  - Triggers a periodic buzzer sound

- **SW7 – Exit**  
  - Exits the main control routine

---

## Notes

- Logical control is implemented using conditional checks on digital input.
- Efficient program design requires anticipating all possible switch combinations.
- This experiment sets the foundation for more complex hardware-software interactions in embedded systems.