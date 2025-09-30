#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* choices[] = {
    "0 = Rock", "1 = Paper", "2 = Scissors", "3 = Lizard", "4 = Spock"
};

void printGameRules() {
    printf("The rules are as follows:\n");
    printf("Rock crushes Scissors and Lizard\n");
    printf("Paper covers Rock and disproves Spock\n");
    printf("Scissors cuts Paper and decapitates Lizard\n");
    printf("Lizard eats Paper and poisons Spock\n");
    printf("Spock vaporizes Rock and smashes Scissors\n");
}

int determineWinner(int player, int computer) {
    if (player == computer) {
        return 0; // Tie
    }

    // Winning conditions:
    if ((player == 0 && (computer == 2 || computer == 3)) ||  // Rock
        (player == 1 && (computer == 0 || computer == 4)) ||  // Paper
        (player == 2 && (computer == 1 || computer == 3)) ||  // Scissors
        (player == 3 && (computer == 1 || computer == 4)) ||  // Lizard
        (player == 4 && (computer == 0 || computer == 2))) {  // Spock
        return 1; // Player wins
    }
    return -1; // Computer wins
}

int getPlayerChoice() {
    int choice;

    printf("Enter your choice (Rock, Paper, Scissors, Lizard, Spock): ");
    while (scanf("%d", &choice) != 1 || choice < 0 || choice > 4) {
        printf("Invalid choice. Please enter a number between 0 and 4: ");
        while (getchar() != '\n'); // clear input buffer
    }
    return choice;
}

int getComputerChoice() {
    return rand() % 5;
}

int main() {
    int playerScore = 0;
    int computerScore = 0;

    printf("Hello, I want to play a game!\n");
    printf("Rock-Paper-Scissors-Lizard-Spock!\n");
    printf("The winner is the first to 5 points!\n");
    printGameRules();
    printf("Good luck!\n");
    printf("Here are your choices:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", choices[i]);
    }

    srand(time(NULL)); // seed RNG

    while (playerScore < 5 && computerScore < 5) {
        int playerChoice = getPlayerChoice();
        int computerChoice = getComputerChoice();

        printf("You chose: %s\n", choices[playerChoice]);
        printf("Computer chose: %s\n", choices[computerChoice]);

        int result = determineWinner(playerChoice, computerChoice);
        if (result == 0) {
            printf("It's a tie!\n");
        } else if (result == 1) {
            printf("You win!\n");
            playerScore++;
        } else {
            printf("Computer wins!\n");
            computerScore++;
        }
        printf("Score: You %d - %d Computer\n\n", playerScore, computerScore);
    }

    if (playerScore == 5) {
        printf("The winner is the player!\n");
        printf("Congratulations you've won!\n");
    } else {
        printf("The winner is the computer!\n");
        printf("Better luck next time!\n");
    }
    printf("Thanks for playing!\n");
    return 0;
}