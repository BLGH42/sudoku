#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	guess_and_try(char s[9][9][10], int i, int j)
{
	int q;

	q = 1;
	while (q <= 9)
	{
		if (s[i][j][0] == '+' && s[i][j][q] == '.')
		{
			s[i][j][0] = q + '0';
			s[i][j][q] = 'b';
		    second_solving_process(s);
		}
		++q;
	}
	return ;
}

void 	second_solution_writer(char s[9][9][10], int i, int j)
{
	int 	q;
	
	q = 1;
	while (q <= 9)
	{
		if(s[i][j][0] == '*')
		{
			if(s[i][j][q] == '.')
			{
				s[i][j][0] = q + '0';
				s[i][j][q] = 'c';
			}
		}
		++q;
	}
	if (s[i][j][0] == '.')
		backtrack_loop(s);
	grid_loop(s, validity_check);
	return ;
}

void 	backtrack_loop(char s[9][9][10])
{		  
	int 	i;
	int 	j;

	i = 8;
	while (i >= 0)
	{
		j = 8;
		while (j >= 0)
		{
			backtrack(s, i, j);
			--j;
		}
		--i;
	}
	return ;
}

void 	backtrack(char s[9][9][10], int i, int j)
{
	int 	q;

	q = 9;
	while (q > 0)
	{
		if (s[i][j][q] == 'x' || s[i][j][q] == 'c' || s[i][j][q] == 'o')
		{
			s[i][j][q] = '.';
			s[i][j][0] = '+';
		}
		else if  (s[i][j][q] == 'b')
		{
			s[i][j][q] = 'o';
			s[i][j][0] = '+';
		    second_solving_process(s);
		}
		--q;
	}
	return ;
}

