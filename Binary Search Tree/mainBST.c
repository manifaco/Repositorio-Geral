#include "BST.h"

int main() {
	int op;
	bool result;
	key* bst = NULL, * aux;
	info info;
	puts("1-Inserir\n2-Remover\n3-Imprimir\n4-Buscar");

	do {
		scanf_s("%i", &op);
		switch (op) {
		case 1:
			puts("Informe um valor:");
			scanf_s("%i", &(info.value));
			printf("insercao: %i\n", insertBST(&bst, info));
			break;

		case 2:
			puts("Informe um valor:");
			scanf_s("%i", &(info.value));
			if (removeBST(&bst, info)) puts("Remocao bem sucedida");
			else puts("Erro na remocao");
			break;

		case 3:
			printBST(bst);
			break;

		case 4:
			puts("Informe um valor:");
			scanf_s("%i", &(info.value));
			if (searchBST(bst, info)) puts("chave encontrada");
			else puts("chave nao encontrada");
			break;

		case 5:
			op = heightBST(bst) + 1;
			printf("altura: %i\n", op - 1);

		case 6:
			aux = smaller(bst);
			if (aux) printf("%i\n", aux->info->value);
			break;
		}
	} while (op);

	return 0;
}