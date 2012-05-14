#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(struct list *list) {
	struct node *temp = list->head->next;
	while (temp != NULL) {
		printf("%i->", *((int *)temp->data));
		temp = temp->next;
	}

	printf("NULL\n");
}

int compare(void *num1, void *num2) {
    return *((int *) num1) - *((int *) num2);
}

int main(void) {
	struct list *my_list = linkedlist_alloc_list();
	
	int i = 0;
	
	for (i = 0; i <= 100; i++) {
	 	linkedlist_append(my_list, &i, sizeof(int));   
	}
	
	int test = 40;
	
	printf("%i\n", linkedlist_contains(my_list, &test, compare));
	
	linkedlist_dealloc_list(my_list);

	return 0;
}

