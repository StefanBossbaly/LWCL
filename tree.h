#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node *right;
	struct node *left;
	void *data;
	size_t size;
};

struct tree {
	struct node *root;
	int size;
	int (*compare_to)(void *, void *);
};

struct tree *tree_alloc(int (*compare_to)(void *, void *));
void tree_insert(struct tree *tree, void *data, size_t size);
int tree_contains(struct tree *tree, void *data);
void tree_dealloc(struct tree *tree);
void tree_treverse_inorder(struct tree *tree);
void *tree_min(struct tree *tree);
void *tree_max(struct tree *tree);


#endif /* TREE_H_ */
