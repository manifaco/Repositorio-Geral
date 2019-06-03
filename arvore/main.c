#include "arvore.h"

int main()
{
    tree *A;
    tree *node = NULL;
    int op = 0;
    int value;
    int busca = NULL;
    int qtdNo = 0;
    int altura = 0;

    // CRIANDO ÁRVORE
    A = createTree();

    do{
        op = menu();
        if(op == 1){
            printf("Informe o value: ");
            scanf("%d", &value);
            node = alocateNode(value);
            A = insert(A, node);
        }else if(op == 2){
                printf("Informe o value a ser buscado: ");
                scanf("%d", &value);
                busca = search(A, value);
                if(busca == 1)
                    printf("valor encontrado!\n");
                else
                    printf("valor nao encontrado!\n");
        }else if(op == 4){
            printpreOrder(A);
        }else if(op == 5){
            printInOrder(A);
        }else if(op == 6){
            printpostOrder(A);
        }else if(op == 7){
            qtdNo = countNode(A);
            printf("Qtd nos: %d\n", qtdNo);
            qtdNo = 0;
        }else if(op == 8){
            altura = countHeight(A);
            printf("Altura : %d\n", altura);
        }
    }while(op != 0);

    return 0;
}
