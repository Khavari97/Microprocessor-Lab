#include <avr/io.h>     
#include <util/delay.h> 
#include <avr/interrupt.h>


int direction[5] = {0x01, 0x04, 0x02, 0x08,0x01};

int main(){
        
    DDRA = 0x0f; 
    PORTA = 0x00;
   
    sei();

    while (true)
    {
        PORTC |= 0x04;
        if (PINC == 0)
        {
            TCCR0 = 0x05;
            TIMSK = 0x01;
        }
    }
    return 0;
}

int num = 0;
ISR(TIMER0_OVF_vect){
   
    num++;
    if (num > 4)
        num = 0;
        PORTA = direction[num];
   
}

