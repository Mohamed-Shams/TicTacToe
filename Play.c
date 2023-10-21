#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<ctype.h>
#include"Functions.h"
#include<windows.h>
#include<unistd.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Function to start the game
void Play()
{
	char ch;
	again: 
	system(CLEAR);
	 // Get the game mode and initialize the game
    int Mode = ChooseMode();
    if (Mode == 2) {
        // Multiplayer mode
        ResetBoard();
        GetNames();
        GetSymbol();
        PlayerOneTurn();
    } else if (Mode == 1) {
        // Single-player mode
        SelectMode();
        ResetBoard();
        PlayerName();
        GetSymbol_SM();
        PlayerTurn();
	}
    printf("\nPress [q] To exit, or any other key Enter to play again: ");
    scanf(" %c", &ch);
    if ((ch != 'q' && ch != 'Q')) {
       	goto again;
    }
}