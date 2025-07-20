# Analog to Digital Conversion – Experiment 6

**Author:** Dr. Menachem Epstein  
**Platform:** Microchip Microcontroller  
**Language:** C

## Overview

This experiment demonstrates the use of Analog-to-Digital Converters (ADC) to read and process analog input signals in an embedded system using a Microchip microcontroller.

The system includes:
- Analog inputs: Variable resistor (potentiometer) and microphone
- LCD display for showing voltage readings
- Keyboard for input selection

---

## Objective

Convert analog signals to digital values and display them on the LCD. The input source is selected by pressing a key on the onboard keyboard.

---

## System Behavior

Upon pressing a key on the keyboard:

- **Key 1**:  
  - Triggers a short beep  
  - Reads the analog voltage from the **variable resistor**  
  - Displays:  
    ```
    Analog 1 – <x.dd>V
    ```

- **Key 2**:  
  - Triggers a short beep  
  - Reads the analog voltage from the **microphone input**  
  - Displays:  
    ```
    Analog 2 – <x.dd>V
    ```

---

## Notes

- The analog voltage range is from **0V to 3.3V**
- ADC sampling and digital output are triggered based on keyboard interaction
- The system combines audio feedback, visual output, and analog signal processing