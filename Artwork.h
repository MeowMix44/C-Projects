#ifndef ARTWORK_H
#define ARTWORK_H

#include "Artist.h"

//Declares a struct Artwork that has 2 variables and a nested struct artist
typedef struct Artwork_Struct {
    char artName[20];
    int yearSet;
    Artist artist;
} Artwork;

//Declares functions to be defined in Artwork.c
Artwork InitArtwork();
Artwork SetArtwork(char* title, int yearCreated, Artist artist);
void GetTitle(char* title, Artwork artwork);
int GetYearCreated(Artwork artwork);
Artist GetArtist(Artwork artwork);
void PrintArtwork(Artwork artwork);

#endif