// DishwasherProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream.h>
#include <stdio.h>

void manualMode();
void defaultMode();

int temp, timeToWash, operation;

int main(void) {
	int mode = 0, part = 3, waterLevel;
	int doorSensor = 0, timer = 3, waterLevelSensor = 0, tempSensor = 25;
	char startPause = 'F';
	printf("Dish Washing Machine CE224 \n");
	do {
		printf("Choose Mode: (1) Default, (2) Manual \n");
		scanf_s("%d", &mode);
		if (mode == 1)
			defaultMode();
		if (mode == 2)
			manualMode();
	} while (mode == 0);

	printf("Choose Parts to wash: (1) Upper Only, (2) Lower Only, (3) Upper and Lower \n");
	scanf_s("%d", &part);

	switch (part) {
	case 1:
	case 2:
		waterLevel = 0.5;
		break;
	case 3:
		waterLevel = 1;
		break;
	}

	if (doorSensor == 0) {
		do {
			printf("Press (S) to Start and close the door. \n");
			scanf_s("%d", &startPause);
			printf("LED is On\n");
			while (waterLevelSensor != waterLevel) {
				waterLevelSensor++;
			}

			while (tempSensor != temp) {
				tempSensor++;
			}

			printf("Washing Operation Started!		Time Left: %p \n", &timeToWash);
			printf("Washing with Soap Operation Started!\n");
			timeToWash = timeToWash / 2;
			printf("Rinsing Operation Started!		Time Left: %p \n", &timeToWash);
			timeToWash = timeToWash / 2;
			printf("Drying Operation Started!		Time Left: %p \n", &timeToWash);
			timeToWash = 0;
			startPause = 'P';
		} while ((startPause == 's') || (startPause == 'S'));
	}

	printf("End!\nLED is Off");

	return 0;
}

void manualMode() {
	printf("Enter temperature: \n");
	scanf_s("%d", &temp);
	printf("Enter time to wash: \n");
	scanf_s("%d", &timeToWash);
	printf("Choose Operation: (1) Water Only, (2) Water and Soap, (3) Rinse, (4) Dry, (5) All \n");
	scanf_s("%d", &operation);
}

void defaultMode() {
	int whatToWash = 0;
	printf("Choose what to wash: (1) Cups, (2) Plates, (3) Pots \n");
	scanf_s("%d", &whatToWash);

	switch (whatToWash) {
	case 1:
		temp = 30;
		timeToWash = 3;
		break;
	case 2:
		temp = 40;
		timeToWash = 3;
		break;
	case 3:
		temp = 60;
		timeToWash = 3;
		break;
	}
}
