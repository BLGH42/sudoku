#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	grid_sweep(char p[9][9][9], char s[9][9], void (*f)(char [9][9][9], char[9][9], int, int));
void 	initial_solution_array_filler(char p[9][9][9], char s[9][9], int i, int j);
	
int 	main()
{
	char 	s[9][9]; /*digit in current tile*/
	char 	p[9][9][9]; /*array of all possible digits*/
	int    	r; /*process repeat*/

	input_grid(s);
	grid_sweep(p, s, validity_check);
	grid_sweep(p, s, initial_solution_array_filler);
	r = 0;
	while (r < 81)
	{
		grid_sweep(p, s, solution_check_lines);
		grid_sweep(p, s, solution_check);
		grid_sweep(p, s, solution_counter);
		grid_sweep(p, s, solution_writer);
		++r;
	}
	print_grid_start(s);
	print_solved_grid(s);
	return (0);
}


void 	grid_sweep(char p[9][9][9], char s[9][9], void (*f)(char[9][9][9], char[9][9], int, int))
{
	int 	i;
	int 	j;
	int 	q;

	q = 1;
	while (q <= 9)
	{	
		i = 0;
		while(i < 9)
		{
			j = 0;
			while(j < 9)
			{
				if (p[i][j][q] == '.' || p[i][j][q] == '\0')
					(*f)(p, s, i, j);
				++j;
			}
			++i;
		}
		++q;
	}
	return ;
}

void 	initial_solution_array_filler(char p[9][9][9], char s[9][9], int i, int j)
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
