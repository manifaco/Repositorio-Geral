#include <stdio.h>
#include <stdlib.h>

void merge (int* vetor, int posicao, int meio, int tamanho){
	int i, j, k=0;
	int* temp = (int*) malloc ((tamanho-posicao)*sizeof(int));
	i = posicao;
	j = meio;
	while (i<meio && j<tamanho){
		if (vetor[i] <= vetor[j]){
			temp[k] = vetor[i];
			k++;
			i++;
		}
		else{
			temp[k] = vetor[j];
			j++;
			k++;
		}
	}
	while(i<meio){
		temp[k] = vetor[i];
		i++;
		k++;
	}
	while (j<tamanho){
		temp[k] = vetor[j];
		j++;
		k++;
	}
	k=0;
	i=posicao;
	while(i<tamanho){
		vetor[i] = temp[k];
		i++;
		k++;
	}
	free(temp);
}

void mergeSort(int *vetor, int posicao, int tamanho){
	if(posicao<tamanho-1){
		int meio = (posicao+tamanho)/2;
		mergeSort(vetor,posicao,meio);
		mergeSort(vetor,meio,tamanho);
		merge(vetor,posicao,meio,tamanho);
	}
}


int main (){
	int vetor[6] = {3,2,5,1,4,6}, i;
	printf("MERGE SORT\n");
	printf("Vetor não ordenado: ");
	for (i=0;i<6;i++){
		printf("%d ", vetor[i]);
	}
	printf("\nOrdenando...\n");
	mergeSort(vetor,0,6);
	printf("Vetor ordenado: ");
	for (i=0;i<6;i++){
		printf("%d ", vetor[i]);
	}
	return 0;
}
