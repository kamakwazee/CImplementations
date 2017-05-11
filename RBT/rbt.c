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

node* rotateRight(node* n, node* p, node* gp)
{

	printf("Rotate Right\n");
	
	gp->left = p->right;
	p->parent = gp->parent;
	gp->parent = p;
	p->right = gp;
	p->black = true;
	gp->black = false;

	return p;

}

node* rotateLeft(node* n, node* p, node* gp)
{

	printf("Rotate Left\n");
	
	gp->right = p->left;
	p->parent = gp->parent;
	gp->parent = p;
	p->left = gp;
	p->black = true;
	gp->black = false;

	return p;

}

node* fixViolations(node* root, node* n)
{
	printf("Fix Violations\n");
	
	node* gg = NULL; 						// great grandparent
	node* gp = NULL; 						// grandparent
	node* p = NULL; 						// parent
	node* u = NULL; 						// uncle
	
	while(n != root && !n->black && !n->parent->black)
	{
		printf("WHILE\n");
		p = n->parent;
		gp = p->parent;

		if(p == gp->left)
		{
			printf("Parent Left\n");
			u = gp->right;
		
			if(u != NULL)
			{
				if(!u->black)
				{
					printf("Uncle Red\n");
					p->black = true;
					u->black = true;
					gp->black = false;
					n = gp;
					continue;
				}
			}
			printf("Uncle Black\n");
			if(n == p->left)
			{
				printf("Left Left\n");
				gg = gp->parent;
				if(gg == NULL)
				{
					root = rotateRight(n, p, gp);
					printf("root=%i\n",root->key);
				}
				else
				{
					if(gp == gg->left)
					{
						printf("Grandparent Left\n");
						gg->left = rotateRight(n, p, gp);
					}
					else
					{
						printf("Grandparent Right\n");
						gg->right = rotateRight(n, p, gp);
					}
				}
				
			}
			else
			{
				printf("Left Right\n");
				gg = gp->parent;
				gp->left = rotateLeft(n->right, n, p);
				dump(root, 0, 2);
				if(gg == NULL)
				{
					root = rotateRight(p, n, gp);
					printf("root=%i\n",root->key);
				}
				else
				{
					if(gp == gg->left)
					{
						printf("Grandparent Left\n");
						gg->left = rotateRight(p, n, gp);
					}
					else
					{
						printf("Grandparent Right %i %i %i\n", gg->key, gp->key, gp->parent->key);
						gg->right = rotateRight(p, n, gp);
					}
				}
				
			}

		}
		else
		{
			printf("Parent Right\n");
			
			u = gp->left;
			if(u != NULL)
			{
				if(!u->black)
				{
					printf("Uncle Red\n");
					p->black = true;
					u->black = true;
					gp->black = false;
					n = gp;
					continue;
				}
			}
		
			printf("Uncle Black\n");
			if(n == p->right)
			{
				printf("Right Right\n");
				gg = gp->parent;

				if(gg == NULL)
				{
					printf("Great Grandparent NULL\n");
					root = rotateLeft(n, p, gp);
					printf("root=%i\n", root->key);
				}
				else
				{
					if(gp == gg->left)
					{
						printf("Grandparent Left\t%i\n", gp->key);
						gg->left = rotateLeft(n, p, gp);
					}
					else
					{
						printf("Grandparent Right\t%i %i %i\n", gg->left->key, gp->key, gg->key);
						gg->right = rotateLeft(n, p, gp);
					}
				}
				
			}
			else
			{
				printf("Right Left\n");
				gg = gp->parent;
				
				gp->right = rotateRight(n->left, n, p);
				if(gg == NULL)
				{
					root = rotateLeft(p, n, gp);
				}
				else
				{
					if(gp == gg->left)
					{
						printf("Grandparent Left\n");
						gg->left = rotateLeft(p, n, gp);
					}
					else
					{
						printf("Grandparent Right\n");
						gg->right = rotateLeft(p, n, gp);
					}
				}
			}
		}

	}
	root->black = true;
	return root;
}

void dump(node* n, int level, int dir)
{

	if(n == NULL)
	{
		return;
	}

	for(int i = 0; i < level; i++)
	{
		printf("-");
	}
	if(dir == 0)
	{
		printf("L");
	}
	else if(dir == 1)
	{
		printf("R");
	}
	else
	{
		printf("T");
	}

	printf("-(%i %i)\n", n->key, n->black);

	if(n->left != NULL)
	{
		dump(n->left, level+1, 0);
	}

	if(n->right != NULL)
	{
		dump(n->right, level+1, 1);
	}

}

node* insert(RBT root, int key)
{

	printf("Insert %i\n", key);
	if(root == NULL)
	{
		root = BSTInsert(root, key);
		root->black = true;
		return root;
	}

	node* n = BSTInsert(root, key);
	n->black = false;
	
	printf("Before\n");
	//Traverse(root);
	dump(root, 0, 2);
	root = fixViolations(root, n);
	printf("After\n");
	dump(root, 0, 2);
	printf("done dumping\n");
	//Traverse(root);
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

	printf("Free %i\n", root->key);
	free(root);

}
