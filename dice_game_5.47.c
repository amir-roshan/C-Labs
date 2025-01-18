// Exercise 5.47 Solution 
// Name: 
// Date: 

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// enumeration constants represent game status 
enum Status { CONTINUE, WON, LOST };

int INIT_BANK_BALANCE = 1000;

int rollDice(void); // function prototype 
enum Status craps(void); // function prototype 
void chatter(void); // function prototype 

void diceGame()
{
    enum Status result;     // result of current game 
    int wager = 0;          // wager for current game 
    int bankBalance = INIT_BANK_BALANCE; // current bank balance 
    int not_broke = 1;      // boolean flag to indicate if broke
    int continue_playing = 1;  // boolean flag to indicate if player wants to continue playing

    srand((unsigned int)time(NULL)); // seed random number generator 

    // display current balance and prompt for wager 
    printf("You have $%d in the bank.\n\n", bankBalance);
    printf("Place your wager: ");
    scanf("%d", &wager);

    // loop while not valid wager 
    while (wager <= 0 || wager > 1000) {
        printf("Please bet a valid amount.\n");
        scanf("%d", &wager);
    } // end while 

    while (not_broke && continue_playing)
    {
		int result = craps();
		int doDice = 1;
        while (doDice) {
            if (result == WON) {
                bankBalance += wager;
				doDice = 0;
            }
            else if (result == LOST) {
                bankBalance -= wager;
                doDice = 0;
            }
            else {
				doDice = 1;
                result = craps();
            }

            if (bankBalance <= 0) {
                not_broke = 0;
				printf("Sorry. You busted!\n");
            }
        }
		chatter();

		printf("You have $%d in the bank.\n\n", bankBalance);

		printf("Place your next wager (-1 to quit): ");
		scanf("%d", &wager);

		if (wager == -1) {
			continue_playing = 0;
        }
    }
} // end main 

// roll dice, calculate sum and display results 
int rollDice(void)
{
    int die1;    // first die value 
    int die2;    // second die value 
    int workSum; // sum of dice 

    die1 = 1 + rand() % 6; // pick random die1 value 
    die2 = 1 + rand() % 6; // pick random die2 value 
    workSum = die1 + die2; // sum die1 and die2 

    // display results of this roll 
    printf("Player rolled %d + %d = %d\n", die1, die2, workSum);

    return workSum; // return sum of dice 
} // end function rollDice 

// craps plays one game of craps, returns result of game 
enum Status craps(void)
{   
	enum Status result; // game result
    int sum = rollDice();

    if (sum == 7 || sum == 11) {
        result = WON;
    }
    else if (sum == 2 || sum == 3 || sum == 12) {
        result = LOST;
    }
    else {
        result = CONTINUE;
    }
	return result;
} // end function craps 

// chatter displays messages at random to create "chatter" 
void chatter(void)
{
    int select; // random number 
    puts("");
    select = 1 + rand() % 6;

    // choose message at random 
    switch (select) {

    case 1:
        printf("Oh, you're going for broke, huh?\n");
        break; // exit switch 

    case 2:
        printf("Aw cmon, take a chance!\n");
        break; // exit switch 

    case 3:
        printf("Hey, I think this guy is going to break the bank!!\n");
        break; // exit switch 

    case 4:
        printf("You're up big. Now's the time to cash in your chips!\n");
        break; // exit switch 

    case 5:
        printf("Way too lucky! Those dice have to be loaded!\n");
        break; // exit switch 

    case 6:
        printf("Bet it all! Bet it all!\n");
        break; // exit switch 

    default:
        printf("ERROR!!! Reached default case in chatter() function.");
        break; // exit switch 
    } // end switch 
} // end function chatter 