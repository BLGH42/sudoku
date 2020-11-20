#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	solution_check_mid_mid(char p[9][9][9], char s[9][9], int i, int j)
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

void 	solution_check_mid_right(char p[9][9][9], char s[9][9], int i, int j)
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

void 	solution_check_bot_left(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j] = q + '0';
		k = 6;
		while(k < 9)
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

void 	solution_check_bot_mid(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j] = q + '0';
		k = 6;
		while(k < 9)
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


void 	solution_check_bot_right(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j] = q + '0';
		k = 6;
		while(k < 9)
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
