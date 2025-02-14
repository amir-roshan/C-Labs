// Assignment 03: Duplicate Elimination
// Name: Amir Roshan
// Date: January 30, 2025

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

#define SIZE 20
#define ROWS 4
#define COLS 5

int isUnique(int ResultArray[], int value); // Function prototype
void displayArray(int array[]); // Function prototype

void duplicateElimination() {
	int counter = 1;
	int value = 0;
	int result[SIZE] = { 0 };

	while (counter <= SIZE)
	{
		printf("Enter #%d : ", counter);
		scanf("%d", &value);

		if (value >= 10 && value <= 100) {
			counter++;
			if (isUnique(result,value)) {
				printf("The number: %d is unique\n", value);
			}
		}
		else {
			printf("The number entered is not in the valid range of 10 to 100.\n");
		}
		puts("");
	}

	displayArray(result);
}

// Check if the number is unique then add it to the result
int isUnique( int ResultArray [], int value) {
	int uniqeNum = value;
	for (size_t i = 0; i < SIZE; i++) {
		if (ResultArray[i] == value) {
			return 0;
		}
	}
	
	for (size_t i = 0; i < SIZE; i++)
	{
		if (ResultArray[i] == 0) {
			ResultArray[i] = uniqeNum;
			return 1;
		}

	}
}


// Display the array
void displayArray(int resultArray[]) {

	printf("All of the unique numbers found are: \n");
	puts("");

	int rows = ROWS;
	int cols = COLS;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int value = resultArray[i * cols + j];
			if (value != 0) {
				printf("%5d ", value);
			}
			else {
				printf("");
			}
		}
		printf("\n");
	}
}