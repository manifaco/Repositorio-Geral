#include "BST.h"

info* createInfoKey(int value) {
	info* newInfo = (info*)calloc(1, sizeof(info));
	if (!newInfo) return newInfo;
	newInfo->value = value;
	return newInfo;
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

void fixBalance(key* avl) {
	if (!avl) return;
	int hLeft = heightBST(avl->left), hRight = heightBST(avl->right);
	avl->balance = hLeft - hRight;
	fixBalance(avl->left);
	fixBalance(avl->right);
}

key* RRRotation(key* pivot) {
	key* aux = pivot->right;
	pivot->right = pivot->right->right;
	aux->right = pivot->right->left;
	pivot->right->left = aux;
	fixBalance(pivot);
}

key* LLRotation(key* pivot){
	key* aux = pivot->left;
	pivot->left = pivot->left->left;
	aux->left = pivot->left->right;
	pivot->left->right = aux;
	fixBalance(pivot);
}

key* LRRotation(key* pivot) {
	key* aux = pivot;
	pivot = pivot->left->right;
	pivot->right = aux;
	pivot->left = aux->left;
	aux->left->right = aux->left->right->right;
	aux->left = NULL;
	fixBalance(pivot);
}

key* RLRotation(key* pivot) {
	key* aux = pivot;
	pivot = pivot->right->left;
	pivot->left = aux;
	pivot->right = aux->right;
	aux->right->left = aux->right->left->left;
	aux->right = NULL;
	fixBalance(pivot);
}

int insertBST(key** bst, info info) {
	int insert = 0;
	int side = 0;
	static int succes = 0;
	key** bst2;
	key* newKey = createKey(info);
	if (!newKey) return 0;
	if (!(newKey->info)) return 0;
	if (!(*bst)) {
		*bst = newKey;
		succes = 1;
		return 1;
	}

	if ((*bst)->info->value < newKey->info->value) {//caso da direita
		insert = insertBST(&((*bst)->right), info);
		if ((*bst)->balance <= 0 && succes) grow = 1;
		if (succes) {//caso do no Pai
			if ((*bst)->balance > 0) (*bst)->balance -= 1;
		}
		if (grow) side = 1;
	}

	if ((*bst)->info->value > newKey->info->value) {//caso da esquerda
		insert = insertBST(&((*bst)->left), info);
		if ((*bst)->balance >= 0 && succes) grow = 1;
		if (succes) {//caso do no Pai
			if ((*bst)->balance < 0) (*bst)->balance += 1;
		}
		if (grow) side = 2;
	}
	if (side == 1) (*bst)->balance -= 1;
	if (side == 2) (*bst)->balance += 1;
	succes = 0;
	if ((*bst)->balance > 1 || (*bst)->balance < -1) balanceAVL(*bst);
	return insert;
}

key* balanceAVL(key* avl) {
	while(avl->balance > 1 || avl->balance < -1){
		if (avl->balance > 1) {
			if (avl->left->balance > 1) avl = LLRotation(avl);
			else avl = LRRotation(avl);
		}
		if (avl->balance < 1) {
			if (avl->left->balance < 1) avl = RRRotation(avl);
			else avl = RLRotation(avl);
		}
	}
}

/*
	se balanco >1 ou menor q <1 :
	se(filho da esquerda tem filho pela esquerda){
		
	}
*/

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
	static int i;
	int j;
	if (!bst) {
		return;
	}
	printf("Key:[%i]\n", bst->info->value);
	printf("Balance:[%i]", bst->balance);
	puts("");
	printBST(bst->left);
	printBST(bst->right);
}
