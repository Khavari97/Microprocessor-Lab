#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"
#include <stdio.h>



int main(){

	DDRB=0xFF;              
	DDRA=0; 							       
	ADCSRA = 0x87;									
	ADMUX = 0x40;                      
	
	char Buffer[16];
    int T = 0; 
      lcd_init();    
      //lcd_clear();
	

	while (true){

            ADCSRA = (1 << ADEN) | (0 << ADSC) | (1 << ADATE) | (0 << ADIF) | (0 << ADIE) | (1 << ADPS2) | (0 << ADPS1) | (0 << ADPS0);
	        SFIOR = (0 << ADTS2) | (0 << ADTS1) | (0 << ADTS0);

            while ((ADCSRA & (1 << ADIF)) == 0); 
	              ADCSRA |= (1 << ADIF); 
	
	
		T = (int)(ADCW/2.05) ; 
		sprintf(Buffer,"temp is = %d C",T);
		lcd_string_signed(Buffer);
		_delay_ms(100);
      }

	return 0;
}