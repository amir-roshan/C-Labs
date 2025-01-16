// Exercise 3.19
// Name: Amir Roshan
// Date: January 15, 2025

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "calculator.h"

void calculateGasMileage() {
	float gallons = 0.0;
	float miles = 0.0;
	float milesPerGallon = 0.0;
	float totalMiles = 0.0;
	float totalGallons = 0.0;

	printf("Enter the gallons used (-1 to end): ");
	scanf("%f", &gallons);

	while (gallons != EXIT_VALUE) {
		if (gallons <= 0.0) {
			printf("You have entered an invalid value for gallons, try again: ");
			scanf("%f", &gallons);
		}
		else {
			printf("Enter the miles driven: ");
			scanf("%f", &miles);

			while (miles <= 0.0) {
				printf("You have entered an invalid value for miles, try again: ");
				scanf("%f", &miles);
			}

			totalMiles += miles;
			totalGallons += gallons;

			milesPerGallon = miles / gallons;

			printf("The miles/gallon for this tank was %.6f\n", milesPerGallon);
			puts("");


			printf("Enter the gallons used (-1 to end): ");
			scanf("%f", &gallons);
		}
	}
	if (!(totalGallons || totalMiles)) {
		printf("The overall average miles could not be computed ;-(");
	}
	else {
		printf("The overall average miles/gallon was %.6f\n", totalMiles / totalGallons);
	}
}