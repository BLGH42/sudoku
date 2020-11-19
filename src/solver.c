#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

void 	line_finder(char p[9][9][9], char all_tiles[9][9], int coordinate1, int coordinate2);
void 	square_finder_top_left(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_top_mid(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
void 	square_finder_top_right(char p[9][9][9], char s[9][9], int counter1, int counter2, int counter3);
char 	square_finder_mid(char s[9][9], int counter1, int counter2, int counter3, int limit);
char 	square_finder_bot(char s[9][9], int counter1, int counter2, int counter3, int limit);
void 	grid_sweep(char s[9][9],void (*f)(char[9][9], int, int, int));
	
int 	main()
{
	char 	s[9][9]; /*what is written in current tile*/
	char 	p[9][9][9]; /*all possible solutions for current tile*/
	int 	i;/*first coordinate*/
	int 	j;/*second coordinate*/
	int 	q;/*third coordinate*/
	int 	k;/*counter*/
	int 	l;/*counter*/
	int 	v;/*limit for square check*/

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
					line_finder(p, s, i, j);
					++j;
				}
				++i;
			}
			i = 0;
			while(i < 3)
			{
				j = 0;
				while(j < 3)
				{
					if(p[i][j][q] == '.')
						square_finder_top_left(p, s, i, j, q);
					++j;
				}
				j = 3;
				while(j < 6)
				{
					if(p[i][j][q] == '.')
						square_finder_top_mid(p, s, i, j, q);
					++j;
				}
				j = 6;
				while(j < 9)
				{
					if(p[i][j][q] == '.')
						square_finder_top_right(p, s, i, j, q);
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
					if(p[i][j][q] == '.')
						p[i][j][q] = square_finder_mid(s, i, j, q, v);
					++j;
				}
				/*central square*/
				v = 6;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '.')
						p[i][j][q] = square_finder_mid(s, i, j, q, v);
					++j;
				}
				/*middle right*/
				v = 9;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '.')
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
					if(p[i][j][q] == '.')
						p[i][j][q] = square_finder_bot(s, i, j, q, v);
					++j;
				}
				/*bottom middle*/
				v = 6;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '.')
						p[i][j][q] = square_finder_bot(s, i, j, q, v);
					++j;
				}
				/*bottom right*/
				v = 9;
				j = v - 3;
				while(j < v)
				{
					if(p[i][j][q] == '.')
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

char 	square_finder_mid(char s[9][9], int i, int j, int q, int u)
{
	int 	k;
	int 	l;

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
						return ('X');
					}
				}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ('.');
}

char 	square_finder_bot(char s[9][9], int i, int j, int q, int u)
{
	int 	k;
	int 	l;

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
						return ('X');
					}
				}
				++l;
			}
			++k;
		}
		s[i][j] = '.';
	}
	return ('.');
}


void 	grid_sweep(char s[9][9], void (*f)(char[9][9], int, int, int))
{
	int 	i;
	int 	j;
	int 	k;

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
