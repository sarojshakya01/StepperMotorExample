/*
 * Driving_stepper_motor.c
 *
 * Created: 6/15/2014 8:10:50 AM
 *  Author: Saroj Shakya
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define MOTOR_DDR DDRD
#define MOTOR_PORT PORTD
void stepper_clockwise(unsigned char rounds)
{
	unsigned char i;
	for (i=0;i<rounds;i++)
	{
		 PORTD=0x01;
		 _delay_ms(500);
		 PORTD=0x04;
		 _delay_ms(500);
		 PORTD=0x02;
		_delay_ms(500);
		 PORTD=0x08;
		 _delay_ms(500);
	}
}
void stepper_anticlockwise(unsigned char rounds)
{
	unsigned char i;
	for (i=0;i<rounds;i++)
	{
		PORTD=0x08;
		_delay_ms(500);
		PORTD=0x02;
		_delay_ms(400);
		PORTD=0x04;
		_delay_ms(500);
		PORTD=0x01;
		_delay_ms(500);
	}
}
int main(void)
{
	MOTOR_DDR=0xFF;
    while(1)
    {/*
		 PORTD=0x01;
		 _delay_ms(500);
		 PORTD=0x04;
		 _delay_ms(500);
		 PORTD=0x02;
		 _delay_ms(500);
		 PORTD=0x08;
		 _delay_ms(500);*/
		stepper_clockwise(5);
		_delay_ms(2000);
		stepper_anticlockwise(5);
		_delay_ms(2000);
    }
}