#include <dstructure.h>

#if 0
int ShellSort(int *in, int inlen) {
	int i, j, k, temp, gap = 1;

	if (!in)
		return -1;

	// Dynamic definition of interval sequences
	while (gap < inlen / 3) {
        gap = gap * 3 + 1;
    }

	for (; gap > 0; gap /= 3) {
		for (i = 0; i < gap; i++) {
			for (j = i + gap; j < inlen; j += gap) {
				temp = in[j];
				for (k = j - gap; temp < in[k] && k >= 0; k -= gap) {
					in[k + gap] = in[k];
				}
				in[k + gap] = temp;
			}
		}
	}

	return 0;
}
#else
int ShellSort(int *in, int inlen) {
    int gap, i, j, temp;

    for(gap = inlen / 2; gap > 0; gap /= 2) {
        for(i = gap; i < inlen; i++) {
            temp = in[i];
            for(j = i - gap; j >= 0 && in[j] > temp; j -= gap)
                in[j + gap] = in[j];
            in[j + gap] = temp;
        }
    }

    return 0;
}
#endif
