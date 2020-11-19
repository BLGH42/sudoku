#ifndef SUDOKU_H
#define SUDOKU_H

#include<stdio.h>
#include<unistd.h>

void 	input_grid(char s[9][9]);
void 	print_grid_start(char s[9][9]);
void 	print_solved_grid(char s[9][9]);
void 	validity(char p[9][9][9], char s[9][9], int i, int j);
void 	line_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	top_left_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	top_mid_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	top_right_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	mid_left_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	mid_mid_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	mid_right_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	bot_left_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	bot_mid_validity(char p[9][9][9], char s[9][9], int i, int j);
void 	bot_right_validity(char p[9][9][9], char s[9][9], int i, int j);

#endif
