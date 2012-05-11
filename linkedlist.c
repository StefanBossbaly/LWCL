#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/*
 * linkedlist.c
 *
 *  Created on: May 10, 2012
 *      Author: stefan
 */

static struct node *linkedlist_alloc_node_data(int data) {
	return linkedlist_alloc_node(NULL, data);
}

static struct node *linkedlist_alloc_node(struct node *next, int data) {
	struct node *node = malloc(sizeof(struct node));

	if (node == NULL) {
		printf("Error allocating memory");
		exit(1);
	}

	node->next = next;
	node->data = data;

	return node;
}

void linkedlist_dealloc_node(struct node *node) {
	free(node);
}

struct list *linkedlist_alloc_list() {
	struct list *list = malloc(sizeof(struct list));

	if (list == NULL) {
		printf("Error allocating memory");
		exit(1);
	}

	list->head = list->tail = linkedlist_alloc_node(NULL, NULL);
	list->size = 0;

	return list;
}

void linkedlist_append(struct list *list, int data) {
	struct node *temp = linkedlist_alloc_node(NULL, data);
	list->tail->next = temp;
	list->tail = temp;
}

void linkedlist_prepend(struct list *list, int data) {
	struct node *temp = list->head->next;
	list->head->next = linkedlist_alloc_node(temp, data);
}

void linkedlist_dealloc_list(struct list *list) {
	struct node *temp = list->head;

	while (temp != NULL) {
		struct node *temp2 = temp->next;
		linkedlist_dealloc_node(temp);
		temp = temp2;
	}

	free(list);
}
