#include <avr/io.h>
#include <avr/delay.h>
#include "LCD.h"
#include <stdio.h>

int get_key(void){  
DDRB=0b00000000;
PORTB=0b00001111;

DDRB=0b00010000; 
if(PINB0==0)return 1;
if(PINB1==0)return 4;
if(PINB2==0)return 7;
if(PINB3==0)return 10;

DDRB=0b00100000;
if(PINB0==0)return 2;
if(PINB1==0)return 5;
if(PINB2==0)return 8;
if(PINB3==0)return 0;

DDRB=0b01000000;
if(PINB0==0)return 3;
if(PINB1==0)return 6;
if(PINB2==0)return 9;
if(PINB3==0)return 11;

return 255;
}


 int user = 0;
 int pass =0;
int main()
{
char buff[16];
int key ;
LCD_Init();
LCD_Clear();
LCD_String_xy(0,1,"The Name Of God");

_delay_ms(1000);
LCD_Clear();
LCD_String_xy(0,0,"Enter user name:");
DDRD = 0b11111111;
while (1)
      {
      key = get_key();
       PORTD=0b11111111;
          if(key<255){ 

          sprintf(buff,"key is:%02d ",key);
          LCD_String_xy(0,0,buff);
          }
      }
}

