#include <18f26K22.h>

#fuses NOWDT, NOMCLR
#use delay(clock=64MHz, oscillator=16MHz)

void main(){
	int tmrx = 1;
	int prx = 159;
	int duty = 0;
	set_tris_c(0x00);
	setup_timer_2(t2_div_by_1,prx,1);
	setup_ccp1(ccp_pwm);
        
   while(true)
   {
      set_pwm1_duty(duty);
      duty = duty+20;
      delay_ms(500);
      if(duty >= 639){
    	duty=0;
      }
      
   } 
}
