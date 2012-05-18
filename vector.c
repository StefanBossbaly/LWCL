#include "vector.h"

static void vector_ensure_capacity(struct vector *vector) {
	if ((vector->length + 1) == vector->capacity) {
		vector->elements = (struct element **) realloc(vector->elements, sizeof(struct element) * 2 * vector->capacity);
		if (vector->elements == NULL)
			return;

		vector->capacity *= 2;
	}
}

struct element *element_alloc(void *data, size_t size) {
	struct element *element = (struct element *) malloc(sizeof(struct element));

	if (element == NULL)
		return NULL;

	if (data != NULL) {
		element->data = malloc(size);
		memcpy(element->data, data, size);
		element->size = size;
	}

	return element;
}

static void element_dealloc(struct element *element) {
	free(element->data);
	free(element);
}

struct vector *vector_alloc() {
	return vector_alloc_with_size(VEC_SIZE);
}

struct vector *vector_alloc_with_size(size_t size) {
	struct vector *vector = (struct vector *) malloc(sizeof(struct vector));

	if (vector == NULL)
		return NULL;

	vector->elements = (struct element **) malloc(size * sizeof(struct element));

	if (vector->elements == NULL)
		return NULL;

	vector->capacity = size;
	vector->length = 0;

	return vector;
}

void vector_add(struct vector *vector, void *data, size_t size) {
	vector_ensure_capacity(vector);
	vector->elements[vector->length] = element_alloc(data, size);
	vector->length++;
}

void *vector_get(struct vector *vector, int index) {
	if (index < 0 || index > vector->length)
		return NULL;

	return vector->elements[index]->data;
}

void vector_insert(struct vector *vector, int index, void *data, size_t size) {
	if (index < 0 || index > vector->length)
		return;

	element_dealloc(vector->elements[index]);
	vector->elements[index] = element_alloc(data, size);
}

void vector_delete(struct vector *vector, int index) {
	if (index < 0 || index > vector->length)
		return;

	element_dealloc(vector->elements[index]);

	int i = 0;

	for (i = index; i < vector->length - 1; i++) {
		vector->elements[i] = vector->elements[i + 1];
	}

	vector->length--;
}

int vector_contains(struct vector *vector, void *data, int (*compare_to)(void *, void *)) {
	int i = 0;

	for (i = 0; i < vector->length; i++) {
		if (compare_to(data, vector->elements[i]->data) == 0)
			return 1;
	}

	return 0;
}

void vector_dealloc(struct vector *vector) {
	int i = 0;

	for (i = 0; i < vector->length; i++) {
		element_dealloc(vector->elements[i]);
	}

	free(vector->elements);
	free(vector);
}
