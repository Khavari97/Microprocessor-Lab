#include <avr/io.h>
#include <avr/delay.h>

int main() {
    DDRA = 0xFF;
    PORTA = 0;
    while (true)
    {
        PORTA = 0xFF;
        _delay_ms(200);
        PORTA = 0;
         _delay_ms(200);
    }
    
}