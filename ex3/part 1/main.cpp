#include <avr/io.h>
#include <avr/delay.h>


int i = 0;
int numbers[10] = {0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b100000010,0b11111000,0b10000000,0b10010000};

int main() {

    while (1)
    {
       // PORTA = 0;
        DDRD = 0xFF;

        if (PINA == 1)
        {
            for(i = 0 ; i < 10 ; i++){
                PORTD = numbers[i];
                _delay_ms(100);
            }
            
        } else {
             return 0;


        }
        
        
    }
    
    
}