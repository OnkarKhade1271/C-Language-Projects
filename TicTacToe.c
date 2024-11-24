#include<stdio.h>
#define BOARD_SIZE 3
int difficulty;

typedef struct
{
int playerwon;
int computerwon;
int draw;	
}Score;
Score score={.playerwon=0,.computerwon=0,.draw=0};
void input_difficulty(){
	while(1){
	printf("\nSelect Difficulty Level ");
	printf("\n1.Human(Standard)");
	printf("\n2.God(Impossible to win)");
	printf("\nChoose Dufficulty : ");
	scanf("%d",&difficulty);
	if(difficulty!=1 && difficulty!=2)
	{
		printf("\nIncorrect choice enter 1 or 2 ");
	}
	else
	{
		break;
	}
	}
}
void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
	clear_screen();
	printf("\nScore - Player X : %d, Computer : %d,Draws : %d",score.playerwon,score.computerwon,score.draw);
	printf("\n Tic-Tac-Toe\n");
	int i,j;
	for(i=0;i<BOARD_SIZE;i++)
	{
		printf("\n");
		for(j=0;j<BOARD_SIZE;j++)
		{
			printf(" %c ",board[i][j]);
			if(j<BOARD_SIZE - 1)
			printf("|");
		}
		if(i<BOARD_SIZE - 1)
		printf("\n---+---+---");
	}
}
void clear_screen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}
int main()
{
	char board[BOARD_SIZE][BOARD_SIZE]={
	{' ',' ',' '},
	{' ',' ',' '},
	{' ',' ',' '},
	};
	input_difficulty();
	print_board(board);
}
