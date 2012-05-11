#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * main.c
 *
 *  Created on: May 10, 2012
 *      Author: stefan
 */

void print_list(struct list *list){
	struct node *temp = list->head;
	while(temp != NULL){
		printf("%i->", temp->data);
		temp = temp->next;
	}

	printf("NULL");
}

int main(void){
	struct list *my_list = linkedlist_alloc_list();

	int i = 0;

	for(i = 0; i < 10000; i++){
		linkedlist_append(my_list, i);
		linkedlist_prepend(my_list, i);
	}

	//print_list(my_list);

	linkedlist_dealloc_list(my_list);

	return 0;
}


