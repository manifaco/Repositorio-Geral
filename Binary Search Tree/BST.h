#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct info {
	int value;
}info;

typedef struct key {
	info* info;
	struct key* left;
	struct key* right;
}key;

void printBST(key* bst);

#endif
