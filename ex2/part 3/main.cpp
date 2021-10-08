#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 1000000UL

int main() {
  
      while (true)
    {
        if(PINA & (1<<PA0) ==1) {
        PORTB = 0b10000000;
       _delay_ms(50);
       PORTB = 0b11000000;
       _delay_ms(50);
       PORTB =0b01000000;
       _delay_ms(50);
       PORTB = 0b01100000;
       _delay_ms(50);
       PORTB = 0b00100000;
       _delay_ms(50);
       PORTB = 0b00110000;
       _delay_ms(50);
       PORTB = 0b00010000;
       _delay_ms(50);
       PORTB = 0b00011000;
       _delay_ms(50);
       PORTB = 0b00001000;
       _delay_ms(50);
       PORTB = 0b00001100;
       _delay_ms(50);
       PORTB = 0b00000100;
       _delay_ms(50);
       PORTB = 0b00000110;
       _delay_ms(50);
       PORTB = 0b00000010;
       _delay_ms(50);
       PORTB = 0b00000011;
       _delay_ms(50);
       PORTB = 0b00000001;
       _delay_ms(50);
       PORTB = 0b00000011;
       _delay_ms(50);
       PORTB = 0b00000010;
       _delay_ms(50);
       PORTB = 0b00000110;
       _delay_ms(50);
       PORTB = 0b00000100;
       _delay_ms(50);
       PORTB = 0b00001100;
       _delay_ms(50);
       PORTB = 0b00001000;
       _delay_ms(50);
       PORTB = 0b00011000;
       _delay_ms(50);
       PORTB = 0b00010000;
       _delay_ms(50);
       PORTB = 0b00110000;
       _delay_ms(50);
       PORTB = 0b00100000;
       _delay_ms(50);
       PORTB = 0b01100000;
       _delay_ms(50);
       PORTB = 0b01000000;
       _delay_ms(50);
       PORTB = 0b11000000;
       _delay_ms(50);
       PORTB = 0b10000000;
       _delay_ms(50);

        }

    }
   

}