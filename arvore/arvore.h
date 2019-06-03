#ifndef _ARVORE_H
#define _ARVORE_H

// INCLUSÃO DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// DEFINIÇÃO DA ESTRUTURA DE DADOS
typedef struct arvore{
    int info;
    struct arvore *esq, *dir;
}tipo_arvore;

// DEFINIÇÃO DA FUNÇÃO QUE EXIBE O MENU
int menu();

// DEFINIÇÃO DA FUNÇÃO CRIA A ÁRVORE
tipo_arvore *criarArvore();

// DEFINIÇÃO DA FUNÇÃO QUE ALOCAR UM NOVO NÓ PARA A ÁRVORE
tipo_arvore *alocarNo(int valor);

// DEFINIÇÃO DA FUNÇÃO QUE INSERE UM NÓ NA ÁRVORE
tipo_arvore *inserir(tipo_arvore *A, tipo_arvore *no);

// DEFINIÇÃO DA FUNÇÃO QUE IMPRIME A EM ORDEM (IN-ORDE)
void imprimirInordem(tipo_arvore *A);

// DEFINIÇÃO DA FUNÇÃO QUE IMPRIME EM PRÉ-ORDEM
void imprimirPreOrdem(tipo_arvore *A);

// DEFINIÇÃO DA FUNÇÃO QUE IMPRIME EM PRÓ-ORDEM
void imprimirPosOrdem(tipo_arvore *A);

// DEFINIÇÃO DA FUNÇÃO DE BUSCA UM ELEMENTO
int buscar(tipo_arvore *A, int valor);

// DEFINIÇÃO DA FUNÇÃO QUE CONTA A QUANTIDADE DE NÓS DE UMA ARVORE
int countNo(tipo_arvore *A);

// DEFINIÇÃO DA FUNÇÃO QUE CONTA A ATURA DE UMA ARVORE
int countAltura(tipo_arvore *A);

#endif // _ARVORE_H
