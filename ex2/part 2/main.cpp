#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>


int main() {

    DDRB = 0xFF;
    
    while (1)
    {
        if(PINA & (1<<PA0)== 1){
            PORTB = 0xFF;
            _delay_ms(500);
            PORTB = 0;
            _delay_ms(500);
        
        } else {
            PORTB = 0;
        }
    }
    return 0;
}