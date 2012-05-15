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

//Vector
struct vector *vector_alloc();
struct vector *vector_alloc_with_size(size_t size);
void vector_add(struct vector *vector, void *data, size_t size);
void *vector_get(struct vector *vector, int index);

static void vector_ensure_capacity(struct vector *vector);

#endif /* VECTOR_C_ */