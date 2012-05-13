/*
 * linkedlist.h
 *
 *  Created on: May 10, 2012
 *      Author: stefan
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

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

#endif /* LINKEDLIST_H_ */
