#include "hashtable.h"

int main() {
	int op;
	hash* hashTable = createHash();
	info info;
	key* auxKey = NULL;
	puts("-----------------------MENU----------------------------------");
	puts("1-Inserir\n2-Remover\n3-Imprimir Tabela\n4-Imprimir posicao \n5-Buscar\n");

	do {
		scanf_s("%i", &op);
		switch (op) {

		case 1:
			puts("Informe o valor a ser inserido:");
			scanf_s("%i", &info.value);
			op = insertHash(info, &hashTable);
			if (op) puts("Insercao bem sucedida");
			else puts("Falha na insercao");
			if(!op) op++;
			break;

		case 2:
			puts("Informe o valor a ser removido:");
			scanf_s("%i", &info.value);
			op = deleteHash(info, &hashTable);
			if (op) puts("remocao bem sucedida");
			else puts("Falha na remocao");
			if(!op) op++;
			break;
		
		case 3:
			printHash(hashTable);
			break;

		case 4:
			puts("Informe a posicao:");
			if (!op) {
				puts("posicao invalida");
				op++;
				break;
			}
			printBST(hashTable->table[op]);
			break;

		case 5:
			puts("Informe o valor a ser buscado:");
			scanf_s("%i", &info.value);
			op = searchHash(hashTable, &auxKey, info);
			if (op) puts("remocao bem sucedida");
			else puts("Falha na remocao");
			if (!op) op++;
			break;

		}
	} while (op);
	return 0;
}