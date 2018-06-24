/*
 * ISRs.h
 *
 * Created: 5/5/2018 8:44:08 PM
 * Authors: Mohan Prabhakar and Kenneth Joel
 */ 

unsigned long int ShaftCountLeft = 0; //to keep track of left position encoder
unsigned long int ShaftCountRight = 0; //to keep track of right position encoder

//ISR for right position encoder
ISR(INT5_vect)
{
	ShaftCountRight++;  //increment right shaft position count
}

//ISR for left position encoder
ISR(INT4_vect)
{
	ShaftCountLeft++;  //increment left shaft position count
}
