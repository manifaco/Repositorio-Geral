#include "FilaDePrioridades.h"

node* createNode(){
    node* newNode = (node*)calloc(1,sizeof(node)); puts("4\n");
    puts("5");
    return newNode;
}

void createPQeues(pQeue *_pQeue, int MaxPriority){
 	puts("11\n");
 	int i,size;
 	_pQeue->vector = (pQeueNode*) calloc(MaxPriority,sizeof(pQeueNode));
 	for(i=0;i<MaxPriority;i++){
 		_pQeue->vector[i].subQeue = createNode();
	 }
	 
	for(i=0;i<MaxPriority;i++){
		puts("15\n");
		printf("informe a quantidade de nos da subfila da prioridade %i\n", i);
		scanf("%i", &size);
		puts("18\n");
		_pQeue->vector[i].sizeQeue = size;
		printf("newPQeue.&vector[i]->sizeQeue: %i\n", _pQeue->vector[i].sizeQeue);
		puts("21\n");
	}
	puts("23\n");
	fillSubQeues(_pQeue, MaxPriority);
	puts("24\n");
	linkSubQeues(_pQeue, MaxPriority);
	puts("25\n");
	printSubQeue(_pQeue, MaxPriority);
}

void fillSubQeues(pQeue *_pQeue,int MaxPriority){
	int i,j;
	puts("32\n");
	for(j=0;j<MaxPriority;j++){
		puts("34\n");
		for(i=0;i<(_pQeue->vector[j].sizeQeue);i++){
			puts("36\n");
			subQeueUp(_pQeue,j);
	}
	puts("39\n");
		}
	
}

void fillSubQeue(pQeue *_pQeue, int priority){
	int i;
	for(i=0;i<(_pQeue->vector[priority].sizeQeue);i++){
		subQeueUp(_pQeue,i);
	}
}

void subQeueUp(pQeue *_pQeue, int i){
	node* newNode = createNode();
	puts("53\n");
	node* aux = _pQeue->vector[i].subQeue;
	puts("55\n");
	while(aux->next){
	puts("56\n");
	aux = aux->next;
	} 
	puts("57\n");
	puts("59\n");
	newNode->next = NULL;
	aux->next = newNode;
	puts("61\n");
}

void linkSubQeues(pQeue *_pQeue,int MaxPriority){
	int i;
	puts("66\n");
	node* aux = _pQeue->vector[i].subQeue;
	puts("68\n");
	int j;
	puts("70\n");
	for(i=0;i<MaxPriority;i++){
		puts("71\n");
		node* aux = _pQeue->vector[i].subQeue;
		puts("74\n");
		j=0;
		puts("76\n");
		while(aux->next) aux = aux->next;
		puts("78\n");
		while (!aux->next && j < MaxPriority){
			puts("80\n");
			aux->next = _pQeue->vector[j].subQeue->next;
			puts("82\n");
			j++;
		}
	}
}



void linkSubQeue(pQeue *_pQeue,int priority,int MaxPriority){
	// SO CHAMAR SE A SUBQEUE CRIADA TIVER TAMANHO > 0;
	int i;
	node* aux1 = _pQeue->vector[priority-1].subQeue->next;
	while(aux1->next) aux1 = aux1->next;
	aux1 = _pQeue->vector[priority].subQeue->next;
	node* aux2 = _pQeue->vector[priority].subQeue->next;
	while(aux2->next) aux2 = aux2->next;
	for(i=0;i<MaxPriority;i++){
		if(i != priority){
			aux2->next = _pQeue->vector[i].subQeue->next;
		}
	}
}

void printSubQeue(pQeue* _pQeue, int MaxPriority){
	int i;
	node* aux = _pQeue->vector[0].subQeue;
		while(aux->next){
			puts("[]\t");
			aux = aux->next;
		}
		puts("\n");
}


/*
void deqeue(node* qeue){
	if (qeue->next){
		node* aux = qeue->next;
		qeue->next = qeue->next->next;
		printf("No removido: [%i]\n", aux->info->value);
		free (aux);
	}
	else puts("Impossivel remover, fila esta vazia\n");
}*/

/*int lenght(node* qeue){
	node* aux = qeue->next;
	int l;
	while (aux){
		aux = aux->next;
		l++;
	}
	return l;
}*/

/*node* next(node* qeue){
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
}*/

