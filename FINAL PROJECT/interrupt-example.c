///* 
// * File:  INTERRUPT_timer4.c
// * Author: MenachemE
// *
// * Created on July 17, 2019, 2:20 PM
// */
////#include <xc.h>
//#pragma config JTAGEN = OFF     
//#pragma config FWDTEN = OFF
//#pragma config FNOSC =	FRCPLL
//#pragma config FSOSCEN =	OFF
//#pragma config POSCMOD =	EC
//#pragma config OSCIOFNC =	ON
//#pragma config FPBDIV =     DIV_1
//#pragma config FPLLIDIV =	DIV_2
//#pragma config FPLLMUL =	MUL_20
//#pragma config FPLLODIV =	DIV_1
////#include "timer.h"
//#include <xc.h>  
//#include <sys/attribs.h>
//#include <string.h>
//#include <stdlib.h>
//
//void __ISR(_TIMER_4_VECTOR, ipl2auto) Timer4SR(void);
//
//void __ISR(_TIMER_4_VECTOR, ipl2) Timer4SR(void) {
//
//    PORTA++;
//    IFS0bits.T4IF = 0;
//}
//
//void main() {
//    int j;
//    TRISA &= 0xff00;
//    PR4 = 0xffff; //             set period register, generates one interrupt every 1 ms
//    TMR4 = 0; //             initialize count to 0
//
//    T4CONbits.TCKPS0 = 1; //            1:256 prescale value
//    T4CONbits.TCKPS1 = 1;
//    T4CONbits.TCKPS2 = 1;
//    T4CONbits.TGATE = 0; //             not gated input (the default)
//    T4CONbits.TCS = 0; //             PCBLK input (the default)
//    T4CONbits.ON = 1; //             turn on Timer1
//    IPC4bits.T4IP = 2; //             priority
//    IPC4bits.T4IS = 0; //             subpriority
//    IFS0bits.T4IF = 0; //             clear interrupt flag
//    IEC0bits.T4IE = 1;
//    INTCONbits.MVEC = 1; //vector interrupt
//    IPTMR = 0; //INTERRUPT PROXIMITY TIMER REGISTER
//    asm("ei"); //on interrupt  --> assembly comman to enable interrupt
//
//    while (1);
//}


////////  2

#include "bomboklat_header.h"

void __ISR(_TIMER_4_VECTOR, ipl7auto) Timer4SR(void);

void __ISR(_TIMER_4_VECTOR, ipl7) Timer4SR(void) {
    PORTAbits.RA0 ^= 1;
    IFS0bits.T4IF = 0;
}

void __ISR(_TIMER_3_VECTOR, ipl6auto) Timer23SR(void);

void __ISR(_TIMER_3_VECTOR, ipl6) Timer23SR(void) {
    PORTAbits.RA1 ^= 1; //sw0
    IFS0bits.T3IF = 0;
}

//void main() {
//    int j; 
//    TRISA &= 0xff00;
//    PR4 = 0xffff; //             set period register, generates one interrupt every 1 ms
//    TMR4 = 0; //             initialize count to 0
//    T4CONbits.TCKPS0 = 1; //            1:256 prescale value
//    T4CONbits.TCKPS1 = 1;
//    T4CONbits.TCKPS2 = 1;
//    T4CONbits.TGATE = 0; //             not gated input (the default)
//    T4CONbits.TCS = 0; //             PCBLK input (the default)
//    T4CONbits.ON = 1; //             turn on Timer1
//    IPC4bits.T4IP = 7; //             priority
//    IPC4bits.T4IS = 3; //             subpriority
//    IFS0bits.T4IF = 0; //             clear interrupt flag
//    IEC0bits.T4IE = 1;
//    T2CONbits.TGATE = 0;
//    T2CONbits.TCS = 0;
//    T2CONbits.T32 = 1; //mode 32bit
//    T2CONbits.TCKPS0 = 1; //????? 256
//    T2CONbits.TCKPS1 = 1;
//    T2CONbits.TCKPS2 = 1;
//    T3CONbits.ON = 0;
//    TMR3 = 0; //TMRy
//    TMR2 = 0; //TMRx
//    PR2 = 0Xffff; //PR2x
//    PR3 = 0x3; //PR2y
//    T2CONbits.ON = 1; //start timer
//    IFS0bits.T3IF = 0; //
//    IPC3bits.T3IP = 6; //             priority
//    IPC3bits.T3IS = 0; //             subpriority
//    IFS0bits.T3IF = 0; //             clear interrupt flag
//    IEC0bits.T3IE = 1;
//    INTCONbits.MVEC = 1; //vector interrupt
//    IPTMR = 0; //INTERRUPT PROXIMITY TIMER REGISTER
//    asm("ei"); //on interrupt
//    while (1);
//}
