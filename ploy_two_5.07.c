// Exercise 3.19
// Name: Amir Roshan
// Date: January 17, 2025

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double poly_two(double a, double b, double c, double x); // Function prototype

void callPolyTwo() {
	double a;
	double b;
	double c;
	double x;

	printf("Enter the value for the 'a' coefficient (must be a non-zero value): ");
	scanf("%lf", &a);

	printf("Enter the value for the 'b' coefficient: ");
	scanf("%lf", &b);

	printf("Enter the value for the 'c' coefficient: ");
	scanf("%lf", &c);

	printf("Enter the value for the 'x' input into the polynomial:");
	scanf("%lf", &x);

	printf("The result when x = %.4f is: %.4f", x, poly_two(a, b, c, x));
}

double poly_two(double a, double b, double c, double x) {
	return a * x * x + b * x + c;
}