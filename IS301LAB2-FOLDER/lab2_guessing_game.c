/*
Name: Jasmine Sakopa
Student ID: (230183)
Date: (20/03/26)
Course: IS301 Structured Programming
Lab 2 – Guessing Game

Algorithm
1. Start the program.
2. Generate a random number between 1 and 20.
3. Display message asking user to guess the number.
4. Allow the user 5 tries using a loop.
5. Each time:
      - Get guess from user using a function.
      - If guess is lower than the number → print "Your guess is low. Try again:"
      - If guess is higher than the number → print "Your guess is high. Try again:"
      - If guess equals the number → print success message and end program.
6. If user fails after 5 tries:
      - Print sorry message showing the correct number.
7. End program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getGuess();
void successfulMessage();
void unsuccessfulMessage();
void sorryMessage(int number);

int main()
{
    int randomNumber, guess, i;

    srand(time(NULL));
    randomNumber = rand() % 20 + 1;

    printf("I am thinking of a number between 1 and 20.\n");
    printf("Can you guess what it is?\n");

    for(i = 1; i <= 5; i++)
    {
        guess = getGuess();

        if(guess < randomNumber)
        {
            printf("Your guess is low. Try again:\n");
        }
        else if(guess > randomNumber)
        {
            printf("Your guess is high. Try again:\n");
        }
        else
        {
            successfulMessage();
            return 0;
        }
    }

    unsuccessfulMessage();
    sorryMessage(randomNumber);

    return 0;
}

int getGuess()
{
    int guess;
    scanf("%d", &guess);
    return guess;
}

void successfulMessage()
{
    printf("Congratulations! You did it.\n");
}

void unsuccessfulMessage()
{
    printf("You have used all your tries.\n");
}

void sorryMessage(int number)
{
    printf("Sorry. The number was %d.\n", number);
    printf("You should have gotten it by now.\n");
    printf("Better luck next time.\n");
}



 
  

     
