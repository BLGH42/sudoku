#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void	solution_counter(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	q;

	q = 1;
	while (q <= 9)
	{
		if(p[i][j][q] == '.')
		{
			if(s[i][j] == '.')
				s[i][j] = '*';
			else if(s[i][j] == '*')
				s[i][j] = '+';
		}
		++q;
	}
	return ;
}

void   	unique_solution_existence_check(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	x;

	if (i == 0 && j ==0)
		x = 0;
	if (s[i][j] == '*')
		x = 1;
	else if (s[i][j] == '+' && (x == 0 || x == 2))
		x = 2;
	if (i == 8 && j == 8 && x == 2)
	{
		printf("\nIt appears that this grid's difficulty is beyond my solving skills. :(\n");
		exit(0);
	}
	else
		return ;
	p[0][0][0] = p[0][0][0];
}

void 	solution_writer(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	q;
	
	q = 1;
	while (q <= 9)
	{
		if(s[i][j] == '*')
		{
			if(p[i][j][q] == '.')
			{
				s[i][j] = q + '0';
				p[i][j][q] = q + '0';
			}
		}
		++q;
	}
	return ;
}
