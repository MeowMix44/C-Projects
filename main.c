#include <stdio.h>
#include <string.h>

#include "Artist.h"
#include "Artwork.h"

int main(void) {
	//Declares variables
	char title[20];
	char name[20];
	int birthYear;
	int deathYear;
	int yearCreated;

	//Takes in the name of the artist, birth date, death date, and the year created 
	fgets(name, 20, stdin);
	scanf("%d\n", &birthYear);
	scanf("%d\n", &deathYear);
	fgets(title, 20, stdin);
	scanf("%d", &yearCreated);

	//remove newline character after name and title
	strtok(name, "\n");
	strtok(title, "\n");

	//Creates objects artist and artwork and initializes them 
	Artist artist = SetArtist(name, birthYear, deathYear);
	Artwork artwork = SetArtwork(title, yearCreated, artist);

	//Calls PrintArtwork() function to print it in format
	PrintArtwork(artwork);

	return 0;
}