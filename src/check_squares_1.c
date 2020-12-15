#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	solution_check_top_left(char s[9][9][10], int i, int j)
{
	int		q;
	int 	k;
	int 	l;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 0;
			while(l < 3)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'X';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}

void 	solution_check_top_mid(char s[9][9][10], int i, int j)
{
	int		q;
	int 	k;
	int 	l;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 3;
			while(l < 6)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'X';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}

void 	solution_check_top_right(char s[9][9][10], int i, int j)
{
	int		q;
	int 	k;
	int 	l;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 6;
			while(l < 9)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'X';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}

void 	solution_check_mid_left(char s[9][9][10], int i, int j)
{
	int		q;
	int 	k;
	int 	l;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 3;
		while(k < 6)
		{
			l = 0;
			while(l < 3)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'X';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}
