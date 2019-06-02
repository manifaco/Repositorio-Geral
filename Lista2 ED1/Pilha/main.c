#include "Pilha.c"

int main(){
    int op,h;
    node* topo;
    node* stack = createStack();
    data _info;

    do{
        printf("Informe qual Operacao deseja realizar:\n1-Empilhar\n2-Desempilhar\n3-Checar tamanho da Pilha\n4-Checar topo da Pilha\n0-Sair\n");
        scanf("%d", &op);

        switch (op) {
            case 0:
            break;

            case 1:
            printf("Informe o valor que deseja inserir na pilha:\n");
            scanf("%d", &(_info.value));
            stackUp( _info , stack);
            break;

            case 2:
            unstack(stack);

            case 3:
            h = height(stack);
            break;

            case 4:
            topo = top(stack);
            break;
        }
        puts("\n");
    }while(op!=0);
}
