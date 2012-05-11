/*
 * linkedlist.h
 *
 *  Created on: May 10, 2012
 *      Author: stefan
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct node {
	struct node *next;
	int data;
};

struct list {
	struct node *head;
	struct node *tail;
	int size;
};

//Node Operations
static struct node *linkedlist_alloc_node_data(int data);
static struct node *linkedlist_alloc_node(struct node *next, int data);
static void linkedlist_dealloc_node(struct node *node);

//List Operations
struct list *linkedlist_alloc_list();
void linkedlist_append(struct list *list, int data);
void linkedlist_prepend(struct list *list, int data);
void linkedlist_remove_head(struct list *list);
void linkedlist_remove_tail(struct list *list);
void linkedlist_dealloc_list(struct list *list);

#endif /* LINKEDLIST_H_ */
