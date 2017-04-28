#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rbt.h"

struct node
{
	int key;
	struct node* right;
	struct node* left;
	struct node* parent;
	bool black;
};

node* BSTInsert(RBT root, int key)
{

	if(root == NULL)
	{
		root = (node*) malloc(sizeof(node));
		root->key = key;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		return root;
	}
	else if(key < root->key)
	{
		if(root->left == NULL)
		{
			node* n = (node*) malloc(sizeof(node));
			n->key = key;
			n->left = NULL;
			n->right = NULL;
			n->parent = root;
			root->left = n;
			return n;
		}
		return BSTInsert(root->left, key);	
	}
	else if(key > root->key)
	{
		if(root->right == NULL)
		{
			node* n = (node*) malloc(sizeof(node));
			n->key = key;
			n->left = NULL;
			n->right = NULL;
			root->right = n;
			n->parent = root;
			return n;
		}
		return BSTInsert(root->right, key);
	}

	return NULL;

}

node* fixViolations(node* root, node* n)
{
	
	return NULL;
}

node* insert(RBT root, int key)
{

	if(root == NULL)
	{
		root = BSTInsert(root, key);
		root->black = true;
		return root;
	}

	node* n = BSTInsert(root, key);
	n->black = false;

	fixViolations(root, n);

	return n;

}

void Traverse(RBT root)
{

	if(root == NULL)
	{
		return;
	}

	if(root->left != NULL)
	{
		Traverse(root->left);
	}

	printf("key=%i\tcolor=%i\n",root->key,root->black);

	if(root->right != NULL)
	{
		Traverse(root->right);
	}

}

void dispose(RBT root)
{

	if(root == NULL)
	{
		return;
	}

	if(root->left != NULL)
	{
		dispose(root->left);
		root->left = NULL;
	}

	if(root->right != NULL)
	{
		dispose(root->right);
		root->right = NULL;
	}

	free(root);

}
