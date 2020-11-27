#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void 	top_left_validity(char p [9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 0;
	while (k < 3)
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
	p[0][0][0] = p[0][0][0];
}

void 	top_mid_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 0;
	while(k < 3)
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
	p[0][0][0] = p[0][0][0];
}

void 	top_right_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 0;
    while (k < 3)
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
	p[0][0][0] = p[0][0][0];
}

void 	mid_left_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 3;
    while (k < 6)
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
	p[0][0][0] = p[0][0][0];
}

void 	mid_mid_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 3;
    while (k < 6)
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
	p[0][0][0] = p[0][0][0];
}
