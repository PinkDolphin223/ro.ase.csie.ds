#include "stdio.h"
void interschimbValoare(int, int);
void interschimbPointer(int*, int*);
void interschimbReferinta(int&, int&);
void main()
{
	int a = 5;
	int b = 7;
	printf("a=%d b=%d \n", a, b);
	//interschimbValoare(a, b);
	//interschimbPointer(&a, &b);
	interschimbReferinta(a, b);
	printf("a=%d b=%d \n", a, b);
}
void interschimbReferinta(int& x, int& y)
{
	int z = x;
	x = y;
	y = z;
}
void interschimbPointer(int* x, int*y)
{
	int z = *x;
	*x = *y;
	*y = z;
}
void interschimbValoare(int x, int y)
{
	int z = x;
	x = y;
	y = z;
}