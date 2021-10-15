#include <avr/io.h>
#include <avr/delay.h>

int i = 0;
int numbers[10] = { 0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b011111101,0b00000111,0b01111111,0b01101111};
                  
int main() {

        PA0 == 0 ;
        DDRD = 0xFF;

        if (PINA ==1)
        {
            for(i = 0 ; i < 10 ; i++){
                PORTD = numbers[i];
                _delay_ms(70);
            }
            
        }

}