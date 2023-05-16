
#include"game.h"


void InitBoard(char board[ROW][COL], int b, int c)
{
	int i = 0;
	int g = 0;
	for (i = 0; i < b; i++)
	{
		for (g = 0; g < c; g++)
		    board[i][g] = ' ';
	}
}
void DisplayBoard(char board[ROW][COL], int b, int c)
{
	int i = 0;
	for (i = 0; i < b; i++)
	{
		//print a row of datas
		int g = 0;
		for (g = 0; g < c; g++)
		{
			printf(" %c ", board[i][g]);
			if (g < c - 1)
				printf("|");
		}
		printf("\n");
		if (i < b - 1)
		{
			for (g = 0; g < c; g++)
			{
				printf("---");
				if (g < c - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
		//seperate line
		
	}

}
void gameplayer(char board[ROW][COL], int b, int c)
{
	int x = 0;
	int y = 0;
	printf("Player settling\n");
	while (1)
	{
		printf("Please let the player move:\n");
		scanf("%d,%d", &x, &y);
		if (x >=1 && x <= b && y >=1 && y <= c)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("This position has been occupied -_-|\n");
			}
		}
		else
		{
			printf("Your piece was in a error position\n");
		}
	}

}

void Auto(char board[ROW][COL], int b, int c)
{
	int s = 0;
	int w = 0;
	printf("Please waiting for the computer move!\n");
	while (1)
	{
		s = rand() % b;
		w = rand() % c;
		if (board[s][w] == ' ')
		{
			board[s][w] = '#';
			break;
		}
	}
}

int Full(char board[ROW][COL], int b, int c)
{
	int i = 0;
	int g = 0;
	for (i = 0; i < ROW; i++)
	{
		for (g = 0; g < COL; g++)
		{
			if (board[i][g] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int b, int c)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
		
	}
	for (i = 0; i < COL; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == Full(board, ROW, COL))
	{
		printf("It was draw!\n");
		return 'S';
	}
	return 'C';
}
