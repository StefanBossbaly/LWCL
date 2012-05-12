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
	struct node *temp = list->head->next;
	while (temp != NULL) {
		printf("%i->", *((int *)temp->data));
		temp = temp->next;
	}

	printf("NULL\n");
}

int main(void) {
	struct list *my_list = linkedlist_alloc_list();
	int test = 5;

	linkedlist_append(my_list, &test, sizeof(int));
	print_list(my_list);
	
	linkedlist_dealloc_list(my_list);

	return 0;
}

