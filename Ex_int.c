void interrupt() {
   if (INTF_bit) {
      PORTB.F1 = 0;        // Turn OFF LED
      Delay_ms(2000);      // Wait for 2 seconds
      PORTB.F1 = 1;
      Delay_ms(2000);        // Turn ON LED again
      INTF_bit = 0;        // Clear interrupt flag
   }
}

void main() {
   TRISB = 0b00000001;     // RB0 as input, RB1 as output
   PORTB.F1 = 1;           // Turn ON LED at start

   OPTION_REG.INTEDG = 0;  // Interrupt on falling edge
   INTE_bit = 1;           // Enable external interrupt (RB0)
   GIE_bit = 1;            // Enable global interrupts
   INTF_bit = 0;           // Clear interrupt flag

   while(1) {
      // Do nothing, LED stays ON by default
   }
}
