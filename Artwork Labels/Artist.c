#include <stdio.h>
#include <string.h>
#include "Artist.h"

//Creates an Artist struct
Artist InitArtist() {
    Artist artist;
    
    //Initializes the struct artist variables
    strcpy(artist.artistName, "None");
    artist.birthYear = 0;
    artist.deathYear = 0;

    return artist;
}

//Sets the birthYear, artistName, and deathYear to variables
Artist SetArtist(char* name, int birthYear, int deathYear) {
    Artist artist;
    
    strcpy(artist.artistName, name);
    artist.birthYear = birthYear;
    artist.deathYear = deathYear;

    return artist;
}

//Prints the artist's name
void GetName(char* name, Artist artist) {
    strcpy(artist.artistName, name);
    printf("Artist: %s", name);
}

//Returns the artist's birth date
int GetBirthYear(Artist artist) {
    return artist.birthYear;
}

//Prints the artist's death date
int GetDeathYear(Artist artist) {
    return artist.deathYear;
}

void PrintArtist(Artist artist) {
    int deathDate;
    
    GetName(artist.artistName, artist);
    deathDate = GetDeathYear(artist);
    
    //If the death date is not known, then only the birth date is shown
    if (deathDate == -1) {
        printf(", born %d\n", GetBirthYear(artist));
    }
    //If the deathdate is known, it is printed along with the birth date
    else if (deathDate != -1) {
        printf(" (%d-", GetBirthYear(artist));
        printf("%d)\n", deathDate);
    }
}