#ifndef __BST_H__
#define __BST_H__

struct node
{
	int key;
	struct node* parent;
	struct node* child[2];
};

struct node* insert_node(struct node *, struct node *);
struct node* remove_node(struct node *, struct node *);
void traverse_node(struct node *);
struct node* lookup_node(struct node *, int);
struct node* alloc_node(int);

#endif
