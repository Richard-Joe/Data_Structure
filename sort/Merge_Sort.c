#include <string.h>
#include <dstructure.h>

#define MAX_SIZE 10000
static int glTmpArray[MAX_SIZE] = {0};

int Merge(int *left, int llen, int* right, int rlen, int leftIndex) {
	int i = 0, j = 0, k = leftIndex;

	while (i < llen && j < rlen) {
		if (left[i] <= right[j]) {
			glTmpArray[k++] = left[i++];
		} else {
			glTmpArray[k++] = right[j++];
		}
	}

	while (i < llen) {
		glTmpArray[k++] = left[i++];
	}

	while (j < rlen) {
		glTmpArray[k++] = right[j++];
	}

	memcpy(left, glTmpArray+leftIndex, (llen+rlen)*sizeof(int));

	return 0;
}

int MergeSort(int *in, int inlen, int leftIndex) {
	int left, right, middle;
	if (!in || inlen > MAX_SIZE)
		return -1;
	if (inlen < 2)
		return 0;

	left = 0;
	middle = inlen / 2;
	right = inlen;

	MergeSort(in+left, middle, leftIndex);
	MergeSort(in+middle, right-middle, leftIndex + middle);

	Merge(in+left, middle, in+middle, right-middle, leftIndex);

	return 0;
}
