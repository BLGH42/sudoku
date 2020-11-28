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
	grid_loop(p, s, initial_solving_process);
	printf("\ntoo ez lol");
	print_grid(s);
	return (0);
}

void 	p_array_fill(char p[9][9][9], char s[9][9], int i, int j)
{
	int		 q;

	q = 1;
	while(q <= 9)
	{
		p[i][j][q] = '.';
		++q;
	}
	return ;
	s[0][0] = s[0][0];
}

void 	initial_solving_process(char p[9][9][9], char s[9][9], int i, int j)
{
	grid_loop(p, s, solution_scan);
	grid_loop(p, s, solution_counter);
	grid_loop(p, s, unique_solution_existence_check);
	grid_loop(p, s, solution_writer);
	print_grid(s);
	i = 0;
	j = 0;
	i = i + j;
	return ;
}

void 	second_solving_process(char p[9][9][9], char s[9][9], int i, int j)
{
	grid_loop(p, s, second_solution_scan);
	grid_loop(p, s, solution_counter);
	grid_loop(p, s, second_unique_solution_existence_check);
	grid_loop(p, s, second_solution_writer);
	print_grid(s);
	i = 0;
	j = 0;
	i = i + j;
	return ;
}
