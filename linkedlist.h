#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node *next;
	void *data;
	size_t data_size;
};

struct list {
	struct node *head;
	struct node *tail;
	int size;
};

struct list_iterator {
	struct node *current;
};

//Node Operations
static struct node *linkedlist_alloc_node(struct node *next, void *data, size_t size);
static inline void linkedlist_dealloc_node(struct node *node);

//List Operations
struct list *linkedlist_alloc_list();
void linkedlist_append(struct list *list, void *data, size_t size);
void linkedlist_prepend(struct list *list, void *data, size_t size);
void linkedlist_remove_head(struct list *list);
void linkedlist_remove_tail(struct list *list);
void linkedlist_dealloc_list(struct list *list);
int linkedlist_contains(struct list *list, void *data, int (*compare_to)(void *, void *));
void linkedlist_sort(struct list *list, int (*compare_to)(void *, void *));
static struct node *linkedlist_merge_sort(struct node *node, int (*compare_to)(void *, void *));
struct node *linkedlist_sort_middle(struct node *node);
struct node *linkedlist_merge(struct node *left, struct node *right, int (*compare_to)(void *, void *));
struct list_iterator *linkedlist_iterator(struct list *list);

//List Iterator Operations
void *iterator_current(struct list_iterator *iterator);
void iterator_next(struct list_iterator *iterator);

#endif /* LINKEDLIST_H_ */
