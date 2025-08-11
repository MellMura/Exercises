#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int generateComputerChoice();
void compareResults(char player[], char computer[]);

int main() {
	srand(time(NULL));
	char *options[] = {"rock", "paper", "scissors"};
	bool gameEnded = false;
	
	while (!gameEnded) {
		bool valid = false;
		char playerChoice[30];
	while (!valid) {
		printf("\nWhat would you like to play? Rock, paper or scissors?\n");
		scanf("%s", playerChoice);
		
		for(int i = 0; playerChoice[i]; i++) {
        	playerChoice[i] = tolower(playerChoice[i]);
        }

        if (strcmp(playerChoice, "rock") != 0 && strcmp(playerChoice, "paper") != 0 && strcmp(playerChoice, "scissors") != 0) {
        	printf("\033[31mInvalid option!\033[0m\n");
        } else {
        	valid = true;
        }
	}
	
	int choiceIndex = generateComputerChoice();
	char *computerChoice = options[choiceIndex];
	
	char modifiedChoice[30];
	strcpy(modifiedChoice, computerChoice);
	
	for(int i = 0; modifiedChoice[i]; i++) {
        	modifiedChoice[i] = tolower(modifiedChoice[i]);
    }

	printf("\nUser: %s\n", playerChoice);
	printf("Computer: %s\n\n", modifiedChoice);
	
	compareResults(playerChoice, modifiedChoice);
	
	char play[10];
	bool valid2 = false;
	while (!valid2) {
		printf("\nPlay again? (Yes|no)\n");
		scanf("%s", play);
	
		for(int i = 0; play[i]; i++) {
        	play[i] = tolower(play[i]);
    	}
    	
		if (strcmp(play, "yes") != 0 && strcmp(play, "no") != 0) {
			printf("\033[31mInvalid option!\033[0m\n\n");
		}
		else if (strcmp(play, "no") == 0) {
			gameEnded = true;
			break;
		}
		else {
			valid2 = true;
			continue;
		}
	}
	}
}
	
int generateComputerChoice() {
	int compChoice = rand() % 3;
	return compChoice;
}

void compareResults(char player[], char computer[]) {
	if (strcmp(player, "rock") == 0) {
        if (strcmp(computer, "rock") == 0) {
            printf("\033[33mDraw!\033[0m\n");
        } else if (strcmp(computer, "paper") == 0) {
            printf("\033[31mYou lose! :(\033[0m\n");
        } else if (strcmp(computer, "scissors") == 0) {
            printf("\033[32mYou win! :)\033[0m\n");
        }
    } 
    else if (strcmp(player, "paper") == 0) {
        if (strcmp(computer, "rock") == 0) {
            printf("\033[32mYou win! :)\033[0m\n");
        } else if (strcmp(computer, "paper") == 0) {
            printf("\033[33mDraw!\033[0m\n\n");
        } else if (strcmp(computer, "scissors") == 0) {
            printf("\033[31mYou lose! :(\033[0m\n");
        }
    } 
    else if (strcmp(player, "scissors") == 0) {
        if (strcmp(computer, "rock") == 0) {
            printf("\033[31mYou lose! :(\033[0m\n");
        } else if (strcmp(computer, "paper") == 0) {
            printf("\033[32mYou win! :)\033[0m\n");
        } else if (strcmp(computer, "scissors") == 0) {
            printf("\033[33mDraw!\033[0m\n");
        }
    }
}

