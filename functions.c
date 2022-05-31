#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "functions.h"

//Function that prints the menu for the user to choose from
void PrintMenu() {
    printf("MENU\n");
    printf("c - Number of non-whitespace characters\n");
    printf("w - Number of words\n");
    printf("f - Fix capitalization\n");
    printf("r - Replace all !'s\n");
    printf("s - Shorten spaces\n");
    printf("q - Quit\n");
}

//Function that executes the option entered by the user
void ExecuteMenu(char userLetter, char* userText) {
    switch (userLetter) {
        case 'c': 
            //Returns the number of characters
            printf("Number of non-whitespace characters: %d\n", GetChars(userText));
            break;
        case 'w':
            //Returns the number of words
            printf("Number of words: %d\n", GetWords(userText));
            break;
        case 'f':
            //Returns the capitalized text
            printf("Edited text: "); 
            FixCapitals(userText);
            printf("%s", userText);
            break;
        case 'r':
            //Returns the text without exclamation points
            printf("Edited text: ");
            ReplaceExclamation(userText);
            printf("%s", userText);
            break;
        case 's':
            //Returns the text without extra spaces
            printf("Edited text: ");
            ShortenSpaces(userText);
            printf("%s", userText);
        case 'q':
            //Quits if the user types q
            break;
    }
}

//Called if the user types c
int GetChars(const char* userText) {
    int count = 0;
    
    //Goes through the text and if the character is a letter or punctuation, increments count
    for (int i = 0; i < strlen(userText); ++i) {
        if (isalpha(userText[i]) != 0 || ispunct(userText[i]) != 0) {
            count++;
        }
    }

    return count;
}

//Called if the user types w
int GetWords(const char* userText) {
    int count = 0;

    //Goes through text and finds words by counting the spaces in between and incrementing count
    for (int i = 0; i < strlen(userText); ++i) {
        if ((userText[i] == ' ' && userText[i - 1] != ' ') || (userText[i] == ' ' && ispunct(userText[i - 1]) != 0)) {
            count++;
        }
    }

    //Returns count + 1 to account for the word at the end that is not counted by the above for loop
    return count + 1; 
}

//Called if the user types f
void FixCapitals(char* userText) {
    //Capitalizes first letter as the first letter should always be capitalized
    userText[0] = toupper(userText[0]); 
    
    for (int i = 0; i < strlen(userText); ++i) {
        //If a punctuation character is found, moves the loop up while there are no letters until a letter is found
        if (userText[i] == '.' || userText[i] == '?' || userText[i] == '!') {
            while (isalpha(userText[i]) == 0) {
                i++;
            }
            //Capitalizes the first letter after punctuation
            userText[i] = toupper(userText[i]);
        }
    }
}

//Called if the user types r
void ReplaceExclamation(char* userText) {
    //Loops through the text and replaces all ! with .
    for (int i = 0; i < strlen(userText); ++i) {
        if (userText[i] == '!') {
            userText[i] = '.';
        }
    }
}

//Called if the user types s
void ShortenSpaces(char* userText) {
    int count = 0;
    
    for (int i = 0; i < strlen(userText); ++i) {
        //Increments count so a null character may be attached to the end of the text
        count++;
        //While there are two spaces are together, the user text gets pushed forward
        while (userText[i] == ' ' && userText[i - 1] == ' ') {
            userText[i] = userText[i + 1]; 
            //Pushes forward the letters that have already been checked
            for (int j = i; j < strlen(userText); ++j) {
                userText[j] = userText[j + 1];
            }
        }
    }

    //Null character is attached to the end
    userText[count] = '\0';
}