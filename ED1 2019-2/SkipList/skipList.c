#include "skipList.h"

node* createNode(int value, int level){
	node* newNode = (node*) calloc(1,sizeof(node));puts("12");
	newNode->next = (node**) calloc(TAM,sizeof(node*));
	if(!newNode) exit(1);
	puts("");
	newNode->level = level;
	newNode->value = value;
	return newNode;
}

node* createHead(){puts("11");
	node* newHead = (node*) calloc(1,sizeof(node));puts("12");
	newHead->next = (node**) calloc(TAM,sizeof(node*));
	puts("");
	return newHead;
}

int isEmptyList(node* head){puts("16");
	int i = 0;
	for(i=0;i<TAM;i++){
		if (head->next[i]) return 0;
	}puts("20");
	return 1;puts("21");
}

int retorna(){
	return 1;
}

search* searchList(node* h, int value, int isPrintTrue, int size){puts("24");
	printf("SIZE:%i\n", size);
	node* aux = h;puts("33");
	node* aux2;puts("34");
	search* pathVector = NULL;puts("35");
	int i;puts("37");
	int j = 0;//J é o ponteiro referente ao contador da posicao do vetor de posicoes que a funcao busca gera
	for(i=TAM-1;i>=0;i--){puts("38");
		if(aux) while(aux->next[i] && aux->next[i]->value < value){puts("39");
			if(!j){puts("40");
				pathVector = (search*) calloc(size,sizeof(search));
				pathVector->pointer = (node**) calloc(5,sizeof(node*));puts("41");
				pathVector->pointer[j] = aux->next[i];puts("42");if(aux->next[i]) printf("aux->Next%i\n", aux->next[i]->value);printf("J:%i\n", j);printf("pathVector->size: %i\n", pathVector->size);printf("path->pointer:%i\n", pathVector->pointer[j]->value);
				j++;puts("43");
				pathVector->size = j;puts("45");
			}
			
			else if (j){puts("48");
				//pathVector->pointer = (node**) realloc(pathVector, (j + 1)*sizeof(node*));puts("49");
				pathVector->pointer[j] = aux->next[i];puts("50");printf("J:%i\n", j);printf("path->pointer:%i\n", pathVector->pointer[j-1]->value);printf("path->pointer:%i\n", pathVector->pointer[j]->value);
				j++;puts("51");
				pathVector->size = j;puts("52");
			}
			aux = aux->next[i];puts("54");
		}
	}puts("56");
		if(j) for(i=0;i<j;i++){
			printf("i:%i\n",i);printf("path->pointer:%i\n", pathVector->pointer[i]->value);
		}if(pathVector) puts("existe");
		return pathVector;
}

int insertList(node* h, int value, int level, int* size){puts("59");
	search* path = searchList(h,value,0,*size);puts("60");
	int i=0;
	int currentLevel;puts("=()");
	node* newNode = createNode(value, level);puts("63");
	if(isEmptyList(h)){
		for(i=0;i<TAM;i++) {
			h->next[i] = newNode;puts("68");
			*(size)+=1;
			return 1;
		}
	}
	puts("71");
	if(path) printf("path->size: %i\n", path->size);
	if(path) for(i=0;i<path->size;i++){
		printf("path->pointer:%i\n", path->pointer[i]->value);
	}
	i = 0;
	for(currentLevel=0;currentLevel<TAM;currentLevel++){puts("76");
		if(!path) return 0;
		if(path->pointer[(path->size)-1]->next[currentLevel] && path->pointer[(path->size)-1]->next[currentLevel]->value == value) return 0;puts("77");
	}puts("57");
	
	//i = path->size;
	
	for(i=0;i<path->size;i++){puts("82");
		for(currentLevel=0;currentLevel<TAM;currentLevel++){puts("83");printf("currentLevel: %i\n", currentLevel);
			if(currentLevel > (path->pointer[i]->level)-1) break;puts("84");
			
			if(currentLevel > level) break;puts("86");
				if(!(path->pointer[i]->next[currentLevel]))
						if(currentLevel <= level-1){puts("66");
							newNode->next[currentLevel] = &(*(path->pointer[i]->next[currentLevel]));puts("67");
							path->pointer[i]->next[currentLevel] = newNode;puts("68");
						}
					
			else if(path->pointer[i]->next[currentLevel])
				if(path->pointer[i]->next[currentLevel]->value > newNode->value)
					if(currentLevel <= level-1){puts("73");
						newNode->next[currentLevel] = &(*(path->pointer[i]->next[currentLevel]));puts("74");
						path->pointer[i]->next[currentLevel] = newNode;puts("75");
					}puts("99");
		}puts("100");
		printf("i:%i\n",i);
		printf("pathSize:%i\n",path->size);
		puts("101");
	}puts("102");
	*(size)+=1;
	return 1;puts("103");
}

int removeList(node* h, int value, int *size){puts("83");
	search* pathVector = searchList(h,value,0,size);puts("114");
	int i=0;
	if(pathVector) for(i=0;i<pathVector->size;i++){
		printf("path:%i\n", pathVector->pointer[i]->value);
	}
	node* aux = NULL;puts("118");
	int currentLevel;puts("119");
	if(!pathVector)	for(i=0;i<TAM-1;i++) {
		if(h->next[i]) if(h->next[i]->value == value){
			aux = h->next[i];
			h->next[i] = h->next[i]->next[i];
		}
		free(aux);
		(*size)-=1;
		return 1;
	}
	
	for(i=0;i<pathVector->size;i++){puts("121");
		for(currentLevel=0;currentLevel<TAM;currentLevel++){puts("122");
			if(currentLevel > (pathVector->pointer[i]->level)-1) break;puts("123");
			if(pathVector->pointer[i]->next[currentLevel] && pathVector->pointer[i]->next[currentLevel]->value == value){puts("124");
				aux = pathVector->pointer[i]->next[currentLevel];puts("125");
				pathVector->pointer[i]->next[currentLevel] = pathVector->pointer[i]->next[currentLevel]->next[currentLevel];puts("126");
			}puts("127");
		}puts("128");
	}puts("129");
	
	if(aux){puts("131");
		free(aux);puts("132");
		*(size)-=1;
		return 1;puts("133");
	}puts("101");puts("134");
	return 0;puts("");
}

void printList(node* head){
	node* aux = head->next[0];puts("128");
	while(aux){
		printf("[%i]|%i| ", aux->value,aux->level);puts("130");
		aux = aux->next[0];puts("131"); if(aux) if(aux->next[0]) printf("aux->next:%i\n", aux->next[0]->value);
	}
	puts("");puts("133");
}

