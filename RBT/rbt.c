#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rbt.h"

struct node
{
	int key;
	struct node* right;
	struct node* left;
	bool r;
};

node* BSTInsert(RBT root, int key)
{

	if(root == NULL)
	{
		root = (node*) malloc(sizeof(node));
		return root;
	}
	else if(key < root->key)
	{
		return BSTInsert(root->left, key);	
	}
	else if(key > root->key)
	{
		return BSTInsert(root->right, key);
	}

	return NULL;

}

node* insert(RBT root, int key)
{

	root = BSTInsert(root, key);

	return root;

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

	printf("key=%i\n",root->key);

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
