#include <dstructure.h>

int SelectionSort(int *in, int inlen) {
	int i, j, minIndex, temp;

	if (!in)
		return -1;

	for (i = 0; i < inlen - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < inlen; j++) {
			if (in[minIndex] > in[j]) {
				minIndex = j;
			}
		}
		if (i != minIndex) {
			temp = in[i];
			in[i] = in[minIndex];
			in[minIndex] = temp;
		}
	}

	return 0;
}
