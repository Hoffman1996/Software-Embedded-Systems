#include "bomboklat_header.h"

void setup_and_init_system() {
    setup_pins_for_seven_segment_display();
    setup_timer1();
    setup_timer2();
    setup_switches_and_leds();
    setup_LCD();
    initialize_keyboard();
    reset_LCD();
}

void setup_pins_for_seven_segment_display() {
    // Configure anode pins as outputs
    TRISBbits.TRISB12 = 0;
    ANSELBbits.ANSB12 = 0; // AN0
    TRISBbits.TRISB13 = 0;
    ANSELBbits.ANSB13 = 0; // AN1
    TRISAbits.TRISA9 = 0; // AN2
    TRISAbits.TRISA10 = 0; // AN3

    // Configure cathode pins as outputs
    TRISGbits.TRISG12 = 0; // CA
    TRISAbits.TRISA14 = 0; // CB
    TRISDbits.TRISD6 = 0; // CC
    TRISGbits.TRISG13 = 0; // CD
    TRISGbits.TRISG15 = 0; // CE
    TRISDbits.TRISD7 = 0; // CF
    TRISDbits.TRISD13 = 0; // CG
    TRISGbits.TRISG14 = 0; // DP = decimal point

    // Set all outputs high (inactive)
    LATBbits.LATB12 = 1;
    LATBbits.LATB13 = 1;
    LATAbits.LATA9 = 1;
    LATAbits.LATA10 = 1;
    LATGbits.LATG12 = 1;
    LATAbits.LATA14 = 1;
    LATDbits.LATD6 = 1;
    LATGbits.LATG13 = 1;
    LATGbits.LATG15 = 1;
    LATDbits.LATD7 = 1;
    LATDbits.LATD13 = 1;
    LATGbits.LATG14 = 1;
}

void setup_timer1() {
    T1CON = 0x0000; // Stop Timer1 and clear settings
    T1CONbits.TCKPS = 0; // Prescaler 1:1
    PR1 = 120000; // Set period register for 3ms
    TMR1 = 0; // Clear Timer1 count
    IPC1bits.T1IP = 5; // Set interrupt priority
    IFS0bits.T1IF = 0; // Clear interrupt flag
    IEC0bits.T1IE = 1; // Enable Timer1 interrupt
    T1CONbits.ON = 1; // Start Timer1
}

void setup_timer2() {
    T2CON = 0x0000; // Stop Timer2 and clear settings
    T2CONbits.TCKPS = 3; // Prescaler 1:8
    PR2 = 1000000; // Period register for 2-second interval
    TMR2 = 0; // Clear Timer2 count
    IPC2bits.T2IP = 4; // Set interrupt priority
    IFS0bits.T2IF = 0; // Clear Timer2 interrupt flag
    IEC0bits.T2IE = 1; // Enable Timer2 interrupt
    T2CONbits.ON = 1; // Start Timer2
}

void setup_switches_and_leds() {

    PORTA = 0xFF; // Turn all LEDs ON
    TRISA &= 0xFF00; // Set RA0-RA7 as outputs for LEDs

    //    LED
    TRISCbits.TRISC2 = 0; //RC2
    TRISCbits.TRISC1 = 0; //RC1
    TRISCbits.TRISC4 = 0; //RC4
    TRISGbits.TRISG6 = 0; //RG6
    ANSELGbits.ANSG6 = 0; //???????
    TRISCbits.TRISC3 = 1; //RC3
    CNPUCbits.CNPUC3;
    TRISGbits.TRISG7 = 1; //RG7
    ANSELGbits.ANSG7 = 0;
    CNPUGbits.CNPUG7;
    TRISGbits.TRISG8 = 1; //RG8
    ANSELGbits.ANSG8 = 0; //???????
    CNPUGbits.CNPUG8; //???
    TRISGbits.TRISG9 = 1; //RG9
    ANSELGbits.ANSG9 = 0; //???????
    CNPUGbits.CNPUG9; //?????

    //    RB14 - sound
    TRISBbits.TRISB14 = 0;
    ANSELBbits.ANSB14 = 0;

    // Configure switches (SW0?SW7) as inputs
    TRISFbits.TRISF3 = 1; // SW0
    TRISFbits.TRISF5 = 1; // SW1
    TRISFbits.TRISF4 = 1; // SW2
    TRISDbits.TRISD15 = 1; // SW3
    TRISDbits.TRISD14 = 1; // SW4
    TRISBbits.TRISB11 = 1; // SW5
    ANSELBbits.ANSB11 = 0; // Disable analog for SW5
    TRISBbits.TRISB10 = 1; // SW6
    ANSELBbits.ANSB10 = 0; // Disable analog for SW6
    TRISBbits.TRISB9 = 1; // SW7
    ANSELBbits.ANSB9 = 0; // Disable analog for SW7
}

void setup_LCD() {
    char control[] = {0x38, 0x38, 0x38, 0xe, 0x6, 0x1};

    TRISBbits.TRISB15 = 0; // RB15 (DISP_RS) set as an output
    ANSELBbits.ANSB15 = 0; // disable analog functionality on RB15 (DISP_RS)
    TRISDbits.TRISD5 = 0; // RD5 (DISP_RW) set as an output
    TRISDbits.TRISD4 = 0; // RD4 (DISP_EN) set as an output
    //TRISEbits.TRISE0 = 1; // RE0 (DB0) set as input (change 1 to 0 for
    TRISE &= 0xff00; //0 - output, E-LCD
    ANSELEbits.ANSE2 = 0;
    ANSELEbits.ANSE4 = 0;
    ANSELEbits.ANSE5 = 0;
    ANSELEbits.ANSE6 = 0;
    PORTBbits.RB15 = 0; //rs=0
    PORTDbits.RD5 = 0; //w=0
    ANSELEbits.ANSE7 = 0;

    for (int l = 0; l < sizeof (control); l++) {
        PORTE = control[l];
        send_pulse_to_LCD();
    }
}

void initialize_keyboard() {
    // Configure rows as outputs
    TRISCbits.TRISC2 = 0; // Row 0
    TRISCbits.TRISC1 = 0; // Row 1
    TRISCbits.TRISC4 = 0; // Row 2
    TRISGbits.TRISG6 = 0; // Row 3

    // Set all row outputs low initially
    LATCbits.LATC2 = 0;
    LATCbits.LATC1 = 0;
    LATCbits.LATC4 = 0;
    LATGbits.LATG6 = 0;

    // Configure columns as inputs
    TRISGbits.TRISG9 = 1; // Column 0
    TRISGbits.TRISG8 = 1; // Column 1
    TRISGbits.TRISG7 = 1; // Column 2
    TRISCbits.TRISC3 = 1; // Column 3

    // Enable pull-up resistors for columns
    CNPUGbits.CNPUG7 = 1;
    CNPUGbits.CNPUG8 = 1;
    CNPUGbits.CNPUG9 = 1;
}

void reset_LCD() {
    PORTBbits.RB15 = 0; // RS = 0 (Command mode)
    PORTDbits.RD5 = 0; // Write mode
    PORTE = 0x01; // Clear display command
    send_pulse_to_LCD();
}

void update_digit_in_seven_segment_display(uint8_t digit, uint8_t value) {
    //    Deactivate all digits - prevents overlap when displaying one digit to another in a multiplexed setup.
    LATBbits.LATB12 = 1; // units
    LATBbits.LATB13 = 1; // tens
    LATAbits.LATA9 = 1;// 0
    LATAbits.LATA10 = 1;// 0

    //    Output cathode pattern for the current digit
    LATGbits.LATG12 = !(digit_patterns[value] & 0b0000001); // CA
    LATAbits.LATA14 = !(digit_patterns[value] & 0b0000010); // CB
    LATDbits.LATD6 = !(digit_patterns[value] & 0b0000100); // CC
    LATGbits.LATG13 = !(digit_patterns[value] & 0b0001000); // CD
    LATGbits.LATG15 = !(digit_patterns[value] & 0b0010000); // CE
    LATDbits.LATD7 = !(digit_patterns[value] & 0b0100000); // CF
    LATDbits.LATD13 = !(digit_patterns[value] & 0b1000000); // CG

    //    Activate the current digit's anode
    switch (digit) {
        case 0: LATBbits.LATB12 = 0;
            break;
        case 1: LATBbits.LATB13 = 0;
            break;
        case 2: LATAbits.LATA9 = 0;
            break;
        case 3: LATAbits.LATA10 = 0;
            break;
    }
}

void decrement_time() {
    if (remaining_time > 0) {
        remaining_time--; // Decrement the time
    }

    //  Update digit values based on the decremented total seconds
    digit_values[0] = remaining_time % 10;
    digit_values[1] = (remaining_time / 10) % 10;
    
    if (remaining_time == 0) {
        write_to_LCD_upon_failier();
        return 1;
    }
}

void make_sound() {
    int i, j, k;

    // Generate a louder sound by adjusting the frequency
    for (i = 0; i < 400; i++) { // Increase the duration of the sound pulse
        PORTBbits.RB14 = 1; // Activate the sound pin
        for (j = 0; j < 900; j++); // Adjust the delay for a lower frequency
        PORTBbits.RB14 = 0; // Deactivate the sound pin
        for (k = 0; k < 900; k++); // Adjust the delay for a lower frequency
    }
}

void write_to_LCD(char msg[]) {//, int *position) {

    int i;

    reset_LCD();

    //     Write a static message to the first line
    char line1[] = "DEFUSE THE BOMB!";

    PORTBbits.RB15 = 1; // RS = 1 (Data mode for writing characters)
    PORTDbits.RD5 = 0; // RW = 0 (Write mode)

    for (i = 0; i < strlen(line1); i++) {
        PORTE = line1[i];
        send_pulse_to_LCD();
    }

    //     Set the cursor position for the second line
    PORTBbits.RB15 = 0; // RS = 0 (Command mode)
    PORTE = second_line_start_index;
    send_pulse_to_LCD();

    //     Write the user-entered code to the second line
    PORTBbits.RB15 = 1; // RS = 1 (Data mode for writing characters)

    for (i = 0; i < strlen(msg); i++) {
        PORTE = msg[i];
        send_pulse_to_LCD();
    }
}

void write_to_LCD_upon_failier() {

    int i;

    reset_LCD();

    //     Write a message to the first line
    char line1[] = "HAHA U'VE FAILED";

    PORTBbits.RB15 = 1; // RS = 1 (Data mode for writing characters)
    PORTDbits.RD5 = 0; // RW = 0 (Write mode)

    for (i = 0; i < strlen(line1); i++) {
        PORTE = line1[i];
        send_pulse_to_LCD();
    }

    // Set the cursor position for the second line
    PORTBbits.RB15 = 0; // RS = 0 (Command mode)
    PORTE = second_line_start_index;
    send_pulse_to_LCD();

    char msg[] = "EXPLOSION! BOOM!";

    //     Write the user-entered code to the second line
    PORTBbits.RB15 = 1; // RS = 1 (Data mode for writing characters)

    for (i = 0; i < strlen(msg); i++) {
        PORTE = msg[i];
        send_pulse_to_LCD();
    }
}

void write_to_LCD_upon_success(int *position) {

    int i;
    char line1[] = "    AWESOME!    "; //first line message
    char line2[] = "   SUCCESS!"; //second line message

    reset_LCD();

    PORTBbits.RB15 = 1; // RS = 1 (Data mode for writing characters)
    PORTDbits.RD5 = 0; // RW = 0 (Write mode)
    for (i = 0; i < strlen(line1); i++) {
        PORTE = line1[i];
        send_pulse_to_LCD();
    }

    // Set the cursor position for the second line
    PORTBbits.RB15 = 0; // RS = 0 (Command mode)
    PORTE = *position;
    send_pulse_to_LCD();


    PORTBbits.RB15 = 1; // RS = 1 (Data mode for writing characters)

    for (i = 0; i < strlen(line2); i++) {
        PORTE = line2[i];
        send_pulse_to_LCD();
    }

    if ((*position) < second_line_end_index - 3)
        (*position)++;
    else {
        (*position) = second_line_start_index;
    }
}

void send_pulse_to_LCD() {
    PORTDbits.RD4 = 1;
    PORTDbits.RD4 = 0;
    busy();
}

int get_pressed_key() {
    const int valueChanger[4] = {14, 13, 11, 7};
    const int valueMatrix[16] = {0xD, 0xC, 0xB, 0xA, 0xE, 9, 6, 3, 0xF, 8, 5, 2, 0, 7, 4, 1};
    for (int i = 0; i < 4; i++) {
        int x = valueChanger[i];
        PORTCbits.RC2 = (x & 0x1);
        PORTCbits.RC1 = (x & 0x2) >> 1;
        PORTCbits.RC4 = (x & 0x4) >> 2;
        PORTGbits.RG6 = (x & 0x8) >> 3;
        int y = (PORTGbits.RG9 << 3) | (PORTGbits.RG8 << 2) | (PORTGbits.RG7 << 1) | PORTCbits.RC3;
        for (int j = 0; j < 4; j++) {
            if (y == valueChanger[j]) {

                return valueMatrix[i * 4 + j];
            }
        }
    }
    return -1;
}

bool verify_code(int entered_code[]) {
    for (int i = 0; i < 4; i++) {
        if (entered_code[i] != correct_passcode[i]) {
            return false;
        }
    }
    return true;
}

void initRGBLED() {
    // Set directions of RGB LED pins (0 = output)
    TRISDbits.TRISD2 = 0; // Red LED pin
    TRISDbits.TRISD12 = 0; // Green LED pin
    TRISDbits.TRISD3 = 0; // Blue LED pin

    // Turn off all LEDs initially
    LATDbits.LATD2 = 0; // Red LED off
    LATDbits.LATD12 = 0; // Green LED off
    LATDbits.LATD3 = 0; // Blue LED off
}

void cycleColors() {
    int i;
    // Green LED on
    LATDbits.LATD12 = 1; // Green LED on
    LATDbits.LATD3 = 0; // Blue LED off
    LATDbits.LATD2 = 0; // Red LED off
    for (i = 0; i < 300000; i++);


    // Blue LED on
    LATDbits.LATD12 = 0; // Green LED off
    LATDbits.LATD3 = 1; // Blue LED on
    for (i = 0; i < 300000; i++);

    // Red LED on
    LATDbits.LATD12 = 0; // Green LED off
    LATDbits.LATD3 = 0; // Blue LED off
    LATDbits.LATD2 = 1; // Red LED on
    for (i = 0; i < 300000; i++);
}

void handle_success() {
    int cursor_pos = second_line_start_index;

    T1CONbits.ON = 0; // Stop Timer1
    T2CONbits.ON = 0; // Stop Timer2
    LATBbits.LATB14 = 0; // Stop ticking sound

    //        turn off 7-segment display
    LATBbits.LATB12 = 1;
    LATBbits.LATB13 = 1;
    LATAbits.LATA9 = 1;
    LATAbits.LATA10 = 1;

    reset_LCD();
    while (1) {
        //    write_to_LCD("SUCCESS!"); //, &cursor_position);
        write_to_LCD_upon_success(&cursor_pos);

        //    activate RGB
        initRGBLED(); // Initialize RGB LED
        cycleColors(); // Start cycling colors
    }
}

void handle_failure() {
    attempts = attempts - 1;
    char msg[17] = "";

    if (attempts == 0) {
        reset_LCD();
        write_to_LCD_upon_failier();
        T1CONbits.ON = 0; // Stop Timer1
        T2CONbits.ON = 0; // Stop Timer2
        LATBbits.LATB14 = 0; // Stop ticking sound

        //        turn off 7-segment display
        LATBbits.LATB12 = 1;
        LATBbits.LATB13 = 1;
        LATAbits.LATA9 = 1;
        LATAbits.LATA10 = 1;

        while (1); // infinite while loop to stop prog.

    } else {
        sprintf(msg, "Wrong! Left: %d/8", attempts);
        reset_LCD();
        update_LEDs();
        write_to_LCD(msg); //, &cursor_position);
    }
}

void update_LEDs() {
    switch (attempts) {
        case 0: led0 = 0;
            break;
        case 1: led1 = 0;
            break;
        case 2: led2 = 0;
            break;
        case 3: led3 = 0;
            break;
        case 4: led4 = 0;
            break;
        case 5: led5 = 0;
            break;
        case 6: led6 = 0;
            break;
        case 7: led7 = 0;
            break;
    }
}

void verify_code_no_switches() {
    bool verified = verify_code(code_from_user);

    if (verified) {
        handle_success();

    } else if (!verified) {
        handle_failure();
    }
}

//void check_switches_for_code_verification_and_modify_LEDs() {
//
//    bool verified = verify_code(code_from_user);
//
//    if (SW7 == 1) {
//
//        led7 = 0;
//
//        if (verified) {
//            handle_success();
//
//        } else if (!verified) {
//            handle_failure();
//        }
//
//    } else if (SW6 == 1) {
//
//        led6 = 0;
//
//        if (verified) {
//            handle_success();
//
//        } else if (!verified) {
//            handle_failure();
//        }
//
//    } else if (SW5 == 1) {
//
//        led5 = 0;
//
//        if (verified) {
//            handle_success();
//
//        } else if (!verified) {
//            handle_failure();
//        }
//
//    } else if (SW4 == 1) {
//
//        led4 = 0;
//
//        if (verified) {
//            handle_success();
//
//        } else if (!verified) {
//            handle_failure();
//        }
//
//    } else if (SW3 == 1) {
//
//        led3 = 0;
//
//        if (verified) {
//            handle_success();
//
//        } else if (!verified) {
//            handle_failure();
//        }
//
//    } else if (SW2 == 1) {
//
//        led2 = 0;
//
//        if (verified) {
//            handle_success();
//
//        } else if (!verified) {
//            handle_failure();
//        }
//
//    } else if (SW1 == 1) {
//
//        led1 = 0;
//
//        if (verified) {
//            handle_success();
//
//        } else if (!verified) {
//            handle_failure();
//        }
//
//    } else if (SW0 == 1) {
//
//        led0 = 0;
//
//        if (verified) {
//            handle_success();
//
//        } else if (!verified) {
//            handle_failure();
//        }
//    }
//}

void busy(void) {
    char RD, RS;
    int STATUS_TRISE;
    int portMap;
    RD = PORTDbits.RD5;
    RS = PORTBbits.RB15;
    STATUS_TRISE = TRISE;
    PORTDbits.RD5 = 1; //w/r
    PORTBbits.RB15 = 0; //rs
    portMap = TRISE;
    portMap |= 0x80;
    TRISE = portMap;
    do {
        PORTDbits.RD4 = 1; //enable=1
        PORTDbits.RD4 = 0; //enable=0
    } while (PORTEbits.RE7); // BF ?????
    PORTDbits.RD5 = RD;
    PORTBbits.RB15 = RS;
    TRISE = STATUS_TRISE;
}

void __ISR(_TIMER_1_VECTOR, IPL5SOFT) Timer1Handler(void) {
    static uint16_t refresh_count = 0;

    update_digit_in_seven_segment_display(current_digit, digit_values[current_digit]);
    current_digit = (current_digit + 1) % 4;

    refresh_count++;

    if (refresh_count >= 1000) { // 1-second intervals
        refresh_count = 0;
        decrement_time();
    }
    IFS0bits.T1IF = 0; // Clear Timer1 interrupt flag
}

void __ISR(_TIMER_2_VECTOR, IPL4SOFT) Timer2Handler(void) {

    //    delay_factor = num*1000 to make it easier to read. 300*1000 instead of 300000.
    if (remaining_time > 50) {
        delay_factor = 300 * 1000; // 2 seconds
    } else if (remaining_time > 40) {
        delay_factor = 250 * 1000; // 1.7 seconds
    } else if (remaining_time > 30) {
        delay_factor = 200 * 1000; // 1.4 seconds
    } else if (remaining_time > 20) {
        delay_factor = 150 * 1000; // 1.1 seconds
    } else if (remaining_time > 10) {
        delay_factor = 100 * 1000; // 0.8 seconds
    } else if (remaining_time > 3) {
        delay_factor = 70 * 1000; // 0.3 seconds
    } else if (remaining_time > 0) {
        delay_factor = 20 * 1000; // 0.03 seconds
    } else {
        delay_factor = 0;
    }

    // Toggle the tick state and set should_play_sound accordingly
    should_play_sound = !should_play_sound;

    // Clear Timer2 interrupt flag
    IFS0bits.T2IF = 0;
}

void delay() {
    // Stop Timers
    T4CONbits.ON = 0;
    T5CONbits.ON = 0;

    // Configure Timer2 and Timer3 in 32-bit mode
    T4CONbits.T32 = 1; // Enable 32-bit Timer mode
    T4CONbits.TCS = 0; // Select internal clock (PBCLK)
    T4CONbits.TGATE = 0; // Disable gated timer mode
    T4CONbits.TCKPS = 0b111; // Prescaler 1:256 for slower clock.

    // Split delay_factor into PR2 (lower 16 bits) and PR3 (upper 16 bits)
    PR4 = (delay_factor & 0xFFFF); // Lower 16 bits
    PR5 = (delay_factor >> 16); // Upper 16 bits

    // Reset Timer Counters
    TMR4 = 0;
    TMR5 = 0;
    
    // Clear Interrupt Flags
    IFS0bits.T4IF = 0;
    IFS0bits.T5IF = 0;

    // Start the Timer
    T4CONbits.ON = 1;
    T5CONbits.ON = 1;

    while (!IFS0bits.T5IF);

    // Stop the Timer
    T4CONbits.ON = 0;
    T5CONbits.ON = 0;
}

void process_key(int key) {

    //     Check if the input position is less than the size of the array
    if (input_position < 4) {

        //         Store the key in the code_from_user array at the current position
        code_from_user[input_position++] = key;

        //         Display the current set of digits
        char display_message[20];
        sprintf(display_message, "Enter Code:");

        for (int i = 0; i < input_position; i++) {
            char digit[2];
            sprintf(digit, "%d", code_from_user[i]);
            strcat(display_message, digit);
        }

        write_to_LCD(display_message); //, &cursor_position);

        //        check_switches_for_code_verification_and_modify_LEDs();

        //         If four digits have been entered, verify the code or take another action
        if (input_position == 4) {
            verify_code_no_switches();
            input_position = 0; // Reset for next input sequence
        }
    }
}

int main(void) {

    setup_and_init_system();

    //    Enable interrupts
    INTCONbits.MVEC = 1; // Multi-vector interrupts
    IPTMR = 0;
    asm("ei");

    //    calculate the number of seconds left on the 7-segment display timer
    remaining_time = digit_values[1] * 10 + digit_values[0];

    char msg[13] = {"Enter Code:"};
    write_to_LCD(msg); //, &cursor_position);

    int key = -1;

    while (1) {

        if (should_play_sound == 1) {
            make_sound(); // Generate the sound pulse
            delay(delay_factor); // Pause before the next pulse
            should_play_sound = 0;
        }

        key = get_pressed_key();

        if (key != -1) {
            process_key(key);
        }

        key = -1;


    }
    return 1;
}