#include "MatrizEsparsa.h"

int main(){
	int op, lineSize, columnSize,qMatrizes=10,i=0,a,b,j;
	char* name;
	puts("Informe a quantidade de matrizes que deseja criar:");
	scanf("%i", &qMatrizes);
	char* matrixName[qMatrizes];
	node* matrixHead[qMatrizes];
	node* matrix = createMatrix();
	
	puts("MENU -----------------------------------------------------------\n1-Ler matriz\n2-Imprimir matriz\n3-somar\n4-subtrair\n5-multiplicar\n6-dividir");
	
	do{
		scanf("%i",&op);
		fflush(stdin);
			if(op==1){
				puts("informe qual matriz deseja ler");
				matrixName[i] = getString();
				matrixHead[i] = createMatrix();
				fillMatrix(matrixHead[i], lineSize, columnSize, matrixName[i]);
				i++;
				
			}		
					
			if(op==2){
				puts("informe qual matriz deseja imprimir:");
				name = getString();
				j = checkMatrix(i,matrixName,name);
				if(j==-1) puts("ERRO: nao existe nenhuma matriz com esse nome criada");
				else printMatrix(matrixHead[j], columnSize, lineSize, matrixName[j]);
			}

			
			if(op==3 || op == 4 || op == 5 || op == 6){
				puts("informe o nome das matrizes nas quais deseja realizar a operacao");
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
				if(op==3) plusMatrix(matrixHead[a],matrixHead[b],matrixHead,matrixName[a],matrixName[b]);
				if(op==4) minusMatrix(matrixHead[a],matrixHead[b],matrixHead,matrixName[a],matrixName[b]);
				if(op==5) multMatrix(matrixHead[a],matrixHead[b],matrixHead,matrixName[a],matrixName[b]);
				if(op==6) divMatrix(matrixHead[a],matrixHead[b],matrixHead,matrixName[a],matrixName[b]);
			}
	}while(op!=0);
	
	return 0;
}
