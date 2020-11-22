#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

int 	main()
{
	char 	s[9][9]; /*digit in current tile*/
	char 	p[9][9][9]; /*array of all digits that could fit in a tile*/

	input_grid(s);
	validity_scan(s);
	print_grid(s);
    initial_solution_array_filler(p, s);
	solving_process(p, s);
	print_grid(s);
	return (0);
}

void 	solving_process(char p[9][9][9], char s[9][9])
{
	int r;

	r = 0;
	while (r < 81)
	{
		solution_scan(p, s);
		solution_count(p, s);
		unique_solution_existence_check(s);
		solution_resolution(p, s);
		++r;
	}
	return ;
}

void	validity_scan(char s[9][9])
{
	int 	i;
	int		j;

	i = 0;
	while(i < 9)
	{
		j = 0;
		while(j < 9)
		{
			validity_check(s, i, j);
			++j;
		}
		++i;
	}
	return ;
}

void 	initial_solution_array_filler(char p[9][9][9], char s[9][9])
{
	int i;
	int j;
	int q;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{	
			q = 1;
			while(q <= 9)
			{
				p[i][j][q] = s[i][j];
				++q;
			}
			++j;
		}
		++i;
	}
	return ;
}
