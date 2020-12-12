#ifndef SUDOKU_H
#define SUDOKU_H

#include<stdio.h>
#include<unistd.h>

void 	input_grid(char s[9][9]);
void 	print_grid(char s[9][9]);
void 	grid_loop(char p[9][9][9], char s[9][9], void (*f)(char p[9][9][9], char s[9][9], int i, int j));
void 	p_array_fill(char p[9][9][9], char s[9][9], int i, int j);
void 	validity_check(char p[9][9][9], char s[9][9], int i, int j);
void 	lines_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	top_left_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	top_mid_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	top_right_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	mid_left_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	mid_mid_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	mid_right_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	bot_left_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	bot_mid_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	bot_right_validity(char p[9][9][9], char s[9][9], int i, int j);
void	initial_solving_process(char p[9][9][9], char s[9][9]);
void	solution_scan(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_lines(char p[9][9][9], char s[9][9], int i, int j);
void	solution_check_squares(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_top_left(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_top_mid(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_top_right(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_mid_left(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_mid_mid(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_mid_right(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_bot_left(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_bot_mid(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_check_bot_right(char p[9][9][9], char s[9][9], int i, int j);
void	solution_counter(char p[9][9][9], char s[9][9], int i, int j);
void	unique_solution_existence_check(char p[9][9][9], char s[9][9], int i, int j);
void 	guess_and_try(char p[9][9][9], char s[9][9], int i, int j);
void 	solution_writer(char p[9][9][9], char s[9][9], int i, int j);
void	second_solving_process(char p[9][9][9], char s[9][9]);
void	second_solution_scan(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_lines(char p[9][9][9], char s[9][9], int i, int j);
void	second_solution_check_squares(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_top_left(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_top_mid(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_top_right(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_mid_left(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_mid_mid(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_mid_right(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_bot_left(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_bot_mid(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_check_bot_right(char p[9][9][9], char s[9][9], int i, int j);
void	second_solution_counter(char p[9][9][9], char s[9][9], int i, int j);
void 	second_solution_writer(char p[9][9][9], char s[9][9], int i, int j);
void 	backtrack_loop(char p[9][9][9], char s[9][9]);
void 	backtrack(char p[9][9][9], char s[9][9], int i, int j);
void	eraser(char p[9][9][9], char s[9][9], int i, int j);

#endif
