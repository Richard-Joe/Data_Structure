#include <dstructure.h>
#include <malloc.h>
#include <string.h>

int CountingSort(int *in, int inlen, int maxValue) {
	int i, j, maxSize = maxValue + 1;
	int *TmpBuf = NULL;

	if (!in)
		return -1;

	TmpBuf = (int *)malloc(maxSize * sizeof(int));
	memset(TmpBuf, 0, maxSize * sizeof(int));

	for (i = 0; i < inlen; i++) {
		TmpBuf[in[i]]++;
	}

	for (i = 0, j = 0; i < maxSize; i++) {
		while (TmpBuf[i]--)
			in[j++] = i;
	}

	free(TmpBuf);

	return 0;
}
