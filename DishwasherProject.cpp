// DishwasherProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream.h>
#include <stdio.h>
#include <16F877a.h>
//LEDs
#define RED_LED PIN_D5
#define YELLOW_LED PIN_D6
#define GREEN_LED PIN_D7
//Segment 1
#define SEGMENT_A1 PIN_B0
#define SEGMENT_B1 PIN_B1
#define SEGMENT_C1 PIN_B2
#define SEGMENT_D1 PIN_B3
#define SEGMENT_E1 PIN_B4
#define SEGMENT_F1 PIN_B5
#define SEGMENT_G1 PIN_B6
#define SEGMENT_DP1 PIN_B7
//Segment 2
#define SEGMENT_A2 PIN_C0
#define SEGMENT_B2 PIN_C1
#define SEGMENT_C2 PIN_C2
#define SEGMENT_D2 PIN_C3
#define SEGMENT_E2 PIN_C4
#define SEGMENT_F2 PIN_C5
#define SEGMENT_G2 PIN_C6
#define SEGMENT_DP2 PIN_C7
//Motor
#define DC_MOTOR PIN_D2

int timeToWash = 59;

int main(void) {
	//RED LED turns on to indicate that the dishwasher is still off, stays on for 5 seconds then turns off to indicate that the dishwasher is not off anymore
	output_bit(PIN_D5, TRUE);
	delay_ms(5000);
	output_bit(PIN_D5, FALSE);

	//GREEN LED turns on to indiacte that the dish washing process started, stays on for 59 seconds until the end of the process
	output_bit(PIN_D7, TRUE);
	delay_ms(timeToWash*1000);

	//Initializing binary values to display on 7-segment displays
	//								  DPGFEDCBA
	int digits[10] = { 0B00111111,
										 0B00000110,
										 0B01011011,
										 0B01001111,
										 0B01100110,
										 0B01101101,
										 0B01111101,
										 0B00000111,
										 0B01111111,
										 0B01101111 };

	//This is where the 7-segment display starts displaying time left for dishwasher to finish
	for (int i = 5; i >= 0; i--)
	{
		//First washing with soap...		Time Left: 59 seconds
		output_b(digits[i]);
		delay_ms(10000);

		for (int j = 9; j >= 0; j--)
		{
			if(i == 2) //Now rinsing...		Time Left: 29 seconds
			{
				//YELLOW LED turns on to indicate that the rinsing process started
				output_bit(PIN_D6, TRUE);
			}
			if(i == 1) //Finally drying...		Time Left: 19 seconds
			{
				//YELLOW LED turns off to indicate that the rinsing process stopped
				output_bit(PIN_D6, FALSE);

				//MOTOR turns on to indicate that the drying process started
				output_high(DC_MOTOR);
			}

			output_c(digits[j]);
			delay_ms(1000);
		}
	}

	//MOTOR turns off to indicate that the drying process stopped
	output_low(DC_MOTOR);

	//GREEN LED turns off to indicate that the dishwasher process finished
	output_bit(PIN_D7, FALSE);
	printf("GREEN LED is OFF\n\n");

	//RED LED turns on to indicate that the dishwasher is now off again
	output_bit(PIN_D5, TRUE);
	printf("RED LED is ON\n\n");

	return 0;
}
