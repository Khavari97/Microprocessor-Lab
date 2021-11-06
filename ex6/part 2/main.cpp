#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"
#include <stdio.h>
#include <string.h>
#define degree_sysmbol 0xdf


void adcInit(){										
	ADCSRA = (1 << ADEN) | (0 << ADSC) | (1 << ADATE) | (0 << ADIF) | (0 << ADIE) | (1 << ADPS2) | (0 << ADPS1) | (0 << ADPS0);
	SFIOR = (0 << ADTS2) | (0 << ADTS1) | (0 << ADTS0);
}

int adcSet(char ch){
	ADMUX = (0 << REFS1) | (1 << REFS0) | (0 << ADLAR) ;

	_delay_ms(10);
	ADCSRA |= (1 << ADSC);

	while ((ADCSRA & (1 << ADIF)) == 0);
	ADCSRA |= (1 << ADIF);
	return ADCW;
}

int main(){
	char Buffer[16];
	LCD_Init();
	adcInit();
    float cel;

	DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
    PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

	while(1){
		
	   LCD_String_xy(0,0,"Temperature: ");
	   cel = (adcSet(0)*4.88);
	   cel = (cel/10.00);
	   sprintf(Buffer,"%d%cC  ", (int)cel, degree_sysmbol);
	   LCD_String_xy(1,0,Buffer);

	   if(cel <=30){
          PORTD = 0;            
      } else {
		  PORTD = 1;
	  }
	   	
	}
}