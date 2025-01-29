// Assignment02
// Name: Amir Roshan
// Date: January 23, 2025

#define _CRT_SECURE_NO_WARNINGS

#include "game_launcher.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define INVALID_VALUE -1
#define MAX_INPUT 10
#define ROMAN_SUBTRACTION_FACTOR 2

// Function prototype
// Function to convert Roman numeral to Hindu-Arabic numeral
int romanToInt(char character);

enum RomanNumerals {
	I = 1,
	V = 5,
	X = 10,
	L = 50,
	C = 100,
	D = 500,
	M = 1000
};

void romanDecoder(void) {
	char character; // Character input
	int romanNumeral = 0;
	int counter = 1; // Counter for number of times asked for input
	int currentValue = 0;
	int lastValue = 0;
	int total = 0;
	int isValid = 1; // Truthy: 1 for validity, Falsy: 0 for invalidness


	printf("%d Roman numeral values will be input and converted into\ntheir equivalent Hindu - Arabic numeric values.\n", MAX_INPUT);
	puts("");

	while (counter <= MAX_INPUT) {
		isValid = 1; // Reset validity
		lastValue = 0; // Reset last value
		total = 0; // Reset total

		printf("Input Roman numeral #%d: ", counter);

		while ((character = toupper(getchar())) != '\n') {
			currentValue = romanToInt(character); // Convert Roman numeral to Hindu-Arabic numeral

			if (currentValue == INVALID_VALUE && isValid) {
				printf("%c Error - last character was not valid!!!\n", character);
				isValid = 0; // Falsy
			}
			else if (!isValid) {
				printf("");
			}
			else {
				printf("%c", character);

				if (currentValue > 0 && lastValue < currentValue) {
					total += currentValue - ROMAN_SUBTRACTION_FACTOR * lastValue;
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


// Function to convert Roman numeral to Hindu-Arabic numeral
int romanToInt(char character) {
	switch (character) {
	case 'I': return I; break;
	case 'V': return V; break;
	case 'X': return X; break;
	case 'L': return L; break;
	case 'C': return C; break;
	case 'D': return D; break;
	case 'M': return M; break;
	default: return INVALID_VALUE;
	}
}
