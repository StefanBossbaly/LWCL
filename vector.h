#ifndef VECTOR_C_
#define VECTOR_C_

#define VEC_SIZE 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element {
	void *data;
	size_t size;
};

struct vector {
	struct element **elements;
	size_t length;
	size_t capacity;
};

//Element
static struct element* element_alloc();
static void element_dealloc(struct element *element);

//Vector
struct vector *vector_alloc();
struct vector *vector_alloc_with_size(size_t size);
void vector_add(struct vector *vector, void *data, size_t size);
void *vector_get(struct vector *vector, int index);
void vector_insert(struct vector *vector, int index, void *data, size_t size);
void vector_delete(struct vector *vector, int index);
int vector_contains(struct vector *vector, void *data, int (*compare_to)(void *, void *));
void vector_dealloc(struct vector *vector);

static void vector_ensure_capacity(struct vector *vector);

#endif /* VECTOR_C_ */
