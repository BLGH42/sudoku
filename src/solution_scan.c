#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void	solution_scan(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	q;

	q = 1;
	while (q <= 9)
		{
			if(p[i][j][q] == '.' && (s[i][j] == '.' || s[i][j] == '+'))
				{
					s[i][j] = q + '0';
				    solution_check_lines(p, s, i, j);
				    solution_check_squares(p, s, i, j);
					s[i][j] = '.';
				}
			++q;
		}
	return ;
}

void 	solution_check_lines(char p[9][9][9], char s[9][9], int i, int j)
{
	int		k;
	int		q;

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
	return ;
}

void	solution_check_squares(char p[9][9][9], char s[9][9], int i, int j)
{
		if (0 <= i && i < 3 && 0 <= j && j < 3)
			solution_check_top_left(p, s, i, j);
		else if (0 <= i && i < 3 && 3 <= j && j < 6)
			solution_check_top_mid(p, s, i, j);
		else if (0 <= i && i < 3 && 6 <= j && j < 9)
			solution_check_top_right(p, s, i, j);
		else if (3 <= i && i < 6 && 0 <= j && j < 3)
			solution_check_mid_left(p, s, i, j);
		else if (3 <= i && i < 6 && 3 <= j && j < 6)
			solution_check_mid_mid(p, s, i, j);
		else if (3 <= i && i < 6 && 6 <= j && j < 9)
			solution_check_mid_right(p, s, i, j);
		else if (6 <= i && i < 9 && 0 <= j && j < 3)
			solution_check_bot_left(p, s, i, j);
		else if(6 <= i && i < 9 && 3 <= j && j < 6)
			solution_check_bot_mid(p, s, i, j);
		else if(6 <= i && i < 9 && 6 <= j && j < 9)
			solution_check_bot_right(p, s, i, j);
	return ;
}
