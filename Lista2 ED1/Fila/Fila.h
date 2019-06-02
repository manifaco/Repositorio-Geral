#ifndef  _FILA_H
#define _FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _data{
    int value;
}data;

typedef struct _node{
    struct _node* next;
    data *info;
}node;

void qeueUp(data info, node* qeue);

void deqeue(node* qeue);

int lenght(node* qeue);

node* next(node* qeue);

void printQeue(node* qeue);

 #endif

