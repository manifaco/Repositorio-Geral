#include "MatrizEsparsa.h"

void error(){
	puts("erro de alocacao, abortando...");	
	exit(1);
}

node* createMatrix(){
	node* newHead =(node*)calloc(1,sizeof(node));puts("8\n");
	newHead->column = -2;
	newHead->line = -2;
	if (newHead) return newHead;
	else error();
}

node* createHeadColumn(int currentColumn){
	node* newHead =(node*)calloc(1,sizeof(node));puts("17\n");
	newHead->column = currentColumn;
	newHead->line = -1;
	if (newHead) return newHead;
	else error();
}

node* createHeadLine(int currentLine){
	node* newHead =(node*)calloc(1,sizeof(node));puts("25\n");
	newHead->column = -1;
	newHead->line = currentLine;
	if (newHead) return newHead;
	else error();
}

node* createNode(double value,int line,int column){
	node* newNode =(node*) calloc(1,sizeof(node));puts("33\n");
	newNode->value = value;
	newNode->line = line;
	newNode->column = column;
	if (newNode) return newNode;
	else error();
}

node* insertColumnHead(node* matrixHead, int currentColumn){
	node* newHead = createHeadColumn(currentColumn);puts("42\n");
	node* aux = matrixHead;
	while(aux->right) aux = aux->right;
	newHead->right = aux->right;
	aux->right = newHead;
	return newHead;
	}

void insertLineHead(node* matrixHead, int currentLine){
	node* newHead = createHeadLine(currentLine);puts("51\n");
	node* aux = matrixHead;
	while(aux->below) {aux = aux->below;}
	newHead->below = aux->below;
	aux->below = newHead;
	aux = matrixHead;
	while(aux->below){ printf("[9999999]\n"); aux = aux->below;}
}

void insertColumnNode(node* currentHead, node* currentNode){puts("58\n");
	while(currentHead->below) currentHead = currentHead->below;
	currentNode->below = currentHead->below;
	currentHead->below = currentNode;
}

void insertLineNode(double value, node* matrixHead,int currentLine,int currentColumn){puts("64\n");
	node* newNode = createNode(value,currentLine,currentColumn);
	node* aux = matrixHead;
	while(aux->below) aux = aux->below;
	while(aux->right) aux = aux->right;
	newNode->right = aux->right;
	aux->right = newNode; puts("69\n");
}

void printMatrix(node* matrixHead, int columnSize, int lineSize){
	FILE *matrix;
	matrix = fopen("matrix.txt", "rt");
    if(!matrix){
    	printf("Erro ao abrir o arquivo! Abortando o programa...\n");
        exit(1);
    }
    fscanf(matrix, "%i", &lineSize);
    fscanf(matrix, "%i", &columnSize);
        
	node* aux = matrixHead;puts("73\n");
	int i,j, nullElements, nullLines;
	if(aux->below) puts("existe\n");
	else if(!aux->below) puts("nao existe\n");
	while (aux->below){
		printf("[%i]", aux->line);
		aux = aux->below;
	}
	puts("\n");
	aux = matrixHead;
	while(aux->below){
		aux = aux->below;
		node* aux2 = aux;
		puts("");
		aux2 = aux;
		
		
		if (aux2->right) nullElements = aux2->right->column - aux2->column;
			if (nullElements>0){
				for(i=0;i<nullElements-1;i++){
					printf("[0]");
				}
		nullElements = 0;
		}
		
		while(aux2->right){
			aux2 = aux2->right;
			printf("[%.0lf]", aux2->value);
			if (aux2->right) nullElements = aux2->right->column - aux2->column;
			else {nullElements = columnSize - aux2->column;}// printf("nullElements:%i\n", nullElements);}
			if (nullElements>0){
				for(i=0;i<nullElements-1;i++){
					printf("[0]");
				}
			nullElements = 0;
			}
		
		if(aux->below){
			nullLines = aux->below->line - aux->line-1;
			for(i=0;i<nullLines;i++){
				nullElements = columnSize;
				puts("");
				for(j=0;j<nullElements;j++){
					nullElements = columnSize;
					printf("[0]");
				}
			nullElements = 0;
			}
		}
		}
	}
			nullLines = lineSize - aux->line - 1;
			for(i=0;i<nullLines;i++){
				nullElements = columnSize;
				puts("");
				for(j=0;j<nullElements;j++){
					nullElements = columnSize;
					printf("[0]");
				}
			nullElements = 0;
			}
}

void printMatrixColumn(node* matrixHead){
	puts("");
	int i;
	node* aux = matrixHead;
	while(aux->right){
		printf("coluna:%i\n", aux->column);
		aux = aux->right;
		while(aux->below){
			aux = aux->below;
			printf("[%lf]", aux->value);
		}
	}
}


void fillMatrix (node* matrixHead, int lineSize, int columnSize){
        double value;
        int l=0, currentLine, currentColumn;
        FILE *matrix;

        matrix = fopen("matrix.txt", "rt");

        // VERIFICANDO DE A ABERTURA FOI BEM SUCEDIDA, CASO CONTRÁRIO O PROGRAMA É ABORTADO
        
        if(!matrix){
                printf("Erro ao abrir o arquivo! Abortando o programa...\n");
                exit(1);
        }

        fscanf(matrix, "%i", &lineSize); puts("107\n");
        fscanf(matrix, "%i", &columnSize); puts("108\n");
        int lineMarker [lineSize], columnMarker [columnSize],i;
        
        for (currentLine=0;currentLine<lineSize;currentLine++){
        	for (i=0;i<lineSize;i++){
        		lineMarker[i] = 0; puts("112\n");
			}
        	
    		for(currentColumn=0;currentColumn<columnSize;currentColumn++){
				fscanf(matrix, "%lf", &value);
				if (value!=0){
					if(lineMarker[currentLine]!=1){
						insertLineHead(matrixHead, currentLine);puts("119\n");
						lineMarker[currentLine] = 1;
					}
        			insertLineNode(value,matrixHead,currentLine,currentColumn);
				}
			}
		}
		
		for (currentColumn=0;currentColumn<columnSize;currentColumn++){
			node* currentHead = insertColumnHead(matrixHead, currentColumn);puts("129\n");
			node* currentNode = matrixHead;
			while(currentNode->below){puts("201\n");
				currentNode = currentNode->below;puts("202\n");
				while(currentNode->right){
					currentNode = currentNode->right;puts("134\n");
					if(currentNode->column == currentHead->column){
					   insertColumnNode(currentHead, currentNode);
					   puts("135\n");
					}
					else if (currentNode->column > currentHead->column) break;puts("136\n");
				}
			}
			if (!currentHead->below) free(currentHead);
		}
}
