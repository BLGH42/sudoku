#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void	solution_counter(char p[9][9][9], char s[9][9], int i, int j)
{
	if(s[i][j] == '.')
		s[i][j] = '*';
	else if(s[i][j] == '*')
		s[i][j] = '+';
	p[1][1][1] = p[1][1][1];
	return ;
} 

void 	solution_writer(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	q;

	q = 1;
	while (q <= 9)
	{
		if(s[i][j] == '*')
		{
			s[i][j] = q + '0';
			p[i][j][q] = q + '0';
			++q;
		}										    
	}
	return ;
}
