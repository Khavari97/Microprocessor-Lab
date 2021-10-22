#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/mega16a.h>
#include <stdio.h>
#include "LCD.h"
#include <util/atomic.h>
 
unsigned char Buffer[17];
unsigned char second = 30;
unsigned char minute = 20;
unsigned char hour = 10;
 
    void time_write(){
    sprintf(Buffer,"%02d:%02d:%02d",hour,minute,second);
    lcd_gotoxy(4,0);
    lcd_string_signed(Buffer);
  
    
    }
 
int main() {
///block 1
lcd_init();
lcd_clear();
///block 2
TIMSK = 0x40;
TIFR = 0x40;
sei();
////block 3
ASSR = 0x08;
TCNT2 = 0x00;
TCCR2 = 0x05;
///block 4
time_write();
lcd_gotoxy(3,1);
lcd_string_signed("Start Time");
while(1);
}
 
    ISR(TIMER2_COMP_vect){
    second++;
        if(second==60){
        second = 0;
        minute++;
            if(minute==60){
            minute = 0;
            hour++;
            if(hour==24) hour = 0;
            }    
        }
    time_write();
    }