#include <stdio.h>
#include <stdlib.h>

void merge (int* v, int p, int q, int r){
	int i, j, k=0;
	int* temp = (int*) malloc ((r-p)*sizeof(int));
	i = p;
	j = q;
	while (i<q && j<r){
		if (v[i] <= v[j]){
			temp[k] = v[i];
			k++;
			i++;
		}
		else{
			temp[k] = v[j];
			j++;
			k++;
		}
	}
	while(i<q){
		temp[k] = v[i];
		i++;
		k++;
	}
	while (j<r){
		temp[k] = v[j];
		j++;
		k++;
	}
	k=0;
	i=p;
	while(i<r){
		v[i] = temp[k];
		i++;
		k++;
	}
	free(temp);
}

void mergeSort(int *v, int p, int r){
	if(p<r-1){
		int q = (p+r)/2;
		mergeSort(v,p,q);
		mergeSort(v,q,r);
		merge(v,p,q,r);
	}
}


int main (){
	int v[6] = {3,2,5,1,4,6}, i;
	printf("MERGE SORT\n");
	printf("Vetor não ordenado: ");
	for (i=0;i<6;i++){
		printf("%d ", v[i]);
	}
	printf("\nOrdenando...\n");
	mergeSort(v,0,6);
	printf("Vetor ordenado: ");
	for (i=0;i<6;i++){
		printf("%d ", v[i]);
	}
	return 0;
}
