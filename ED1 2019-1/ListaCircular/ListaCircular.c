#include "ListaCircular.h"

info* createInfo(int value){
	info* newInfo =(info*) calloc(1,sizeof(info));
	if (!newInfo) return newInfo;
	else newInfo->value = value;
	return newInfo;
}
node* createNode(int value){
	node* newNode =(node*) calloc(1,sizeof(node));
	if(newNode) newNode->info = createInfo(value);
	return newNode;
}

void insertB(int value, node** first, node** last){
	if(!(*first)){
		*first = createNode(value);
		*last = *first;
		return;
	}
	node* newNode = createNode(value);
	if(!newNode) return newNode;
	newNode->next = *first;
	*first = newNode;
}

void insertE(int value, node** first, node** last){
	if(!(*first)){
		*first = createNode(value);
		*last = *first;
		return;
	}
	node* newNode = createNode(value);
	if(!newNode) return newNode;
	(*(last))->next = newNode;
	*last = newNode;
}

void removeB(node** first, node** last){
	if(!(*first)) return;
	node* aux = *first;
	if((*last)->info->value == (*first)->info->value) *last = (*last)->next;
	*first = (*first)->next;
	printf("Removido: [%i]\n", aux->info->value);
	free(aux);
}

void removeE(node** first, node** last){
	if(!(*first)) return;
	node* aux = *first;
	if((*last)->info->value != (*first)->info->value){
		while(aux->next->info->value != (*last)->info->value) aux = aux->next;
		node* aux2 = aux;
		aux->next = (*last)->next;
		aux = *last;
		*last = aux2;
	}
	else {
		*last = (*last)->next;
		*first = (*first)->next;
	}
	printf("Removido: [%i]\n", aux->info->value);
	free(aux);
}

void removeP(int value, node** first, node** last){
	if(!(*first)) return;
	node* aux = *first;
	node* aux2;
	if((*last)->info->value != (*first)->info->value){
		while(aux->info->value != value) {
			aux2 = aux;
			aux = aux->next;
		}
	}
	if(aux->info->value == value){
		if(aux->info->value != (*first)->info->value) aux2->next = aux->next;
		if((*first)->info->value == aux->info->value) *first = (*first)->next;
		if((*last)->info->value == aux->info->value) *last = aux2;
		printf("Removido: [%i]\n", aux->info->value);
		free(aux);
	}
	else puts("Valor nao encontrado");
	
}

void print(node* first){
	node* aux = first;
	while(aux){
		printf("[%i] ", aux->info->value);
		aux = aux->next;
	}
	puts("");
}
