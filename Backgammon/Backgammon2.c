



#include"game.h"

void menu()
{
	printf("************************\n");
	printf("|   ENTER 1 GO PLAY!   |\n");
	printf("|   ENTER 0 GO EXIT!   |\n");
	printf("************************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);
	//Print the board
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//player move
		gameplayer(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//Judge if the player win
	    ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
		  break;
        }
        //Computer move
		Auto(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//Judge if the computer win
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
		  break;
	     }

		
	}
	if (ret == '*')
	{
		printf("Player Win!\n");
		printf("Nice stratigies\n");
	}
	if (ret == '#')
	{
		printf("AI defeat you XD \n");
	}
	

}

void test()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Please ENTER 1 or 0 \n");
		scanf("%d", &a);//print the corrdinate(x,y)
		switch (a)
		{
		case 1:
			printf("BACKGAMMON!\n");
			game();
			break;
		case 0:
			printf("E-X-I-T\n");
			break;
		default:
			printf("Enter 1 or 0 idiot |-_-|\n");
			break;
				
		}
	} 
	while (a);

}

int main()
{
	test();
	return 0;

}