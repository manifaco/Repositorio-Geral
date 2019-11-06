#ifndef  _FILADEPRIORIDADES_H
#define _FILADEPRIORIDADES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node* next;
}node;

typedef struct _pQeueNode{
	int sizeQeue;
	node* subQeue;
}pQeueNode;

typedef struct pQeue{
	pQeueNode *vector;
}pQeue;


void printSubQeue(pQeue* _pQeue, int MaxPriority);

void createPQeues(pQeue *_pQeue, int MaxPriority);

void fillSubQeues(pQeue *_pQeue,int MaxPriority);

void fillSubQeue(pQeue *_pQeue, int priority);

void subQeueUp(pQeue *_pQeue, int i);

void linkSubQeues(pQeue *_pQeue,int MaxPriority);

 #endif

