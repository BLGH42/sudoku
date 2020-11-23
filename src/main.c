#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

int 	main()
{
	char 	s[9][9]; /*digit in current tile*/
	char 	p[9][9][9]; /*array of all digits that could fit in a tile*/

	input_grid(s);
	grid_loop(p, s, validity_check);
	print_grid(s);
    grid_loop(p, s, p_array_fill);
	grid_loop(p, s, solving_process);
	print_grid(s);
	return (0);
}

void 	solving_process(char p[9][9][9], char s[9][9], int i, int j)
{
	i = i;
	j = j;
	grid_loop(p, s, solution_scan);
	grid_loop(p, s, solution_counter);
	grid_loop(p, s, unique_solution_existence_check);
	grid_loop(p, s, solution_writer);
	return ;
}

void 	p_array_fill(char p[9][9][9], char s[9][9], int i, int j)
{
	int q;
	
	q = 1;
	while(q <= 9)
		{
		p[i][j][q] = s[i][j];
		++q;
		}
	return ;
}

void 	grid_loop(char p[9][9][9], char s[9][9], void (*f)(char p[9][9][9], char s[9][9], int i, int j))
{
	int 	i;
	int 	j;

	i = 0;
	while (i < 9)
		{
			j = 0;
			while (j < 9)
				{
					(*f)(p, s, i, j);
					++j;
				}
			++i;
		}
	return ;
}
				
