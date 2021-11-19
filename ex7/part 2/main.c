#include <alcd.h>
#include <delay.h>
#include <stdio.h>


int get_key(void){  
DDRB=0b00000000;
PORTB=0b00001111;

DDRB=0b00100000; 
if(PINB.0==0)return 9;
if(PINB.1==0)return 6;
if(PINB.2==0)return 3;
if(PINB.3==0)return 11;

DDRB=0b01000000;
if(PINB.0==0)return 8;
if(PINB.1==0)return 5;
if(PINB.2==0)return 2;
if(PINB.3==0)return 0;

DDRB=0b10000000;
if(PINB.0==0)return 7;
if(PINB.1==0)return 4;
if(PINB.2==0)return 1;
if(PINB.3==0)return 10;

return 255;
}

void main(void)
{
char buff[16];
int key ;
lcd_init(16);
lcd_clear();
lcd_putsf("Enter id : ");
lcd_gotoxy(0,1);
delay_ms(1000);
lcd_clear();
//DDRD = 0b11111111;
while (1)
      {
      key = get_key();
       //PORTD=0b11111111;
          if(key<255){  
          sprintf(buff,"number :%d ",key);
          lcd_gotoxy(0,0);
          lcd_puts(buff); 
          lcd_gotoxy(0,1); 
          lcd_putsf("not exist");
          PORTD=0b10000000;
          } 
          if(key == 10){        
             PORTD=0b00000001;
             lcd_gotoxy(0,0);
             lcd_puts(buff);  
              lcd_gotoxy(0,1); 
              lcd_putsf("enter password :)"); 
              delay_ms(1000);  
              lcd_clear(); 
              while(1){
               key = get_key();
              if(key<255){ 
              sprintf(buff,"number :%d ",key);
              lcd_gotoxy(0,0);
              lcd_puts(buff); 
              lcd_gotoxy(0,1); 
              lcd_putsf("pass is false");
              PORTD=0b10000000;
                  
              if(key == 10){
               lcd_gotoxy(0,1); 
              lcd_putsf("successfull :)"); 
               PORTD=0b00000001;
              }
              }
                 
              } 
              
          }  
         
      }
} 
