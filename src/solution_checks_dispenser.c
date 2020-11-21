#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void	solution_check_squares(char p[9][9][9], char s[9][9], int i, int j)
{
	if (s[i][j] == '.')
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
		s[i][j] = '.';
	}
	return ;
}
