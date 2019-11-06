#include "skipList.h"



FILE* openFile(){
	FILE *LIST;
	LIST = fopen("LIST", "rt");
    if(!LIST){
    	printf("Erro ao abrir o arquivo! Abortando o programa...\n");
        exit(1);
    }
    return LIST;
}
node* createNode(int value, int level){
	node* newNode = (node*) calloc(1,sizeof(node));
	newNode->next = (node**) calloc(TAM,sizeof(node*));
	if(!newNode) exit(1);
	newNode->level = level;
	newNode->value = value;
	return newNode;
}

node* createHead(){
	node* newHead = (node*) calloc(1,sizeof(node));
	newHead->next = (node**) calloc(TAM,sizeof(node*));
	return newHead;
}

int isEmptyList(node* head){
	int i = 0;
	for(i=0;i<TAM;i++){
		if (head->next[i]) return 0;
	}
	return 1;
}

int retorna(){
	return 1;
}

search* searchList(node* h, int value, int isPrintTrue, int size, FILE* LIST){
	node* aux = h;
	node* aux2;
	search* pathVector = NULL;

	int i;
	int j = 0;//J é o ponteiro referente ao contador da posicao do vetor de posicoes que a funcao busca gera
	for(i=TAM-1;i>=0;i--){
		if(aux) while(aux->next[i] && aux->next[i]->value < value){
			if(!j){
				pathVector = (search*) calloc(size,sizeof(search));
				pathVector->pointer = (node**) calloc(5,sizeof(node*));
				pathVector->pointer[j] = aux->next[i];
				j++;
				pathVector->size = j;
			}
			
			else if (j){
				pathVector->pointer[j] = aux->next[i];
				j++;
				pathVector->size = j;
			}
			aux = aux->next[i];
		}
	}
		return pathVector;
}

int insertList(node* h, int value, int level, int* size){
	search* path = searchList(h,value,0,*size);
	int i=0;
	int currentLevel;
	node* newNode = createNode(value, level);
	if(isEmptyList(h)){
		for(i=0;i<TAM;i++) {
			h->next[i] = newNode;
			*(size)+=1;
			return 1;
		}
	}
	for(currentLevel=0;currentLevel<TAM;currentLevel++){
		if(!path) return 0;
		if(path->pointer[(path->size)-1]->next[currentLevel] && path->pointer[(path->size)-1]->next[currentLevel]->value == value) return 0;
	}
	
	for(i=0;i<path->size;i++){
		for(currentLevel=0;currentLevel<TAM;currentLevel++){
			if(currentLevel > (path->pointer[i]->level)-1) break;
			
			if(currentLevel > level) break;
				if(!(path->pointer[i]->next[currentLevel]))
						if(currentLevel <= level-1){
							newNode->next[currentLevel] = &(*(path->pointer[i]->next[currentLevel]));
							path->pointer[i]->next[currentLevel] = newNode;
						}
					
			else if(path->pointer[i]->next[currentLevel])
				if(path->pointer[i]->next[currentLevel]->value > newNode->value)
					if(currentLevel <= level-1){
						newNode->next[currentLevel] = &(*(path->pointer[i]->next[currentLevel]));
						path->pointer[i]->next[currentLevel] = newNode;
					}
		}
	}
	*(size)+=1;
	return 1;
}

int removeList(node* h, int value, int *size){
	search* pathVector = searchList(h,value,0,size);
	int i=0;
	node* aux = NULL;
	int currentLevel;
	if(!pathVector)	for(i=0;i<TAM-1;i++) {
		if(h->next[i]) if(h->next[i]->value == value){
			aux = h->next[i];
			h->next[i] = h->next[i]->next[i];
		}
		free(aux);
		(*size)-=1;
		return 1;
	}
	
	for(i=0;i<pathVector->size;i++){
		for(currentLevel=0;currentLevel<TAM;currentLevel++){
			if(currentLevel > (pathVector->pointer[i]->level)-1) break;
			if(pathVector->pointer[i]->next[currentLevel] && pathVector->pointer[i]->next[currentLevel]->value == value){
				aux = pathVector->pointer[i]->next[currentLevel];
				pathVector->pointer[i]->next[currentLevel] = pathVector->pointer[i]->next[currentLevel]->next[currentLevel];
			}
		}
	}
	
	if(aux){
		free(aux);
		*(size)-=1;
		return 1;
	}
	return 0;
}

void printList(node* head){
	node* aux = head->next[0];
	while(aux){
		printf("[%i]|%i| ", aux->value,aux->level);
		aux = aux->next[0];
	}
	puts("");
}

