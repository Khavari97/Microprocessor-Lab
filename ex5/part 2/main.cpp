#include <avr/io.h>
#include <util/delay.h>


int main() {
//1 8 3 5 1
        int round[5] = {0X01,0X08,0X02,0X04,0X01};

        if((0>>PC2)==0){
                DDRA=0X0F;
        PORTA=0X01;    //1
        _delay_ms(50);
        PORTA=0X08;     //8
        _delay_ms(50);
         PORTA=0X02;     //3
        _delay_ms(50);
        PORTA=0X04;    //5
        _delay_ms(50);
        PORTA=0X01;    //1
        _delay_ms(50);
        }
   
}