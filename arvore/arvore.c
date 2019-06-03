#include "arvore.h"

// FUN��O QUE EXIBE O MENU
int menu(){
    int op;

    printf("\n1. INSERIR NO | 2. BUSCAR | 3. REMOVER NO | 4. PRE-ORDEM | 5. IN-ORDEM | 6. POS-OREM | 7. QTD NO | 8. ALTURA | 0. SAIR\n");
    scanf("%d", &op);

    return op;
}

// CRIANDO A �RVORE
tree *createTree(){
    return NULL;
}

// ALOCANDO N�
tree *alocateNode(int x){
    tree *node = (tree *)malloc(sizeof(tree));

    if(node){
        node->info = x;
        node->left = NULL;
        node->right = NULL;
    }else{
        printf("Erro de alocacao...\n");
        exit(1);
    }

    return node;
}

// INSERINDO N� NA �RVORE
tree *insert(tree *A, tree *node){
    if(!A)
        return node;
    if(A->info > node->info)
        A->left = insert(A->left, node);
    else
        A->right = insert(A->right, node);

    return A;
}

// IMPRIMINDO �RVORE PR�-ORDEM
void printpreOrder(tree *A){
    if(A != NULL){
        printf("%d ", A->info);
        printpreOrder(A->left);
        printpreOrder(A->right);
    }
}

// IMPRIMINDO �RVORE IN-ORDEM
void printInOrder(tree *A){
    if(A != NULL){
        printInOrder(A->left);
        printf("%d ", A->info);
        printInOrder(A->right);
    }
}

// IMPRIMINDO �RVORE P�S-ORDEM
void printpostOrder(tree *A){
    if(A != NULL){
        printpostOrder(A->left);
        printpostOrder(A->right);
        printf("%d ", A->info);
    }
}

// BUCSANDO ELEMENTO NA �RVORE
int search(tree *A, int value){
    if(A){
        if(A->info == value){
            return 1;
        }else{
            if(value < A->info)
                search(A->left, value);
            else
                search(A->right, value);
        }
    }else{
        return 0;
    }
}

// CONTANDO QUANTIDADE DE N�S DA �RVORE
int countNode(tree *A){
    if(!A)
        return 0;
    else{
       int conte = countNode(A->left);
       int contd = countNode(A->right);
       return conte + contd + 1 ;
    }
}

// CONTANDO A ALTURA DE UMA �RVORE

int countHeight(tree *A){
    if(!A)
        return 0;
    else{
        int alte = countHeight(A->left);
        int altd = countHeight(A->right);
        if(alte > altd)
            return alte + 1;
        else
            return altd + 1;
    }
}
