#include "tree.h"

static struct node *tree_alloc_node(void *data, size_t size) {
	struct node *node = (struct node *) malloc(sizeof(struct node));

	if (node == NULL)
		return NULL;

	if (data != NULL) {
		node->data = malloc(size);
		memcpy(node->data, data, size);
		node->size = size;
	}

	return node;
}

static void tree_dealloc_node(struct node *node) {
	free(node->data);
	free(node);
}

struct tree *tree_alloc(int (*compare_to)(void *, void *)) {
	struct tree *tree = (struct tree *) malloc(sizeof(struct tree));

	if (tree == NULL)
		return NULL;

	tree->root = NULL;
	tree->size = 0;
	tree->compare_to = compare_to;

	return tree;
}

static void tree_insert_helper(struct node *node, void *data, size_t size, int (*compare_to)(void *, void *)) {
	int result = compare_to(node->data, data);

	if (result == 0) {
		return;
	} else if (result > 0) {
		if (node->left == NULL) {
			node->left = tree_alloc_node(data, size);
		} else {
			tree_insert_helper(node->left, data, size, compare_to);
		}
	} else {
		if (node->right == NULL) {
			node->right = tree_alloc_node(data, size);
		} else {
			tree_insert_helper(node->right, data, size, compare_to);
		}
	}
}

void tree_insert(struct tree *tree, void *data, size_t size) {
	if (tree->root == NULL)
		tree->root = tree_alloc_node(data, size);
	else
		tree_insert_helper(tree->root, data, size, tree->compare_to);
}

static int tree_contains_helper(struct node *node, void *data, int (*compare_to)(void *, void *)) {
	if (node == NULL)
		return 0;

	int result = compare_to(node->data, data);

	if (result == 0)
		return 1;
	else if (result > 0)
		return tree_contains_helper(node->left, data, compare_to);
	else
		return tree_contains_helper(node->right, data, compare_to);
}

int tree_contains(struct tree *tree, void *data) {
	if (tree->root == NULL)
		return 0;
	return tree_contains_helper(tree->root, data, tree->compare_to);
}

static void tree_dealloc_helper(struct node *node) {
	if (node->left != NULL)
		tree_dealloc_helper(node->left);
	if (node->right != NULL)
		tree_dealloc_helper(node->right);

	tree_dealloc_node(node);
}

void tree_dealloc(struct tree *tree) {
	if (tree->root != NULL)
		tree_dealloc_helper(tree->root);
	free(tree);
}

static void tree_treverse_inorder_helper(struct node *node) {
	if (node == NULL)
		return;

	tree_treverse_inorder_helper(node->left);
	printf("%i,", *((int *) node->data));
	tree_treverse_inorder_helper(node->right);
}

void tree_treverse_inorder(struct tree *tree) {
	tree_treverse_inorder_helper(tree->root);
	printf("\n");
}
