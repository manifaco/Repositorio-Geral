#include "ListaPolinomial.h"

int main() {
	node* list1 = NULL, *list2 = NULL, *list3 = NULL;
	node* aux;
	createNode(&aux, 0,0);
	setlocale(LC_ALL, "Portuguese");
	int op, coeficiente, potencia;
	puts("1-Imprimir\n2-Inserir\n3-Somar\n4-Subtrair\n5-Multiplicar\n0-Sair");
	
	do{
		scanf("%i", &op);
		
		switch(op){
			
			case 1:
				puts("1- lista1\n2- lista2\n3- lista3");
				scanf("%i", &op);
				if(op == 1) print(list1);
				if(op == 2) print(list2);
				if(op == 3) print(list3);
				break;
			
			case 2:
				puts("1- lista1\n2- lista2\n3- lista3:");
				scanf("%i", &op);
				puts("informe o coeficiente:");
				scanf("%i", &coeficiente);
				puts("Informe a potencia");
				scanf("%i", &potencia);
				if(op == 1) insert(&list1, coeficiente, potencia);
				else if(op == 2) insert(&list2, coeficiente, potencia);
				else if(op == 3) insert(&list3, coeficiente, potencia);
				break;
			
			case 3:
				soma(&list1, &list2, &list3);
				break;
				
			case 4:
				subtracao(&list1, &list2, &list3);
				break;
			
			case 5:
				multiplicacao(&list1, &list2, &list3);
				break;
				
		}
		
	}while(op);
	return 0;
}
