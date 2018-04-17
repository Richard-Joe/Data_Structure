#include <dstructure.h>
#include <malloc.h>

typedef struct StBucketElem {
	int data;
	struct StBucketElem *next;
} BktElem;

#define BUCKET_COUNT 1000

int BucketSort(int *in, int inlen) {
	int i, j;
	BktElem *ptr = NULL, *elem = NULL;
	BktElem Buckets[BUCKET_COUNT] = {0};
	BktElem *elemLists = (BktElem *)malloc(inlen * sizeof(BktElem));
	
	for (i = 0; i < inlen; i++) {
		elem = elemLists + i;
		elem->data = in[i];
		elem->next = NULL;
		ptr = &Buckets[in[i] % 1000];
		while (ptr) {
			if (!ptr->next) {
				ptr->next = elem;
				break;
			}
			if (ptr->next->data > elem->data) {
				elem->next = ptr->next;
				ptr->next = elem;
			}
			ptr = ptr->next;
		}
	}

	for (i = 0, j = 0; i < BUCKET_COUNT && j < inlen; i++) {
		ptr = Buckets[i].next;
		while (ptr) {
			in[j++] = ptr->data;
			ptr = ptr->next;
		}
	}

	free(elemLists);

	return 0;
}