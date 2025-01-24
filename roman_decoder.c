// Exercise 6.19
// Name: Amir Roshan
// Date: January 21, 2025

#define _CRT_SECURE_NO_WARNINGS

#include "game_launcher.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define INVALID_VALUE -1
#define MAX_INPUT 10

enum RomanNumerals {
	I = 1,
	V = 5,
	X = 10,
	L = 50,
	C = 100,
	D = 500,
	M = 1000
};


int romanToInt(char character) {
	switch (character) {
	case 'I': return I;
	case 'V': return V;
	case 'X': return X;
	case 'L': return L;
	case 'C': return C;
	case 'D': return D;
	case 'M': return M;
	default: return INVALID_VALUE;
	}
}

void romanDecoder(void) {
	char character;
	int romanNumeral = 0;
	int counter = 1;
	int currentValue = 0;
	int lastValue = 0;
	int total = 0;
	int isValid = 1; // Truthy


	printf("%d Roman numeral values will be input and converted into\ntheir equivalent Hindu - Arabic numeric values.\n", MAX_INPUT);
	puts("");

	while (counter <= MAX_INPUT) {
		isValid = 1;
		lastValue = 0;
		total = 0;
		
		printf("Input Roman numeral #%d: ", counter);
		
		while ((character = toupper(getchar())) != '\n') {
			currentValue = romanToInt(character);
			
			if (currentValue == INVALID_VALUE && isValid) {
				printf(" Error - last character was not valid!!!\n");
				isValid = 0; // Falsy
			}
			else if (!isValid) {
				printf("");
			}
			else {
				printf("%c", character);

				if (currentValue > 0 && lastValue < currentValue) {
					total += currentValue - 2 * lastValue;
				}
				else {
					total += currentValue;
				}
			}
			
			lastValue = currentValue;
		}
		
		if (isValid) {
			printf(" = %d\n", total);
		}
		
		counter++;

		puts("");
	}
}