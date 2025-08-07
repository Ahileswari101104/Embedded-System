void Rotation0() //0 Degree
{
unsigned int i;
for(i=0;i<50;i++)
{
PORTC.F2 = 1;
Delay_us(800); // pulse of 800us
PORTC.F2 = 0;
Delay_us(19200);
}
}

void Rotation90() //90 Degree
{
unsigned int i;
for(i=0;i<50;i++)
{
PORTC.F2 = 1;
Delay_us(1500); // pulse of 1500us
PORTC.F2 = 0;
Delay_us(18500);
}
}

void Rotation180() //180 Degree

{
unsigned int i;
for(i=0;i<50;i++)
{
PORTC.F2 = 1;
Delay_us(2200); // pulse of 2200us
PORTC.F2 = 0;
Delay_us(17800);
}
}

void main()
{
TRISC = 0; // PORTB as Ouput Port
do
{
Rotation0(); //0 Degree
Delay_ms(2000);
Rotation90(); //90 Degree
Delay_ms(2000);
Rotation180(); //180 Degree
}while(1);
}