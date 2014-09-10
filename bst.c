#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct node* insert_node(struct node *head, struct node *new_node)
{
	if (head == NULL)
		return new_node;

	struct node* ptr = head;
	struct node* previous;
	while (ptr != NULL) {
		previous = ptr;
		ptr = ptr->child[new_node->key > ptr->key];
	}

	new_node->parent = previous;
	previous->child[new_node->key > previous->key] = new_node;

	return head;
}

struct node* remove_node(struct node *head, struct node *rm_node)
{
	if (!rm_node->child[0] && !rm_node->child[1]) {
		if (rm_node == head) {
			free(head);
			return NULL;
		}
		rm_node->parent->child[rm_node->key > rm_node->parent->key] = NULL;
	} else if (!rm_node->child[0] && rm_node->child[1]) {
		if (rm_node == head) {
			rm_node->child[1]->parent = rm_node->child[1];
			free(head);
			return rm_node->child[1];
		}
		rm_node->parent->child[rm_node->key > rm_node->parent->key] = rm_node->child[1];
		rm_node->child[1]->parent = rm_node->parent;
	} else if (rm_node->child[0] && !rm_node->child[1]) {
		if (rm_node == head) {
			rm_node->child[0]->parent = rm_node->child[0];
			free(head);
			return rm_node->child[0];
		}
		rm_node->parent->child[rm_node->key > rm_node->parent->key] = rm_node->child[0];
		rm_node->child[0]->parent = rm_node->parent;
	} else {
		struct node* temp = rm_node->child[0];
		if (!temp->child[1]) {
			rm_node->key = temp->key;
			rm_node->child[0] = temp->child[0];
			free(temp);
			return head;
		}
		while (temp->child[1])
			temp = temp->child[1];
		rm_node->key = temp->key;
		if (temp->child[0]) {
			temp->parent->child[temp->key > temp->parent->key] = temp->child[0];
			temp->child[0]->parent = temp->parent;
		} else {
			temp->parent->child[temp->key > temp->parent->key] = NULL;
		}
		free(temp);
		return head;
	}
	free(rm_node);
	return head;
}

/* in-order traversal*/
void traverse_node(struct node *head)
{
	if (head) {
		traverse_node(head->child[0]);
		printf("%d ", head->key);
		traverse_node(head->child[1]);
	}
}

void free_all(struct node* head)
{
	if (head) {
		free_all(head->child[0]);
		free_all(head->child[1]);
		free(head);
	}
}

struct node* lookup_node(struct node *head, int key)
{
	struct node *ptr = head;
	while (ptr != NULL && ptr->key != key) {
		ptr = ptr->child[key > ptr->key];
	}
	
	return ptr;
}

struct node* alloc_node(int key)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->key = key;
	temp->parent = temp;
	temp->child[0] = NULL;
	temp->child[1] = NULL;

	return temp;
}


