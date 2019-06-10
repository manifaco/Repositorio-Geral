#ifndef	_BST_H
#define _BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _info{
	int value;
}info;

typedef struct _bst{
	info *info;
	struct _bst *left, *right;
}bst;

bst* createBST();

info* createInfo(int value);

bst* createBSTNode(info* data);

bst* leftBST(bst* tree);

bst* rightBST(bst* tree);

bst* searchBSTNode(bst* tree, bst* searchNode);

bst* subInsertBSTNode(bst* tree, bst* newNode);

bst* insertBSTNode(bst* tree, info* data);

bst* getLargerNode(bst* tree);

bst* getSmallerNode(bst* tree);

int removeBSTNode(bst* tree, int value);

#endif
