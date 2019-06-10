#include "BST.h"

int main() {
	int op, value;
	bst* tree = createBST();
	info* info;
	bst* aux;
	puts("informe a operacao que deseja realizar:\n1-Inserir\n2-Buscar\n3-Buscar Maior chave\n4-Buscar menor chave\n5-Remover no");
	
	do{
		scanf("%i",&op);

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
				aux = searchBSTNode(aux, newNode);
				if(aux) puts("no encontrado");
				else puts("no nao encontrado");
				break;
				
			case 3:
				aux = tree;
				aux = getLargerNode(aux);
				if (!aux) puts("no nao encontrado");
				else printf("a maior chave da arvore eh: %i", aux->info->value);
				break;
			
			case 4:
				aux = tree;
				aux = getSmallerNode(aux);
				if (!aux) puts("no nao encontrado");
				else printf("a menor chave da arvore eh: %i", aux->info->value);
				break;
			
			case 5:
				puts("Informe o valor a ser removido:");
				scanf("%i", &value);
				value = removeBSTNode(tree,value);
				if(value == 1) puts("sucesso na remocao");
				else puts("no nao removido");
		}
	}while(op!=0);
	return 0;
}
