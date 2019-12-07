#include "BST.h"

info* createInfoKey(int value) {
	info* newInfo = (info*)calloc(1, sizeof(info));
	if (!newInfo) return newInfo;
	newInfo->value = value;
}

key* createKey(info inf) {
	key* newKey = (key*)calloc(1, sizeof(key));
	if (!newKey) return newKey;
	newKey->info = createInfoKey(inf.value);
	newKey->left = NULL;
	newKey->right = NULL;
	if (!newKey->info) return newKey;
	newKey->info->value = inf.value;
	return newKey;
}

key* leftBST(key* key) {
	return key->left;
}

key* rightBST(key* key) {
	return key->right;
}

void listPreOrder(key* bst, node** first, node** last) {
	if (!bst) return;
	if (bst) {
		*first = insertE(bst->info->value , *first, last);
	}
	listPreOrder(bst->left, first, last);
	listPreOrder(bst->right, first, last);
}

key* rebuildTree(node** preListFirst, node* inListFirst, node** preListLast, node** inListLast) {
	if(!(*preListFirst)) return NULL;
	if(!(*preListFirst) && !inListFirst) return NULL;
	node* aux = inListFirst, * aux2 = NULL;
	info inf;
	inf.value = (*preListFirst)->info->value;
	key* newKey = createKey(inf);
	if(inListFirst && inListFirst->info->value == (*preListFirst)->info->value){
		(*preListFirst) = (*preListFirst)->next;
		return newKey;
	}
	if (aux)
		if (aux->next)
			while (aux->next->info->value != (*preListFirst)->info->value) {
				aux = aux->next;
			}
	(*preListFirst) = (*preListFirst)->next;
	aux2 = aux->next;
	if(aux2) if(aux2->next) aux2 = aux2->next;
	aux->next = NULL;
	newKey->left = rebuildTree(preListFirst, inListFirst, preListLast, inListLast);
	newKey->right = rebuildTree(preListFirst,aux2, preListLast, inListLast);
	return newKey;
}

void listInOrder(key* bst, node** first, node** last) {
	if (!bst) return;
	listInOrder(bst->left, first, last);
	if (bst) {
		*first = insertE(bst->info->value, *first, last);
	}
	listInOrder(bst->right, first, last);
}

void listPosOrder(key* bst, node** first, node** last) {
	if (!bst) return;

	listPosOrder(bst->left, first, last);
	listPosOrder(bst->right, first, last);

	if (bst) {
		*first = insertE(bst->info->value, *first, last);
	}
}

void printPreOrder(key* bst) {
	if (!bst) return;
	printf("[%i] \n", bst->info->value);
	printPreOrder(bst->left);
	printPreOrder(bst->right);
}

int nFolhas(key* bst) {
	static int i=0;
	if (!bst) return 0;
	if(!bst->right && !bst->left) i++;
	nFolhas(bst->left);
	nFolhas(bst->right);
	return i;
}

void printInOrder(key* bst) {
	if (!bst) return;
	printInOrder(bst->left);
	printf("[%i] \n", bst->info->value);
	printInOrder(bst->right);
}

void printPosOrder(key* bst) {
	if (!bst) return;
	printPosOrder(bst->left);
	printPosOrder(bst->right);
	printf("[%i] \n", bst->info->value);
}

int insertBST(key** bst, info info) {
	key* newKey = createKey(info);
	if (!(*bst)) {
		*bst = newKey;
		return 1;
	}

	if ((*bst)->info->value < newKey->info->value) return insertBST(&((*bst)->right), info);
	if ((*bst)->info->value > newKey->info->value) return insertBST(&((*bst)->left), info);
	return 0;
}

key* searchBST(key* bst, info info) {
	if (!bst) return NULL;
	if (bst->info->value == info.value) return bst;

	if (bst->info->value < info.value) return searchBST(bst->right, info);
	if (bst->info->value > info.value) return searchBST(bst->left, info);
}

int searchBSTFather(key* bst, info info, key** father) {
	if (!bst) return -1;
	if (bst->info->value == info.value) return 0;
	if (!bst->left && !bst->right) return 0;
	if (bst->right && bst->right->info->value == info.value) {
		*father = bst;
		return 1;//1 = filho a direita
	}
	if (bst->left && bst->left->info->value == info.value) {
		*father = bst;
		return 2;// 2 = filho a esquerda
	}

	if (bst->info->value < info.value) return searchBSTFather(bst->right, info, father);
	if (bst->info->value > info.value) return searchBSTFather(bst->left, info, father);
}

key* smaller(key* bst) {
	if (!bst) return NULL;
	if (!bst->left) return bst;
	if (bst->left) return smaller(bst->left);
}

key* larger(key* bst) {
	if (!bst) return NULL;
	if (!bst->right) return bst;
	if (bst->right) return smaller(bst->left);
}

int heightBST(key* bst) {
	int height = 0, left = 0, right = 0;
	if (!bst) return 0;
	left = 1 + heightBST(bst->left);
	right = 1 + heightBST(bst->right);
	height = left > right ? left : right;
	return height;
}

key* removeCurrent(key* bst, key* current) {
	key* aux, * aux2;
	aux = current;
	//Os casos de remocao dessa implementacao trabalham juntos.
	if (!aux->left) {
		aux2 = current->right;
		free(aux);
		return aux2;
	}
	aux2 = current->left;

	if (aux2)
		while (aux2->right) {
			aux = aux2;
			aux2 = aux2->right;
		}
	if (aux != current) {
		aux->right = aux2->left;
		aux2->left = current->left;
	}
	if (aux2) aux2->right = current->right;
	free(current);
	return aux2;
}

int removeBST(key** bst, info info) {
	key* father = NULL, * current = (*bst), * subTree = NULL;
	int side;
	if (!(*bst)) return 0;
	side = searchBSTFather((*bst), info, &father);
	if (side == -1) return 0;
	if (side == 1) if (father) current = father->right;
	if (side == 2) if (father) current = father->left;
	subTree = removeCurrent((*bst), current);
	if (side && father) { //Se o pai nao existir significa que a arvore possui apenas um no, que e a propria raiz
		if (side == 2) father->left = subTree;
		else father->right = subTree;
	}
	else (*bst) = subTree;
	return 1;
}

void printBST(key* bst) {
	if (!bst) {
		return;
	}
	printf("[%i] ", bst->info->value);
	printBST(bst->left);
	printBST(bst->right);
}
