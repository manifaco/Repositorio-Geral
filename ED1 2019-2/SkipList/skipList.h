#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct{
	int value
}info;

typedef struct _node{
	info* info;
	struct _node* next[TAM];
}node;

typedef struct {
	node *first[TAM];
}head;

#endif
