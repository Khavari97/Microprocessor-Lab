#include <avr/io.h>
#include <avr/delay.h>
#include <util/atomic.h>

int main() 
{
    TIMSK = 0b00000100;
    TCCR1B = 0b0000010;
    DDRD = 0xff;
    DDRC = 0xff;
    sei();
    PORTA = 0;
    PORTD = 0;

    while (true)
    {
        
    }
    
    return 0;
}
//  0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b100000010,0b11111000,0b10000000,0b10010000
int numbers = 0;
ISR(TIMER1_OVF_vect){
    PA0 ==0;
       if(PINA == 1){
            numbers = (numbers + 1) % 10;
    switch(numbers){
        case 0:
            PORTD = 0b0111111;
            break;
        case 1:
            PORTD = 0b0000110;
            break;
        case 2:
            PORTD = 0b1011011;
            break;
        case 3:
            PORTD = 0b1001111;
            break;
        case 4:
            PORTD = 0b1100110;
            break;
        case 5:
            PORTD = 0b1101101;
            break;
        case 6:
            PORTD = 0b1111101;
            break;
        case 7:
            PORTD = 0b0000111;
            break;
        case 8:
            PORTD = 0b1111111;
            break;
        case 9:
            PORTD = 0b1101111;
            break;
        default:
            PORTD = 0xFF;
    }
       }
}


