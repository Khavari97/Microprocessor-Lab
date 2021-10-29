#include <avr/io.h>
#include <util/delay.h>


int main() {   

    
        DDRA=0X0F;
        PORTA=0X01;    //1
        _delay_ms(50);
        PORTA=0X04;    //5
        _delay_ms(50);
        PORTA=0X02;     //3
        _delay_ms(50);
        PORTA=0X08;     //8
        _delay_ms(50);
        PORTA=0X01;    //1
        _delay_ms(50);
   


}