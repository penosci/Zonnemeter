/* 
 * File:   opdracht 3.c
 * Author: joran
 *
 * Created on March 8, 2018, 5:03 PM
 */

#define __18F25K80
#include "xc.h"
#include "fuses.h"
#include <stdio.h>
#define _XTAL_FREQ 8000000  // X-tal = 8 MHz

int getal = 100;
void putch(char c) //putch functie moet aangepast worden om de string naar de TXREG te sturen
{
        while(TXSTA1bits.TRMT == 0);
        TXREG1 = c;
}

void main(void)
{
    PIE3bits.RC2IE = 0; //interrrups op 0
    PIE3bits.TX2IE = 0;
    PIE1bits.RC1IE = 0;
    PIE1bits.TX1IE = 0;
   
    TXSTA1 = 0b10100000; //Transmit status & control register
    RCSTA1 = 0b10000000; //Recieve status & control register
    BAUDCON1 = 11000000; //Baud rate control register
    SPBRG1 = 51; //Transmissie snelheid
 
    
    while(1){
        getal = getal++;
        if(getal == 100){
            getal = 0;
        }
        printf("%d",getal);
        __delay_ms(90);
    }
   
}

