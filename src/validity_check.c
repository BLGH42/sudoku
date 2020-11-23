#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void 	validity_check(char p[9][9][9], char s[9][9], int i, int j)
{
	lines_validity(s, i, j);
	if(0 <= i && i < 3 && 0 <= j && j < 3)
		top_left_validity(s, i, j);
	else if(0 <= i && i < 3 && 3 <= j && j < 6)
		top_mid_validity(s, i, j);
	else if(0 <= i && i < 3 && 6 <= j && j < 9)
		top_right_validity(s, i, j);
	else if(3 <= i && i < 6 && 0 <= j && j < 3)
		mid_left_validity(s, i, j);
	else if(3 <= i && i < 6 && 3 <= j && j < 6)
		mid_mid_validity(s, i, j);
	else if(3 <= i && i < 6 && 6 <= j && j < 9)
		mid_right_validity(s, i, j);
	else if(6 <= i && i < 9 && 0 <= j && j < 3)
		bot_left_validity(s, i, j);
	else if(6 <= i && i < 9 && 3 <= j && j < 6)
		bot_mid_validity(s, i, j);
	else if(6 <= i && i < 9 && 6 <= j && j < 9)
		bot_right_validity(s, i, j);
	return ;
	p[0][0][0] = p[0][0][0];
}
