#include "vector.h"

struct element *element_alloc(void *data, size_t size) {
	struct element *element = (struct element *) malloc(sizeof(struct element));

	if (element == NULL) {
		printf("Error allocating memory");
		exit(1);
	}

	if (data != NULL) {
		element->data = malloc(size);
		memcpy(element->data, data, size);
		element->size = size;
	}

	return element;
}

struct vector *vector_alloc() {
	return vector_alloc_with_size(VEC_SIZE);
}

struct vector *vector_alloc_with_size(size_t size) {
	struct vector *vector = (struct vector *) malloc(sizeof(struct vector));

	vector->elements = (struct element **) malloc(size * sizeof(struct element));
	vector->capacity = size;
	vector->length = 0;

	return vector;
}

void vector_add(struct vector *vector, void *data, size_t size) {
	vector_ensure_capacity(vector);

	if (vector->elements[vector->length] == NULL) {
		vector->elements[vector->length] = element_alloc(data, size);
	} else {
		vector->elements[vector->length]->data = data;
		vector->elements[vector->length]->size = size;
	}

	vector->length++;
}

void *vector_get(struct vector *vector, int index) {
	if (index < 0 || index > vector->length)
		return NULL;

	return vector->elements[index]->data;
}

void *vector_insert(struct vector *vector, int index, void *data, size_t size) {
	if (index < 0 || index > vector->length)
		return;

	vector->elements[index]->data = data;
	vector->elements[index]->size = size;
}

static void vector_ensure_capacity(struct vector *vector) {
	if ((vector->length + 1) == vector->capacity) {
		vector->elements = (struct element **) realloc(vector->elements, sizeof(struct element) * 2 * vector->capacity);
		vector->capacity *= 2;
	}
}
