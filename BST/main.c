#include "BST.h"

int main() {
	int op, value;
	bst* tree = createBST();
	info* info;
	bst* aux, *aux2;
	puts("informe a operacao que deseja realizar:\n1-Inserir\n2-Buscar\n3-Buscar Maior chave\n4-Buscar menor chave\n5-Remover no\n6-Imprimir arvore\n");
	
	do{
		scanf("%i",&op);
		fflush(stdin);
		switch(op) {
			
			case 1:
				puts("Informe o valor da chave que deseja inserir:");
				scanf("%i", &value);
				info = createInfo(value);
				tree = insertBSTNode(tree, info);
				break;
				
			case 2:
				puts("Informe a chave que deseja buscar:");
				scanf("%i", &value);
				info = createInfo(value);
				bst* newNode = createBSTNode(info);
				aux = tree;
				if(!aux) puts("arvore nula");
				aux = searchBSTNode(aux, newNode);
				if(aux) printf("valor encontrado:%i\n", aux->info->value);
				else puts("no nao encontrado");
				break;
				
			case 3:
				aux = tree;
				aux = getLargerNode(aux);
				if (!aux) puts("no nao encontrado");
				else printf("a maior chave da arvore eh: %i\n", aux->info->value);
				break;
			
			case 4:
				aux = tree;
				aux = getSmallerNode(aux);
				if (!aux) puts("no nao encontrado");
				else printf("a menor chave da arvore eh: %i\n", aux->info->value);
				break;
			
			case 5:
				puts("Informe o valor a ser removido:");
				scanf("%i", &value);
				aux = tree;
				printf("raiz da arvore: %i\n", aux->info->value);
				value = removeBSTNode(aux,value);
				printf("value:%i\n", value);
				if(value == 2) tree = createBST();
				if(value!=0) puts("sucesso na remocao");
				else puts("no nao removido");
				break;
			
			case 6:
				aux = tree;
				printpreOrder(aux);
				break;
			
			case 7:
				puts("Informe a chave que deseja buscar:");
				scanf("%i", &value);
				info = createInfo(value);
				newNode = createBSTNode(info);
				aux = tree;
				if(!aux) puts("arvore nao existe");
				aux = searchBSTFather(aux, newNode);
				if(aux) printf("No encontrado:%i\n",aux->info->value);
				else puts("no nao encontrado");
				break;
		}
	}while(op!=0);
	return 0;
}
