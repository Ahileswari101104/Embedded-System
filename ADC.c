unsigned int adc_value;
unsigned int pwm_duty;

void main() {
  ADCON1 = 0x80;
  TRISA.F0 = 1;
  TRISC.F2 = 0;

  PWM1_Init(5000);
  PWM1_Start();
  PWM1_Set_Duty(0);

  while(1) {
    adc_value = ADC_Read(0);
    pwm_duty = adc_value / 4;
    pwm_duty=255-pwm_duty;
    PWM1_Set_Duty(pwm_duty);
    Delay_ms(10);
  }
}