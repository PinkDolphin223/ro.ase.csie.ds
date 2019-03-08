#include "stdio.h"
#include "string"
struct Letter
{
	char : 5;
	char switchBit		: 1;
	char lastTwoBits	: 2;
};
void main()
{
	char letter = 'F';
	printf("Initial letter: %c \n", letter);
	printf("1.Converted letter: %d \n", letter);
	letter += 32;
	printf("2.Converted letter: %c \n", letter);
	printf("3.Converted letter: %d \n", letter);
	letter = letter & 223;
	printf("4.Converted letter: %c \n", letter);
	letter = letter | 32;
	printf("5.Converted letter: %c \n", letter);

	Letter* ptrLtr = (Letter*)&letter;
	ptrLtr->switchBit = ~ptrLtr->switchBit;
	printf("6.Converted letter: %c \n", letter);

	char buffer[] = {"This Is An Example"};
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != 32) {
			Letter* ptrLtr = (Letter*)&buffer[i];
			ptrLtr->switchBit = ~ptrLtr->switchBit;
		}
	}
	printf("%s\n", buffer);
	int value = -32;
	printf("Initial int: %d \n", value);
	//value = ~value + 1;
	value = value ^ -1;
	printf("Sign changed int: %d \n", value);
}