// DishwasherProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

//#include <iostream.h>
#include <stdio.h>
//#include <16F877a.h>
//#define RED_LED PIN_B7 /* Pin 40 */
//#define YELLOW_LED PIN_C7 /* Pin 26 */
//#define GREEN_LED PIN_D7 /* Pin 30 */
//#define 7-segment display here
//#define air hardware part here

int timeToWash = 60;

int main(void) {
	//RED LED turns on to indicate that the dishwasher is still off
	printf("RED LED is ON\n\n");
	//output_bit(PIN_B7, TRUE);
	//delay_ms(3000);
	//RED LED turns off to indicate that the dishwasher is not off anymore
	//output_bit(PIN_B7, FALSE);
	printf("RED LED is OFF\n\n");

	//This is where the 7-segment display starts displaying time left for dishwasher to finish

	//GREEN LED turns on to indiacte that the dish washing process started
	printf("GREEN LED is ON\n\n");
	//output_bit(PIN_D7, TRUE);
	//GREEN LED stays on for timeToWash
	//delay_ms(timeToWash*1000);

	//First washing with soap...		Time Left: timeToWash
	timeToWash = timeToWash / 2;

	//delay_ms(timeToWash*1000);

	//Now rinsing...		Time Left: timeToWash
	timeToWash = timeToWash / 2;

	//YELLOW LED turns on to indicate that the drying operation started
	printf("YELLOW LED is ON\n\n");
	//output_bit(PIN_B7, TRUE);
	//This is where the air hardware part will start working
	//delay_ms(timeToWash*1000);
	//YELLOW LED turns off to indicate that the drying operation stopped
	//output_bit(PIN_B7, FALSE);
	printf("YELLOW LED is OFF\n\n");

	//Finally drying...		Time Left: timeToWash
	timeToWash = 0;

	//GREEN LED turns off to indicate that the dishwasher operation finished
	//output_bit(PIN_D7, FALSE);
	printf("GREEN LED is OFF\n\n");

	//RED LED turns on to indicate that the dishwasher is now off again
	printf("RED LED is ON\n\n");
	//output_bit(PIN_B7, TRUE);

	return 0;
}
