#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

char line_finder(char all_tiles[9][9], int coordinate1, int coordinate2);
char square_finder_top(char s[9][9], int counter1, int counter2, int counter3, int limit);
char square_finder_mid(char s[9][9], int counter1, int counter2, int counter3, int limit);
char square_finder_bot(char s[9][9], int counter1, int counter2, int counter3, int limit);
void grid_sweep(char s[9][9], void (*f)(char[9][9], int, int, int));
void validity(char s[9][9], int i, int j, int k);
void line_validity(char s[9][9], int i, int j, int k);
void top_left_validity(char s[9][9], int i, int j, int k);
void top_mid_validity(char s[9][9], int i, int j, int k);
void top_right_validity(char s[9][9], int i, int j, int k);
void mid_left_validity(char s[9][9], int i, int j, int k);
void mid_mid_validity(char s[9][9], int i, int j, int k);
void mid_right_validity(char s[9][9], int i, int j, int k);
void bot_left_validity(char s[9][9], int i, int j, int k);
void bot_mid_validity(char s[9][9], int i, int j, int k);
void bot_right_validity(char s[9][9], int i, int j, int k);
	
int main()
{
    char s[9][9]; /*what is written in current tile*/
    char p[9][9][9]; /*all possible solutions for current tile*/
    int i;/*first dimension*/
	int j;/*second dimension*/
	int q;/*third dimension*/
	int k;/*counter*/
	int l;/*counter*/
	int v;/*limit for square check*/

	input_grid(s);
	grid_sweep(s, validity);
	print_grid_start(s);
	/*We put things in p[i][j][q]*/
	i = 0;
	while(i < 9)
	{
		j = 0;
		while(j < 9)
		{
			q = 1;
			while(q <= 9)
			{
				if(s[i][j] == '.')
				{
					p[i][j][q] = '-';
				}
				else
					p[i][j][q] = s[i][j];
				++q;
			}
			++j;
		}
		++i;
	}
	/*MONSTER SOLVING LOOP*/
	l = 0;
	while(l < 82)
	{
		q = 1;
	    while(q <= 9)
		{
			i = 0;
		    while(i < 9)
			{
				j = 0;
				while(j < 9)
				{
					if(s[i][j] == '.' || s[i][j] == '+')
					{
						s[i][j] = q + '0';
						p[i][j][q] = line_finder(s, i, j);
					}
					++j;
				}
				++i;
			}
			i = 0;
			while(i < 3)
			{
				/*top left*/
				v = 3;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_top(s, i, j, q, v);
					++j;
				}
				/*top middle*/
				v = 6;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_top(s, i, j, q, v);
					++j;
				}
				/*top right*/
				v = 9;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_top(s, i, j, q, v);
					++j;
				}
				++i;
			}
			i = 3;
			while(i < 6)
			{
				/*middle left*/
				v = 3;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_mid(s, i, j, q, v);
					++j;
				}
				/*central square*/
				v = 6;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_mid(s, i, j, q, v);
					++j;
				}
				/*middle right*/
				v = 9;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_mid(s, i, j, q, v);
					++j;
				}
				++i;
			}
			i = 6;
		    while(i < 9)
			{
				/*bottom left*/
				v = 3;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_bot(s, i, j, q, v);
					++j;
				}
				/*bottom middle*/
				v = 6;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_bot(s, i, j, q, v);
					++j;
				}
				/*bottom right*/
				v = 9;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '-')
						p[i][j][q] = square_finder_bot(s, i, j, q, v);
					++j;
				}
				++i;
			}
			i = 0;
		    while(i < 9)
			{
				j = 0;
			    while(j < 9)
				{
					k = 1;
				    while(k <= 9)
						/*changes s[i][i] from '.' to stars if unique possible solution, or '+' if at least 2 solutions*/
					{
						if(p[i][j][k] == '-' && s[i][j] == '.')
							s[i][j] = '*';
						else if(p[i][j][k] == '-' && s[i][j] == '*')
							s[i][j] = '+';
						++k;
					}
					/*writes solution in s[i][j] if there is only one possible (s[i][j] is star!)*/
					if(s[i][j] == '*')
					{
						k = 1;
						while(k <= 9)
						{
						if(p[i][j][k] == '-')
							{
								s[i][j] = k + '0';
								p[i][j][k] = k + '0';
							}
							++k;
						}										    
					}
					++j;
				}
				++i;
			}
			++q;
		}
		++l;
	}
	print_solved_grid(s);
}

char line_finder(char s[9][9], int i, int j)
{

	int k;

	k = 0;
	while(k < 9)
	{
		if(s[i][k] != '.' && s[i][k] != '+')
		{
			if(k != j && s[i][k] == s[i][j])
			{
				s[i][j] = '.';
				return 'X';
			}
		}
		if(s[k][j] != '.' && s[k][j] != '+')
		{
			if(k != i && s[k][j] == s[i][j])
			{
				s[i][j] = '.';
				return 'X';
			}
		}
		++k;
	}
	s[i][j] = '.';
	return '-';
}

char square_finder_top(char s[9][9], int i, int j, int q, int u)
{
	int k;
	int l;

	k = 0;
	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
	    while(k < 3)
		{
			l = u - 3;
			while(l < u)
			{
				if (s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						return 'X';
					}	
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return '-';
}

char square_finder_mid(char s[9][9], int i, int j, int q, int u)
{
	int k;
	int l;

	k = 3;
	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
	    while(k < 6)
		{
			l = u - 3;
			while(l < u)
			{
				if(s[k][l] != '.' && s[k][l] != '+')
				{
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						return 'X';
					}
				}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return '-';
}

char square_finder_bot(char s[9][9], int i, int j, int q, int u)
{
	int k;
	int l;

	k = 6;
	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
	    while(k < 9)
		{
			l = u - 3;
			while(l < u)
			{
				if(s[k][l] != '.' && s[k][l] != '+')
				{
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						return 'X';
					}
				}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return '-';
}


void grid_sweep(char s[9][9], void (*f)(char[9][9], int, int, int))
{
	int i;
	int j;
	int k;

	i = 0;
	while(i < 9)
		{
			j = 0;
			while(j < 9)
				{
					k = 0;
					while(k < 9)
						{
							(*f)(s, i, j, k);
							++k;
						}
					++j;
				}
			++i;
		}
}

void line_validity(char s[9][9], int i, int j, int k)
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
}


void validity(char s[9][9], int i, int j, int k)
{
	line_validity(s, i, j , k);
	if(0 <= i && i < 3 && 0 <= j && j < 3)
		top_left_validity(s, i, j, k);
	else if(0 <= i && i < 3 && 3 <= j && j < 6)
		top_mid_validity(s, i, j , k);
	else if(0 <= i && i < 3 && 6 <= j && j < 9)
		top_right_validity(s, i, j , k);
	else if(3 <= i && i < 6 && 0 <= j && j < 3)
		mid_left_validity(s, i, j , k);
	else if(3 <= i && i < 6 && 3 <= j && j < 6)
		mid_mid_validity(s, i, j , k);
	else if(3 <= i && i < 6 && 6 <= j && j < 9)
		mid_right_validity(s, i, j , k);
	else if(6 <= i && i < 9 && 0 <= j && j < 3)
		bot_left_validity(s, i, j , k);
	else if(6 <= i && i < 9 && 3 <= j && j < 6)
		bot_mid_validity(s, i, j , k);
	else if(6 <= i && i < 9 && 6 <= j && j < 9)
		bot_right_validity(s, i, j , k);
}

void top_left_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
	if(k < 3)
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
void top_mid_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
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

void top_right_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
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

void mid_left_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
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

void mid_mid_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
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

void mid_right_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
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

		void bot_left_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
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

void bot_mid_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
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

void bot_right_validity(char s[9][9], int i, int j, int k)
{
	int l;
	
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
