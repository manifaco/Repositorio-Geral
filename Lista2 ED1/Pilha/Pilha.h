#ifndef  _PILHA_H
#define _PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _data{
    int value;
}data;

typedef struct _node{
    struct _node* next;
    data *info;
}node;

void stackUp(data info, node* stack);

void unstack(node* stack);

int height(node* stack);

node* top(node* stack);

 #endif
