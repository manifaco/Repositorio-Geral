#include "arvore.h"

// FUN��O QUE EXIBE O MENU
int menu(){
    int op;

    printf("\n1. INSERIR NO | 2. BUSCAR | 3. REMOVER NO | 4. PRE-ORDEM | 5. IN-ORDEM | 6. POS-OREM | 7. QTD NO | 8. ALTURA | 0. SAIR\n");
    scanf("%d", &op);

    return op;
}

// CRIANDO A �RVORE
tipo_arvore *criarArvore(){
    return NULL;
}

// ALOCANDO N�
tipo_arvore *alocarNo(int x){
    tipo_arvore *no = (tipo_arvore *)malloc(sizeof(tipo_arvore));

    if(no){
        no->info = x;
        no->esq = NULL;
        no->dir = NULL;
    }else{
        printf("Erro de alocacao...\n");
        exit(1);
    }

    return no;
}

// INSERINDO N� NA �RVORE
tipo_arvore *inserir(tipo_arvore *A, tipo_arvore *no){
    if(!A)
        return no;
    if(A->info > no->info)
        A->esq = inserir(A->esq, no);
    else
        A->dir = inserir(A->dir, no);

    return A;
}

// IMPRIMINDO �RVORE PR�-ORDEM
void imprimirPreOrdem(tipo_arvore *A){
    if(A != NULL){
        printf("%d ", A->info);
        imprimirPreOrdem(A->esq);
        imprimirPreOrdem(A->dir);
    }
}

// IMPRIMINDO �RVORE IN-ORDEM
void imprimirInordem(tipo_arvore *A){
    if(A != NULL){
        imprimirInordem(A->esq);
        printf("%d ", A->info);
        imprimirInordem(A->dir);
    }
}

// IMPRIMINDO �RVORE P�S-ORDEM
void imprimirPosOrdem(tipo_arvore *A){
    if(A != NULL){
        imprimirPosOrdem(A->esq);
        imprimirPosOrdem(A->dir);
        printf("%d ", A->info);
    }
}

// BUCSANDO ELEMENTO NA �RVORE
int buscar(tipo_arvore *A, int valor){
    if(A){
        if(A->info == valor){
            return 1;
        }else{
            if(valor < A->info)
                buscar(A->esq, valor);
            else
                buscar(A->dir, valor);
        }
    }else{
        return 0;
    }
}

// CONTANDO QUANTIDADE DE N�S DA �RVORE
int countNo(tipo_arvore *A){
    if(!A)
        return 0;
    else{
       int conte = countNo(A->esq);
       int contd = countNo(A->dir);
       return conte + contd + 1 ;
    }
}

// CONTANDO A ALTURA DE UMA �RVORE

int countAltura(tipo_arvore *A){
    if(!A)
        return 0;
    else{
        int alte = countAltura(A->esq);
        int altd = countAltura(A->dir);
        if(alte > altd)
            return alte + 1;
        else
            return altd + 1;
    }
}
