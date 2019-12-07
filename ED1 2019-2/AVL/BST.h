#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"
#include <stdbool.h>

int grow;

typedef struct key {
	info* info;
	int balance;
	struct key* left;
	struct key* right;
}key;

info* createInfoKey(int value);
key* createKey(info inf);
key* leftBST(key* key);
key* rightBST(key* key);
void listPreOrder(key* bst, node** first, node** last);
void listInOrder(key* bst, node** first, node** last);
void listPosOrder(key* bst, node** first, node** last);
key* rebuildTree(node** preListFirst, node* inListFirst, node** preListLast, node** inListLast);
void printBST(key* bst);
void printPreOrder(key* bst);
void printInOrder(key* bst);
void printPosOrder(key* bst);
int insertBST(key** bst, info info);
key* searchBST(key* bst, info info);
int searchBSTFather(key* bst, info info, key** father);
key* smaller(key* bst);
key* larger(key* bst);
int heightBST(key* bst);
key* removeCurrent(key* bst, key* current);
int removeBST(key** bst, info info);

#endif
