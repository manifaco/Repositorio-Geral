#ifndef _ARVORE_H
#define _ARVORE_H

// INCLUSÃO DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// DEFINIÇÃO DA ESTRUTURA DE DADOS
typedef struct arvore{
    int info;
    struct arvore *left, *right;
}tree;

// DEFINIÇÃO DA FUNÇÃO QUE EXIBE O MENU
int menu();

// DEFINIÇÃO DA FUNÇÃO CRIA A ÁRVORE
tree *createTree();

// DEFINIÇÃO DA FUNÇÃO QUE ALOCAR UM NOVO NÓ PARA A ÁRVORE
tree *alocateNode(int value);

// DEFINIÇÃO DA FUNÇÃO QUE INSERE UM NÓ NA ÁRVORE
tree *insert(tree *A, tree *node);

// DEFINIÇÃO DA FUNÇÃO QUE IMPRIME A EM ORDEM (IN-ORDE)
void printInOrder(tree *A);

// DEFINIÇÃO DA FUNÇÃO QUE IMPRIME EM PRÉ-ORDEM
void printpreOrder(tree *A);

// DEFINIÇÃO DA FUNÇÃO QUE IMPRIME EM PRÓ-ORDEM
void printpostOrder(tree *A);

// DEFINIÇÃO DA FUNÇÃO DE BUSCA UM ELEMENTO
int search(tree *A, int value);

// DEFINIÇÃO DA FUNÇÃO QUE CONTA A QUANTIDADE DE NÓS DE UMA ARVORE
int countNode(tree *A);

// DEFINIÇÃO DA FUNÇÃO QUE CONTA A ATURA DE UMA ARVORE
int countHeight(tree *A);

#endif // _ARVORE_H
