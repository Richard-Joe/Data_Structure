#include <dstructure.h>
#include <stdio.h>

typedef struct StBucketElem {
	int data;
	struct StBucketElem *next;
} BktElem;

#define BUCKET_COUNT 100

int BucketSort(int *in, int inlen) {
	int i, j;
	BktElem *ptr = NULL;
	BktElem Buckets[BUCKET_COUNT] = {0};
	
	for (i = 0; i < inlen; i++) {
		BktElem elem;
		elem.data = in[i];
	    printf("%d\t", elem.data);
		elem.next = NULL;
		ptr = &Buckets[in[i] / 10];
		while (ptr) {
			if (!ptr->next) {
				ptr->next = &elem;
				break;
			}
			printf("%d > %d\n", ptr->next->data, elem.data);
			if (ptr->next->data > elem.data) {
				elem.next = ptr->next;
				ptr->next = &elem;
			}
			ptr = ptr->next;
		}
	}

	printf("DONE\n");

	for (i = 0, j = 0; i < BUCKET_COUNT && j < inlen; i++) {
		ptr = Buckets[i].next;
		printf("%p\n", ptr);
		while (ptr) {
			in[j++] = ptr->data;
			printf("%d ", ptr->data);
			ptr = ptr->next;
		}
	}

	return 0;
}