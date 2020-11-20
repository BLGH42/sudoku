#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	solution_check_lines(char p[9][9][9], char s[9][9], int i, int j)
{
	int		k;
	int		q;

	if(s[i][j] == '.' || s[i][j] == '+')
	{
		q = 1;
		while (q <= 9)
		{
			k = 0;
			while(k < 9)
			{
				s[i][j] = q + '0';
				if(s[i][k] != '.' && s[i][k] != '+')
					if(k != j && s[i][k] == s[i][j])
						p[i][j][q] = 'X';
				if(s[k][j] != '.' && s[k][j] != '+')
					if(k != i && s[k][j] == s[i][j])
						p[i][j][q] = 'X';
				++k;
			}
			++q;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	solution_check_top_left(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 0;
			while(l < 3)
			{
				if (s[k][l] != '.' && s[k][l] != '+')
				{
					if(k != i && l != j && s[i][j] == s[k][l])
						p[i][j][q] = 'X';
				}
				++l;
			}
			++k;		}
		++q;
	}
	return ;
}

void 	solution_check_top_mid(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 3;
			while(l < 6)
			{
				if (s[k][l] != '.' && s[k][l] != '+')
				{
					if(k != i && l != j && s[i][j] == s[k][l])
						p[i][j][q] = 'X';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}

void 	solution_check_top_right(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 6;
			while(l < 9)
			{
				if (s[k][l] != '.' && s[k][l] != '+')
				{
					if(k != i && l != j && s[i][j] == s[k][l])
						p[i][j][q] = 'X';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}

void 	solution_check_mid_left(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j] = q + '0';
		k = 3;
		while(k < 6)
		{
			l = 0;
			while(l < 3)
			{
				if (s[k][l] != '.' && s[k][l] != '+')
				{
					if(k != i && l != j && s[i][j] == s[k][l])
						p[i][j][q] = 'X';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}
