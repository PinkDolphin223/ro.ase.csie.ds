#include "stdio.h"
void interchangeByValue(int, int);
void interchangeByPointer(int*, int*);
void interchangeByReference(int&, int&);
void main()
{
	int a = 7;
	int b = 9;
	printf("Before: a=%d ; b=%d\n", a, b);
	//interchangeByValue(a, b);
	//interchangeByPointer(&a, &b);
	interchangeByReference(a, b);
	printf("After: a=%d ; b=%d\n", a, b);
}
void interchangeByReference(int& x, int& y)
{
	int z = x;
	x = y;
	y = z;
}

void interchangeByPointer(int* x, int* y)
{
	//lvl for the interchangeByPointer stack
	/*int* z = x;
	x = y;
	y = z;*/

	//lvl for the main stack
	int z = *x;
	*x = *y;
	*y = z;
}
void interchangeByValue(int x, int y)
{
	int z = x;
	x = y;
	y = z;
}