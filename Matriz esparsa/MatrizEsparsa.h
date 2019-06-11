#ifndef _MATRIZESPARSA_H
#define _MATRIZESPARSA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printMatrix(node* matrixHead, int columnSize, int LineSize, char* matrixName);

void fillMatrix (node* matrixHead, int lineSize, int columnSize, char* matrixName);

void printMatrixColumn(node* matrixHead);

/*plusMatrix(node* matrix1, node* matrix2, node** matrixVector, char* matrix1Name, char* matrix2Name);

minusMatrix(node* matrix1, node* matrix2, node** matrixVector, char* matrix1Name, char* matrix2Name);

multMatrix(node* matrix1, node* matrix2, node** matrixVector, char* matrix1Name, char* matrix2Name);

divMatrix(node* matrix1, node* matrix2, node** matrixVector, char* matrix1Name, char* matrix2Name);*/

char* getString();

int checkMatrix(int i,char** matrixName, char* name);

#endif
