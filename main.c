#include <stdio.h>
#include "bst.h"

int main (void)
{
	struct node *tree = NULL;
	struct node *temp;

	temp = alloc_node(5);
	tree = insert_node(tree, temp);
	temp = alloc_node(6);
	tree = insert_node(tree, temp);
	temp = alloc_node(7);
	tree = insert_node(tree, temp);
	temp = alloc_node(2);
	tree = insert_node(tree, temp);
	temp = lookup_node(tree, 5);
	tree = remove_node(tree, temp);
	traverse_node(tree);
	printf("\n");
	free_all(tree);

	return 0;
}
