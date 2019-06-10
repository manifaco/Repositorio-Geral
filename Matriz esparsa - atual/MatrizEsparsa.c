#include "MatrizEsparsa.h"


int getQMat(){
	int qMatrizes;
	printf("informe quantas matrizes deseja criar:\n");
	scanf("%i", &qMatrizes);
	return qMatrizes;
}

char* getString(){
   	char character , *str = NULL;
	int count1 = 0, count2 = 1;
	
	str = (char *) malloc(10 * sizeof(char) + 1);
	printf(":");
	
	while ((character = getchar()) != '\n' && character != EOF && character != '\0')
	{
		if (count2 == 10) {
			str = (char *) realloc(str, strlen(str) + 10 * sizeof(char) + 1);
			count2 = 1;
		}

		*(str + count1 * sizeof(char)) = character;

		count1++;
		count2++;
	}
	
	*(str + count1 * sizeof(char)) = '\0';
	
	puts("\n\n");
	
	printf("%s\n\n", str);
    return str;
}



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

void printMatrix(node* matrixHead, int columnSize, int lineSize, char* matrixName){
	FILE *matrix;
	matrix = fopen(matrixName, "rt");
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

int checkMatrix(int i,char* matrixName, char* name){
	int j;
	for(j=i;j>-1;j++){
		if(strcmp(name,matrixName[j])) return j;
	}
	return -1;
}

void plusMatrix(node* matrix1, node* matrix2, node*matrixVector, char* matrix1Name, char* matrix2Name){
		
	    double value, lineSize[2],columnSize[2];
        int i, l=0, result;
        node *currentLine1,*currentLine2, *currentColumn1, *currentColumn2,*currentNode1,*currentNode2;
        FILE *matrix;
        
        for(i=0;i<2;i++){
        	matrix = fopen(matrix1Name, "rt");

        	// VERIFICANDO DE A ABERTURA FOI BEM SUCEDIDA, CASO CONTRÁRIO O PROGRAMA É ABORTADO
        	
        	if(!matrix){
                printf("Erro ao abrir o arquivo! Abortando o programa...\n");
                exit(1);
        }
        fscanf(matrix, "%i", &lineSize[i]);
        fscanf(matrix, "%i", &columnSize[i]);
        fclose(matrix);
		}
        
        if((lineSize[0] == lineSize[1]) && (columnSize[0] == columnSize[1])){
        	
        	puts("Nome da nova matriz:");
        	matrix = fopen(getString(), "w");

        	// VERIFICANDO DE A ABERTURA FOI BEM SUCEDIDA, CASO CONTRÁRIO O PROGRAMA É ABORTADO
        
        	if(!matrix){
                printf("Erro ao abrir o arquivo! Abortando o programa...\n");
                exit(1);
            
            fprintf(matrix, "%i", lineSize[0]);
            l=10;
            fputs("",matrix);
            fprintf(matrix, "%i", columnSize[0]);
            putc(l,matrix);
            
        	}
        	if(lineSize[0]!=0 && columnSize[0]!=0){
        		
        		currentLine1 = matrix1->below;
        		currentLine2 = matrix2->below;
        		currentNode1 = currentLine1->right;
        		currentNode2 = currentLine2->right;
        		
        		while(currentLine1){
        			
        			currentLine1 = currentLine1->below;
        			currentLine2 = currentLine2->below;
        			currentNode1 = currentLine1->right;
        			currentNode2 = currentLine2->right;
        			fputs("",matrix);
        			while(currentNode1->right){
        				
        				double result = currentNode1->value + currentNode2->value;
        				fprintf(matrix, "%.1lf ", result);
        				currentNode1 = currentNode1->right;
        				currentNode2 = currentNode2->right;
					}
				}
			}
		}
		else puts("ERRO - as matrizes nao possuem as mesmas dimensoes");
}


void fillMatrix (node* matrixHead, int lineSize, int columnSize, char* matrixName){
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
