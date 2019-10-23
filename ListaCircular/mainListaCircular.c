#include "ListaCircular.h"
enum { false = 0, true} boolean;



  
int main(){
	node* last = NULL, *first= NULL;
	int op, value;
	puts("informe que operacao deseja realizar:");
	puts("1-Inserir\n2-Remover\n3-Imprimir\n0-Sair");
	do{
		scanf("%i", &op);
		switch (op){
			case 1:
				puts("1-Inicio\n2-Fim");
				scanf("%i", &op);
				puts("Informe um valor:");
				scanf("%i", &value);
				if(op == 1) insertB(value, &first, &last);
				if(op == 2) insertE(value,&first,&last);
				break;
				
			case 2:
				puts("1-Inicio\n2-Fim\n3-Especifico");
				scanf("%i", &op);
				if(op == 1) removeB(&first,&last);
				if(op == 2) removeE(&first,&last);
				if(op == 3){
					puts("Informe um valor:");
					scanf("%i", &value);
					removeP(value,&first,&last);
				}
				break;
				
			case 3:
				print(first);
				break;
		}
	}while (op);
	return false;
}
