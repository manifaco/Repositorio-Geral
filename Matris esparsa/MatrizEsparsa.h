#ifndef _MATRIZESPARSA_H
#define _MATRIZESPARSA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
struct _node *right, *below;
int line, column;
double value;
}node;

void error();

node* createMatrix();

node* createHeadColumn(int currentColumn);

node* createHeadLine(int currentLine);

node* createNode(double value,int line,int column);

node* insertColumnHead(node* matrixHead, int currentColumn);

void insertLineHead(node* matrixHead, int currentLine);

void insertColumnNode(node* currentHead, node* currentNode);

void insertLineNode(double value, node* matrixHead,int currentLine,int currentColumn);

void printMatrix(node* matrixHead, int columnSize, int LineSize);

void fillMatrix (node* matrixHead, int lineSize, int columnSize);

void printMatrixColumn(node* matrixHead);

#endif
