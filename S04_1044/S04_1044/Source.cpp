#include "stdio.h"
#include "string.h"
#include "malloc.h"
struct Lista
{
	char* numeStudent;
	int grupa;
	Lista* pNext;
};
Lista* creareElement(char*, int);
Lista* inserareHead(Lista*, Lista*);
void inserareTail(Lista**, Lista*);
//void inserareTail(Lista*&, Lista*);
void main()
{
	FILE* pFile = fopen("Date.txt", "r");
	if (pFile)
	{
		//definire lista de studenti
		//1.sizeof(Lista) alocat pe stiva functiei
		//unde este declarata variabila
		//Lista lstStudenti;

		//2.1 sizeof(Lista*) alocat pe stiva functiei
		//unde este declarata variabila
		//2.2 sizeof(Lista) alocat in HEAP
		Lista* capatLista = NULL;

		char buffer[100];
		int grupa;
		fscanf(pFile, "%s", buffer);
		while (!feof(pFile))
		{
			fscanf(pFile, "%d", &grupa);
			//1.creare element ptr la structura
			Lista* elementNou = creareElement(buffer, grupa);
			//2.inserare element in lista
			//2.1 inserare la inceput
			//capatLista = inserareHead(capatLista, elementNou);
			//2.2 inserare la sfarsit
			inserareTail(&capatLista, elementNou);
			fscanf(pFile, "%s", buffer);
		}
		fclose(pFile);
		Lista* index = capatLista;
		while (index)
		{
			printf("Student: %s, grupa: %d \n",
				index->numeStudent,
				index->grupa);
			index = index->pNext;
		}
	}
}

void inserareTail(Lista** capat, Lista* nou)
{
	if (*capat == NULL)
	{
		*capat = nou;
	}
	else
	{
		Lista* index = *capat;
		while (index->pNext)
			index = index->pNext;
		index->pNext = nou;
	}
}

Lista* inserareHead(Lista* capat, Lista* nou)
{
	nou->pNext = capat;
	return nou;
}

Lista* creareElement(char* nume, int grupa)
{
	Lista* elementNou = (Lista*)malloc(sizeof(Lista));
	elementNou->pNext = NULL;
	elementNou->grupa = grupa;
	elementNou->numeStudent = (char*)malloc(strlen(nume) + 1);
	strcpy(elementNou->numeStudent, nume);
	return elementNou;
}