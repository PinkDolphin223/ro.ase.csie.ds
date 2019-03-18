#include "stdio.h"
#include "string.h"
#include "malloc.h"
struct List
{
	char* studentName;
	int groupNo;
	List* pNext;
};

List* createElement(char*, int);
List* headInsertion(List*, List*);
//by reference
void tailInsertion(List*&, List*);
//by pointer
void tailInsertion(List**, List*);
void main()
{
	FILE* pFile = fopen("source.txt", "r");
	List* headList = NULL;
	if (pFile)
	{
		char buffer[100]; int groupNo;
		fscanf(pFile, "%s", buffer);
		while (!feof(pFile))
		{
			fscanf(pFile, "%d", &groupNo);
			//1.create a new element of type List*
			List* newNode = createElement(buffer, groupNo);
			//2.insert the newly created element into the list
			//2.1 head insertion
			headList = headInsertion(headList, newNode);
			//2.2 tail insertion
			//calling by reference
			//tailInsertion(headList, newNode);
			//calling by pointer
			//tailInsertion(&headList, newNode);
			fscanf(pFile, "%s", buffer);
		}
		List* index = headList;
		while (index)
		{
			printf("Student: %s, group number: %d \n",
				index->studentName,
				index->groupNo);
			index = index->pNext;
		}
		fclose(pFile);
	}
}
//by reference
void tailInsertion(List*& head, List* element)
{
	if (head == NULL)
	{
		head = element;
	}
	else
	{
		List* index = head;
		while (index->pNext)
			index = index->pNext;
		//connect the tail with the new element
		index->pNext = element;
	}
}
//by pointer
void tailInsertion(List** head, List* element)
{
	if (*head == NULL)
	{
		*head = element;
	}
	else
	{
		List* index = *head;
		while (index->pNext)
			index = index->pNext;
		//connect the tail with the new element
		index->pNext = element;
	}
}
List* headInsertion(List* head, List* element)
{
	element->pNext = head;
	return element;
}
List* createElement(char* name, int groupNo)
{
	//1.declare and initialize the new element
	List* newNode = (List*)malloc(sizeof(List));
	newNode->pNext = NULL;
	newNode->groupNo = groupNo;
	newNode->studentName = (char*)malloc(strlen(name) + 1);
	strcpy(newNode->studentName, name);
	//2.return the node
	return newNode;
}