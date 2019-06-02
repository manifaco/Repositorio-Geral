#include "FilaDePrioridades.h"


int main(){
	int MaxPriority;
    //node* prox;
    //node* qeue = createNode();
    //data _info;
	pQeue *_pQeue = (pQeue*) calloc(1,sizeof(pQeue));
	puts("Informe a quantidade de prioridades:\n");
	scanf("%i", &MaxPriority);
	createPQeues(_pQeue,MaxPriority);
	
	/*
    do{
		scanf("%d", &op);
		  
        switch (op) {
            case 0:
            break;

            case 1:
            printf("Informe a prioridade do valor que deseja inserir :\n");
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
    }while(op!=0);*/
    return 0;
}

