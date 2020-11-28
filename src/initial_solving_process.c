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
	int 	m;

	if (i == 0 && j ==0)
		m = 0;
	if (s[i][j] == '*')
		m = 1;
	else if (s[i][j] == '+' && (m == 0 || m == 2))
		m = 2;
	if (i == 8 && j == 8 && m == 2)
		grid_loop(p, s, initialiser);
	return ;
	void(p[0][0][0]);
}

void	initialiser(char p[9][9][9], char s[9][9], int i, int j)
{
	int q;

	q = 1;
	while (q <= 9)
	{
		if (s[i][j] == '+' && p[i][j][q] == '.')
		{
			s[i][j] = q + '0';
			p[i][j][q] = 'd';
			grid_loop(p, s, second_solving_process);
		}
		++q;
	}
	return ;
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
				p[i][j][q] = 'a';
			}
		}
		++q;
	}
	return ;
}

void 	thisfunctionsavesmylife(char p[9][9][9], char s[9][9], int i, int j)
{
			s[i][j] = '+';
			grid_loop(p, s, initialiser);
			return ;
}
