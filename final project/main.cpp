#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 #define RS 0
 #define RW 1
 #define EN 2
 #define LCD_PORT PORTC
 #define LCD_DIR DDRC

 #define CLEAR_LCD 0x01
 #define LCD_HOME 0x02
 #define LCD_LINE_1 0x80
 #define LCD_LINE_2 0xC0
 #define LCD_R_SHIFT 0x1C
 #define LCD_L_SHIFT 0x18
 #define FWD 0x0A
 #define REV 0x05
 #define R 0x02
 #define L 0x08
 #define CW 0x09
 #define CCW 0x06
 #define STOP 0x00
 #define B 0xFF

 #define RSPEED OCR1AL
 #define LSPEED OCR1BL

 #define MAX 3
 #define HMAX 1

 void move(unsigned char dir);
 void Lcd_Cmd(unsigned char cmd);
 void lcd_message(char line, char * ptr );
 void lcd_data(unsigned char data);
 void lcd_init(void);

 unsigned char i , rdev , ldev , ip , delay , dir , power , dirl , history[MAX] , hcount = 0 , rotpow , val = 0;

 unsigned char rep=0, prev=0;

 void disp()
 {
 char mess[] = "LINE FOLLOWING ROBOT";
 char mess2[] = "Hello";
 lcd_message(LCD_LINE_1, mess );

 _delay_ms(1000);

 for(int i=0;i<20;i++)
 {
 Lcd_Cmd(LCD_R_SHIFT);
 _delay_ms(100);
 }
 Lcd_Cmd(LCD_HOME);
 lcd_message(LCD_LINE_2, mess2);
 _delay_ms(1000);

}

 int main(void)
 {

 lcd_init();
 disp();

 PORTA = 0x00;
 DDRA = 0x00;

 PORTB = 0xFF;
 DDRB = 0xFF;

 PORTC=0x00;
 DDRC=0xFF;

 PORTD=0xff;
 DDRD=0xff;

 TCCR0=0x00;
 TCNT0=0x00;
 OCR0=0x00;

 TCCR1A=0xA1;
 TCCR1B=0x0A;
 TCNT1H=0x00;
 TCNT1L=0x00;

 OCR1AH=0xFF;
 OCR1AL=0xFF;
 OCR1BH=0xFF;
 OCR1BL=0xFF;

 ACSR=0x80;// adc disable
 move(STOP);
 _delay_ms(1000);
 while(1)
 {

if(PINA!=0)
 {

ldev=0;
 rdev=0;
 val = PINA;

if((val & 0x08)==8)
 {
 rdev=1;
 ldev=1;
 }
 if((val & 0x04)==4)
 rdev=2;

if((val & 0x10)==0x10)
 ldev=2;

if((val & 0x02)==2)
 rdev=3;

if((val & 0x20)==0x20)
 ldev=3;

if((val & 0x01)==1)
 rdev=4;

if((val & 0x40)==0x40)
 ldev=4;
 if(rdev>ldev)
 move(L);
 else if(rdev<ldev)
 move(R);
 else if(rdev==ldev)
 move(FWD);
 }
 else
 {
 for(i=0;i<dirl;i++)
 {
 if(history[i]==L)
 {
 dirl++;
 }
 }
 if(dirl>HMAX)
 {
 move(CCW);

_delay_ms(1000); 
 }
 else
 {
 move(CW);

_delay_ms(1000); 
 }

_delay_ms(1000);

}

};
 }
 void move(unsigned char dir)//,unsigned char delay,unsigned char power)
 {
 PORTD=dir;

 char ch[10];
 itoa(dir,ch,10);
 Lcd_Cmd(CLEAR_LCD);

if(dir == STOP)
 {
 lcd_message(LCD_LINE_1, "STOP");
 }
 else if(dir == FWD)
 {
 lcd_message(LCD_LINE_1, "FORWARD");
 }
 else if(dir == REV)
 {
 lcd_message(LCD_LINE_1, "REVERSE");
 }
 else if(dir == R)
 {
 lcd_message(LCD_LINE_1, "RIGHT");
 }
 else if(dir == L)
 {
 lcd_message(LCD_LINE_1, "LEFT");
 }
 else if(dir == CW)
 {
 lcd_message(LCD_LINE_1, "CW");
 }
 else if(dir == CCW)
 {
 lcd_message(LCD_LINE_1, "CCW");
 }

lcd_message(LCD_LINE_2, ch );
 if(dir==L||dir==R)
 {
 hcount=(hcount+1)%MAX;
 history[hcount]=dir;
 }
 LSPEED=50;
 RSPEED=50;
 _delay_ms(1000);

}


void Lcd_Cmd(unsigned char cmd)
 {

//LCD_PORT &= ~((1<<rs)|(1<<rw)); rs="" low="" for="" command,="" rw="" <span="" class="hiddenSpellError" pre="for " data-mce-bogus="1">write
 LCD_PORT |= (1<<EN); // Set enable
 LCD_PORT &= 0x0F;
 LCD_PORT |= (cmd & 0xF0);
 LCD_PORT &= ~(1<<EN); 
 _delay_ms(1);
 LCD_PORT |= (1<<EN); // Set enable
 LCD_PORT &= 0x0F;
 LCD_PORT |= (cmd << 4); 
 LCD_PORT &= ~(1<<EN); 
 _delay_ms(1);
 }

void lcd_data(unsigned char data)
 {

 LCD_PORT |= (1<<RS); 
 //LCD_PORT &= ~(1<<rw); rw="" low="" for="" <span="" class="hiddenSpellError" pre="for " data-mce-bogus="1">write
 LCD_PORT |= (1<<EN); // Set enable
 LCD_PORT &= 0x0F;
 LCD_PORT |= (data & 0xF0);
 LCD_PORT &= ~(1<<EN); 
 _delay_ms(1);
 LCD_PORT |= (1<<EN);
 LCD_PORT &= 0x0F;
 LCD_PORT |= (data << 4); 
 LCD_PORT &= ~(1<<EN); 
 _delay_ms(1);
 }

 void lcd_init(void)
 {
 LCD_DIR = 0xFF;
 _delay_ms(15);
 Lcd_Cmd(0x03);
 _delay_ms(5);
 Lcd_Cmd(0x03);
 _delay_ms(1);
 Lcd_Cmd(0x03);
 _delay_ms(1);
 Lcd_Cmd(0x02);
 _delay_ms(1); 
 Lcd_Cmd(0x28);
 _delay_ms(1);
 Lcd_Cmd(0x08); // Turn off display
 _delay_ms(1);
 Lcd_Cmd(0x01); //Clear display
 _delay_ms(1);
 Lcd_Cmd(0x06); 
 _delay_ms(1);
 Lcd_Cmd(0x0F); 
 _delay_ms(1);
 }
 void lcd_message(char line, char * ptr ) // 1st argument is the string pointer the other is line No.
 {

//Lcd_Cmd(CLEAR_LCD);
 Lcd_Cmd(line); //move cursor to line

}