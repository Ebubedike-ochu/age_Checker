#include <stdio.h>
#include <time.h>

int main(void) {
    int birthYear, age;
    time_t t;
    struct tm tm;
    int currentYear;

    while (1) {
        t = time(NULL);
        tm = *localtime(&t);
        currentYear = tm.tm_year + 1900;

        printf("Welcome to Bet-Ebubedike: \n  Enter your birth year: ");
        if (scanf("%d", &birthYear) != 1) {
            printf("Invalid input. Please enter numbers only.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        if (birthYear < 1900 || birthYear > currentYear) {
            printf("Invalid birth year. Please enter a year between 1900 and %d.\n", currentYear);
            continue;
        }

        age = currentYear - birthYear;
        printf("You are %d years old.\n", age);

        if (age >= 18) {
            printf("Access granted. Welcome to SportBet, You are Free to Liquidate!\n");
        } else {
            printf("Access denied. You're not old enough to be a Gambler.\n");
        }

        printf("\n"); // Add a blank line before next loop
    }

    return 0;
}
