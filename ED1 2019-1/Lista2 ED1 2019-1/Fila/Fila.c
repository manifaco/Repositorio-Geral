#include "Fila.h"

node* createNode(){
    node* newNode = (node*)calloc(1,sizeof(node));
    newNode->info = (data*)calloc(1,sizeof(data));
    return newNode;
}

void qeueUp(data info, node* qeue){
	node* newNode = createNode();
	*(newNode->info) = info;
	node* aux = qeue;
	while(aux->next){
	aux = aux->next;
	}
	aux->next = newNode;
}

void deqeue(node* qeue){
	if (qeue->next){
		node* aux = qeue->next;
		qeue->next = qeue->next->next;
		printf("No removido: [%i]\n", aux->info->value);
		free (aux);
	}
	else puts("Impossivel remover, fila esta vazia\n");
}

int lenght(node* qeue){
	node* aux = qeue->next;
	int l;
	while (aux){
		aux = aux->next;
		l++;
	}
	return l;
}

node* next(node* qeue){
	if (qeue->next){
		printf("proximo: [%i]\n", qeue->next->info->value);
		return qeue->next;
	}
	else puts("Fila vazia\n");
}

void printQeue(node* qeue){
	node* aux = qeue->next;
	while(aux){
		printf(" [%i] ", aux->info->value);
		aux = aux->next;
	}
}

