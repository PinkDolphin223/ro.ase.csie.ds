#include "stdio.h"
struct Litera
{
	int firstFiveBits : 5;
	int switchBit : 1;
	int lastTwoBits : 2;
};
void main()
{
	char litera = 'A';
	printf("Litera initiala: %c \n", litera);
	litera = litera + 32;
	printf("Litera conv1.: %c \n", litera);
	litera = litera & 223;
	printf("Litera conv2.: %c \n", litera);
	litera = litera | 32;
	printf("Litera conv3.: %c \n", litera);
	Litera* ptrLitera = (Litera*)&litera;
	ptrLitera->switchBit = ~ptrLitera->switchBit;
	printf("Litera conv4.: %c \n", litera);
	int val = 23;
	printf("Val. initiala: %d \n", val);
	val = ~val;
	printf("Val. conversie: %d \n", val);
	val = val | 1;
	printf("Val. conversie: %d \n", val);
}