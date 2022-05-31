#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Declares functions to bedefined in the c file
void PrintMenu();
void ExecuteMenu(char userLetter, char* userText);
int GetChars(const char* userText);
int GetWords(const char* userText);
void FixCapitals(char* userText);
void ReplaceExclamation(char* userText);
void ShortenSpaces(char* userText);

#endif