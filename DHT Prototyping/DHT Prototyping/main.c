#include <util/delay.h>
#include "DHT.h"
#include <avr/io.h>
#include <stdio.h>

#define F_CPU	16000000UL
#define RED		D, 3
#define GREEN	D, 5
#define BLUE	
#define BLUE	D, 6
#define FAN		D, 0
#define Drive	C, 0
#define VH400	C, 1
#define LED		C, 4

void Init()
{
	
	PinMode(RED, Output);
	PinMode(GREEN, Output);
	PinMode(BLUE, Output);
	PinMode(BLUE, Output);
	PinMode(FAN, Output);
	PinMode(Drive, Output);
	PinMode(VH400, Input);
	PinMode(LED, Output);
	
	DHT_Setup();
	
}

void error_checks()
{
	
}

int main(void)
{
	
	double temp[1], hum[1];
	temp[0] = hum[0] = 0;
	Init();
	
    while (1) 
    {
		
		float vh_val = DigitalRead(VH400);
		DHT_Read(temp, hum);
		
		if(vh_val > 0)
		{
			DigitalWrite(LED, High);
			//DigitalWrite(Drive, High);
		}
		else
		{
			DigitalWrite(LED, Low);
			//DigitalWrite(Drive, Low);
		}
		
			
		if(temp[0] > 80)
		{
			DigitalWrite(RED, High);
			DigitalWrite(GREEN, Low);
			DigitalWrite(BLUE, Low);
		}
		else if(temp[0] < 50)
		{
			DigitalWrite(BLUE, High);
			DigitalWrite(GREEN, Low);
			DigitalWrite(RED, Low);
		}
		else
		{
			DigitalWrite(GREEN, High);
			DigitalWrite(RED, Low);
			DigitalWrite(BLUE, Low);
		}
    }
}

