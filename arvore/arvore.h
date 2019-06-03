#ifndef _ARVORE_H
#define _ARVORE_H

// INCLUS�O DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// DEFINI��O DA ESTRUTURA DE DADOS
typedef struct arvore{
    int info;
    struct arvore *left, *right;
}tree;

// DEFINI��O DA FUN��O QUE EXIBE O MENU
int menu();

// DEFINI��O DA FUN��O CRIA A �RVORE
tree *createTree();

// DEFINI��O DA FUN��O QUE ALOCAR UM NOVO N� PARA A �RVORE
tree *alocateNode(int value);

// DEFINI��O DA FUN��O QUE INSERE UM N� NA �RVORE
tree *insert(tree *A, tree *node);

// DEFINI��O DA FUN��O QUE IMPRIME A EM ORDEM (IN-ORDE)
void printInOrder(tree *A);

// DEFINI��O DA FUN��O QUE IMPRIME EM PR�-ORDEM
void printpreOrder(tree *A);

// DEFINI��O DA FUN��O QUE IMPRIME EM PR�-ORDEM
void printpostOrder(tree *A);

// DEFINI��O DA FUN��O DE BUSCA UM ELEMENTO
int search(tree *A, int value);

// DEFINI��O DA FUN��O QUE CONTA A QUANTIDADE DE N�S DE UMA ARVORE
int countNode(tree *A);

// DEFINI��O DA FUN��O QUE CONTA A ATURA DE UMA ARVORE
int countHeight(tree *A);

#endif // _ARVORE_H
