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
/*
node* search(dList* list,data info){
	node* aux = list->head;
	while(aux->next || aux->info != info){
		aux = aux->next;
	}
	if(!aux) puts("no nao existe");
	return aux;
}*/
/*
void intercalNode(dList* list1, dList list2, data info1, data info2){
	node* aux1, *aux2, *aux3, aux4;
	aux1 = search(list,info1);
	aux 2 = search(list,info2);
	if (aux1 && aux2){
		aux1->prev->next = aux2;
		aux2->prev->next = aux1;
		aux3 = aux1->prev;
		aux1->prev = aux2->prev;
		aux2->prev = aux3;
		aux4 = aux2->next;
		aux2->next = aux1->next;
		aux2->next->prev = aux2;
		aux1->next = aux4;
		aux1->next->prev = aux1;
		if (list1->last == aux1){
			aux4 = list2->last;
			list2->last = aux2;
		}
		if (aux4 == aux2) list1->last = aux4;
	}
}
*/
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
		scanf("%i", &position);
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

/*void insert2(dList* list, data info,data info2, int option){
	// option = 1 : comeco, 2:fim, 3:posicao escolhida
	int position,i;
	node* newNode = createNode(info);
	else if (option == 3){
		puts("Informe a posicao na qual deseja inserir o novo no:\n");
		scanf("%i", &position);
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
}*/

void removeNode(dList* list, int option){
	if (option == 4){
		if (list->head->next){
			node* aux = list->head->next;
			printf("list->head->next: %i\n", list->head->next->info->value);
			list->head->next = list->head->next->next;
			if(list->head->next) list->head->next->prev = list->head;
			else list->last = list->head->next;
			free(aux);
		}
		else puts("Lista vazia\n");
	}
	
	else if (option == 5){
		puts("foi\n");
		if (list->last){
			puts("foi\n");
			node* aux = list->last;
			printf("list->last %i\n", aux->info->value);
			puts("foi\n");
			list->last = list->last->prev;
			printf("list->last %i\n", list->last->info->value);
			puts("foi\n");
			list->last->next = NULL;
			puts("foi\n");
			printf("No removido:%i", aux->info->value);
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
	printf("I: %i\n", i);
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
	right->info->value = getSizeList(list);
	left->info->value = 1;
	
	while(left->info->value<((right->info->value)-1)){
		node* aux = list->head;
		middle->info->value = ((left->info->value)+(right->info->value))/2;
		for(i=0;i<(middle->info->value);i++){
			aux = aux->next;
		}
		middle->next = aux;
		if (middle->next->info->value < info.value){
			left->info->value = middle->info->value;
			left->next = middle;
		}
		else{
			right->info->value = middle->info->value;
			right->next = middle;
		}
	}
		node* aux = list->head;
		for(i=0;i<(right->info->value);i++){
			aux = aux->next;
		}
		printf("AUX:%i\n", aux->info->value);
		printf("o elemento buscado se encontra na posicao %i\n", right->info->value);
		return aux;
}

node* search(dList* list, data info){
	node* aux = list->head;
	int position=0;
	while (aux->next){
		aux = aux->next;
		position++;
		if (aux->info->value == info.value){
			puts("valor encontrado!");
			printf("posicao: %i\n", position);
			return aux;
		}
	}
	puts("valor nao encontrado\n");
	return NULL;
}

/*void quickSort(dList* list, int left, int right) {
    int i, j,count1,count2, middle;puts("215");
    node* pivot = list->head;puts("216");
    node* auxLeft = list->head->next;puts("217");
    node* auxRight = list->head->next;puts("218");
    node* aux;puts("219");
    i = left;
    j = right;
    middle =(left + right) / 2;
    while(middle>0){
    	pivot = pivot->next;puts("224");
    	middle--;
	}

    while(i <= j) {
    	count1 = i;
    	while(count1>0){
    		auxLeft = auxLeft->next;puts("231");
    		count1--;
		}
		count2 = j;
		while(count2>0){
			auxRight = auxRight->next;puts("236");
			count2--;
		}
    	
        while(auxLeft->info->value < pivot->info->value && i < right) {
            i++;puts("240");
        }
        while(auxRight->info->value > pivot->info->value && j > left) {
            j--;puts("243");
        }
        
        if(i <= j) {
        	node* auxPrev, *auxNext;
        	if(auxLeft->prev) auxPrev = auxLeft->prev;puts("247");
        	if(auxLeft->next) auxNext = auxLeft->next;
           	if (auxLeft->prev) auxLeft->prev->next = auxRight;
           	if(auxLeft->next) auxLeft->next->prev = auxRight;
           	auxLeft->prev = auxRight->prev;
           	auxLeft->next = auxRight->next;
           	if(auxRight->prev) auxRight->prev->next = auxLeft;
           	if(auxRight->next) auxRight->next->prev = auxLeft;
           	else list->last = auxLeft;
           	auxRight->prev = auxPrev;
           	auxRight->next = auxNext;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quickSort(list, left, j);
    }
    if(i < right) {
        quickSort(list, i, right);
    }
}

void ord(dList *list){
	int left=0, right=0;
	node *aux = list->head;
	while(aux->next){
		aux = aux->next;
		right++;
	}
	right--;
	printf("right:%i\n", right);
	quickSort(list, left,right);
}*/

void ord(dList *list){
	node* aux = list->head;
	node* auxNext;
	int isOrd=1;
	auxNext = aux->next;
	while(aux->next){
		if(aux->info->value < auxNext->info->value){
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
		if(aux->info->value < auxNext->info->value){
			isOrd = 0;
			break;
		}
		aux = aux->next;
	}
	if(isOrd == 0) ord(list);
}

void printList(dList* list){
	node* aux = list->head->next;
	while(aux){
		printf("[%i]  ", aux->info->value);
		aux = aux->next;
	}
	puts("\n");
}

void printListI(dList* list){
	node* aux = list->last;
	while(aux->prev){
		printf("[%i]  ", aux->info->value);
		aux = aux->prev;
	}
	puts("\n");
}
