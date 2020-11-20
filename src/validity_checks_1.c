#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void 	top_left_validity(char p[9][9][9], char s[9][9], int i, int j)
{
	int 	l;
	int 	k;

	k = 0;
	while (k < 3)
	{
		l = 0;
		while(l < 3)
		{
			if(s[k][l] != '.' && k!=i && l!=j && s[i][j] == s[k][l])
			{
				printf("Invalid	 grid.\n");
				exit(0);
			}
			++l;
		}
		p[i][j][k] = s[i][j];
		++k;
	}
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
			if(s[k][l] != '.' && k!=i && l!=j && s[i][j] == s[k][l])
			{
				printf("Invalid	 grid.\n");
				exit(0);
			}
			++l;
		}
		p[i][j][k] = s[i][j];
		++k;
	}
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
			if(s[k][l] != '.' && k!=i && l!=j && s[i][j] == s[k][l])
			{
				printf("Invalid	 grid.\n");
				exit(0);
			}
			++l;
		}
		p[i][j][k] = s[i][j];
		++k;
	}
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
			if(s[k][l] != '.' && k!=i && l!=j && s[i][j] == s[k][l])
			{
				printf("Invalid	 grid.\n");
				exit(0);
			}
			++l;
		}
		p[i][j][k] = s[i][j];
		++k;
	}
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
			if(s[k][l] != '.' && k!=i && l!=j && s[i][j] == s[k][l])
			{
				printf("Invalid	 grid.\n");
				exit(0);
			}
			++l;
		}
		p[i][j][k] = s[i][j];
		++k;
	}
}
