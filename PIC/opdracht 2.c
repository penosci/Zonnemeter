/*
 * File:   opdracht 2.c
 * Author: joran
 *
 * Created on March 8, 2018, 12:05 PM
 */

#define __18F25K80
#include "xc.h"
#include "fuses.h"
#include <stdio.h>

#define _XTAL_FREQ 8000000  // X-tal = 8 MHz
#define true 1
#define false 0
#define knoptrue 0
#define knopfalse 1
#define button1 PORTBbits.RB0 //defineer de buttons en leds met een naam
#define button2 PORTBbits.RB1
#define geel LATCbits.LATC7
#define groen1 LATCbits.LATC4
#define groen2 LATCbits.LATC5

char eersteknop1 = false; //defineer de knoppen met een waarde
char eersteknop2 = false;
char ledon = false;

void main(void){
    TRISB = 0x03; //defineer de B pins als inputs
    TRISC = 0x00; //defineer leds als output
    ANCON1 = 0x00; //defineer pins als digitaal
    groen1 = false;
    groen2 = false;
    geel = false;

    while(1){
        if(button1 == knoptrue){
            if(eersteknop2 == false){
                eersteknop1 = true;
                ledon = true;
            }
            if(eersteknop2 == true){
                eersteknop1 = false;
                eersteknop2 = false;
                ledon = false;
                __delay_ms(90);
            }


        }
        if(button2 == knoptrue){
            if(eersteknop1 == false){
                eersteknop2 = true;
                ledon = true;
            }
            if(eersteknop1 == true){
                eersteknop1 = false;
                eersteknop2 = false;
                ledon = false;
                __delay_ms(90);
            }

        }
      if(ledon == true){
            groen1 = true;
            __delay_ms(90);
            groen1 = false;
            groen2 = true;
            __delay_ms(90);
            groen2 = false;
            geel = true;
             __delay_ms(90);
            geel = false;
        }
       /* if(button1 == knopfalse && button2 == knopfalse){
            eersteknop1 = false;
            eersteknop2 = false;
        }*/
    }




}