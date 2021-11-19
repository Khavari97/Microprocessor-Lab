#include <mega16.h>
#include <delay.h>
int i ;
int direction[5] = {0x01, 0x04, 0x02, 0x08,0x01};

void main(void){
DDRA = 0XFF;
while(1){
for(i = 0 ; i<5 ; i++){
PORTA = direction[i];
delay_ms(500);
}
}
}