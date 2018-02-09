#include <18f26K22.h>
#device adc=10;     
#fuses NOWDT, NOMCLR, HSH  
#use delay(clock=64MHz, oscillator=16MHz)     // para configurar a 64MHz con pll

void main(){
	int tmrx = 1;
	int prx = 159;
	long duty = 0;
	set_tris_c(0x00);
	setup_timer_2(t2_div_by_1,prx,1);
	setup_ccp1(ccp_pwm);
	setup_adc(adc_clock_internal);
	setup_adc_ports(all_analog);                         
        
   while(true)
   {                              

		long value;
 
		 
		set_adc_channel(0);
		 //the next read_adc call will read channel 0
		 
		delay_us(10);
		 //a small delay is required after setting the channel
		 
		 
		 //and before read
		 
		value=read_adc();
		 //starts the conversion and reads the result
		 
		 
		 //and store it in value
		 
		read_adc(ADC_START_ONLY);
		 //only starts the conversion
		 
		value=read_adc(ADC_READ_ONLY);
		duty = value;
 
   
	    set_pwm1_duty(duty);     
	    duty = duty+20;            
	    delay_ms(500);
	    if(duty >= 639)
	    {
	    	duty=0;
	    } 
   } 
}
