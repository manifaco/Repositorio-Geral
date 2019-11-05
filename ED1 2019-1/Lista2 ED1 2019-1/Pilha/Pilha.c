#include "Pilha.h"

node* createStack(){
    node* newStack = (node*)calloc(1,sizeof(node));
    newStack->info = (data*)calloc(1,sizeof(data));
    return newStack;
}

void stackUp(data info, node* stack){
    node* newNode = (node*)calloc(1,sizeof(node));
    newNode->info = (data*)calloc(1,sizeof(data));
    *(newNode->info) = info;
    newNode->next = stack->next;
    stack->next = newNode;
}

void unstack(node* stack){
    if(stack->next){
        node* aux = stack->next;
        stack->next = stack->next->next;
        free (aux);
    }
}

int height(node* stack){
    int h;
    node* aux = stack->next;
    while(aux){
        aux = aux->next;
        h++;
    }
}

node* top(node* stack){
	if(stack->next){
	node* aux = stack->next;
	printf("Topo:%d\n", aux->info->value);
    return stack->next;
	}
	else printf("Nao existe Topo\n");	
}
