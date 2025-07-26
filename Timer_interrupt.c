// LCD Connections
sbit LCD_RS at RD0_bit;
sbit LCD_EN at RD1_bit;
sbit LCD_D4 at RD2_bit;
sbit LCD_D5 at RD3_bit;
sbit LCD_D6 at RD4_bit;
sbit LCD_D7 at RD5_bit;

sbit LCD_RS_Direction at TRISD0_bit;
sbit LCD_EN_Direction at TRISD1_bit;
sbit LCD_D4_Direction at TRISD2_bit;
sbit LCD_D5_Direction at TRISD3_bit;
sbit LCD_D6_Direction at TRISD4_bit;
sbit LCD_D7_Direction at TRISD5_bit;

unsigned int counter = 0;
char txt[6];
 // Enough space for "99999" + '\0'

// Interrupt Service Routine
void interrupt() {
    if (PIR1.TMR1IF) {
        PIR1.TMR1IF = 0;           // Clear Timer1 overflow flag
        TMR1H = 0x0B;              // Reload for 500ms (based on 20MHz clock and prescaler 8)
        TMR1L = 0xDC;
        counter++;
        if(counter==5)
        {
        T1CON.TMR1ON=0;
        }                // Increment counter
    }
}

void main() {
    TRISB = 0x00;
    TRISD = 0x00;                 // Set PORTB as output
    PORTB = 0x00;

    Lcd_Init();                   // Initialize LCD
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1, 1, "Timer1 Count:");

    // Timer1 Settings
    T1CON = 0x31;                // Timer1 ON, prescaler 1:8 (bit 5-4 = 11), 16-bit mode
    TMR1H = 0x0B;                // Load Timer1 for 500ms overflow
    TMR1L = 0xDC;

    PIE1.TMR1IE = 1;             // Enable Timer1 interrupt
    INTCON.PEIE = 1;             // Enable peripheral interrupts
    INTCON.GIE = 1;              // Enable global interrupts
    
    while(1) {
        IntToStr(counter, txt);  // Convert counter to string
        Lcd_Out(2, 1, txt);      // Display on second line
        //Delay_ms(100);  
        if(counter>=5)
        {
         T1CON.TMR1ON=0;
         PORTB.F1=1;
         Delay_ms(1000);
         PORTB.F1=0;
         Delay_ms(1000);
        }          // Delay for stability
    }
}
