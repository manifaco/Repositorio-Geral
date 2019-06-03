#include "MatrizEsparsa.h"

int main(){
	int lineSize, columnSize;
	node* matrixHead = createMatrix();
	fillMatrix(matrixHead, lineSize, columnSize);
	int op;
	
//	puts("Informe a operacao que deseja realizar:\n1-Imprimir matriz\n0-Sair\n");
	
//	do{
//		scanf("%i", &op);
//		switch (op){
//			case 1:
				printMatrix(matrixHead, columnSize, lineSize);
				printMatrixColumn(matrixHead);
//				break;
//		}
		
//	}while(op!=0);
	
	return 0;
}
