#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dstructure.h>

void BufPrint(int *data, int datalen) {
	int i;

	for (i = 0; i < datalen; i++)
		printf("%d, ", data[i]);
	printf("\n\n");
}

int GenRandNumber(int *out, int count, int max) {
	int i;

	if (!out)
		return -1;

	srand((unsigned int)time(NULL));

	for (i = 0; i < count; i++)
		out[i] = rand() % max;

	return 0;
}

#define MAX 1000
#define SIZE 500

int sortArray[SIZE];

void MainMenu() {
	int key;
	printf("\n");
	printf("0: Bubble Sort\n");
	printf("1: Selection Sort\n");
	printf("2: Insertion Sort\n");

	printf("\nPlease Select: ");
	scanf("%d", &key);
	printf("\n");

	switch(key) {
		case 0:
			BubbleSort(sortArray, SIZE);
			BufPrint(sortArray, SIZE);
			break;
		case 1:
			SelectionSort(sortArray, SIZE);
			BufPrint(sortArray, SIZE);
			break;
		case 2:
			InsertionSort(sortArray, SIZE);
			BufPrint(sortArray, SIZE);
			break;
		default:
			printf("error\n");
			break;
	}
}

int main() {
	GenRandNumber(sortArray, SIZE, MAX);
	BufPrint(sortArray, SIZE);

	MainMenu();

	return 0;
}