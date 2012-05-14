#include "linkedlist.h"

static struct node *linkedlist_alloc_node(struct node *next, void *data, size_t size) {
	struct node *node = malloc(sizeof(struct node));

	if (node == NULL) {
		printf("Error allocating memory");
		exit(1);
	}

	node->next = next;
	
	if (data != NULL) {
	    node->data = malloc(size);
	    memcpy(node->data, data, size);
	}
	else {
	    node->data = NULL;
	}

	return node;
}

static inline void linkedlist_dealloc_node(struct node *node) {
    free(node->data);
	free(node);
}

struct list *linkedlist_alloc_list() {
	struct list *list = malloc(sizeof(struct list));

	if (list == NULL) {
		printf("Error allocating memory");
		exit(1);
	}

	list->head = list->tail = linkedlist_alloc_node(NULL, NULL, 0);
	
	if (list->head == NULL) {
	    printf("Error allocating memory");
		exit(1);
	}
	
	list->size = 0;

	return list;
}

void linkedlist_append(struct list *list, void *data, size_t size) {
	struct node *temp = linkedlist_alloc_node(NULL, data, size);
	list->tail->next = temp;
	list->tail = temp;
	list->size++;
}

void linkedlist_prepend(struct list *list, void *data, size_t size) {
	struct node *temp = list->head->next;
	list->head->next = linkedlist_alloc_node(temp, data, size);
	list->size++;
}

void linkedlist_remove_head(struct list *list) {
	struct node *temp = list->head->next;

	if (temp != NULL) {
		struct node *temp2 = temp->next;
		linkedlist_dealloc_node(temp);
		list->head->next = temp2;
		list->size--;
	}
}
void linkedlist_remove_tail(struct list *list) {
	struct node *temp = list->head;

	while (temp->next != list->tail) {
		temp = temp->next;
	}

	linkedlist_dealloc_node(list->tail);

	list->tail = temp;
	list->tail->next = NULL;
	list->size--;
}

int linkedlist_contains(struct list *list, void *data, int (*compare_to)(void *, void *)) {
    struct node *temp = list->head->next;
    
    while (temp != NULL) {
        if (compare_to(data, temp->data) == 0)
            return 1;
        temp = temp->next;
    }
    
    return 0;
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
