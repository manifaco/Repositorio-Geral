#include "listaCircular.h"
enum { false = 0, true} boolean;

int main(){
	node* first = NULL, *last = NULL;
	int op, value;
	puts("informe que operacao deseja realizar:");
	puts("1-Inserir\n2-Remover\n3-Imprimir\n0-Sair");
	do{
		scanf("%i", &op);
		switch (op){
			case 1:
				puts("1-Inicio\n2-Fim");
				scanf("%i", &op);
				puts("Informe o valor:");
				scanf("%i", &value);
				if(op == 1) first = insertB(value, first, &last);
				if(last) printf("Last: %i\n", last->info->value);
				else puts("last nao existe");
				if(op == 2) first = insertE(value,first,&last);
				break;
				
			case 2:
				puts("1-Inicio\n2-Fim\n3-Especifico");
				scanf("%i", &op);
				if(op == 1) first = removeB(first,&last);
				if(op == 2) first = removeE(first,&last);
				if(op == 3) first = removeP(value,first,&last);
				break;
				
			case 3:
				if(first) printf("first: %i\n", first->info->value);
				print(first);
				break;
		}
	}while (op!= false);
	return false;
}
