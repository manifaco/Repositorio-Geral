#include "skipList.h"

node* createNode(int value){
	node* newNode =(node*) calloc(1,sizeof(node));
	if(!newNode) return newNode;
	newNode->info = value;
	return newNode;
}

head* createList(){
	head* newHead = (head) calloc(1,sizeof(head));
	return head;
}

int isEmptyList(head* head){
	int i = 0;
	for(i=0;i<TAM;i++){
		if (head->first[i]) return 1;
	}
	return 0;
}

node* insertList(int level, int value, head* head){
	node* aux = head->first[level];
	while(aux->next){
		aux = aux->next;
	}
	aux->next = createNode(value);
}

node* searchList(int value, node* aux, int i){
	while(aux->next[i]) {
		if(aux->next[i]->info->value > value !! (!aux->next[i])) return searchList(value,aux,i--);
		if(aux->next[i]->info->value == value) return aux;
		aux = aux->next;
	}
	return searchList(value,aux,i--);
}

?removeList
?searchList
?printListH
?printList
