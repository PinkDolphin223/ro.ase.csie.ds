#include "stdio.h"
#include "malloc.h"
void main()
{
	FILE* pFile = NULL;
	int*** matPtr = NULL;
	pFile = fopen("Matrice.txt", "r");
	if (pFile)
	{
		int nrLinii, nrColoane;
		fscanf(pFile, "%d %d", &nrLinii, &nrColoane);
		matPtr = (int***)malloc(sizeof(int**)*nrLinii);
		for (int i = 0; i < nrLinii; i++)
		{
			matPtr[i] = (int**)malloc(sizeof(int*)*nrColoane);
		}
		int i, j, contor=0;
		while (!feof(pFile))
		{
			int element;
			fscanf(pFile, "%d", &element);
			i = contor / nrColoane;
			j = contor % nrColoane;
			matPtr[i][j] = (int*)malloc(sizeof(int));
			*matPtr[i][j] = element;
		}
	}
}