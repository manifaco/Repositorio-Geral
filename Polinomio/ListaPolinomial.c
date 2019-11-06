#include "ListaPolinomial.h"

void createInfo(info** inf, int coeficiente, int potencia){
	info* newInfo = (info*) calloc(1,sizeof(info));
	if(!newInfo) return;
	newInfo->coeficiente = coeficiente;
	newInfo->potencia = potencia;
	*inf = newInfo;
}

void createNode(node** N, int coeficiente, int potencia){
	node* newNode = (node*) calloc(1,sizeof(node));
	if(!newNode) return;
	createInfo(&(newNode->info),coeficiente,potencia);
	*N = newNode;
}

void insert(node** list, int coeficiente, int potencia){
	node* aux = *list, *newNode;
	createNode(&newNode, coeficiente, potencia);
	if(!(*list)) {
		*list = newNode;
		return;
	}
	
	while(aux->next && aux->info->potencia > newNode->info->potencia) {puts("26");aux = aux->next;}
	
	if(aux->info->potencia == newNode->info->potencia){
		aux->info->coeficiente += newNode->info->coeficiente;puts("29");
	}
	
	else{
		newNode->next = aux->next;
		aux->next = newNode;
		printf("aux%i\n", aux->info->coeficiente);
		printf("aux->next%i\n", aux->next->info->coeficiente);
	}
}

void soma(node** list1, node** list2, node** list3){
	node* aux = *list1, *aux2 = *list2, *aux3;
	createNode(&aux3,0,0);
	while(aux || aux2){
		if(aux && aux){
			insert(list3,aux->info->coeficiente + aux2->info->coeficiente, aux->info->potencia);
			aux = aux->next;
			aux2 = aux2->next;
		}
		
		else if(aux) insert(list3,aux->info->coeficiente, aux->info->potencia);
		
		else if(aux2) insert(list3,aux2->info->coeficiente, aux2->info->potencia);
	}
}

void subtracao (node** list1, node** list2, node** list3){
	node* aux = *list1, *aux2 = *list2, *aux3;
	createNode(&aux3,0,0);
	while(aux || aux2){
		if(aux && aux){
			insert(list3,aux->info->coeficiente - aux2->info->coeficiente, aux->info->potencia);
			aux = aux->next;
			aux2 = aux2->next;
		}
		
		else if(aux) insert(list3,aux->info->coeficiente, aux->info->potencia);
		
		else if(aux2) insert(list3,aux2->info->coeficiente, aux2->info->potencia);
	}
}

void multiplicacao(node** list1, node** list2, node** list3){
	node* aux = *list1, *aux2 = *list2 , *aux3;
	createNode(&aux3,0,0);
	while(aux){
		while(aux2!=NULL){
		insert(list3, aux->info->coeficiente * aux2->info->coeficiente, aux->info->potencia + aux2->info->potencia);
		aux2 = aux2->next;puts("loop1");
		}
		aux = aux->next;puts("loop2");
	}
}

void print(node* list){
	node* aux = list;
	while(aux){
		if(!aux->next){
			if(aux->info->coeficiente == 1) printf("X^%i ", aux->info->potencia);
			else if (aux->info->coeficiente == 0) printf("");
			else if (aux->info->coeficiente < 0) printf("(%iX^%i) ", aux->info->coeficiente, aux->info->potencia);
			else printf("%iX^%i", aux->info->coeficiente, aux->info->potencia);
			break;
		}
		
		if(aux->info->coeficiente == 1) printf(" X^%i ", aux->info->potencia);
		else if (aux->info->coeficiente == 0) printf("");
		else if (aux->info->coeficiente < 0) printf(" (%iX^%i) + ", aux->info->coeficiente, aux->info->potencia);
		else printf(" %iX^%i +", aux->info->coeficiente, aux->info->potencia);
		aux = aux->next;
	}
	puts("");
}
