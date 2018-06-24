/*
 * Timers.c
 *
 * Created: 5/5/2018 8:42:19 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

#define F_CPU 14745600

#include "Common_includes.h"
#include "Timers.h"

// Timer 1 initialized in PWM mode for servo control
// Prescale:256
// PWM 10bit fast, TOP=0x03FF
// Timer Frequency:56.000Hz
void timer1_init()
{
 TCCR1B = 0x00; //stop
 TCNT1H = 0x00; //Counter high value to which OCR1xH value is to be compared with
 TCNT1L = 0x00;	//Counter low value to which OCR1xH value is to be compared with
 OCR1AH = 0x00;	//Output compare Register high value for servo 1
 OCR1AL = 0x61;	//Output Compare Register low Value For servo 1
 OCR1BH = 0x00;	//Output compare Register high value for servo 2
 OCR1BL = 0x61;	//Output Compare Register low Value For servo 2
 OCR1CH = 0x00;	//Output compare Register high value for servo 3
 OCR1CL = 0x61;	//Output Compare Register low Value For servo 3
 TCCR1A = 0xAB; /*{COM1A1=1, COM1A0=0; COM1B1=1, COM1B0=0; COM1C1=1 COM1C0=0}
 					For Overriding normal port functionality to OCRnA outputs.
				  {WGM11=1, WGM10=1} Along With WGM12 in TCCR1B for Selecting FAST PWM Mode*/
 TCCR1C = 0x00;
 TCCR1B = 0x0C; //WGM12=1; CS12=1, CS11=0, CS10=0 (Prescaler=256)
}

// Timer 4 initialized in normal mode for ultrasound sensor
// Prescale:256
void timer4_init()
{
	TCNT4 = 0;
	TCCR4A = 0x00;
	TCCR4B = (0<<CS40) | (0<<CS41) | (1<<CS42);  // Timer mode with 256 prescler
	sei();
}

// Timer 5 initialized in PWM mode for velocity control
// Prescale:256
// PWM 8bit fast, TOP=0x00FF
// Timer Frequency:225.000Hz
void timer5_init()
{
	TCCR5B = 0x00;	//Stop
	TCNT5H = 0xFF;	//Counter higher 8-bit value to which OCR5xH value is compared with
	TCNT5L = 0x01;	//Counter lower 8-bit value to which OCR5xH value is compared with
	OCR5AH = 0x00;	//Output compare register high value for Left Motor
	OCR5AL = 0xFF;	//Output compare register low value for Left Motor
	OCR5BH = 0x00;	//Output compare register high value for Right Motor
	OCR5BL = 0xFF;	//Output compare register low value for Right Motor
	OCR5CH = 0x00;	//Output compare register high value for Motor C1
	OCR5CL = 0xFF;	//Output compare register low value for Motor C1
	TCCR5A = 0xA9;	/*{COM5A1=1, COM5A0=0; COM5B1=1, COM5B0=0; COM5C1=1 COM5C0=0}
 					  For Overriding normal port functionality to OCRnA outputs.
				  	  {WGM51=0, WGM50=1} Along With WGM52 in TCCR5B for Selecting FAST PWM 8-bit Mode*/
	
	TCCR5B = 0x0B;	//WGM12=1; CS12=0, CS11=1, CS10=1 (Prescaler=64)
}
