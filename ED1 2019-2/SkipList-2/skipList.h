#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct _node{
	int value;
	int level;
	struct _node** next;
}node;

/*typedef struct {
	node *first[TAM];
}head;*/

typedef struct {
	node** pointer;
	int size;
}search;

#endif
