#ifndef _LDE_H
#define _LDE_H
#include <stdio.h>
#include <stdlib.h>



typedef struct _data{
    int value;
}data;

typedef struct _node{
    struct _node* next;
    struct _node* prev;
    data *info;
}node;

typedef struct _dList{
	node* head;
	node* last;
}dList;

dList* createList();

node* createNode(data info);

void insert(dList* list, data info, int position);

void removeNode(dList* list, int position);

void printList(dList* list);

void printListI(dList* list);

node* ordSearch(dList* list, data info);

node* search(dList* list, data info)

int getSizeList(dList* list);

#endif
