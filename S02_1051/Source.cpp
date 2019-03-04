#include "stdio.h"
#include "malloc.h"
void main()
{
	FILE* pFile = NULL;
	int*** matPtr = NULL;
	pFile = fopen("Matrix.txt", "r");
	if (pFile)
	{
		int noRows, noColumns;
		fscanf(pFile,"%d %d",&noRows, &noColumns);
		matPtr = (int***)malloc(noRows * sizeof(int**));
		for (int i = 0; i < noRows; i++)
			matPtr[i] = (int**)malloc(sizeof(int*)*noColumns);
		int i=0, j=0, counter = 0;
		while (!feof(pFile))
		{
			int element;
			fscanf(pFile, "%d", &element);
			i = counter / noColumns;
			j = counter % noColumns;
			matPtr[i][j] = (int*)malloc(sizeof(int));
			/*j++;
			if (j == noColumns - 1)
			{
				j = 0;
				i++;
			}*/
			*matPtr[i][j] = element;
			//matPtr[i][j] = &element;
			counter++;
		}
	}
}