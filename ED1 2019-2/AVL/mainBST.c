#include "BST.h"

int main() {
	int op, side = 0;
	bool result;
	key* bst = NULL, * aux = NULL, * father = NULL;
	node *first = NULL, *last = NULL, *first2 = NULL, *last2 = NULL;
	info info;
	puts("1-Inserir\n2-Remover\n3-Imprimir\n4-Buscar\n\n5-Altura\n6-Buscar menor chave\n7-Buscar Pai\n8-Remover atual");
	puts("9-Criar lista a partir de um percurso");

	do {
		scanf_s("%i", &op);
		switch (op) {
		case 1:
			puts("Informe um valor:");
			scanf_s("%i", &(info.value));
			printf("insercao: %i\n", insertBST(&bst, info));
			grow = 0;
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
			if (aux) if (aux->info) printf("%i\n", aux->info->value);
			break;

		case 7:
			puts("Informe um valor:");
			scanf_s("%i", &(info.value));
			side = searchBSTFather(bst, info, &father);
			if (father) printf("Pai: %i\n", father->info->value);
			printf("side: %i\n", side);
			break;

		case 8:
			puts("Informe um valor:");
			scanf_s("%i", &(info.value));
			aux = searchBST(bst, info);
			aux = removeCurrent(bst, aux);
			if (aux) printf("AUX: %i\n", aux->info->value);
			else puts("aux nao existe");
			break;

		case 9:
			puts("1-PreOrdem\n2-InOrdem\n3-PosOrdem");
			scanf_s("%i", &op);
			if (op == 1) {
				listPreOrder(bst, &first, &last);
				puts("Lista pre Ordem:");
				print(first);
			}
			if (op == 2) {
				listInOrder(bst, &first2, &last2);
				puts("Lista em Ordem:");
				print(first2);
			}
			if (op == 3) {
				listPosOrder(bst, &first2, &last2);
				puts("Lista em Ordem:");
				print(first2);
			}
			break;

		}
	} while (op);

	return 0;
}