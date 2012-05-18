#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int compare(void *num1, void *num2) {
	return *((int *) num1) - *((int *) num2);
}

int main(void) {
	struct vector *vector = vector_alloc();

	int i;
	for (i = 0; i < 20; i++)
		vector_add(vector, &i, sizeof(int));

	for (i = 0; i < 20; i++)
		printf("%i,", *((int *) vector_get(vector, i)));

	printf("\n");

	vector_dealloc(vector);
}
