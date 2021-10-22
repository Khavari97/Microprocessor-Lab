#include <avr/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "LCD.h"
#include <avr/mega16a.h>
#include <util/atomic.h>

    unsigned long int c;
    unsigned char hour,minute,second;
    char buffer[17];
    
    ISR(TIMER1_OVF_vect){
     TCNT1H=0xBDC >> 8;
     TCNT1L=0xBDC & 0xff;
     c++;
    }   
    
    void calc_time(){
      //default time
       unsigned long int h1=0,m1=0,s1=0;
       s1=c%60;
        m1=c/60; 
        h1=m1/60;
        m1=m1%60;
       hour=h1; minute=m1; second=s1;
    }
    
    void display(){
      calc_time();
      lcd_init(); 
      lcd_clear();
      sprintf(buffer,"%02d:%02d:%02d\n ALARM:",hour,minute,second);
      lcd_string_signed(buffer);
    }
    
    void main(void){
      PORTA=0x00;
      DDRA=0x01;
      
      
        TCCR1A=0x00;
        TCCR1B=0x03;
        TCNT1H=0x0B;
        TCNT1L=0xDC;
        ICR1H=0x00;
        ICR1L=0x00;
        OCR1AH=0x00;
        OCR1AL=0x00;
        OCR1BH=0x00;
        OCR1BL=0x00;  
        
        // Timer(s)/Counter(s) Interrupt(s) initialization
        TIMSK=0x04;
        sei();

        while (1){
         display();
      
        }
    }