unsigned int s = 123;  // Value to display

unsigned int Hex(int a) {
    switch(a) {
        case 0: return ~0x3F;  // 0011 1111
        case 1: return ~0x06;  // 0000 0110
        case 2: return ~0x5B;  // 0101 1011
        case 3: return ~0x4F;  // 0100 1111
        case 4: return ~0x66;  // 0110 0110
        case 5: return ~0x6D;  // 0110 1101
        case 6: return ~0x7D;  // 0111 1101
        case 7: return ~0x07;  // 0000 0111
        case 8: return ~0x7F;  // 0111 1111
        case 9: return ~0x6F;  // 0110 1111
        default: return 0xFF;  // All segments OFF
    }
}

void display_digits(unsigned int val) {
    // Display unit digit (rightmost)
    PORTB = Hex(val % 10);
    PORTD = 0xFE;  // 1111 1110 ? RD0=0 (only first digit ON)
    Delay_ms(5);
    
    // Display tens digit (middle)
    PORTB = Hex((val / 10) % 10);
    PORTD = 0xFD;  // 1111 1101 ? RD1=0 (only second digit ON)
    Delay_ms(5);
    
    // Display hundreds digit (leftmost)
    PORTB = Hex((val / 100) % 10);
    PORTD = 0xFB;  // 1111 1011 ? RD2=0 (only third digit ON)
    Delay_ms(5);
}

void main() {
    TRISB = 0x00;   // PORTB as output (segments)
    TRISD = 0x00;   // PORTD as output (digit control)
    PORTB = 0xFF;   // Turn off all segments initially
    PORTD = 0xFF;   // Turn off all digits initially

    while(1) {
        display_digits(s);  // Continuously refresh display
    }
}
-