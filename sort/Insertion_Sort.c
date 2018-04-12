#include <dstructure.h>

int InsertionSort(int *in, int inlen) {
	int i, j, temp;

	if (!in)
		return -1;

	for (i = 1; i < inlen; i++) {
		temp = in[i];
		j = i - 1;
		if (temp >= in[j])
			continue;

		while (temp < in[j] && j >= 0) {
			in[j+1] = in[j];
			j--;
		}
		in[j+1] = temp;
	}
 	return 0;
}
