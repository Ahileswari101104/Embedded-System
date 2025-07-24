// Title: LCD Continuous Scroll in Both Directions with PIC16F877A

// LCD module connections
sbit LCD_RS at RC5_bit;
sbit LCD_EN at RC4_bit;

sbit LCD_D4 at RD0_bit;
sbit LCD_D5 at RD1_bit;
sbit LCD_D6 at RD2_bit;
sbit LCD_D7 at RD3_bit;

// LCD Pin Direction
sbit LCD_RS_Direction at TRISC5_bit;
sbit LCD_EN_Direction at TRISC4_bit;
sbit LCD_D4_Direction at TRISD0_bit;
sbit LCD_D5_Direction at TRISD1_bit;
sbit LCD_D6_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD3_bit;

char i;

void Scroll_Left(){
   for(i = 0; i < 16; i++) {  // Adjust 16 based on LCD width
      Lcd_Cmd(_LCD_SHIFT_LEFT);
      Delay_ms(250);
   }
}

void Scroll_Right(){
   for(i = 0; i < 16; i++) {
      Lcd_Cmd(_LCD_SHIFT_RIGHT);
      Delay_ms(250);
   }
}

void main() {
   Lcd_Init();
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Cmd(_LCD_CURSOR_OFF);

   while(1) {
      // Scroll Left Sequence

      Lcd_Out(1, 1, "Welcome to KPRIET");
      Delay_ms(2000);
      Scroll_Left();
      Lcd_Cmd(_LCD_CLEAR);

      Lcd_Out(1, 1, "Welcome to ARC");
      Delay_ms(2000);
      Scroll_Left();
      Lcd_Cmd(_LCD_CLEAR);

      Lcd_Out(1, 1, "I am AHI");
      Delay_ms(2000);
      Scroll_Left();
      Lcd_Cmd(_LCD_CLEAR);

      Lcd_Out(1, 1, "My dept ECE");
      Delay_ms(2000);
      Scroll_Left();
      Lcd_Cmd(_LCD_CLEAR);

      // Scroll Right Sequence

      Lcd_Out(1, 1, "Welcome to KPRIET");
      Delay_ms(2000);
      Scroll_Right();
      Lcd_Cmd(_LCD_CLEAR);

      Lcd_Out(1, 1, "Welcome to ARC");
      Delay_ms(2000);
      Scroll_Right();
      Lcd_Cmd(_LCD_CLEAR);

      Lcd_Out(1, 1, "I am AHI");
      Delay_ms(2000);
      Scroll_Right();
      Lcd_Cmd(_LCD_CLEAR);

      Lcd_Out(1, 1, "My dept ECE");
      Delay_ms(2000);
      Scroll_Right();
      Lcd_Cmd(_LCD_CLEAR);
   }
}