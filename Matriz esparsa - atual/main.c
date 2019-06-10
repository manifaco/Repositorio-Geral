#include "MatrizEsparsa.h"

int main(){
	int op, lineSize, columnSize,qMatrizes=10,i=0,a,b,j;
	char* name;
	puts("Informe a quantidade de matrizes que deseja criar:");
	scanf("%i", &qMatrizes);
	char* matrixName[qMatrizes];
	node* matrixHead[qMatrizes];
	node* matrix = createMatrix();
	
	do{
		scanf("%i",&op);
		fflush(stdin);
			if(op==1){
				puts("informe qual matriz deseja ler");
				matrixName[i] = getString();
				puts(matrixName[i]);
				matrixHead[i] = createMatrix();
				fillMatrix(matrixHead[i], lineSize, columnSize, matrixName[i]);
				printMatrix(matrixHead[i], columnSize, lineSize, matrixName[i]);
				//fillMatrix(matrix, lineSize, columnSize, matrixName[i]);
				//printMatrix(matrix, columnSize, lineSize, matrixName[i]);
				
			}		
					
			if(op==2){
				puts("informe qual matriz deseja imprimir:");
				name = getString();
				j = checkMatrix(i,matrixName,name);
				if(j==-1) puts("ERRO: nao existe nenhuma matriz com esse nome criada");
				else printMatrix(matrixHead[j], columnSize, lineSize, matrixName[j]);
			}

			
			if(op==3){
				puts("informe o nome das matrizes nas quais deseja realizar a soma");
				char* name = getString();
				a = checkMatrix(i,matrixName,name);
				if (a==-1){
					puts("ERRO: nao existe nenhuma matriz com esse nome criada");
					break;
					}
					
				name = getString();
				b = checkMatrix(i,matrixName,name);
				if (b==-1){
					puts("ERRO: nao existe nenhuma matriz com esse nome criada");
				}
				else plusMatrix(matrixHead[a],matrixHead[b],matrixHead,matrixName[a],matrixName[b]);
			}
	}while(op!=0);
	
	return 0;
}
