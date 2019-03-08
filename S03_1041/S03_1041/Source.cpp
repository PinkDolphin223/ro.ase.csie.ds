#include "stdio.h"
#include "string"
struct Litera
{
	char firstFiveBits	: 5;
	char switchBit		: 1;
	char : 2;
};
void main()
{
	char litera = 'H';
	printf("Litera initiala: %c \n", litera);
	litera += 32;
	printf("Conv. => h: %c \n", litera);
	//litera = litera & 223;
	litera = litera ^ 32;
	printf("Conv. => H: %c \n", litera);
	litera = litera | 32;
	printf("Conv. => h: %c \n", litera);
	Litera* ptrLtr = (Litera*)&litera;
	ptrLtr->switchBit = ~ptrLtr->switchBit;
	printf("Conv. => H: %c \n", litera);
	char buffer [] = "Exemplu Operatori Pe Biti";
	//"eXEMPLU oPERATORI pE bITI"
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != 32)
		{
			Litera* ptr = (Litera*)&buffer[i];
			ptr->switchBit = ~ptr->switchBit;
		}
	}
	printf("%s\n", buffer);

	int value = -23;
	printf("%d \n", value);
	value = (value ^ 4294967295) + 1;
	printf("%d \n", value);
}