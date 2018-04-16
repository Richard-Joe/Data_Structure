#include <dstructure.h>

int partition(int *in, int left, int right) {
	int i, pivot = left, index = pivot + 1;

	for (i = index; i <= right; i++) {
		if (in[i] < in[pivot]) {
			swap(in, i, index);
			index++;
		}
	}
	swap(in, pivot, index - 1);
	return index - 1;
}

int QuickSort(int *in, int left, int right) {
	int partitionIndex;

	if (!in)
		return -1;

	if (left < right) {
		partitionIndex = partition(in, left, right);
		QuickSort(in, left, partitionIndex - 1);
		QuickSort(in, partitionIndex + 1, right);
	}

	return 0;
}