#include <dstructure.h>

void swap(int *in, int i, int j) {
	int temp = in[i];
	in[i] = in[j];
	in[j] = temp;
}

int BubbleSort(int *in, int inlen) {
	int i, j;
	if (!in)
		return -1;

	for (j = 0; j < inlen - 1; j++) {
		for (i = 0; i < inlen - 1 - j; i++) {
			if (in[i] > in[i+1]) {
				swap(in, i, i+1);
			}
		}
	}

	return 0;
}
