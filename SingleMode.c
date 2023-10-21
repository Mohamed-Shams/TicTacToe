#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include"Functions.h"
#include<windows.h>
#include<unistd.h>
#include <stdbool.h>

#define maxx(a, b)	 ((a > b) ? (a) : (b))
#define minn(a, b) 	 ((a < b) ? (a) : (b))

extern char Board[3][3];
char Player[20];
char PlayerSymbol[2];
char ComputerSymbol[2];
int TurnNumber;
char flag;
int mode = -1;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void SelectMode()
{
	printf("\n \t \t Easy[1]\tHard[2]\n");
	printf("Choose Mode: ");
	scanf("%d",&mode);
	clearbuffer();
	system(CLEAR);
}
void PrintHeader()
{
	if(mode==1)
	{
		printf("   Welcome To Easy Mode \n");
	}
	else if(mode == 2)
	{
		printf("   Welcome To Hard Mode \n");
	}
}

void PlayerName()
{
	printf("Enter Your Name: ");
	gets(Player);
	printf("\nHit Enter to continue .....\n");
	clearbuffer();
	system(CLEAR);
}

void GetSymbol_SM()
{
	printf("%s! Choose between X or O: ",Player);
	scanf("%1s",PlayerSymbol);
	clearbuffer();
	while(1)
	{
		if(((PlayerSymbol[0] == 'x') || (PlayerSymbol[0] == 'X')) && (PlayerSymbol[1] == '\0') )
		{
			PlayerSymbol[0] = 'X';
			ComputerSymbol[0] = 'O';
			break;
		}
		else if(((PlayerSymbol[0] == 'o') || (PlayerSymbol[0] == 'O') || (PlayerSymbol[0] == '0')) && (PlayerSymbol[1] == '\0'))
		{
			PlayerSymbol[0] = 'O';
			ComputerSymbol[0] = 'X';
			break;
		}
		else
		{
			printf("Invalid Input!! TRY AGAIN\n");
			printf("%s!, Choose between X or O: ",Player);
			scanf("%s",PlayerSymbol);
			clearbuffer();
		}
	}
	printf("%s is %s\n",Player,PlayerSymbol);
	printf("Computer is %s\n",ComputerSymbol);
	printf("\nHit Enter to continue .....\n");
	clearbuffer();
	system(CLEAR);
}

void PlayerTurn()
{
	again:
	if((CheckFreeSpace() == '0' && CheckStatus()!= 'X' && CheckStatus()!= 'O'))
	{
		system(CLEAR);
		PrintHeader();
		PrintBoard();
		int num=0;
		int i,j;
		printf("\n%s!, it's your turn\nEnter the place number: ",Player);
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
			else if((Board[i][j] == ComputerSymbol[0]))
			{
				printf("Trying To Cheat!!, Make Some Sense!");
				printf("\nHit Enter to continue .....");
				clearbuffer();
				clearbuffer();
				goto again;
			}
			else if((Board[i][j] == PlayerSymbol[0]))
			{
				printf("It's Saved From YOUUU!!, Make Some Sense!");
				printf("\nHit Enter to continue .....");
				clearbuffer();
				clearbuffer();
				goto again;
			}
			else
			{
				Board[i][j] = PlayerSymbol[0];
				ComputerTurn();
				break;
			}
		}
	}
	else if(CheckStatus() == PlayerSymbol[0])
	{
		system(CLEAR);
		PrintHeader();
		PrintBoard();
		printf("The Winner is: %s",Player);
		return;
	}
	else if(CheckStatus() == ComputerSymbol[0])
	{
		system(CLEAR);
		PrintHeader();
		PrintBoard();
		printf("The Winner is: The Computer");
		return;
	}
	else if(CheckFreeSpace() != '0' && CheckStatus() == 'T')
	{
		system(CLEAR);
		PrintHeader();
		PrintBoard();
		printf("\n It's a Tie!");
		return;
	}
}
void ComputerTurn()
{
	
	if(mode == 1)
	{
		ComputerEasyMode();
	}
	else if(mode == 2){
		ComputerHardMode();
	}
	else printf("ERROR");
}

void ComputerEasyMode(){
	if((CheckFreeSpace() == '0' && CheckStatus()!= 'X' && CheckStatus()!= 'O'))
		{
			system(CLEAR);
			PrintHeader();
			PrintBoard();
			int i,j;
			srand(time(0));
			do
			{
				i = rand() % 3;
				j = rand() % 3;
			} while (Board[i][j] != '1' && Board[i][j] != '2' && Board[i][j] != '3' &&Board[i][j] != '4' && Board[i][j] != '5' && Board[i][j] != '6' && Board[i][j] != '7' && Board[i][j] != '8' && Board[i][j] != '9');
			Board[i][j] = ComputerSymbol[0];
			PlayerTurn();
		}
		else if(CheckStatus() == PlayerSymbol[0])
		{
			system(CLEAR);
			PrintHeader();
			PrintBoard();
			printf("The Winner is: %s",Player);
			return;
		}
		else if(CheckStatus() == ComputerSymbol[0])
		{
			system(CLEAR);
			PrintHeader();
			PrintBoard();
			printf("The Winner is: The Computer");
			return;
		}
		else if(CheckFreeSpace() != '0' && CheckStatus() == 'T')
		{
			system(CLEAR);
			PrintHeader();
			PrintBoard();
			printf("\n It's a Tie!");
			return;
		}
}

void HardPlay(){
	if (1 == flag && Board[1][1] != PlayerSymbol[0])
	{
        Board[1][1] = ComputerSymbol[0];
        flag++;
    }
    else if (IFWinMove())
	{
		flag++;
	}
    else if (IFBlockMove())
	{
		flag++;
    }
    else if (flag==3 && ComputerSymbol[0] == Board[1][1])
	{
		if(PlayerSymbol[0] == Board[1][2])
		{
			Board[0][2] = 'O';
		}
		else if(PlayerSymbol[0] == Board[1][0])
		{
			Board[1][2] = ComputerSymbol[0];
		}
		else
		{
        	Board[1][1] = PlayerSymbol[0];
        	if (IfWinStatus() == 1)
			{
        	    Board[1][2] = ComputerSymbol[0];
        	}
        	else if (IfWinStatus() == 0)
			{
        	    Board[0][1] = ComputerSymbol[0];
        	}
        	Board[1][1] = ComputerSymbol[0];
		}
        flag++;
    }
    else if (flag ==1 && PlayerSymbol[0] == Board[1][1])
	{
        Board[0][2] = ComputerSymbol[0];
        flag++;
    }
    else
	{
		//Random
        int i,j;
		srand(time(0));
		do
		{
			i = rand() % 3;
			j = rand() % 3;
		} while (Board[i][j] != '1' && Board[i][j] != '2' && Board[i][j] != '3' &&Board[i][j] != '4' && Board[i][j] != '5' && Board[i][j] != '6' && Board[i][j] != '7' && Board[i][j] != '8' && Board[i][j] != '9');
		Board[i][j] = ComputerSymbol[0];
    }
}
void ComputerHardMode(){

	if (CheckFreeSpace() == '0' && CheckStatus() != 'X' && CheckStatus() != 'O') {
        int i = 0, j = 0;
        system(CLEAR);
        PrintHeader();
        PrintBoard();
		HardPlay();
        PlayerTurn();
    }
		else if(CheckStatus() == PlayerSymbol[0])
		{
			system(CLEAR);
			PrintHeader();
			PrintBoard();
			printf("The Winner is: %s",Player);
			return;
		}
		else if(CheckStatus() == ComputerSymbol[0])
		{
			system(CLEAR);
			PrintHeader();
			PrintBoard();
			printf("The Winner is: The Computer");
			return;
		}
		else if(CheckFreeSpace() != '0' && CheckStatus() == 'T')
		{
			system(CLEAR);
			PrintHeader();
			PrintBoard();
			printf("\n It's a Tie!");
			return;
		}
}


char IFWinMove()
{
	char temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] != PlayerSymbol[0] && Board[i][j] != ComputerSymbol[0])
            {
                temp = Board[i][j];
                Board[i][j] = ComputerSymbol[0];
                if (ComputerSymbol[0] == CheckStatus())
                {
                    return 1;
                }
                Board[i][j] = temp;
            }
        }
    }
	
	return 0;
}

char IFBlockMove()
{
	char temp;
	for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] != PlayerSymbol[0] && Board[i][j] != ComputerSymbol[0])
            {
                temp = Board[i][j];
                Board[i][j] = PlayerSymbol[0];
                if (PlayerSymbol[0] == CheckStatus())
                {
                    Board[i][j] = ComputerSymbol[0];
                    return 1;
                }
                Board[i][j] = temp;
            }
        }
    }
	return 0;
}