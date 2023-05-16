#define ROW 5
#define COL 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//announcement
void InitBoard(char board[ROW][COL], int b, int c);
void DisplayBoard(char board[ROW][COL], int b , int c);
void gameplayer(char board[ROW][COL], int b, int c);
void Auto(char board[ROW][COL], int b, int c);



//It cna tell us all(4) status about the game result
//player win "*"
//computer win "#"
//Nobody win "S"
//continue "C"
char IsWin(char board[ROW][COL], int b, int c);

//notificaiton: I do not know how to import the Artifical Intelligence now so the computer does not have the concept of win.