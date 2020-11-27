#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void   	second_unique_solution_existence_check(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	m;

	if (i == 0 && j ==0)
		m = 0;
	if (s[i][j] == '*')
		m = 1;
	else if (s[i][j] == '+' && (m == 0 || m == 2))
		m = 2;
	if (i == 8 && j == 8 && m == 2)
		grid_loop(p, s, guess_and_try);
	if (i == 8 && j == 8 && m == 0)
	{
		printf("\nFUCKING SOLVED HAHAHA");
		print_grid(s);
	    exit(0);
	}
	return ;
	p[0][0][0] = p[0][0][0];
}

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
			grid_loop(p, s, second_solving_process);
		}
		++q;
	}
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
	int 	q;

	i = 8;
	while (i >= 0)
	{
		j = 8;
		while (j >= 0)
		{
			q = 9;
			while (q > 0)
			{
				backtrack(p, s, i, j);
				if (p[i][j][q] != 'X' && p[i][j][q] != 'a' && p[i][j][q] != '.')
				{
					printf("Invalid grid\n");
					exit(0);
				}
				--q;
			}
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
		if (p[i][j][q] == 'x' || p[i][j][q] == 'c')
		{
			p[i][j][q] = '.';
			s[i][j] = '+';
		}
		else if  (p[i][j][q] == 'b')
		{
			p[i][j][q] = 'o';
			grid_loop(p, s, second_solving_process);
		}
		else if (p[i][j][q] == 'o')
		{
			p[i][j][q] = '.';
			s[i][j] = '+';
		}
		else if (p[i][j][q] == 'd')
			thisfunctionsavesmylife(p, s, i, j);
		--q;
	}
	return ;
}
