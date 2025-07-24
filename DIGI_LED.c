void main()
{
    TRISB=0xFF;
    TRISC=0x00;
    PORTC.F2=0;
    while(1)
     {
       if(PORTB.F0==0)
        {
          PORTC.F2=1;
        }
      else{
          PORTC.F2=0;
          }
     }
}

