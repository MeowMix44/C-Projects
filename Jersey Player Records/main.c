//Lucia Wang
//Section 1
//11/02/2021
#include <stdio.h>

//Creates a struct to store the info of the players
typedef struct PlayerInfo_struct {
   char firstName[20];
   char lastName[20];
   int playerJersey;
   int playerRating;
} PlayerInfo;

//Declares functions to be defined elsewhere
void GetPlayerInfo(PlayerInfo playerInfo[], int players);
void PrintRoster(PlayerInfo playerInfo[], int players);
void UpdateRating(PlayerInfo playerInfo[], int players);
void FindAbove(PlayerInfo playerInfo[], int players);
void ReplacePlayer(PlayerInfo playerInfo[], int players);

int main(void) {
   //Initializes variables with the given conditions and restrictions
   int players = 0;
   char userLetter;

   //Asks the user to input how many players there are
   printf("How many players to enter: ");
   scanf("%d", &players);

   PlayerInfo playerInfo[players];
   GetPlayerInfo(playerInfo, players);
    
   //Fills two arrays with the player jersey numbers and corresponding rating

   //Runs while the user does not hit q for quit
   while (userLetter != 'q') {
      //Resets check to 0 every interation
      printf("MENU\no - Output roster");
      printf("\nu - Update player rating");
      printf("\na - Output players above a rating");
      printf("\nr - Replace player");
      printf("\nq - Quit");
      printf("\nChoose an option:\n");
      scanf(" %c", &userLetter);
      //Checks and runs if the user inputs a letter from the menu  
      switch (userLetter) {
         //Outputs players's jersey number and rating
         case 'o': 
            PrintRoster(playerInfo, players);
            break;
         //Changes a jersey's rating
         case 'u': 
            UpdateRating(playerInfo, players);
            break;
         //Prints values above entered rating
         case 'a':
            FindAbove(playerInfo, players);
            break;
         //Replaces a player
         case 'r':
            ReplacePlayer(playerInfo, players);
            break;
         //Stops the program
         case 'q': 
            break;
         default: 
            break;
      }
   }

   return 0;
}

void GetPlayerInfo(PlayerInfo playerInfo[], int players) {
   for (int i = 0; i < players; ++i) {
      printf("Enter player %d first name:\n", i + 1);
      scanf("%s", playerInfo[i].firstName);

      printf("Enter player %d last name:\n", i + 1);
      scanf("%s", playerInfo[i].lastName);

      printf("\nEnter player %d's jersey number:\n", i + 1);
      scanf("%d", &playerInfo[i].playerJersey);

      printf("Enter player %d's rating:\n", i + 1);
      scanf("%d", &playerInfo[i].playerRating);
   }
}

void PrintRoster(PlayerInfo playerInfo[], int players) {
   printf("ROSTER\n");
   for (int i = 0; i < players; ++i) {
      printf("Player %d -- Name: %s %s, Jersey number: %d, Rating: %d\n", i + 1, playerInfo[i].firstName, playerInfo[i].lastName, playerInfo[i].playerJersey, playerInfo[i].playerRating);
   }
}

void UpdateRating(PlayerInfo playerInfo[], int players) {
   int jersey = 0;
   int newRating = 0;
   int check = 0;
   int place = 0;
   
   printf("Enter a jersey number:\n");
   scanf("%d", &jersey);
   //Checks if entered number is in the array 
   for (int i = 0; i < players; ++i) {
      if (playerInfo[i].playerJersey == jersey) {
         check++;
      }
   }
   
   //Keeps track of where in the array the player is
   for (int i = 0; i < players; ++i) {
      place++;
      if (playerInfo[i].playerJersey == jersey) {
         break;
      }
   }
   if (check == 0) {
      printf("Player not in roster.\n");
   }
   else {
      printf("Enter a new rating for player:\n");
      scanf("%d", &newRating);
   }
   if (check != 0) {
      playerInfo[place - 1].playerRating = newRating;
   }
}

void FindAbove(PlayerInfo playerInfo[], int players) {
   int rating = 0;
   
   //Prompts the user to enter a rating
   printf("Enter a rating:");
   scanf("%d", &rating);
   //Prints all players that have a rating higher than the number input by the user
   printf("\nABOVE %d\n", rating);
   for (int i = 0; i < players; ++i) {
      if (playerInfo[i].playerRating > rating) {
         printf("Player %d -- Name: %s %s, Jersey number: %d, Rating: %d\n", i + 1, playerInfo[i].firstName, playerInfo[i].lastName, playerInfo[i].playerJersey, playerInfo[i].playerRating);
      }
   }
}

void ReplacePlayer(PlayerInfo playerInfo[], int players) {
   int jersey = 0;
   int check = 0;
   int newJersey = 0;
   int rating = 0;
   
   printf("Enter a jersey number to replace:\n");
   scanf("%d", &jersey);
   //Searches the playerInfo array for the jersey number entered and increments check if found
   for (int i = 0; i < players; ++i) {
      if (playerInfo[i].playerJersey == jersey) {
         check++;
      }
   }
   //If the player is not in the roster, prints an error message
   if (check == 0) {
      printf("Player not in roster.\n");
   }
   //Prompts the user to enter new information for the player being replaced and replaces them in the array
   else {
      printf("Enter a first name for the new player:\n");
      scanf("%s", playerInfo[check].firstName);
      printf("Enter a last name for the new player:\n");
      scanf("%s", playerInfo[check].lastName);
      printf("Enter a jersey number for the new player:\n");
      scanf("%d", &newJersey);
      for (int i = 0; i < players; ++i) {
         if (playerInfo[i].playerJersey == jersey) {
            playerInfo[i].playerJersey = newJersey;
         }
      }
      printf("Enter a rating for the new player:\n");
      scanf("%d", &rating);
      for (int i = 0; i < players; ++i) {
         if (playerInfo[i].playerJersey == newJersey) {
            playerInfo[i].playerRating = rating;
         }
      }
   } 
}