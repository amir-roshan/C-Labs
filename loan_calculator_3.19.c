// Exercise 3.19
// Name: Amir Roshan
// Date: January 14, 2025

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "calculator.h"

void calculateLoanInterest() {
	int principal = 0;
	float rate;
	float interest;
	int days;

	printf("Enter loan principal (-1 to end): ");
	scanf("%d", &principal);

	while (principal != EXIT_VALUE) {
		printf("Enter the rate: ");
		scanf("%lf", &rate);

		printf("Enter the number of days: ");
		scanf("%d", &days);

		interest = principal * rate * days / 365;
		printf("The interest charge is $%.2f\n", interest);
		printf("\n");
	}
}
