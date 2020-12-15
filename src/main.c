#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

int 	main()
{
	char 	s[9][9][10]; /*digit in current tile*/

	grid_loop(s, input_grid);
	grid_loop(s, validity_check);
	print_grid(s);
    grid_loop(s, p_array_fill);
    initial_solving_process(s);
	return (0);
}

void 	p_array_fill(char s[9][9][10], int i, int j)
{
	int		 q;

	q = 1;
	while(q <= 9)
	{
		s[i][j][q] = '.';
		++q;
	}
	return ;
}

void 	initial_solving_process(char s[9][9][10])
{
	int 	r;

	r = 0;
	while (r < 81)
	{
		grid_loop(s, solution_scan);
		grid_loop(s, solution_counter);
		grid_loop(s, unique_solution_existence_check);
		grid_loop(s, solution_writer);
		++r;
	}
	return ;
}

void 	second_solving_process(char s[9][9][10])
{
	int 	r;

	r = 0;
	while (r < 81)
	{
		grid_loop(s, second_solution_scan);
		grid_loop(s, solution_counter);
		grid_loop(s, unique_solution_existence_check);
		grid_loop(s, second_solution_writer);
		++r;
	}
	return ;
}
