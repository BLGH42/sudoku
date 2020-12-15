#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void 	validity_check(char p[9][9][9], char s[9][9], int i, int j)
{
	lines_validity(p, s, i, j);
	columns_validity(p, s, i, j);
	if(0 <= i && i < 3 && 0 <= j && j < 3)
		top_left_validity(p, s, i, j);
	else if(0 <= i && i < 3 && 3 <= j && j < 6)
		top_mid_validity(p, s, i, j);
	else if(0 <= i && i < 3 && 6 <= j && j < 9)
		top_right_validity(p, s, i, j);
	else if(3 <= i && i < 6 && 0 <= j && j < 3)
		mid_left_validity(p, s, i, j);
	else if(3 <= i && i < 6 && 3 <= j && j < 6)
		mid_mid_validity(p, s, i, j);
	else if(3 <= i && i < 6 && 6 <= j && j < 9)
		mid_right_validity(p, s, i, j);
	else if(6 <= i && i < 9 && 0 <= j && j < 3)
		bot_left_validity(p, s, i, j);
	else if(6 <= i && i < 9 && 3 <= j && j < 6)
		bot_mid_validity(p, s, i, j);
	else if(6 <= i && i < 9 && 6 <= j && j < 9)
		bot_right_validity(p, s, i, j);
	return ;
}

void 	columns_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;

	k = 0;
	while (k < 9)
	{
		if(k != j && s[i][k] == s[i][j] && s[i][k] > 47)
		{
			if (p[i][j][1] == '0')
			{
				printf("Invalid grid.\n");
				exit(0);
			}
			else
				backtrack_loop(p, s);
		}
		++k;
	}
	return ;
}

void 	lines_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;

	k = 0;
	while (k < 9)
	{
		if(k != i && s[k][j] == s[i][j] && s[k][j] > 47)
		{
			if (p[i][j][1] == '0')
			{
				printf("Invalid grid.\n");
				exit(0);
			}
			else
				backtrack_loop(p, s);
		}
		++k;
	}
	return ;
}
