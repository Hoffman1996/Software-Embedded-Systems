//#include <xc.h>
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
//
//void delay();
//
////void main() {
////    int j;
////    TRISA &= 0xff00;
////    while (1) {
////        PORTA++;
//////        for(j=0;j<64000;j++);
////        delay();
////    }
////}
//
//void delay(void) {
//    T1CONbits.ON = 0;
//    T1CONbits.TGATE = 0;
//    T1CONbits.TCS = 0; //in clock --> when its 1 
//    T1CONbits.TCKPS0 = 1;
//    T1CONbits.TCKPS1 = 1;
//    T1CONbits.TSYNC = 1;
//    TMR1 = 0;
//    PR1 = 0X04FF;
//    T1CONbits.ON = 1;
//    IFS0bits.T1IF = 0;
//    while (!IFS0bits.T1IF);
//}
//
////void delay(void) {
////    T2CONbits.ON = 0;
////    T2CONbits.TGATE = 0;
////    T2CONbits.TCS = 0;
////    T2CONbits.T32 = 1; //mode 32bit
////    T2CONbits.TCKPS0 = 1; //????? 256
////    T2CONbits.TCKPS1 = 1;
////    T2CONbits.TCKPS2 = 1;
////    T3CONbits.ON = 0;
////    TMR3 = 0; //TMRy
////    TMR2 = 0; //TMRx
////    PR2 = 0X5000; //PR2x
////    PR3 = 0; //PR2y
////    T2CONbits.ON = 1; //start timer
////    IFS0bits.T2IF = 0;
////    IFS0bits.T3IF = 0; //
////    while (!IFS0bits.T3IF); //timer stop
////}
//
