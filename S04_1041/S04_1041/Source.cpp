#include "stdio.h"
#include "string.h"
#include "stdlib.h"
//COMAN ALEXANDRU
//CHIOIBAS DORIN
//CONSTANTINESCU RAZVAN
//CRETU LEONARD
//CHICIU MIHAI
//CIOBANU ALEXANDRU
struct List
{
	char* profesie;
	float salariuMediu;
	List* pNext;
};

List* creareElement(char*, float);
List* headInsertion(List*, List*);
void tailInsertion(List**, List*);
void tailInsertion(List*&, List*);

void main()
{
	FILE* pFile = fopen("date.txt", "r");
	List* headList = NULL;
	if (pFile)
	{
		char buffer[100]; float salariu;
		fscanf(pFile,"%s", buffer);
		while (!feof(pFile))
		{
			fscanf(pFile, "%d", &salariu);
			//1.creare element
			List* nou = creareElement(buffer, salariu);
			//2.inserare element nou in lista
			//2.1 inserare la inceput
			headList = headInsertion(headList, nou);
			//2.2 inserare la sfarsit
			tailInsertion(headList, nou); //referinta
			tailInsertion(&headList, nou); //pointer
			fscanf(pFile, "%s", buffer);
		}
		fclose(pFile);
	}
}
List* headInsertion(List* head, List* newNode)
{
	newNode->pNext = head;
	return newNode;
}
void tailInsertion(List** head, List* nou)
{
	if (*head == NULL)
		*head = nou;
	else
	{
		List* index = *head;
		while (index->pNext)
			index = index->pNext;
		index->pNext = nou;
	}
}
void tailInsertion(List*& head, List* nou)
{
	if (head == NULL)
		head = nou;
	else
	{
		List* index = head;
		while (index->pNext)
			index = index->pNext;
		index->pNext = nou;
	}
}
List* creareElement(char* profesie, float salariu)
{
	List* nou = (List*)malloc(sizeof(List));
	nou->salariuMediu = salariu;
	nou->profesie = (char*)malloc(strlen(profesie) + 1);
	strcpy(nou->profesie, profesie);
	nou->pNext = NULL;
	return nou;
}