#ifndef SUDOKU_H
#define SUDOKU_H

#include<stdio.h>
#include<unistd.h>

void 	input_grid(char s[9][9]);
void 	print_grid_start(char s[9][9]);
void 	print_solved_grid(char s[9][9]);
void 	validity(char s[9][9], int i, int j, int k);
void 	line_validity(char s[9][9], int i, int j, int k);
void 	top_left_validity(char s[9][9], int i, int j, int k);
void 	top_mid_validity(char s[9][9], int i, int j, int k);
void 	top_right_validity(char s[9][9], int i, int j, int k);
void 	mid_left_validity(char s[9][9], int i, int j, int k);
void 	mid_mid_validity(char s[9][9], int i, int j, int k);
void 	mid_right_validity(char s[9][9], int i, int j, int k);
void 	bot_left_validity(char s[9][9], int i, int j, int k);
void 	bot_mid_validity(char s[9][9], int i, int j, int k);
void 	bot_right_validity(char s[9][9], int i, int j, int k);

#endif
