#include "skipList.h"

int main() {
	int level,value,op,size=0;
	node* head = createHead();
	printf("head:%i\n",head->value);
	puts("1-inserir\n2-remover\n3-imprimir\n");
	
	do{	
		scanf("%i",&op);
		if(op == 1){
			puts("valor,level");
			scanf("%i%i",&value,&level);
			insertList(head,value,level,&size);
			printList(head);
		}
		
		if(op == 2){
			scanf("%i",&value);
			removeList(head,value, &size);
		}
		
		if(op == 3) printList(head);
		
	}while(op);
	return 0;
}
