#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "malloc.h"
struct Letter
{
	int FirstFiveBits : 5;
	int switchBit : 1;
	int LastTwoBits : 2;
};
void main()
{
	char buffer[] = { "C Bitwise Operators" };
	char result[] = { "c bITWISE oPERATORS" };
	//char* example = new char[strlen(buffer)+1];
	char* example = (char*)malloc(strlen(buffer) + 1);
	printf("First character: %c \n", buffer[0]);
	buffer[0] = buffer[0] | 32;
	printf("First character after conver.: %c \n", buffer[0]);
	buffer[0] = buffer[0] & 223;
	printf("First character after conver.: %c \n", buffer[0]);

	buffer[0] += 32;
	printf("First character after conver.: %c \n", buffer[0]);

	
	//ptrLetter->switchBit = ptrLetter->switchBit ^ 1;
	
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
	{
		Letter * ptrLetter = (Letter*)&buffer[i];
		ptrLetter->switchBit = ~ptrLetter->switchBit;
		printf("%c", buffer[i]);
	}
	printf("\nString: %s\n", buffer);

	int value = 23;
	value = value ^ 4294967294;
	printf("%d", value);
}