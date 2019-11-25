// DishwasherProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

//#include <iostream.h>
#include <stdio.h>
//#include <16F877a.h>
//#fuses HS, NOLVP, NOWDT, PUT
//#use delay (clock = 20000000)
//LEDs
//#define RED_LED PIN_D5
//#define YELLOW_LED PIN_D6
//#define GREEN_LED PIN_D7
//Segment 1
//#define SEGMENT_A1 PIN_B0
//#define SEGMENT_B1 PIN_B1
//#define SEGMENT_C1 PIN_B2
//#define SEGMENT_D1 PIN_B3
//#define SEGMENT_E1 PIN_B4
//#define SEGMENT_F1 PIN_B5
//#define SEGMENT_G1 PIN_B6
//#define SEGMENT_DP1 PIN_B7
//Segment 2
//#define SEGMENT_A2 PIN_C0
//#define SEGMENT_B2 PIN_C1
//#define SEGMENT_C2 PIN_C2
//#define SEGMENT_D2 PIN_C3
//#define SEGMENT_E2 PIN_C4
//#define SEGMENT_F2 PIN_C5
//#define SEGMENT_G2 PIN_C6
//#define SEGMENT_DP2 PIN_C7
//Motor
//#define PIN_D2 air hardware part here

int timeToWash = 60;

int main(void) {
	//RED LED turns on to indicate that the dishwasher is still off
	printf("RED LED is ON\n\n");
	//output_bit(PIN_D5, TRUE);
	//delay_ms(3000);
	//RED LED turns off to indicate that the dishwasher is not off anymore
	//output_bit(PIN_D5, FALSE);
	printf("RED LED is OFF\n\n");

	//GREEN LED turns on to indiacte that the dish washing process started
	printf("GREEN LED is ON\n\n");
	//output_bit(PIN_D7, TRUE);
	//GREEN LED stays on for timeToWash
	//delay_ms(timeToWash*1000);

	//This is where the 7-segment display starts displaying time left for dishwasher to finish
	int digits[10] = { 0B01111110, 0B00001100, 0B10110110, 0B10011110, 0B11001100, 0B11011010, 0B11111010, 0B00001110, 0B11111110, 0B11011110 };
	int i;

	int display1 = 5, display2 = 9;
	while (TRUE) {
		 for (i = 0; i < 10; i++) {
			 output_b(digits[i]);
			 delay_ms(10000);

			 output_b(digits[i]);
			 delay_ms(1000);
		 }
	 }

	for (i = 6; i >= 0; i--)
	{
		//First washing with soap...		Time Left: 60 minutes
		timeToWash = timeToWash / 2;

		//delay_ms(timeToWash*1000);

		//Now rinsing...		Time Left: 30 minutes
		timeToWash = timeToWash / 2;

		output_b(digits[i]);
		delay_ms(10000);

		for (j = 0; j < 10; j++)
		{
			if(i == 1)
			{
				if(j == 5)
				{
					//Finally drying...		Time Left: 15
					//YELLOW LED turns on to indicate that the drying operation started
					printf("YELLOW LED is ON\n\n");
					//output_bit(PIN_D6, TRUE);

					//This is where the air hardware part will start working
					//output_bit(???, TRUE);
					//delay_ms(timeToWash*1000);
					//output_bit(???, FALSE);

					//YELLOW LED turns off to indicate that the drying operation stopped
					//output_bit(PIN_D6, FALSE);
					printf("YELLOW LED is OFF\n\n");

					timeToWash = 0;
				}
			}

			output_b(digits[j]);
			delay_ms(1000);
		}
	}

	//GREEN LED turns off to indicate that the dishwasher operation finished
	//output_bit(PIN_D7, FALSE);
	printf("GREEN LED is OFF\n\n");

	//RED LED turns on to indicate that the dishwasher is now off again
	//output_bit(PIN_D5, TRUE);
	printf("RED LED is ON\n\n");

	return 0;
}
