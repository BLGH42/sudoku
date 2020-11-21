#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void input_grid(char s[9][9])
{
	int i;
	int j;
	printf("Enter a 9x9 grid with digits from 1 to 9 in one single line, from top left to bottom right following the lines.\nNo identical digits in the same line, column or 3x3 subsquare.\nType . for empty tile.\n");
	i = 0;
	while(i < 9)
	{
		j = 0;
		while(j < 9)
		{
			scanf("%c", &s[i][j]);
			if(s[i][j] == '.' || (s[i][j] >= '1' && s[i][j] <= '9'))
				;
			else
			{
			    printf("Instructions not followed.\n");
				exit(0);
			}
			++j;
		}
		++i;
	}
	return;
}

void print_grid(char s[9][9])
{
	int i;
	int j;
	
	i = 0;
	while(i < 9)
	{
		printf("\n");
		j = 0;
		while(j < 9)
		{
			printf("%c", s[i][j]);
			++j;
		}
		++i;
	}
	printf("\n");
	return;
}
