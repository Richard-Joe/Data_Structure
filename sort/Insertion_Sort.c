#include <dstructure.h>

int InsertionSort(int *in, int inlen) {
	int i, j, temp;

	if (!in)
		return -1;

	for (i = 1; i < inlen; i++) {
		temp = in[i];
		j = i - 1;
		while (temp < in[j]) {
			in[j+1] = in[j];
			j--;
		}
		in[j] = temp;
	}
 	return 0;
}
