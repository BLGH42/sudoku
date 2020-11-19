#include<stdio.h>
#include<stdlib.h>
#include"sudoku.h"

void 	validity(char s[9][9], int i, int j, int k)
{
	line_validity(s, i, j, k);
	if(0 <= i && i < 3 && 0 <= j && j < 3)
		top_left_validity(s, i, j, k);
	else if(0 <= i && i < 3 && 3 <= j && j < 6)
		top_mid_validity(s, i, j, k);
	else if(0 <= i && i < 3 && 6 <= j && j < 9)
		top_right_validity(s, i, j, k);
	else if(3 <= i && i < 6 && 0 <= j && j < 3)
		mid_left_validity(s, i, j, k);
	else if(3 <= i && i < 6 && 3 <= j && j < 6)
		mid_mid_validity(s, i, j, k);
	else if(3 <= i && i < 6 && 6 <= j && j < 9)
		mid_right_validity(s, i, j, k);
	else if(6 <= i && i < 9 && 0 <= j && j < 3)
		bot_left_validity(s, i, j, k);
	else if(6 <= i && i < 9 && 3 <= j && j < 6)
		bot_mid_validity(s, i, j, k);
	else if(6 <= i && i < 9 && 6 <= j && j < 9)
		bot_right_validity(s, i, j, k);
	return ;
}

void 	line_validity(char s[9][9], int i, int j, int k)
{	
	if(k != j && s[i][k] == s[i][j] && s[i][k] != '.')
	{
		printf("Invalid	 grid.\n");
		exit(0);
	}
	else if(k != i && s[k][j] == s[i][j] && s[k][j] != '.')
	{
		printf("Invalid	 grid.\n");
		exit(0);
	}
	return ;
}

void 	top_left_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
	if (k < 3)
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
	}
}

void 	top_mid_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
	if(k < 3)
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
	}
}

void 	top_right_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
	if(k < 3)
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
	}
}

void 	mid_left_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
	if(3 <= k && k < 6)
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
	}
}

void 	mid_mid_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
    if(3 <= k && k < 6)
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
	}
}

void 	mid_right_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
    if(3 <= k && k < 6)
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
	}
}

void 	bot_left_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
	if(6 <= k && k < 9)
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
	}
}

void 	bot_mid_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
	if(6 <= k && k < 9)
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
	}
}

void 	bot_right_validity(char s[9][9], int i, int j, int k)
{
	int 	l;
	
	if(6 <= k && k < 9)
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
	}
}
