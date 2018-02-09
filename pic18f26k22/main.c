#include <18f26K22.h>

#fuses NOWDT, NOMCLR, PLLEN
#use delay(clock=64MHz, oscillator=16MHz)
#byte TRISB = 0xf93
#byte PORTB = 0xf81
#byte LATB = 0xf8a
#bit RB0 = LATB.0

void main(){
   TRISB=0b00000000;
   while(true){
      RB0 = 1;
      delay_ms(1000);
      RB0 = 0;
      delay_ms(1000);
      
   }
}
