sbit LCD_RS at RC0_bit;
sbit LCD_EN at RC1_bit;
sbit LCD_D4 at RD0_bit;
sbit LCD_D5 at RD1_bit;
sbit LCD_D6 at RD2_bit;
sbit LCD_D7 at RD3_bit;

sbit LCD_RS_Direction at TRISC0_bit;
sbit LCD_EN_Direction at TRISC1_bit;
sbit LCD_D4_Direction at TRISD0_bit;
sbit LCD_D5_Direction at TRISD1_bit;
sbit LCD_D6_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD3_bit;

// Pins
#define BUTTON1 PORTB.F0
#define BUTTON2 PORTB.F1

// EEPROM
 // Arbitrary marker byte
void main() {
      TRISB.F0 = 1;            // Button 1 input
    TRISB.F1 = 1;            // Button 2 input
    TRISD = 0x00;
    TRISC = 0x00;
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);

   EEADR = 0x01;
   EEDATA = 'A';
   EECON1.EEPGD=0;
   EECON1.WREN=1;
   INTCON.GIE=0;
   EECON2=0x55;
   EECON2=0xAA;
   EECON1.WR=1;
   while(EECON1.WR);
   EECON1.WREN=0;
   EEADR = 0x01;
   EECON1.EEPGD = 0;
   EECON1.RD = 1; 
   Lcd_Out(1, 1, "Stored:");
   Lcd_Chr(2, 1, EEDATA);
}