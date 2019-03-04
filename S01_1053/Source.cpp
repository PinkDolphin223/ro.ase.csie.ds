#include "stdio.h"
void interchangeByValue(int, int);
void interchangeByPointer(int*, int*);
void interchangeByReference(int&, int&);
void main()
{
	int a = 4;
	int b = 8;
	printf("Before a=%d, b=%d\n", a, b);
	interchangeByValue(a, b);
	interchangeByPointer(&a, &b);
	interchangeByReference(a, b);
	printf("After a=%d, b=%d\n", a, b);
}
void interchangeByReference(int& x, int& y)
{
	int z = x;
	x = y;
	y = z;
}
void interchangeByPointer(int* x, int* y)
{
	/*int* z = x;
	x = y;
	y = z;*/

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