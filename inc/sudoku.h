#ifndef SUDOKU_H
#define SUDOKU_H

#include<stdio.h>
#include<unistd.h>

void 	input_grid(char s[9][9][10], int i, int j);
void 	print_grid(char s[9][9][10]);
void 	grid_loop(char s[9][9][10], void (*f)(char s[9][9][10], int i, int j));
void 	p_array_fill(char s[9][9][10], int i, int j);
void 	validity_check(char s[9][9][10], int i, int j);
void 	lines_validity(char s[9][9][10], int i, int j);
void 	columns_validity(char s[9][9][10], int i, int j);
void 	top_left_validity(char s[9][9][10], int i, int j);
void 	top_mid_validity(char s[9][9][10], int i, int j);
void 	top_right_validity(char s[9][9][10], int i, int j);
void 	mid_left_validity(char s[9][9][10], int i, int j);
void 	mid_mid_validity(char s[9][9][10], int i, int j);
void 	mid_right_validity(char s[9][9][10], int i, int j);
void 	bot_left_validity(char s[9][9][10], int i, int j);
void 	bot_mid_validity(char s[9][9][10], int i, int j);
void 	bot_right_validity(char s[9][9][10], int i, int j);
void	initial_solving_process(char s[9][9][10]);
void	solution_scan(char s[9][9][10], int i, int j);
void 	solution_check_lines(char s[9][9][10], int i, int j);
void	solution_check_squares(char s[9][9][10], int i, int j);
void 	solution_check_top_left(char s[9][9][10], int i, int j);
void 	solution_check_top_mid(char s[9][9][10], int i, int j);
void 	solution_check_top_right(char s[9][9][10], int i, int j);
void 	solution_check_mid_left(char s[9][9][10], int i, int j);
void 	solution_check_mid_mid(char s[9][9][10], int i, int j);
void 	solution_check_mid_right(char s[9][9][10], int i, int j);
void 	solution_check_bot_left(char s[9][9][10], int i, int j);
void 	solution_check_bot_mid(char s[9][9][10], int i, int j);
void 	solution_check_bot_right(char s[9][9][10], int i, int j);
void	solution_counter(char s[9][9][10], int i, int j);
void	unique_solution_existence_check(char s[9][9][10], int i, int j);
void 	solution_writer(char s[9][9][10], int i, int j);
void	initialiser(char s[9][9][10], int i, int j);
void	second_solving_process(char s[9][9][10]);
void	second_solution_scan(char s[9][9][10], int i, int j);
void 	second_solution_check_lines(char s[9][9][10], int i, int j);
void	second_solution_check_squares(char s[9][9][10], int i, int j);
void 	second_solution_check_top_left(char s[9][9][10], int i, int j);
void 	second_solution_check_top_mid(char s[9][9][10], int i, int j);
void 	second_solution_check_top_right(char s[9][9][10], int i, int j);
void 	second_solution_check_mid_left(char s[9][9][10], int i, int j);
void 	second_solution_check_mid_mid(char s[9][9][10], int i, int j);
void 	second_solution_check_mid_right(char s[9][9][10], int i, int j);
void 	second_solution_check_bot_left(char s[9][9][10], int i, int j);
void 	second_solution_check_bot_mid(char s[9][9][10], int i, int j);
void 	second_solution_check_bot_right(char s[9][9][10], int i, int j);
void	second_solution_counter(char s[9][9][10], int i, int j);
void	second_unique_solution_existence_check(char s[9][9][10], int i, int j);
void	guess_and_try(char s[9][9][10], int i, int j);
void 	second_solution_writer(char s[9][9][10], int i, int j);
void 	backtrack_loop(char s[9][9][10]);
void 	backtrack(char s[9][9][10], int i, int j);

#endif
