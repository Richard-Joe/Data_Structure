#ifndef DSTRUCTURE_H
#define DSTRUCTURE_H

int BubbleSort(int *in, int inlen);

int SelectionSort(int *in, int inlen);

int InsertionSort(int *in, int inlen);

int ShellSort(int *in, int inlen);

int MergeSort(int *in, int inlen, int leftIndex);

int QuickSort(int *in, int left, int right);

int CountingSort(int *in, int inlen, int maxValue);

int BucketSort(int *in, int inlen);

#endif // DSTRUCTURE_H