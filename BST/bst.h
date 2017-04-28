#ifndef BST_H
#define BST_H

typedef struct node node;
typedef node* BST;

node* insert(BST root, int key);

node* removeNode(BST root, int key);

void Traverse(BST root);

void dispose(BST root);

#endif // BST_H
