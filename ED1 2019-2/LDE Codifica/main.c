#include "LDE.h"

int main(){
    int op,position;
    dList* list = createList();
    data _info;
    node* currentNode;
    puts("----------------------------------------MENU-------------------------------------------- ");
	puts("Informe qual Operacao deseja realizar:\n");
    puts("1-Inserir no comeco\n2-Inserir no Final\n3-Inserir em uma posicao \n");
    puts("4-Remover no comeco\n5-Remover no Final\n6-Remover numa posicao\n");
    puts("7-Imprimir lista\n");
    puts("8-Imprimir lista inversamente\n");
    puts("9-Buscar Ordenada\n");
    puts("10-Buscar Desordenada\n");
    puts("11-Ordenar\n");
    puts("0-Sair\n");
    do{
        
        scanf("%d", &op);
        
        if(op == 1) {	
        	getString(list);
		}
		if(op == 2){
			encode(list);
		}
		if(op == 3) invert(list);
		
		if (op == 4 || op == 5 || op == 6){
			removeNode(list, op);
		}

        switch (op) {
            case 0:
            break;

            case 7:
            	printList(list);
            break;
            
            case 8:
            	printListI(list);
            break;
            
            case 9:
            	puts("informe o valor que deseja buscar:\n");
            	scanf("%c", &_info.character);
            	currentNode = ordSearch(list,_info);
            	break;
            
            case 10:
            	puts("informe o valor que deseja buscar:\n");
            	scanf("%c", &_info.character);
            	currentNode = search(list,_info);
            	break;
            
            case 11:
            	ord(list);
            	break;
        }
        if (op>11 || op < 0) printf("Opcao Invalida\n");
    }while(op);
}

