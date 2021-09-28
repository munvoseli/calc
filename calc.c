#include <stdlib.h>
#include <math.h>
#include <curses.h>

struct Calcstate
{
	double valstack[16];
	char inputstr[32];
	int* p_vali;
	int* p_stri;
};

void push_num_to_stack
(double valstack[], char inputstr[], int* p_vali, int* p_stri)
{
	valstack[*p_vali] = strtod( inputstr, NULL );
	mvprintw(*p_vali, 4, "%f", valstack[*p_vali]);
	++*p_vali;
	inputstr[0] = 0;
	*p_stri = 0;
}

void push_char_to_buf
(char ch, char inputstr[], int* p_vali, int* p_stri)
{
	inputstr[*p_stri] = (char) ch;
	++*p_stri;
	inputstr[*p_stri] = 0;
	mvprintw( *p_vali, 4, "%s", inputstr );
}

void push_val_to_stack
(double val, double valstack[], int* p_vali)
{
	valstack[*p_vali] = val;
	mvprintw(*p_vali, 4, "%f", valstack[*p_vali]);
	++*p_vali;
	mvprintw(*p_vali, 4, "            ");
}

/*
Janeway
O'Brian
Michael
Sisko
McCoy
Jean
Julian
August
Spock
Archer
Nerys
Data
 */

#include "operations.c"

int character_loop
(double valstack[], char inputstr[], int* p_vali, int* p_stri)
{
	int ch = getch();
	void (*func) (double*, char*, int*, int*) = NULL;
	if (ch == 'q') return 1;
	else if( ch == '\n' )func = &do_nothing;
	else if( ch == '+' ) func = &do_add;
	else if( ch == '*' ) func = &do_mul;
	else if( ch == '/' ) func = &do_div;
	else if( ch == 'm' ) func = &do_sub;
	else if( ch == '_' ) func = &do_negsub;
	else if( ch == 'd' ) func = &do_duu;
	else if( ch == 'Q' ) func = &do_sqrt;
	else if( ch == 's' ) func = &do_sin;
	else if( ch == 'c' ) func = &do_cos;
	else if( ch == 't' ) func = &do_tan;
	else if( ch == 'S' ) func = &do_asin;
	else if( ch == 'C' ) func = &do_acos;
	else if( ch == 'T' ) func = &do_atan;
	else push_char_to_buf( ch, inputstr, p_vali, p_stri );
	if( func != NULL )
	{
		if( *p_stri )
			push_num_to_stack( valstack, inputstr, p_vali, p_stri );
		(*func)( valstack, inputstr, p_vali, p_stri );
	}
	mvprintw(0, 0, "%d", *p_vali);
	return 0;
}

int main
(void)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	double valstack [16];
	char inputstr [32];
	int vali = 0;
	int stri = 0;
	
	mvprintw(10, 10, "Heyo");
	refresh();
	int ch;
	int i;
	for(;;)
	{
		if (character_loop( valstack, inputstr, &vali, &stri ))
			break;
	}
	/*	attron(A_BOLD);
		mvprintw(10, 10, "%c", ch);
		attroff(A_BOLD);*/
	endwin();
	return 0;
}
