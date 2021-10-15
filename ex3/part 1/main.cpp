#include <avr/io.h>
#include <avr/delay.h>

int i = 0;
// for anod 0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b100000010,0b11111000,0b10000000,0b10010000
// 0-9 binary (catod)
int numbers[10] = { 0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b011111101,0b00000111,0b01111111,0b01101111};
                  
int main() {

        PA0 == 0; 
        DDRD = 0xFF;

        if (PINA ==1)
        {
            for(i = 0 ; i < 10 ; i++){
                PORTD = numbers[i];
                _delay_ms(50);
            }
            
        }

}