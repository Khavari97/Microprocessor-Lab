#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"
#include <stdio.h>

int read_adc(char adc_input)
{
    ADMUX=adc_input;
    _delay_ms(10);
    ADCSRA|=0x40;
    while ((ADCSRA & 0x10)==0);
    ADCSRA|=0x10;
    return ADCW;
}

int main(){

	DDRB=0xFF;              
	DDRA=0; 							       
	ADCSRA = 0x87;									
	ADMUX = 0x40;  
    lcd_init();
    PORTB=0x00;
    TCCR0=0x6B;
    TCNT0=0x00;
    OCR0=0x00;                    
	
	char Buffer[16];
	int T = 0;

	int up , down ;



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