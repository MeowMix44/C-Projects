//This program takes in input from the user and shows a menu with options and the program runs until the q (quit) option is chosen
#include <stdio.h>
#include <string.h>

#include "functions.h"

int main (void) {
    char userText[250];
    char userLetter;

    //Prompts the user to input a string that can include special characters
    printf("Enter a sample text:\n");
    fgets(userText, 250, stdin);

    //Displays what was entered and then calls the function to print the menu that then takes in an option
    printf("\nYou entered: %s\n", userText);
    PrintMenu();
    printf("\nChoose an option:\n");
    scanf(" %c", &userLetter);

    //While the user does not input q and while the letter is an option from the menu
    while (userLetter != 'q') {
        while (userLetter != 'c' || userLetter != 'w' || userLetter != 'f' || userLetter != 'r' || userLetter != 's' || userLetter != 'q') {
            if (userLetter == 'c' || userLetter == 'w' || userLetter == 'f' || userLetter == 'r' || userLetter == 's' || userLetter == 'q') {
                break;
            }
            printf("Choose an option:\n");
            scanf(" %c", &userLetter);
        }
        //Calls the ExecuteMenu function and repeats the command to choose an option from the menu
        ExecuteMenu(userLetter, userText);
        printf("\n");
        PrintMenu();
        printf("\nChoose an option:\n");
        scanf(" %c", &userLetter);
    }

    return 0;
}