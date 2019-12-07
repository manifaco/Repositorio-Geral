#include "BST.h"

info* createInfo(int value){
	info* newInfo =(info*) calloc(1,sizeof(info));
	if (!newInfo) return newInfo;
	else newInfo->value = value;
	return newInfo;
}
node* createNode(int value){
	node* newNode =(node*) calloc(1,sizeof(node));
	if(newNode){
		newNode->info = createInfo(value);
		newNode->next = NULL;
	}
	return newNode;
}

node* insertB(int value, node* first, node** last){
	if(!first){
		first = createNode(value);
		(*last) = first;
		return first;
	}
	node* newNode = createNode(value);
	newNode->next = first;
	first = newNode;
	return first;
}

node* insertE(int value, node* first, node** last){
	if(!first){
		first = createNode(value);
		(*last) = first;
		return first;
	}
	node* newNode = createNode(value);
	if((*last)) (*last)->next = newNode;
	(*last) = newNode;
	return first;
}

node* removeB(node* first, node** last){
	if(!first) return first;
	node* aux = first;
	if((*last)->info->value == first->info->value) (*last) = (*last)->next;
	first = first->next;
	printf("Removido: %i\n", aux->info->value);
	free(aux);
	if(!first) puts("first nao existe");
	return first;
}

node* removeE(node* first, node** last){
	if(!first) return first;
	node* aux = first;
	if((*last)->info->value != first->info->value){
		while(aux->next->info->value != (*last)->info->value) aux = aux->next;
		node* aux2 = aux;
		aux->next = (*last)->next;
		aux = (*last);
		(*last) = aux2;
	}
	else {
		(*last) = (*last)->next;
		first = first->next;
	}
	printf("Removido: %i\n", aux->info->value);
	free(aux);
	return first;
}

node* removeP(int value, node* first, node** last){
	if(!first) return first;
	node* aux = first;
	if((*last)->info->value != first->info->value){
		while(aux->next->info->value != value) aux = aux->next;
		node* aux2 = aux->next;
		aux->next = aux->next->next;
		if(first->info->value == aux2->info->value) first = first->next;
		if((*last)->info->value == aux2->info->value) (*last) = aux;
		free(aux2);
	}
	printf("Removido: %i\n", aux->info->value);
	free(aux);
	return first;
}

void print(node* first){
	node* aux = first;
	while(aux){
		printf("[%i] ", aux->info->value);
		aux = aux->next;
	}
	puts("");
}
