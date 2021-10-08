#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 1000000UL

int main() {

    DDRA = 0xFF;
    PORTA = 0;
    while (true)
    {
        PORTA = 0xFF;
        _delay_ms(500);
        PORTA = 0;
         _delay_ms(500);
    }
}