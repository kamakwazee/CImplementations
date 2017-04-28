#ifndef RBT_H
#define RBT_H

typedef struct node node;
typedef node* RBT;

node* BSTInsert(RBT root, int key);

node* insert(RBT root, int key);

//node* removeNode(RBT root, int key);

void Traverse(RBT root);

void dispose(RBT root);

#endif // RBT_H
