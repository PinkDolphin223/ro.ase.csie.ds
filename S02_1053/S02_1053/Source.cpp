//STEFAN IULIA
//TURCU MIHAI
#include "stdio.h"
#include "malloc.h"
void main()
{
	FILE* pFile = NULL;
	int*** matPtr = NULL;
	pFile = fopen("Matrix.txt", "r");
	//1. read something before testing the eof
	int noLin, noCol;
	if (pFile)
	{
		int i, j, index = 0;
		fscanf(pFile, "%d %d", &noLin, &noCol);
		matPtr = (int***)malloc(noLin * sizeof(int**));
		for (int i = 0; i < noLin; i++)
			matPtr[i] = (int**)malloc(noCol * sizeof(int*));
		
		while (!feof(pFile))
		{
			int element;
			fscanf(pFile, "%d", &element);
			i = index / noCol;
			j = index % noCol;
			matPtr[i][j] = (int*)malloc(sizeof(int));
			*matPtr[i][j] = element;
			index++;
		}
	}
}