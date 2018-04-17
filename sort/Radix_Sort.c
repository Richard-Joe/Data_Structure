#include <dstructure.h>
#include <string.h>
#include <math.h>

int RadixSort(int *in, int inlen) {
	int i, j, k, h, max = in[0], maxBits = 1, digit;
	int radixAry[10][500] = {0};
	int count[10] = {0};

	for(i = 1; i < inlen; i++) {
		if (in[i] > max)
			max = in[i];
	}

	while (max / 10) {
		maxBits++;
		max = max / 10;
	}

	for (i = 0; i < maxBits; i++) {
		for (j = 0; j < inlen; j++) {
			digit = (in[j] / (int)pow(10, i)) % 10;
			radixAry[digit][count[digit]] = in[j];
			count[digit]++;
		}

		h = 0;
		for (j = 0; j < 10; j++) {
			for (k = 0; k < count[j]; k++) {
				in[h++] = radixAry[j][k];
			}
		}
		memset(count, 0, sizeof(int)*10);
	}

	return 0;
}