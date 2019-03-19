#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "string.h"
using namespace std;
struct List
{
	char* employee;
	float salary;
	List* pList;
};

List* createElement(char*, float);
List* insertToHead(List*, List*);
void insertToTail(List**, List*);
//void insertToTail(List*&, List*);
void main()
{
	FILE* pFile = fopen("Source.txt", "r");

	List* listHead = NULL;

	if (pFile)
	{
		char buffer[100]; float salary;
		fscanf(pFile, "%s", buffer);
		while (!feof(pFile))
		{
			fscanf(pFile, "%d", &salary);

			//1. create an element of type List*
			List* newElement = createElement(buffer, salary);

			//2. insert the newly created element
			listHead = insertToHead(listHead, newElement);
			//insertToTail(&listHead, newElement);
			fscanf(pFile, "%s", buffer);
		}
		fclose(pFile);
	}
}
void insertToTail(List** head, List* newElemenet)
{
	//test if the first element exists
	if (*head == NULL)
	{
		*head = newElemenet;
	}
	else
	{
		List* index = *head;
		while (index->pList)
			index = index->pList;
		index->pList = newElemenet;
	}
}

List* insertToHead(List* head, List* newElement)
{
	newElement->pList = head;
	return newElement;
}

List* createElement(char* buffer, float salary)
{
	//1.allocate memory for the new element
	List* newElement = (List*)malloc(sizeof(List));
	//2.initialize it with the params 
	//(the connection attributes should remain NULL)
	newElement->pList = NULL;
	newElement->salary = salary;
	newElement->employee = (char*)malloc(strlen(buffer) + 1);
	strcpy(newElement->employee, buffer);
	//3.return the new element
	return newElement;
}