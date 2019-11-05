#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int soma (int a[], int inicio=0 , int fim = 7, int incr = 1){
	int soma = 0,i;
	for(i=inicio;i<fim;i+=incr) soma+= a[i];
	return soma;
}

int main(){
	int pontuacao[] = {9,4,8,9,5,6,2};
	int pTotal, pQuaSab, pTerQui,pSegQuaSex;
	pTotal = soma(pontuacao);
	pQuaSab = soma(pontuacao,3);
	pTerQui = soma(pontuacao,2,5);
	pSegQuaSex = soma(pontuacao,1,6,2);
	printf("pTotal: %i\npQuaSab: %i\nPterQui: %i\npSegQuaSex: %i\n", pTotal,pQuaSab, pTerQui, pSegQuaSex);
}
