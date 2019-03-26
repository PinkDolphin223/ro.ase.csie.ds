#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "string.h"

using namespace std;
struct DLL
{
	char* profession;
	float salary;
	DLL* pNext;
	DLL* pPrev;
};

DLL* createElement(const char*, float);
DLL* insertToHead(DLL*, DLL*);
void insertToTail(DLL**, DLL*);
//void insertToTail(List*&, List*);
void afisareLista(DLL*);
void insertMiddle(const char*, DLL*, DLL*);
void main()
{
	FILE* pFile = fopen("Data.txt", "r");

	DLL* listHead = NULL;

	if (pFile)
	{
		char buffer[100]; float salary;
		fscanf(pFile, "%s", buffer);
		while (!feof(pFile))
		{
			fscanf(pFile, "%f", &salary);

			//1. create an element of type List*
			DLL* newElement = createElement(buffer, salary);

			//2. insert the newly created element
			//listHead = insertToHead(listHead, newElement);
			insertToTail(&listHead, newElement);
			fscanf(pFile, "%s", buffer);
		}
		fclose(pFile);

		afisareLista(listHead);
		DLL* node = createElement("Avocat", 1300);
		insertMiddle("Judecator", listHead, node);
		printf("----------------------------\n");
		afisareLista(listHead);
	}
}

void insertMiddle(const char* cond, DLL* head, DLL* node)
{
	while (head && strcmp(cond, head->profession) != 0)
		head = head->pNext;
	if (head)
	{
		//1.legare nod de structura
		node->pNext = head->pNext;
		node->pPrev = head;
		//2.legare structura de 
		if (head->pNext)
			head->pNext->pPrev = node;
		head->pNext = node;
	}
}

void afisareLista(DLL* head)
{
	if (head)
		do
		{
			printf("Profesie: %s, salariu: %f \n",
				head->profession, head->salary);
			head = head->pNext;
		} while (head->pNext);
		printf("Profesie: %s, salariu: %f \n",
			head->profession, head->salary);
		printf("---------------------------------------\n");
		for (DLL* index = head; index; index = index->pPrev)
		{
			printf("Profesie: %s, salariu: %f \n",
				index->profession, index->salary);
		}

}

void insertToTail(DLL** head, DLL* newElemenet)
{
	//test if the first element exists
	if (*head == NULL)
	{
		*head = newElemenet;
	}
	else
	{
		DLL* index = *head;
		while (index->pNext)
			index = index->pNext;
		newElemenet->pPrev = index;
		index->pNext = newElemenet;
	}
}

DLL* insertToHead(DLL* head, DLL* newElement)
{
	newElement->pNext = head;
	if (head)
		head->pPrev = newElement;
	return newElement;
}

DLL* createElement(const char* buffer, float salary)
{
	//1.allocate memory for the new element
	DLL* newElement = (DLL*)malloc(sizeof(DLL));
	//2.initialize it with the params 
	//(the connection attributes should remain NULL)
	newElement->pNext = NULL;
	newElement->pPrev = NULL;
	newElement->salary = salary;
	newElement->profession = (char*)malloc(strlen(buffer) + 1);
	strcpy(newElement->profession, buffer);
	//3.return the new element
	return newElement;
}