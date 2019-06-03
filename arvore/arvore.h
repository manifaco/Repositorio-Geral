#ifndef _ARVORE_H
#define _ARVORE_H

// INCLUS�O DE BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// DEFINI��O DA ESTRUTURA DE DADOS
typedef struct arvore{
    int info;
    struct arvore *esq, *dir;
}tipo_arvore;

// DEFINI��O DA FUN��O QUE EXIBE O MENU
int menu();

// DEFINI��O DA FUN��O CRIA A �RVORE
tipo_arvore *criarArvore();

// DEFINI��O DA FUN��O QUE ALOCAR UM NOVO N� PARA A �RVORE
tipo_arvore *alocarNo(int valor);

// DEFINI��O DA FUN��O QUE INSERE UM N� NA �RVORE
tipo_arvore *inserir(tipo_arvore *A, tipo_arvore *no);

// DEFINI��O DA FUN��O QUE IMPRIME A EM ORDEM (IN-ORDE)
void imprimirInordem(tipo_arvore *A);

// DEFINI��O DA FUN��O QUE IMPRIME EM PR�-ORDEM
void imprimirPreOrdem(tipo_arvore *A);

// DEFINI��O DA FUN��O QUE IMPRIME EM PR�-ORDEM
void imprimirPosOrdem(tipo_arvore *A);

// DEFINI��O DA FUN��O DE BUSCA UM ELEMENTO
int buscar(tipo_arvore *A, int valor);

// DEFINI��O DA FUN��O QUE CONTA A QUANTIDADE DE N�S DE UMA ARVORE
int countNo(tipo_arvore *A);

// DEFINI��O DA FUN��O QUE CONTA A ATURA DE UMA ARVORE
int countAltura(tipo_arvore *A);

#endif // _ARVORE_H
