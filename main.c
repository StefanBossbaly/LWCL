#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * main.c
 *
 *  Created on: May 10, 2012
 *      Author: stefan
 */

void print_list(struct list *list) {
	struct node *temp = list->head;
	while (temp != NULL) {
		printf("%i->", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");
}

int main(void) {
	struct list *my_list = linkedlist_alloc_list();

	linkedlist_append(my_list, 2);
	linkedlist_append(my_list, 3);
	linkedlist_append(my_list, 4);
	linkedlist_prepend(my_list, 1);
	print_list(my_list);

	linkedlist_remove_tail(my_list);
	print_list(my_list);

	linkedlist_dealloc_list(my_list);

	return 0;
}

