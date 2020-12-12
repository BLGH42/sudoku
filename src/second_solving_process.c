#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	guess_and_try(char p[9][9][9], char s[9][9], int i, int j)
{
	int q;

	q = 1;
	while (q <= 9)
	{
		if (s[i][j] == '+' && p[i][j][q] == '.')
		{
			s[i][j] = q + '0';
			p[i][j][q] = 'b';
		    second_solving_process(p, s);
		}
		++q;
	}
	return ;
}

void 	second_solution_writer(char p[9][9][9], char s[9][9], int i, int j)
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
				p[i][j][q] = 'c';
			}
		}
		++q;
	}
	if (s[i][j] == '.')
		backtrack_loop(p, s);
	grid_loop(p, s, validity_check);
	return ;
}

void 	backtrack_loop(char p[9][9][9], char s[9][9])
{		  
	int 	i;
	int 	j;

	i = 8;
	while (i >= 0)
	{
		j = 8;
		while (j >= 0)
		{
			backtrack(p, s, i, j);
			--j;
		}
		--i;
	}
	return ;
}

void 	backtrack(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	q;

	q = 9;
	while (q > 0)
	{
		if (p[i][j][q] == 'x' || p[i][j][q] == 'c' || p[i][j][q] == 'o')
		{
			p[i][j][q] = '.';
			s[i][j] = '+';
		}
		else if  (p[i][j][q] == 'b')
		{
			p[i][j][q] = 'o';
			s[i][j] = '+';
		    second_solving_process(p, s);
		}
		--q;
	}
	return ;
}

