#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct node 
{

	int key;
	struct node* left;
	struct node* right;

};

node* insert(BST root, int key) 
{

	if(root == NULL) 
	{
		root = malloc(sizeof(node));
		root->key = key;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	
	if(key < root->key)
	{
		if(root->left == NULL)
		{
			node* n = (node*) malloc(sizeof(node));
			n->key = key;
			n->left = NULL;
			n->right = NULL;
			root->left = n;
			return n;
		}
		return insert(root->left, key);	
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
			return n;
		}
		return insert(root->right, key);
	}

	return NULL;

}

node* removeNode(BST root, int key)
{

	node* parent = NULL;
	node* child = NULL;

	if(root -> key == key)
	{
		printf("HELLO\n");
		if(root->left == NULL && root->right == NULL)
		{
			printf("NOOO\n");
			free(root);
			return NULL;
		}

		parent = root;
		if(root->right != NULL)
		{
			printf("AYY\n");
			child = parent->right;

			while(child->left != NULL)
			{
				parent = child;
				child = parent->left;
			}
			parent->left = child->right;
			child->left = root->left;
			child->right = root->right;
			return child;	
		}

		child = parent->left;

		while(child->right != NULL)
		{
			parent = child;
			child = parent->right;
		}
		parent->right = child->left;
		child->left = root->left;
		child->right = root->right;
		
		printf("WTF\n");
		return child;
	}
	return NULL;

}

void Traverse(BST root) {

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

void dispose(BST root) {

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

/*int main(void)
{

	BST tree = NULL;
	tree = insert(tree, 20);
	insert(tree, 25);
	insert(tree, 15);
	Traverse(tree);

}*/
