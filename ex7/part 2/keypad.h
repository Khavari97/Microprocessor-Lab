#ifndef keypad_h
#define keypad_h

#include <io.h>

#define KEY_PORT    PORTD
#define KEY_DDR     DDRD
#define KEY_PIN     PIND

#define C1  PIND.4  
#define C2  PIND.5  
#define C3  PIND.6  
#define C4  PIND.7  



/****************functions prototypes*************************************/
void keypad_init(void);
unsigned char key_released(void);
unsigned char key_pressed(void);
unsigned char key_scan(void);

#endif