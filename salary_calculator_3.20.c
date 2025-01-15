// Exercise 3.19
// Name: Amir Roshan
// Date: January 14, 2025

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "calculator.h"

void calculateSalary() {
	int hours = 0;
	float salary = 0.00;
	float rate = 0.00;

	printf("Enter # of hours aworked (-1 to end): ");
	scanf("%d", &hours);

	while (hours != EXIT_VALUE) {
		printf("Enter hourly rate of the worker ($00.00): ");
		scanf("%f", &rate);

		if (hours > NORMAL_HOURS) {
			salary = hours * rate + (NORMAL_HOURS - hours) * (rate * OVERTIME_RATE);
		}
		else {
			salary = hours * rate;
		}

		printf("Salary is $%.2f\n", salary);
	}

}