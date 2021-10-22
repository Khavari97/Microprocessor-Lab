#include <avr/io.h>
#include <avr/LCD.h>
#include <avr/delay.h>



int main() {
   
    DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
    PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
    lcd_init();

while (1)
      {
       lcd_clear();
       lcd_gotoxy(0,0);
       lcd_string_signed("Zahra Khavari");
       lcd_gotoxy(0,1);
       lcd_string_signed("Hello World");
       _delay_ms(500);
              
      }
    
    
    



   
}