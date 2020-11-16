#include<stdio.h>
#include<stdlib.h>
#include "sudoku.h"

char line_finder(char all_tiles[9][9], int coordinate1, int coordinate2);
char square_finder_top(char s[9][9], int counter1, int counter2, int counter3, int limit);
char square_finder_mid(char s[9][9], int counter1, int counter2, int counter3, int limit);
char square_finder_bot(char s[9][9], int counter1, int counter2, int counter3, int limit);
void line_loop(char s[9][9]);

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
	line_loop(s);
    /*checks doubles in all nine 3x3 squares*/
	i = 0;
	while(i < 3)
	{
		j = 0;
		while(j < 3)
		{
			k = 0;
			while(k < 3)
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
				++k;
			}
			++j;
		}	
		j = 3;
		while(j < 6)
		{
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
				++k;
			}
			++j;
		}
		j = 6;
		while(j < 9)
		{
			k = 0;
			while(k < 3)
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
				++k;
			}
			++j;
		}
		++i;
	}
	i = 3;
	while(i < 6)
	{
		j = 0;
		while(j < 3)
		{
			k = 3;
			while(k < 6)
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
				++k;
			}
			++j;
		}
		j = 3;
		while(j < 6)
		{
			k = 3;
			while(k < 6)
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
				++k;
			}
			++j;
		}
		j = 6;
		while(j < 9)
		{
			k = 3;
			while(k < 6)
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
				++k;
			}
			++j;
		}
		++i;
	}
	i = 6;
	while(i < 9)
	{
		j = 0;
		while(j < 3)
		{
			k = 6;
			while(k < 9)
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
				++k;
			}
			++j;
		}
		j = 3;
		while(j < 6)
		{
			k = 6;
			while(k < 9)
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
				++k;
			}
			++j;
		}
		j = 6;
		while(j < 9)
		{
			k = 6;
			while(k < 9)
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
				++k;
			}
			++j;
		}
		++i;
	}
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


void line_loop(char s[9][9])
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
							++k;
						}
					++j;
				}
			++i;
		}
}

/*i0j0 = 1
  i0j3 = 1 OK*/

/*i0j2 = 1
  i0j5 = 1 WRONG*/

