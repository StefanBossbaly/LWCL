#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int compare(void *num1, void *num2) {
    return *((int *) num1) - *((int *) num2);
}


int main(){
	struct tree *tree = tree_alloc(compare);

	int i = 1;
	int j = 10;
	int k = 20;
	int l = 13;

	int z = 12;

	tree_insert(tree, &k, sizeof(int));
	tree_insert(tree, &j, sizeof(int));
	tree_insert(tree, &l, sizeof(int));
	tree_insert(tree, &i, sizeof(int));
	tree_insert(tree, &i, sizeof(int));

	assert(tree_contains(tree, &i) == 1);
	assert(tree_contains(tree, &z) == 0);


	return 0;
}
