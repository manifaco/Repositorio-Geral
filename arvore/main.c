#include "arvore.h"

int main()
{
    tipo_arvore *A;
    tipo_arvore *no = NULL;
    int op = 0;
    int valor;
    int busca = NULL;
    int qtdNo = 0;
    int altura = 0;

    // CRIANDO ÁRVORE
    A = criarArvore();

    do{
        op = menu();
        if(op == 1){
            printf("Informe o valor: ");
            scanf("%d", &valor);
            no = alocarNo(valor);
            A = inserir(A, no);
        }else if(op == 2){
                printf("Informe o valor a ser buscado: ");
                scanf("%d", &valor);
                busca = buscar(A, valor);
                if(busca == 1)
                    printf("Valor encontrado!\n");
                else
                    printf("Valor nao encontrado!\n");
        }else if(op == 4){
            imprimirPreOrdem(A);
        }else if(op == 5){
            imprimirInordem(A);
        }else if(op == 6){
            imprimirPosOrdem(A);
        }else if(op == 7){
            qtdNo = countNo(A);
            printf("Qtd nos: %d\n", qtdNo);
            qtdNo = 0;
        }else if(op == 8){
            altura = countAltura(A);
            printf("Altura : %d\n", altura);
        }
    }while(op != 0);

    return 0;
}
