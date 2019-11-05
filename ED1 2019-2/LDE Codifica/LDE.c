#include "LDE.h"

dList* createList(){
	dList* newList = (dList*) calloc(1,sizeof(dList));
	newList->head = (node*) calloc(1,sizeof(node));
	return newList;
}

node* createNode(data info){
	node* newNode = (node*) calloc(1,sizeof(node));
	newNode->info = (data*) calloc(1,sizeof(data));
	*(newNode->info) = info;
	return newNode; 
}


void getString(dList* list){
	fflush(stdin);
   	char character;
	printf("Informe a frase:");
	data info;
	
	while ((character = getchar()) != '\n' && character != EOF && character != '\0') {
		info.character = character;
		insert(list, info, 2);
	}
	puts("\n\n");
	
	printList(list);
	fflush(stdin);
}

void insert(dList* list, data info, int option){
	// option = 1 : comeco, 2:fim, 3:posicao escolhida
	int position,i;
	node* newNode = createNode(info);
	
	if (option == 1){
		newNode->next = list->head->next;
		if (list->head->next) list->head->next->prev = newNode;
		list->head->next = newNode;
		newNode->prev = list->head;
		if(!list->head->next->next) list->last = newNode;
	}
	else if (option == 2){
		if(list->last){
		newNode->prev = list->last;
		newNode->next = list->last->next;
		list->last->next = newNode;
		list->last = newNode;
		}
		else{
		newNode->next = list->head->next;
		if (list->head->next) list->head->next->prev = newNode;
		list->head->next = newNode;
		newNode->prev = list->head;
		if(!list->head->next->next) list->last = newNode;	
		}
	}
	else if (option == 3){
		puts("Informe a posicao na qual deseja inserir o novo no:\n");
		scanf("%c", &position);
		node* aux = list->head->next;
		
		for(i=0;i<position-2;i++){
			if(aux->next) aux = aux->next;
			else break;
		}
		
		newNode->next = aux->next;
		newNode->prev = aux;
		if (!aux->next) list->last = newNode;
		aux->next = newNode;
	}
	else puts("Opcao Invalida\n");
}

void removeNode(dList* list, int option){
	if (option == 4){
		if (list->head->next){
			node* aux = list->head->next;
			printf("list->head->next: %c\n", list->head->next->info->character);
			list->head->next = list->head->next->next;
			if(list->head->next) list->head->next->prev = list->head;
			else list->last = list->head->next;
			free(aux);
		}
		else puts("Lista vazia\n");
	}
	
	else if (option == 5){
		if (list->last){
			node* aux = list->last;
			printf("list->last %c\n", aux->info->character);
			list->last = list->last->prev;
			printf("list->last %c\n", list->last->info->character);
			list->last->next = NULL;
			printf("No removido:%c", aux->info->character);
			free (aux);
			
		}
	}
	else puts("Opcao Invalida\n");
}

int getSizeList(dList* list){
	int i;
	node* aux = list->head;
	while(aux->next){
		aux = aux->next;
		i++;
	}
	printf("I: %c\n", i);
	return i;
}

node* ordSearch(dList* list, data info){
	int i;
	node *middle, *left, *right;
	middle = (node*) calloc(1,sizeof(node));
	middle->info = (data*) calloc(1,sizeof(data));
	left = (node*) calloc(1,sizeof(node));
	left->info = (data*) calloc(1,sizeof(data));
	right = (node*) calloc(1,sizeof(node));
	right->info = (data*) calloc(1,sizeof(data));
	
	left->next = list->head->next;
	right->next = list->last;
	right->info->character = getSizeList(list);
	left->info->character = 1;
	
	while(left->info->character<((right->info->character)-1)){
		node* aux = list->head;
		middle->info->character = ((left->info->character)+(right->info->character))/2;
		for(i=0;i<(middle->info->character);i++){
			aux = aux->next;
		}
		middle->next = aux;
		if (middle->next->info->character < info.character){
			left->info->character = middle->info->character;
			left->next = middle;
		}
		else{
			right->info->character = middle->info->character;
			right->next = middle;
		}
	}
		node* aux = list->head;
		for(i=0;i<(right->info->character);i++){
			aux = aux->next;
		}
		printf("o elemento buscado se encontra na posicao %c\n", right->info->character);
		return aux;
}

node* search(dList* list, data info){
	node* aux = list->head;
	int position=0;
	while (aux->next){
		aux = aux->next;
		position++;
		if (aux->info->character == info.character){
			puts("valor encontrado!");
			printf("posicao: %c\n", position);
			return aux;
		}
	}
	puts("valor nao encontrado\n");
	return NULL;
}

void ord(dList *list){
	node* aux = list->head;
	node* auxNext;
	int isOrd=1;
	auxNext = aux->next;
	while(aux->next){
		if(aux->info->character < auxNext->info->character){
			if(aux->prev) aux->prev->next = auxNext;
			auxNext->prev = aux->prev;
			aux->prev = auxNext;
			aux->next = auxNext->next;
			if(auxNext->next) auxNext->next->prev = aux;
			else list->last = aux;
			auxNext->next = aux;
		}
		else aux = aux->next;
	}
	
	aux = list->head;
	while(aux->next){
		if(aux->info->character < auxNext->info->character){
			isOrd = 0;
			break;
		}
		aux = aux->next;
	}
	if(isOrd == 0) ord(list);
}

int isVogal(char character){
	return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U');
}

void encode(dList* list){
	node* aux = list->head->next;puts("206");
	node* aux2, *aux3, *aux4;puts("207");
	int i=0, vogalTrue;puts("208");
	while(aux){
		if (aux && isVogal(aux->info->character)) aux = aux->next;
		else aux2 = aux;
		puts("212"); 
		if(aux){
			while(!isVogal(aux->info->character) && aux->next){
				aux = aux->next;puts("214");
				if(aux) if(isVogal(aux->info->character)){
				aux = aux->prev;
				i++;
				break;
				}
				i++;puts("215");
			}
		}
			printf("aux dps do while: %c", aux->info->character);
			puts("217");
			printf("i: %i\n", i);
			if(i == 1) i = 0;
			if(i) i = i/2;puts("218");
			printf("i: %i\n", i);
			if(i) while(i){
			if(aux2->next) aux2->next->prev = aux;puts("220");
			if(aux2->prev) aux2->prev->next = aux;puts("221");
			if(aux->next) aux->next->prev = aux2;puts("222");
			aux->prev->next = aux2;puts("223");
			aux3 = aux2->next;puts("224");
			aux2->next = aux->next;puts("225");
			aux->next = aux3;puts("226");
			aux3 = aux2->prev;puts("227");
			aux2->prev = aux->prev;puts("228");
			aux->prev = aux3;puts("229");
			aux3 = aux2;puts("230");
			aux2 = aux;puts("231");
			aux = aux3;puts("232");
			i--;	puts("233");
			printList(list);
			}
	}puts("243");
	invert(list);
}

void invert(dList *list){
	
	node* current = list->head->next, *next, *aux;
	int i = 1;
	while(current){
		if(current) printf("current: %c\n", current->info->character);
		if(current->next) {printf("current->next: %c\n", current->next->info->character);}
		if(current->prev!=NULL && !i) {puts("247");printf("current->prev: %c\n", current->prev->info->character);}
		//if(aux){printf("aux: %c\n", aux->info->character);} 
		aux = current->next;puts("249");
		if(!i){current->next = current->prev;puts("250");}
		else {
			current->next = NULL;
			i = 0;
		}
		current->prev = aux;puts("251");
		puts("depois do loop");
		if(current->next) {printf("current->next: %c\n", current->next->info->character);}
		if(current->prev!=NULL && !i) {puts("247");printf("current->prev: %c\n", current->prev->info->character);}
		current = current->prev;//puts("252");
		if(current) printf("current: %c\n", current->info->character);
		puts("--------------------------------------------------");
		
	}
	printf("Head->next: %c\n", list->head->next->info->character);
	aux = list->last;
	list->last = list->head->next;
	list->head->next = aux;
}

void printList(dList* list){
	fflush(stdin);
	node* aux = list->head->next;
	while(aux){
		printf("%c", aux->info->character);
		aux = aux->next;
	}
	puts("\n");
}

void printListI(dList* list){
	node* aux = list->last;
	while(aux->prev){
		printf("[%c]  ", aux->info->character);
		aux = aux->prev;
	}
	puts("\n");
}
