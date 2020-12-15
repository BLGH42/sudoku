#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void 	top_left_validity(char s[9][9][10], int i, int j)
{
	int 	l;
	int 	k;
	
	k = 0;
	while (k < 3)
	{
		l = 0;
		while(l < 3)
		{
			if(s[k][l][0] > 47 && k!=i && l!=j && s[i][j][0] == s[k][l][0])
			{
				if (s[i][j][1] == '0')
				{
					printf("Invalid grid.\n");
					exit(0);
				}
				else
					backtrack_loop(s);
			}
			++l;
		}
		++k;
	}
	return ;
}

void 	top_mid_validity(char s[9][9][10], int i, int j)
{
	int 	l;
	int 	k;

	k = 0;
	while(k < 3)
	{
		l = 3;
		while(l < 6)
		{
			if(s[k][l][0] > 47 && k!=i && l!=j && s[i][j][0] == s[k][l][0])
			{
				if (s[i][j][0] == '0')
				{
					printf("Invalid grid.\n");
					exit(0);
				}
				else
					backtrack_loop(s);
			}
			++l;
		}
		++k;
	}
	return ;
}

void 	top_right_validity(char s[9][9][10], int i, int j)
{
	int 	l;
	int 	k;

	k = 0;
    while (k < 3)
	{
		l = 6;
		while(l < 9)
		{
			if(s[k][l][0] > 47 && k!=i && l!=j && s[i][j][0] == s[k][l][0])
			{
				if (s[i][j][0] == '0')
				{
					printf("Invalid grid.\n");
					exit(0);
				}
				else
					backtrack_loop(s);
			}
			++l;
		}
		++k;
	}
	return ;
}

void 	mid_left_validity(char s[9][9][10], int i, int j)
{
	int 	l;
	int 	k;

	k = 3;
    while (k < 6)
	{
		l = 0;
		while(l < 3)
		{
			if(s[k][l][0] > 47 && k!=i && l!=j && s[i][j][0] == s[k][l][0])
			{
				if (s[i][j][0] == '0')
				{
					printf("Invalid grid.\n");
					exit(0);
				}
				else
					backtrack_loop(s);
			}
			++l;
		}
		++k;
	}
	return ;
}

void 	mid_mid_validity(char s[9][9][10], int i, int j)
{
	int 	l;
	int 	k;

	k = 3;
    while (k < 6)
	{
		l = 3;
		while(l < 6)
		{
			if(s[k][l][0] > 47 && k!=i && l!=j && s[i][j][0] == s[k][l][0])
			{
				if (s[i][j][0] == '0')
				{
					printf("Invalid grid.\n");
					exit(0);
				}
				else
					backtrack_loop(s);
			}
			++l;
		}
		++k;
	}
	return ;
}
