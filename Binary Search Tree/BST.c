#include "BST.h"

key* createKey(info inf) {
	key* newKey = (key*)calloc(1, sizeof(key));
	if (!newKey) return newKey;
	newKey->info = (info*)calloc(1, sizeof(info));
	newKey->info->value = inf.value;
	return newKey;
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
	if (!bst) return 0;
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

int removeBST(key** bst, info info) {
	int side, side2;//1 = direita, 2=esquerda, 3=nao achado
	key* father = NULL;
	key* b = *bst;
	if (!b) return 0;
	puts("73");
	side = searchBSTFather(b, info, &father);
	printBST(father);
	b = side > 1 ? father->left : father->right;
	printf("bst:%i \n", b->info->value);
	printBST(father);
	if (!side) return 0;
	puts("76");

	//nenhum filho
	if (!b->right && !b->left) {
		puts("78"); printBST(father);
		if (father) {
			puts("79");
			if (side == 1) father->right = NULL;
			if (side == 2) father->left = NULL;
		}
		else (*bst) = NULL; puts("82");
	}
	printBST(father);

	if (b) {
		puts("86");
		printf("father:%i\n", father->info->value);
		printBST(father);
		if (father->left) printf("father->left:%i\n", father->left->info->value);
		if (father->right) printf("father->right:%i\n", father->right->info->value);
		printf("bst:%i\n", b->info->value);
		printf("side: %i\n", side);
		//1 filho
		if (!b->right && b->left) {
			puts("84");
			if (side == 1) father->right = b->left;
			if (side == 2) father->left = b->left;
		}

		if (b->right && !b->left) {
			puts("89");
			if (side == 1) father->right = b->right;
			if (side == 2) father->left = b->right;
		}

		//2 filhos
		if (b->right && b->left) {
			puts("106");
			key* aux = NULL;
			key* auxFather = NULL;
			aux = larger(b->left);
			searchBSTFather(b, *(aux->info), &auxFather);

			if (side == 1) father->right = aux;
			if (side == 2) father->left = aux;
			auxFather->right = NULL;
			aux->left = b->left;
			aux->right = b->right;
		}
	}

	puts("105");
	if (father->left) printf("father->left:%i\n", father->left->info->value);
	if (father->right) printf("father->right:%i\n", father->right->info->value);
	printf("bst:::%i\n", b->info->value);
	if (b) free(b->info);
	free(b);
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