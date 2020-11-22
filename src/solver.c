#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void	solution_count(char p[9][9][9], char s[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			solution_counter(p, s, i, j);
			++j;
		}
		++i;
	}
	return ;
}

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

void   	unique_solution_existence_check(char s[9][9])
{
	int 	x;
	int 	i;
	int 	j;

	x = 0;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (s[i][j] == '*')
				x = 1;
			else if (s[i][j] == '+' && x == 0)
				x = 2;
			++j;
		}
		++i;
	}
	if (x == 2)
	{
		printf("\nIt appears that this grid's difficulty is beyond my solving skills. :(\n");
		exit(0);
	}
	else
		return ;
}

void	solution_resolution(char p[9][9][9], char s[9][9])
{
	int 	i;
	int 	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			solution_writer(p, s, i, j);
			++j;
		}
		++i;
	}
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
