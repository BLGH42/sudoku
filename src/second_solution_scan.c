#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void	second_solution_scan(char s[9][9][10], int i, int j)
{
	int 	q;

	q = 1;
	while (q <= 9)
		{
			if(s[i][j][q] == '.' && (s[i][j][0] == '.' || s[i][j][0] == '+'))
				{
					s[i][j][0] = q + '0';
				    second_solution_check_lines(s, i, j);
				    second_solution_check_squares(s, i, j);
					s[i][j][0] = '.';
				}
			++q;
		}
	return ;
}

void 	second_solution_check_lines(char s[9][9][10], int i, int j)
{
	int		k;
	int		q;

		q = 1;
		while (q <= 9)
		{
			k = 0;
			while(k < 9)
			{
				s[i][j][0] = q + '0';
				if(s[i][k][0] != '.' && s[i][k][0] != '+')
					if(k != j && s[i][k][0] == s[i][j][0])
						s[i][j][q] = 'x';
				if(s[k][j][0] != '.' && s[k][j][0] != '+')
					if(k != i && s[k][j][0] == s[i][j][0])
						s[i][j][q] = 'x';
				++k;
			}
			++q;
		}
	return ;
}

void	second_solution_check_squares(char s[9][9][10], int i, int j)
{
		if (0 <= i && i < 3 && 0 <= j && j < 3)
			second_solution_check_top_left(s, i, j);
		else if (0 <= i && i < 3 && 3 <= j && j < 6)
			second_solution_check_top_mid(s, i, j);
		else if (0 <= i && i < 3 && 6 <= j && j < 9)
			second_solution_check_top_right(s, i, j);
		else if (3 <= i && i < 6 && 0 <= j && j < 3)
			second_solution_check_mid_left(s, i, j);
		else if (3 <= i && i < 6 && 3 <= j && j < 6)
			second_solution_check_mid_mid(s, i, j);
		else if (3 <= i && i < 6 && 6 <= j && j < 9)
			second_solution_check_mid_right(s, i, j);
		else if (6 <= i && i < 9 && 0 <= j && j < 3)
			second_solution_check_bot_left(s, i, j);
		else if(6 <= i && i < 9 && 3 <= j && j < 6)
			second_solution_check_bot_mid(s, i, j);
		else if(6 <= i && i < 9 && 6 <= j && j < 9)
			second_solution_check_bot_right(s, i, j);
	return ;
}
