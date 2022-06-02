//Lucy Wang
//9/30/2021
//Section 001
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char player1[50];
   char player2[50];
   int rounds;
   int gameRandomizer;
   int player1Choice;
   int player2Choice;
   int player1Score = 0;
   int player2Score = 0;

   //Asks users for the names of the players and how many rounds they wanna play
   printf("Enter player 1: \n");
   scanf("%s", player1);
   printf("Enter player 2: \n");
   scanf("%s", player2);
   printf("How many rounds to play? \n");
   scanf("%d", &rounds);

   //Error message for when the user inputs an invalid round number
   while (rounds < 1) {
      printf("How many rounds to play? \n");
      scanf("%d", &rounds);
   }
   //User inputs a number to seed rand with 
   printf("Pick a number to randomize game: \n");
   scanf("%d", &gameRandomizer);
   printf("Starting game with %s versus %s for %d rounds!\n", player1, player2, rounds);
   srand(gameRandomizer);
   
   //Begins the game by randomly choosing rock, paper, or scissors for each player (1 = rock, 2 = paper, and 3 = scissors) 
   //Adds a point to whichever player wins the round
   //Prints out who wins and what they won with
   for (int i = 1; i <= rounds; ++i) {
      player1Choice = (rand() % 3) + 1;
      player2Choice = (rand() % 3) + 1;
      if (player1Choice == 1 && player2Choice == 2) { 
         player2Score += 1;
         printf("%s wins round %d with PAPER\n", player2, i);
      }
      else if (player1Choice == 1 && player2Choice == 3) {
         player1Score += 1;
         printf("%s wins round %d with SCISSORS\n", player1, i);
      }
      else if (player1Choice == 2 && player2Choice == 1) {
         player1Score += 1; 
         printf("%s wins round %d with PAPER\n", player1, i);
      }
      else if (player1Choice == 2 && player2Choice == 3) {
         player2Score += 1;
         printf("%s wins round %d with SCISSORS\n", player2, i);
      }
      else if (player1Choice == 3 && player2Choice == 1) {
         player2Score += 1;
         printf("%s wins round %d with ROCK\n", player2, i);
      }
      else if (player1Choice == 3 && player2Choice == 2) {
         player1Score += 1;
         printf("%s wins round %d with SCISSORS\n", player1, i);
      }
      //If the numbers are the same, then there is a tie
      else if (player1Choice == player2Choice) {
         printf("Round %d is a TIE\n");
      }
      //At the end of the loop, this prints the points each player has
      if (i == rounds) {
         printf("\n%s wins %d and %s wins %d\n", player1, player1Score, player2, player2Score);
      }
   }

   return 0;
}