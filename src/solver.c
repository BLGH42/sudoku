#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	line_finder(char p[9][9][9], char all_tiles[9][9], int coordinate1, int coordinate2);
void 	square_finder_top_left(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_top_mid(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_top_right(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_mid_left(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_mid_mid(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_mid_right(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_bot_left(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_bot_mid(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_bot_right(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	grid_sweep(char p[9][9][9], char s[9][9], void (*f)(char [9][9][9], char[9][9], int, int));
	
int 	main()
{
	char 	s[9][9]; /*what is written in current tile*/
	char 	p[9][9][9]; /*all possible solutions for current tile*/
	int 	i;/*first coordinate*/
	int 	j;/*second coordinate*/
	int 	q;/*third coordinate*/
	int 	k;/*counter*/
	int 	l;/*counter*/

	input_grid(s);
	grid_sweep(p, s, validity);
	print_grid_start(s);
	i = 0;
	while(i < 9)
	{
		j = 0;
		while(j < 9)
		{
			q = 1;
			while(q <= 9)
			{
				p[i][j][q] = s[i][j];
				++q;
			}
			++j;
		}
		++i;
	}
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
					line_finder(p, s, i, j);
					++j;
				}
				++i;
			}
			i = 0;
			while (i < 9)
			{
				j = 0;
				while (j < 9)
				{
						if (p[i][j][q] == '.')
						{
							if (0 <= i && i < 3 && 0 <= j && j < 3)
								square_finder_top_left(p, s, i, j, q);
							else if (0 <= i && i < 3 && 3 <= j && j < 6)
								square_finder_top_mid(p, s, i, j, q);
							else if (0 <= i && i < 3 && 6 <= j && j < 9)
								square_finder_top_right(p, s, i, j, q);
							else if (3 <= i && i < 6 && 0 <= j && j < 3)
								square_finder_mid_left(p, s, i, j, q);
							else if (3 <= i && i < 6 && 3 <= j && j < 6)
								square_finder_mid_mid(p, s, i, j, q);
							else if (3 <= i && i < 6 && 6 <= j && j < 9)
								square_finder_mid_right(p, s, i, j, q);
							else if (6 <= i && i < 9 && 0 <= j && j < 3)
								square_finder_bot_left(p, s, i, j, q);
							else if(6 <= i && i < 9 && 3 <= j && j < 6)
								square_finder_bot_mid(p, s, i, j, q);
							else if(6 <= i && i < 9 && 6 <= j && j < 9)
								square_finder_bot_right(p, s, i, j, q);
						}
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
					{
						if(p[i][j][k] == '.' && s[i][j] == '.')
							s[i][j] = '*';
						else if(p[i][j][k] == '.' && s[i][j] == '*')
							s[i][j] = '+';
						++k;
					}
					if(s[i][j] == '*')
					{
						k = 1;
						while(k <= 9)
						{
							if(p[i][j][k] == '.')
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


void 	line_finder(char p[9][9][9], char s[9][9], int i, int j)
{
	int		k;
	int		q;

	if(s[i][j] == '.' || s[i][j] == '+')
	{
		q = 1;
		while (q <= 9)
		{
			{
				s[i][j] = q + '0';
				k = 0;
				while(k < 9)
				{
					if(s[i][k] != '.' && s[i][k] != '+')
						if(k != j && s[i][k] == s[i][j])
							p[i][j][q] = 'X';
					if(s[k][j] != '.' && s[k][j] != '+')
						if(k != i && s[k][j] == s[i][j])
							p[i][j][q] = 'X';
					++k;
				}
			}
			++q;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_top_left(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 0;
			while(l < 3)
			{
				if (s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}	
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_top_mid(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 3;
			while(l < 6)
			{
				if (s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}	
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_top_right(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 0;
		while(k < 3)
		{
			l = 6;
			while(l < 9)
			{
				if (s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}	
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_mid_left(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 3;
	    while(k < 6)
		{
			l = 0;
			while(l < 3)
			{
				if(s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_mid_mid(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 3;
		while(k < 6)
		{
			l = 3;
			while(l < 6)
			{
				if(s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_mid_right(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 3;
		while(k < 6)
		{
			l = 6;
			while(l < 9)
			{
				if(s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_bot_left(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 6;
		while(k < 9)
		{
			l = 0;
			while(l < 3)
			{
				if(s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_bot_mid(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 6;
		while(k < 9)
		{
			l = 3;
			while(l < 6)
			{
				if(s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	square_finder_bot_right(char p[9][9][9], char s[9][9], int i, int j, int q)
{
	int 	k;
	int 	l;

	if(s[i][j] == '.')
	{
		s[i][j] = q + '0';
		k = 6;
		while(k < 9)
		{
			l = 6;
			while(l < 9)
			{
				if(s[k][l] != '.' && s[k][l] != '+')
					if(k != i && l != j && s[i][j] == s[k][l])
					{
						s[i][j] = '.';
						p[i][j][q] = 'X';
					}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ;
}

void 	grid_sweep(char p[9][9][9], char s[9][9], void (*f)(char[9][9][9], char[9][9], int, int))
{
	int 	i;
	int 	j;

	i = 0;
	while(i < 9)
	{
		j = 0;
		while(j < 9)
		{
			(*f)(p, s, i, j);
			++j;
		}
		++i;
	}
}
