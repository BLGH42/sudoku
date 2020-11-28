#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void 	mid_right_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 3;
    while (k < 6)
	{
		l = 6;
		while(l < 9)
		{
			if(s[k][l] > 47 && k!=i && l!=j && s[i][j] == s[k][l])
				backtrack_loop(p, s);
			++l;
		}
		++k;
	}
	return ;
    p[0][0][0] = ' ';
}

void 	bot_left_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 6;
    while (k < 9)
	{
		l = 0;
		while(l < 3)
		{
		    if(s[k][l] > 47 && k!=i && l!=j && s[i][j] == s[k][l])
				backtrack_loop(p, s);
			++l;
		}
		++k;
	}
	return ;
    p[0][0][0] = ' ';
}

void 	bot_mid_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 6;
    while (k < 9)
	{
		l = 3;
		while(l < 6)
		{
		    if(s[k][l] > 47 && k!=i && l!=j && s[i][j] == s[k][l])
				backtrack_loop(p, s);
			++l;
		}
		++k;
	}
	return ;
    p[0][0][0] = ' ';
}

void 	bot_right_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int		k;

	k = 6;
	while (k < 9)
	{
		l = 6;
		while (l < 9)
		{
		    if(s[k][l] > 47 && k!=i && l!=j && s[i][j] == s[k][l])
				backtrack_loop(p, s);
			++l;
		}
		++k;
	}
	return ;
    p[0][0][0] = ' ';
}

void 	lines_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	k;

	k = 0;
	while (k < 9)
	{
		if(k != j && s[i][k] == s[i][j] && s[i][k] > 47)
			backtrack_loop(p, s);
		else if(k != i && s[k][j] == s[i][j] && s[k][j] > 47)
			backtrack_loop(p, s);
		++k;
	}
	return ;
    p[0][0][0] = ' ';
}
