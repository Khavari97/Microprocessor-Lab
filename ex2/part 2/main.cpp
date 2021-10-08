#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 1000000UL

int main() {

    DDRB = 0xFF;
    PORTB = 0;
    while (true)
    {
        PORTB = 0xFF;
        _delay_ms(50);
        PORTB = 0;
         _delay_ms(50);
    }
}