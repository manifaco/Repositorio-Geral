#include "excecoes.h"

excecoes <int> funcoesInt;
excecoes <String> funcoesSTR;


int main(){
	
	isDivByZero(3/1);
	isDivByZero(3/0);
	return 0;
}
