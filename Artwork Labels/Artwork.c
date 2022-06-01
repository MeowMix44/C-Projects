#include <stdio.h>
#include "Artwork.h"
#include <string.h>

//Initialies the Artwork struct variables in artwork  
Artwork InitArtwork() {
    Artwork artwork;
    
    strcpy(artwork.artName, "None");
    artwork.yearSet = 0;
    artwork.artist = InitArtist();

    return artwork;
}

//Sets the artwork variables to values given by the user
Artwork SetArtwork(char* title, int yearCreated, Artist artist) {
    Artwork artwork;
    
    strcpy(artwork.artName, title);
    artwork.yearSet = yearCreated;

    return artwork;
}

//Prints the title of the artwork
void GetTitle(char* title, Artwork artwork) {
    strcpy(artwork.artName, title);
    printf("%s", title);
}

//Returns the year the artwork was created
int GetYearCreated(Artwork artwork) {
    return artwork.yearSet;
}

//Returns the name of the artist that created the artwork
Artist GetArtist(Artwork artwork) {
    return artwork.artist;
}

//Prints the variables associated with the artwork with a nested function that prints variables associated with the artist
void PrintArtwork(Artwork artwork) {
    PrintArtist(artwork.artist);
    printf("Title: %s, ", artwork.artName);
    printf("%d\n", artwork.yearSet);
}