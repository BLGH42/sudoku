#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void	solution_counter(char s[9][9][10], int i, int j)
{
	int 	q;

	q = 1;
	while (q <= 9)
	{
		if(s[i][j][q] == '.')
		{
			if(s[i][j][0] == '.')
				s[i][j][0] = '*';
			else if(s[i][j][0] == '*')
				s[i][j][0] = '+';
		}
		++q;
	}
	return ;
}

void   	unique_solution_existence_check(char s[9][9][10], int i, int j)
{
	int 	m;

	if (i == 0 && j == 0)
		m = 0;
	if (s[i][j][0] == '*')
		m = 1;
	else if (s[i][j][0] == '+' && m != 1)
		m = 2;
	else if (s[i][j][0] == '.' && m == 0)
		m = 3;
	if (i == 8 && j == 8 && m == 0)
	{
		printf("\nGrid solved.");
		print_grid(s);
		exit(0);
	}
	else if (i == 8 && j == 8 && m == 2)
		grid_loop(s, guess_and_try);
	else if (i == 8 && j == 8 && m == 3)
	{
		printf("\nGrid has no valid solution.");
		print_grid(s);
		exit(0);
	}	
	return ;
}

void 	solution_writer(char s[9][9][10], int i, int j)
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
				s[i][j][q] = 'a';
			}
		}
		++q;
	}
	return ;
}
