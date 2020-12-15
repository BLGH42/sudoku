#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void 	input_grid(char s[9][9][10], int i, int j)
{
    int 	q;

	if (i == 0 && j == 0)
		printf("Enter a 9x9 grid with digits from 1 to 9 in one single line, from top left to bottom right following the lines.\nNo identical digits in the same line, column or 3x3 subsquare.\nType . for empty tile.\n");
	scanf("%c", &s[i][j][0]); 
	if(s[i][j][0] == '.' || (s[i][j][0] >= '1' && s[i][j][0] <= '9'))
		;
	else
		{
			printf("Instructions not followed.\n");
			exit(0);
		}
	q = 1;
	while (q <= 9)
		{
			if (s[i][j][0] != '.')
				s[i][j][q] = '0';
			++q;
		}
	return;
}

void 	print_grid(char s[9][9][10])
{
	int 	i;
	int 	j;

	i = 0;
	while(i < 9)
	{
		printf("\n");
		j = 0;
		while(j < 9)
		{
			printf("%c", s[i][j][0]);
			++j;
		}
		++i;
	}
	printf("\n");
	return;
}

void 	grid_loop(char s[9][9][10], void (*f)(char s[9][9][10], int i, int j))
{
	int 	i;
	int 	j;

	i = 0;
	while (i < 9)
		{
			j = 0;
			while (j < 9)
				{
					(*f)(s, i, j);
					++j;
				}
			++i;
		}
	return ;
}
