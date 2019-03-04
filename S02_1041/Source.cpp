#include "stdio.h"
#include "malloc.h"
void main()
{
	FILE* pFile = NULL;
	int*** matPtr = NULL;
	pFile = fopen("matrice.txt","r");
	if (pFile)
	{
		int nrLinii, nrColoane;
		fscanf(pFile, "%d %d", &nrLinii, &nrColoane);
		matPtr = (int***)malloc(nrLinii * sizeof(int**));
		for (int i = 0; i < nrLinii; i++)
			matPtr[i] = (int**)malloc(nrColoane * sizeof(int*));
		int index = 0;
		while (!feof(pFile))
		{
			int element;
			fscanf(pFile, "%d", &element);
			//printf("%d", element);
			//determinare i si j
			int i = index / nrColoane;
			int j = index % nrColoane;
			//alocare element (i,j)
			matPtr[i][j] = (int*)malloc(sizeof(int));
			//initializare element (i,j)
			*matPtr[i][j] = element;
			index++;
		}
		for (int i = 0; i < nrLinii; i++)
		{
			for (int j = 0; j < nrColoane; j++)
				printf(" %d ", *matPtr[i][j]);
			printf("\n");
		}
	}
	fclose(pFile);
}