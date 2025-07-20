#include <stdint.h>
#include <xc.h>
#include <sys/attribs.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <p32xxxx.h>
#include <stdbool.h>

#pragma config JTAGEN = OFF       // Disable JTAG to free up pins
#pragma config FWDTEN = OFF       // Disable Watchdog Timer
#pragma config FNOSC = FRCPLL     // Select Fast RC Oscillator with PLL
#pragma config FSOSCEN = OFF      // Disable Secondary Oscillator
#pragma config POSCMOD = HS       // High-Speed Crystal Oscillator mode
#pragma config OSCIOFNC = OFF     // Disable clock output on OSCO pin
#pragma config FPBDIV = DIV_2     // Peripheral Bus Clock = System Clock / 2
#pragma config FPLLIDIV = DIV_2   // Divide input clock by 2 before PLL
#pragma config FPLLMUL = MUL_20   // Multiply PLL input clock by 20
#pragma config FPLLODIV = DIV_1   // Divide PLL output by 1

//  LCD CONSTANTS
#define SECOND_LINE_START_INDEX 0xc0
#define SECOND_LINE_END_INDEX 0xc5

//  Switches
#define SW0 PORTFbits.RF3
#define SW1 PORTFbits.RF5
#define SW2 PORTFbits.RF4
#define SW3 PORTDbits.RD15
#define SW4 PORTDbits.RD14
#define SW5 PORTBbits.RB11
#define SW6 PORTBbits.RB10
#define SW7 PORTBbits.RB9

//  LEDs
#define led0 LATAbits.LATA0
#define led1 LATAbits.LATA1
#define led2 LATAbits.LATA2
#define led3 LATAbits.LATA3
#define led4 LATAbits.LATA4
#define led5 LATAbits.LATA5
#define led6 LATAbits.LATA6
#define led7 LATAbits.LATA7

//  Constants
const uint8_t digit_patterns[10] = {
    0b0111111, // 0
    0b0000110, // 1
    0b1011011, // 2
    0b1001111, // 3
    0b1100110, // 4
    0b1101101, // 5
    0b1111101, // 6
    0b0000111, // 7
    0b1111111, // 8
    0b1101111 // 9
};
const int correct_passcode[4] = {1, 2, 9, 6};

//  Global variables
uint32_t delay_factor = 0;
uint16_t remaining_time;
uint8_t should_play_sound = 0;
uint8_t current_digit = 0; // Current digit for 7-segment multiplexing
uint8_t digit_values[4] = {9, 1, 0, 0}; // Initial 59-second countdown
uint8_t attempts = 8; // Remaining attempts (linked to switches/LEDs)
int code_from_user[4] = {'\0'};
int input_position = 0;
int second_line_start_index = SECOND_LINE_START_INDEX;
int second_line_end_index = SECOND_LINE_END_INDEX;

//  FunctionS Declarations
void setup_and_init_system();

void setup_pins_for_seven_segment_display();

void setup_timer1();

void setup_timer2();

void setup_switches_and_leds();

void setup_LCD();

void initialize_keyboard();

void reset_LCD();

void update_digit_in_seven_segment_display(uint8_t digit, uint8_t value);

void decrement_time();

void make_sound();

void write_to_LCD(char msg[]);

void write_to_LCD_upon_failier();

void send_pulse_to_LCD();

int get_pressed_key();

bool verify_code(int entered_code[]);

void initRGBLED();

void cycleColors();

void handle_success();

void handle_failure();

void update_LEDs();

void verify_code_no_switches();

//void check_switches_for_code_verification_and_modify_LEDs();

void busy(void);

void __ISR(_TIMER_1_VECTOR, IPL5SOFT) Timer1Handler(void);

void __ISR(_TIMER_2_VECTOR, IPL4SOFT) Timer2Handler(void);

void delay();

void process_key(int key);