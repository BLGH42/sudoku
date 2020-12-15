#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	second_solution_check_mid_mid(char s[9][9][10], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 3;
		while(k < 6)
		{
			l = 3;
			while(l < 6)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'x';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}

void 	second_solution_check_mid_right(char s[9][9][10], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 3;
		while(k < 6)
		{
			l = 6;
			while(l < 9)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'x';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}

void 	second_solution_check_bot_left(char s[9][9][10], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 6;
		while(k < 9)
		{
			l = 0;
			while(l < 3)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'x';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}

void 	second_solution_check_bot_mid(char s[9][9][10], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 6;
		while(k < 9)
		{
			l = 3;
			while(l < 6)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'x';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}


void 	second_solution_check_bot_right(char s[9][9][10], int i, int j)
{
	int 	k;
	int 	l;
	int		q;

	q = 1;
	while (q <= 9)
	{
		s[i][j][0] = q + '0';
		k = 6;
		while(k < 9)
		{
			l = 6;
			while(l < 9)
			{
				if (s[k][l][0] != '.' && s[k][l][0] != '+')
				{
					if(k != i && l != j && s[i][j][0] == s[k][l][0])
						s[i][j][q] = 'x';
				}
				++l;
			}
			++k;
		}
		++q;
	}
	return ;
}
