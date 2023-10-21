// Function declarations for the Tic Tac Toe game
void Play();
void ResetBoard();
int ChooseMode();
void GetNames();
void GetSymbol();
void PrintBoard();
void PlayerOneTurn();
void PlayerTwoTurn();
char CheckStatus();
char CheckFreeSpace();
void PlayerName();
void GetSymbol_SM();
void PlayerTurn();
void ComputerTurn();
void clearbuffer();
void SelectMode();

// Additional function declarations for AI or hard mode
char IFWinMove();
char IFBlockMove();
void HardPlay();
char IfWinStatus();
void ComputerHardMode();
void ComputerEasyMode();


/*typedef struct  {
    int row;
    int col;
}Move;
char getBestMove(char board[3][3]);
Move getBestMove(char board[3][3]);
int Minimax(char board[3][3], int depth, int Ai);*/
