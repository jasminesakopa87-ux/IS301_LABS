/*
 * Full Name  : [Jasmine SAKOPA]
 * Student ID : [230183]
 * Date       : 18th of March 2026
 * Course     : IS301 Structured Programming - Lab 2
 *
 * Algorithm:
 * 1. START
 * 2. Generate a random number between 1 and 20 (secret)
 * 3. Display opening message to user
 * 4. Set tries = 0
 * 5. REPEAT (up to 5 times):
 *    a. Call getGuess() to read the user's guess
 *    b. Increment tries
 *    c. IF guess == secret THEN
 *          Call printSuccess()
 *          STOP (exit program)
 *    d. ELSE IF guess < secret THEN
 *          Print "Your guess is low."
 *    e. ELSE
 *          Print "Your guess is high."
 *    f. IF tries < 5 THEN print "Try again: "
 * 6. After 5 failed tries:
 *    Call printSorry(secret)
 * 7. STOP
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
int  getGuess(void);
void printSuccess(void);
void printUnsuccessful(void);
void printSorry(int secret);

/* -------------------------------------------------------
 * getGuess
 * Prompts the user and reads a single integer guess.
 * Returns the guess entered by the user.
 * ------------------------------------------------------- */
int getGuess(void) {
    int guess;
    scanf("%d", &guess);
    return guess;
}

/* -------------------------------------------------------
 * printSuccess
 * Prints the congratulations message when the user
 * guesses the number correctly.
 * ------------------------------------------------------- */
void printSuccess(void) {
    printf("Congratulations! You did it.\n");
}

/* -------------------------------------------------------
 * printUnsuccessful
 * Prints a message indicating the guess was wrong and
 * prompts for the next attempt.
 * ------------------------------------------------------- */
void printUnsuccessful(void) {
    printf("Try again: ");
}

/* -------------------------------------------------------
 * printSorry
 * Prints the sorry message when the user exhausts all
 * five attempts without guessing correctly.
 * secret - the number the computer had chosen
 * ------------------------------------------------------- */
void printSorry(int secret) {
    printf("Sorry. The number was %d. ", secret);
    printf("You should have gotten it by now. Better luck next time.\n");
}

/* -------------------------------------------------------
 * main
 * Entry point. Runs the guessing game.
 * ------------------------------------------------------- */
int main(void) {
    int secret, guess, tries;

    /* Seed the random number generator with the current time */
    srand((unsigned int)time(NULL));

    /* Generate a random number between 1 and 20 (inclusive) */
    secret = (rand() % 20) + 1;

    /* Opening prompt */
    printf("I am thinking of a number between 1 and 20. ");
    printf("Can you guess what it is? ");

    /* Allow up to 5 guesses */
    for (tries = 1; tries <= 5; tries++) {

        guess = getGuess();

        if (guess == secret) {
            printSuccess();
            return 0;           /* Correct guess - end program immediately */
        } else if (guess < secret) {
            printf("Your guess is low. ");
        } else {
            printf("Your guess is high. ");
        }

        /* Prompt for next guess only if tries remain */
        if (tries < 5) {
            printUnsuccessful();
        }
    }

    /* User exhausted all 5 tries */
    printSorry(secret);

    return 0;
}
