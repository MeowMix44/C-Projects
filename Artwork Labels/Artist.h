#ifndef ARTIST_H
#define ARTIST_H

//Initializes a struct called Artist with 3 variables in it
typedef struct Artist_struct {
    char artistName[20];
    int birthYear;
    int deathYear;
} Artist;

//Initializes functions to be defined in Artist.c
Artist InitArtist();
Artist SetArtist(char* name, int birthYear, int deathYear);
void PrintArtist(Artist artist);
void GetName(char* name, Artist artist);
int GetBirthYear(Artist artist);
int GetDeathYear(Artist artist);

#endif