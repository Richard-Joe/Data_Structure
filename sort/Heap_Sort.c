#include <dstructure.h>

int len;

int heapify(int *in, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if (left < len && in[left] > in[largest]) {
		largest = left;
	}

	if (right < len && in[right] > in[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(in, i, largest);
		heapify(in, largest);
	}

	return 0;
}

int buildMaxHeap(int *in, int inlen) {
	int i;

	len = inlen;

	for (i = inlen / 2; i >= 0; i--) {
		heapify(in, i);
	}

	return 0;
}

int HeapSort(int *in, int inlen) {
	int i;

	if (!in)
		return -1;

	buildMaxHeap(in, inlen);

	for (i = inlen - 1; i > 0; i--) {
		swap(in, 0, i);
		len--;
		heapify(in, 0);
	}

	return 0;
}
