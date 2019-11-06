	#include "Fila.h"

int main(){
    int op,l;
    node* prox;
    node* qeue = createNode();
    data _info;
    
    printf("Informe qual Operacao deseja realizar:\n1-Enfileirar\n2-Desenfileirar\n3-Checar tamanho da Fila\n4-Checar proximo da Fila\n5-Imprimir Fila\n0-Sair\n");

    do{  
		scanf("%d", &op);
		  
        switch (op) {
            case 0:
            break;

            case 1:
            printf("Informe o valor que deseja inserir na Fila:\n");
            scanf("%d", &(_info.value));
            qeueUp( _info , qeue);
            break;

            case 2:
            deqeue(qeue);
            break;

            case 3:
            l = lenght(qeue);
            printf("Tamanho: %i\n", l);
            break;

            case 4:
            prox = next(qeue);
            break;
            
            case 5:
            	printQeue(qeue);
            	break;
        }
        puts("\n");
    }while(op!=0);
}

