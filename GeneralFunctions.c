#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<time.h>
#include<ctype.h>
#include"Functions.h"
#include<windows.h>
#include<unistd.h>

int status = -1;
char Board[3][3];
char PlayerOne[20];
char PlayerTwo[20];
char PlayerOneSymbol[2];
char PlayerTwoSymbol[2];
static int TurnNumber;
static int TurnNumber2;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


void clearbuffer()
{
	while(getchar()!='\n');
}
int ChooseMode()
{
	int mode;
	while(1)
	{
		printf("Enter Mode:\n\t[1] Single Mode \t [2] MultiMode: \n");
		scanf("%d",&mode);
		getchar();
		if(mode == 1)
		{
			system(CLEAR);
			return 1;
			break;
		}
		else if (mode == 2)
		{
			system(CLEAR);
			return 2;
			break;
		}
		else
		{
			printf("Invalid Input!, TRY AGAIN!\n");
		}
	}
}
void PrintBoard()
{
	printf("\n");
	printf("\033[0;32m"); // Set the text color to green
	printf("        %c | %c | %c ", Board[0][0], Board[0][1], Board[0][2]);
	printf("\n       ---|---|---\n");
	printf("        %c | %c | %c ", Board[1][0], Board[1][1], Board[1][2]);
	printf("\n       ---|---|---\n");
	printf("        %c | %c | %c ", Board[2][0], Board[2][1], Board[2][2]);
	printf("\033[0m"); // Reset the text color to default
	printf("\n\n");
}
void ResetBoard()
{
	char c= '1';
	for(int i = 0; i<3 ; i++)
	{
		for(int j = 0; j<3 ; j++)
		{
			Board[i][j] = c;
			c++;
		}
	}
}

void GetNames()
{
	int i = 0;
	printf("Enter Player One Name: ");
	gets(PlayerOne);
	printf("Enter Player Two Name: ");
	gets(PlayerTwo);
	if (strcmp(PlayerOne, PlayerTwo) == 0) 
	{
    int i = 0;
    while (PlayerOne[i] != '\0') 
	{
        i++;
    }
    strcat(PlayerOne, "_1");
    strcat(PlayerTwo, "_2");
	}
	printf("\nHit Enter to continue .....\n");
	clearbuffer();
	system(CLEAR);
}

void GetSymbol()
{
	printf("%s! Choose between X or O: ",PlayerOne);
	scanf("%s",PlayerOneSymbol);
	//getchar();	
	while(1)
	{
		if(((PlayerOneSymbol[0] == 'x') || (PlayerOneSymbol[0] == 'X')) && (PlayerOneSymbol[1] == '\0') )
		{
			PlayerOneSymbol[0] = 'X';
			PlayerTwoSymbol[0] = 'O';
			break;
		}
		else if(((PlayerOneSymbol[0] == 'o') || (PlayerOneSymbol[0] == 'O') || (PlayerOneSymbol[0] == '0')) && (PlayerOneSymbol[1] == '\0'))
		{
			PlayerOneSymbol[0] = 'O';
			PlayerTwoSymbol[0] = 'X';
			break;
		}
		else
		{
			printf("Invalid Input!! TRY AGAIN\n");
			printf("%s!, Choose between X or O: ",PlayerOne);
			scanf("%s",PlayerOneSymbol);
			getchar();
		}
	}
	printf("%s is %s\n",PlayerOne,PlayerOneSymbol);
	printf("%s is %s\n",PlayerTwo,PlayerTwoSymbol);

	printf("\nHit Enter to continue .....\n");
	getchar();
	getchar();
	system(CLEAR);
}

void PlayerOneTurn()
{
	again: if((CheckFreeSpace() == '0' && CheckStatus()!= 'X' && CheckStatus()!= 'O'))
	{
		system(CLEAR);
		PrintBoard();
		int num=0;
		int i,j;
		printf("\n%s!, it's your turn\nEnter the place number: ",PlayerOne);
		scanf("%d",&TurnNumber);
		
		for(i=0; i<3; i++)
		{
			for(j=0; j<3; j++)
			{
				num++;
				if(num == TurnNumber)
				{
					break;
				}
			}
			if(num == TurnNumber)
			{
				num=0;
				break;
			}
		}
		while(1)
		{
			if(TurnNumber>9)
			{
				printf("Are U kidding me? Make Some Sense");
				printf("\nHit Enter to continue .....");
				clearbuffer();
				clearbuffer();
				goto again;
			}
			else if((Board[i][j] == PlayerTwoSymbol[0]))
			{
				printf("Trying To Cheat!!, Make Some Sense!");
				printf("\nHit Enter to continue .....");
				clearbuffer();
				clearbuffer();		
				goto again;
			}
			else if((Board[i][j] == PlayerOneSymbol[0]))
			{
				printf("It's Saved From YOUUU!!, Make Some Sense!");
				printf("\nHit Enter to continue .....");
				clearbuffer();
				clearbuffer();
				goto again;
			}
			else
			{
				Board[i][j] = PlayerOneSymbol[0];
				PlayerTwoTurn();
				break;
			}
		}
	}
	else if(CheckFreeSpace() == '0' && CheckStatus() == PlayerOneSymbol[0])
	{
		system(CLEAR);
		PrintBoard();
		printf("The Winner is: %s",PlayerOne);
		return;
	}
	else if(CheckFreeSpace() == '0' && CheckStatus() == PlayerTwoSymbol[0])
	{
		system(CLEAR);
		PrintBoard();
		printf("The Winner is: %s",PlayerTwo);
		return;
	}
	else
	{
		system(CLEAR);
		PrintBoard();
		printf("\n It's a Tie!");
		return;
	}
}

void PlayerTwoTurn()
{
	again: if((CheckFreeSpace() == '0' && CheckStatus()!= 'X' && CheckStatus()!= 'O'))
	{
		system(CLEAR);
		PrintBoard();
		int num1=0;
		int i,j;
		printf("\n%s!, it's your turn\nEnter the place number: ",PlayerTwo);
		scanf("%d",&TurnNumber2);
		getchar();
		for(i=0; i<3; i++)
		{
			for(j=0; j<3; j++)
			{
				num1++;
				if(num1 == TurnNumber2)
				{
				break;
				}
			}
			if(num1 == TurnNumber2)
			{
				break;
			}
		}
		while(1)
		{
			if(TurnNumber2>9)
			{
				printf("Are U kidding me? Make Some Sense");
				printf("\nHit Enter to continue .....");
				clearbuffer();
				clearbuffer();
				goto again;
			}
			else if((Board[i][j] == PlayerOneSymbol[0]))
			{
				printf("Trying To Cheat!!, Make Some Sense!");
				printf("\nHit Enter to continue .....");
				clearbuffer();
				clearbuffer();		
				goto again;
			}
			else if((Board[i][j] == PlayerTwoSymbol[0]))
			{
				printf("It's Saved From YOUUU!!, Make Some Sense!");
				printf("\nHit Enter to continue .....");
				clearbuffer();
				clearbuffer();		
				goto again;
			}
			else
			{
				Board[i][j] = PlayerTwoSymbol[0];
				PlayerOneTurn();
				break;
			}
		}
	}
	else if(CheckFreeSpace() == '0' && CheckStatus() == PlayerOneSymbol[0])
	{
		system(CLEAR);
		PrintBoard();
		printf("The Winner is: %s",PlayerOne);
		return;
	}
	else if(CheckFreeSpace() == '0' && CheckStatus() == PlayerTwoSymbol[0])
	{
		system(CLEAR);
		PrintBoard();
		printf("The Winner is: %s",PlayerTwo);
		return;
	}
	else
	{
		system(CLEAR);
		PrintBoard();
		printf("\n It's a Tie!");
		return;
	}
}

char CheckStatus()
{
    for (int i = 0; i < 3; i++)
    {
        if ((Board[i][0] == Board[i][1]) && (Board[i][0] == Board[i][2]))
        {
            return Board[i][0];
        }

        if ((Board[0][i] == Board[1][i]) && (Board[0][i] == Board[2][i]))
        {
            return Board[0][i];
        }
    }

    if ((Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]) ||
        (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0]))
    {
        return Board[1][1];
    }

    return 'T';
}

char IfWinStatus()
{
    for (int i = 0; i < 3; i++)
    {
        if ((Board[i][0] == Board[i][1]) && (Board[i][0] == Board[i][2]))
        {
            return 1;
        }

        if ((Board[0][i] == Board[1][i]) && (Board[0][i] == Board[2][i]))
        {
            return 1;
        }
    }

    if ((Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]) ||
        (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0]))
    {
        return 0;
    }

    return 5;
}

char CheckFreeSpace()
{
	char num = '0';
	int i,j;
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++)
		{
			num++;
			if(num == Board[i][j])
			{
				return '0'; //free space
			}
		}
	}
	if(num != Board[i][j])
	{
		return '5';
	}
}
