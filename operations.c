// math operations

#include <math.h>

void do_add( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	double a = valstack[*p_vali];
	--*p_vali;
	push_val_to_stack( valstack[*p_vali] + a, valstack, p_vali );
}

void do_mul( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	double a = valstack[*p_vali];
	--*p_vali;
	push_val_to_stack( valstack[*p_vali] * a, valstack, p_vali );
}

void do_div( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	double a = valstack[*p_vali];
	--*p_vali;
	push_val_to_stack( valstack[*p_vali] / a, valstack, p_vali );
}

void do_sub( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	double a = valstack[*p_vali];
	--*p_vali;
	push_val_to_stack( valstack[*p_vali] - a, valstack, p_vali );
}

void do_negsub( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	double a = valstack[*p_vali];
	--*p_vali;
	push_val_to_stack( a - valstack[*p_vali], valstack, p_vali );
}

void do_duu( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	push_val_to_stack( valstack[*p_vali - 1], valstack, p_vali );
}

void do_sqrt( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	push_val_to_stack( sqrt(valstack[*p_vali]), valstack, p_vali );
}

void do_inv( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	push_val_to_stack( 1 / valstack[*p_vali], valstack, p_vali );
}


// trig functions

void do_sin( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	push_val_to_stack( sin(valstack[*p_vali]*M_PI/180), valstack, p_vali );
}

void do_cos( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	push_val_to_stack( cos(valstack[*p_vali]*M_PI/180), valstack, p_vali );
}

void do_tan( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	push_val_to_stack( tan(valstack[*p_vali]*M_PI/180), valstack, p_vali );
}

void do_asin( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	push_val_to_stack( asin(valstack[*p_vali])*180/M_PI, valstack, p_vali );
}

void do_acos( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	push_val_to_stack( acos(valstack[*p_vali])*180/M_PI, valstack, p_vali );
}

void do_atan( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
	--*p_vali;
	push_val_to_stack( atan(valstack[*p_vali])*180/M_PI, valstack, p_vali );
}

void do_nothing
( double valstack[], char inputstr[], int* p_vali, int* p_stri )
{
}
