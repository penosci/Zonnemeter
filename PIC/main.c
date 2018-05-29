//kaas
#define __18F25K80
#include "xc.h"
#include "fuses.h"
#include <stdio.h>
#include "booleantype.h"
#define _XTAL_FREQ 8000000  // X-tal = 8 MHz
#define varible_amount 10 //aantal getallen die in array komen
bool Inter = false;
int _Analog_Digital_convertor(int);

void putch (char c){
    while(TXSTA1bits.TRMT== 0);
    TXREG = c;

}
void interrupt myIsr(void){
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF){
        TMR0H = 0xB; //begin offset
        TMR0L = 0xDC;// eind offset
        Inter = true; //interupt flag
        INTCONbits.TMR0IF = 0; //interupt afgehandeld
    }
}

int main(void)
{
    unsigned int value1;//value aanmaken, dan de registers
    unsigned int value2;
    int array_counter = 0;
    int value1_array[varible_amount];
    int value2_array[varible_amount];

    TXSTA1 = 0b10100000; //Transmit status & control register
    RCSTA1 = 0b10000000; //Recieve status & control register
    BAUDCON1 = 0b11000000; //Baud rate control register
    SPBRG1 = 51; //Transmissie snelheid

    TRISC = 0b00000000; // PORTC input of output maken
    LATC = 0b0000000; //
    T0CON = 0b10000100; //Timer 0 configureren
    INTCON2bits.TMR0IP = 1; // prioritijd voor interupt zetten
    INTCONbits.TMR0IE = 1; // zet overflow interupt aan
    ei();
    printf("check::%d",(varible_amount-1));
    while(1) {
        if (Inter == true){
           //value1 =
           //value2 =
           value1_array[array_counter] = _Analog_Digital_convertor(0b00000111); // an1
           value2_array[array_counter] = _Analog_Digital_convertor(0b00100111); // an9
           if (array_counter==varible_amount){ // 
               for (int i =1; i<varible_amount; i++){
                   value1 += value1_array[i];
                   value2 += value2_array[i];
               }
               value1 /= varible_amount;
               value1 /= varible_amount;
               printf("%d,%d\n\r",value1, value2);
               array_counter = 0;
           }
           ++array_counter;
           Inter=false;
        }
    }
}
int _Analog_Digital_convertor(int adcon1settings)//de uitleescode
      {

      ADCON0 = adcon1settings;//selected an1, go/done on, a/d on, 00100111 voor an9
      ADCON1 = 0b00110000;//eccp1 trigger, internal vref 4.1, vref- avss, avss negative
      ADCON2 = 0b10000110;//laatste 3 bits zijn a/d clock bits op fosc/16, right justified want adresh smaller than 8 adresl full, adres, niks, a/d 0 tad
//hier
        while( ADCON0bits.GODONE == 1);
        return ADRESH<<8|ADRESL;//adresh 2-4 bits, adresl full 8 bits, want right-justified


      }

