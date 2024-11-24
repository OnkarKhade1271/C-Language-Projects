#include<stdio.h>
int puzzle[9][9]={	{3,0,0,0,2,0,0,7,0},
					{9,0,0,5,0,0,0,1,4},
					{0,1,6,3,7,0,0,0,8},
					{2,0,0,8,0,0,0,0,1},
					{5,0,0,0,4,1,8,0,0},
					{0,8,9,0,0,0,0,5,0},
					{0,0,5,0,1,0,2,8,0},
					{0,4,0,0,0,6,0,9,3},
					{7,3,1,0,8,2,0,0,0}
};
int valid_move(int puzzle[9][9] , int row,int col,int val)
{
	int i;
	//valid row
	for(i=0;i<9;i++)
	{
		if(puzzle[row][i]==val)
		return 0;
	}
	//valid column
	for(i=0;i<9;i++)
	{
		if(puzzle[i][col]==val)
		return 0;
	}
	
	int r=row-row%3;
	int c=col-col%3;
	int j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(puzzle[r+i][c+j]==val)
			{
				return 0;
			}
		}
	}
	return 1;
}

void print_puzzle(int puzzle[9][9])
{
	int row,col;
	printf("\n+-------+-------+-------+");
	for(row=0;row<9;row++)
	{
		if(row%3==0 && row!=0)
		printf("\n|-------+-------+-------|");
		printf("\n");
		for(col=0;col<9;col++)
		{
			if(col%3==0)
			printf("| ");
			if(puzzle[row][col] !=0)
			{
			printf("%d ",puzzle[row][col]);
			}
			else
			{
				printf("  ");
			}
		}
		printf("|");
	}
	printf("\n+-------+-------+-------+\n");
	
}
int solve_puzzle(int puzzle[9][9],int row,int col)
{
	if(col==9)
	{
		if(row==8)
		return 1;		
		row++;
		col=0;
	}
	if(puzzle[row][col]>0)
	{
		return solve_puzzle(puzzle,row,col+1);
	}
	int i;
	for(i=1;i<=9;i++)
	{
		if(valid_move(puzzle,row,col,i))
		{
			puzzle[row][col]=i;
			if(solve_puzzle(puzzle,row,col+1))
			{
				return 1;
			}
			puzzle[row][col]=0;
		}
	}
	return 0;
}
int main()
{
	printf("\n		Welcome to Sudoku Solver : ");
	printf("\nOriginal Puzzle : ");
	print_puzzle(puzzle);
	if(solve_puzzle(puzzle,0,0)){
		printf("\n The puzzle was solved !!!");
		print_puzzle(puzzle);
	}
	else
	{
		printf("\nthis puzzle is not solvable ");
	}
	//printf("%d",valid_move(puzzle,0,1,3));
	//printf("%d",valid_move(puzzle,0,1,5));
}
