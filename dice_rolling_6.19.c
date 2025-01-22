// Exercise 6.19
// Name: Amir Roshan
// Date: January 21, 2025

#include "game_launcher.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 7


void diceRolling(void) {
	int frequency[SIZE] = { 0 };

	srand(time(NULL));

	size_t face = 1 + rand() % 6;

}