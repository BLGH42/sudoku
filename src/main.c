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
	/*sij is # or . || pijq is \0*/
	grid_sweep(p, s, validity_check);
	/*no change*/
	grid_sweep(p, s, initial_solution_array_filler);
	/*sij is # or . || pijq is # or .*/
	print_grid(s);
	r = 0;
	while (r < 81)
	{
		/*sij is # or . or +* || pijq is . (or # or X)*/
		grid_sweep(p, s, solution_check_lines);
		/*sij is # or . || pijq is . (or # or X)*/
		grid_sweep(p, s, solution_check_squares);
		/*sij is # or . || pijq is . (or # or X)*/
		grid_sweep(p, s, solution_counter);
		/*sij is # or . or * || pijq is . (or # or X)*/
		grid_sweep(p, s, solution_writer);
		/*sij is # or . or +|| pijq is . (or # or X)*/
		++r;
	}
	/*if all sij # grid solved, otherwise .*/
	print_grid(s);
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
