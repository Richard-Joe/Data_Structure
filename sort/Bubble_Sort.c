#include <dstructure.h>

int BubbleSort(int *in, int inlen) {
	int i, j, temp;
	if (!in)
		return -1;

	for (j = 0; j < inlen - 1; j++) {
		for (i = 0; i < inlen - 1 - j; i++) {
			if (in[i] > in[i+1]) {
				temp = in[i];
				in[i] = in[i+1];
				in[i+1] = temp;
			}
		}
	}

	return 0;
}
