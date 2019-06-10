#include "BST.h"

bst* createBST(){
	return NULL;
}

info* createInfo(int value){
	info* newInfo = (info*) calloc (1,sizeof(info));
	newInfo->value = value;
	return newInfo;
}

bst* createBSTNode(info* data){
	bst* newNode = (bst*)calloc(1,sizeof(bst));
	newNode->info = (info*) calloc(1,sizeof(info));
	newNode->info = data;
	printf("chave criada: [%i]\n", newNode->info->value);
	return newNode;
}

bst* leftBST(bst* tree){
	if(!tree) return NULL;
	return tree->left;
}

bst* rightBST(bst* tree){
	if(!tree) return NULL;
	return tree->right;
}


void printpreOrder(bst* tree){
    if(tree){
        printf("|%i| ", tree->info->value);
        printpreOrder(leftBST(tree));
        printpreOrder(rightBST(tree));
    }
    if(!tree) ("arvore vazia");
}

bst* searchBSTNode(bst* tree, bst* searchNode){
	//printf("tree->info->value:%i\nsearchNode->info->value:%i\n", tree->info->value, searchNode->info->value);
	if (!tree || tree->info->value == searchNode->info->value) return tree;
	if(searchNode->info->value < tree->info->value) tree = searchBSTNode(leftBST(tree),searchNode);
	else tree = searchBSTNode(rightBST(tree), searchNode);
}

bst* subInsertBSTNode(bst* tree, bst* newNode){
	if (!tree){
		return newNode;
	}
	
	if(newNode->info->value < tree->info->value) tree->left = subInsertBSTNode(leftBST(tree), newNode);
	else tree->right = subInsertBSTNode(rightBST(tree), newNode);
	return tree;
}

bst* insertBSTNode(bst* tree, info* data){
	bst* newNode = createBSTNode(data);
	bst* aux = tree;
	bst* aux2;puts("51");
	aux2 = subInsertBSTNode(aux, newNode);
	printpreOrder(aux2);
	return aux2;
}

bst* getLargerNode(bst* tree){
	if (!tree || !tree->right) return tree;
	tree = getLargerNode(rightBST(tree));
}

bst* getSmallerNode(bst* tree){
	if (!tree || !tree->left) return tree;
	tree = getSmallerNode(leftBST(tree));
}

int removeBSTNode(bst* tree, int value){
	if(!tree) return 0;
	else {
		info* newInfo = createInfo(value);
		bst* newNode = createBSTNode(newInfo);
		bst* auxTree = tree;
		auxTree = searchBSTNode(tree,newNode);
		printpreOrder(tree);
		printf("auxTree value:\n", auxTree->info->value);
		puts("83");
		
		if (!auxTree->left && !auxTree->right){
			puts("86"); free(auxTree);
		}
	
		if(auxTree->left || auxTree->right){
			if(auxTree->left && !auxTree->right){
				bst* aux = auxTree->left;
				auxTree->info = auxTree->left->info;
				auxTree->left = auxTree->left->left;
				auxTree->right = auxTree->left->right;
				free (aux);
			}
			
			if(auxTree->right && !auxTree->left){
				bst*aux = auxTree->right;
				auxTree->info = auxTree->right->info;
				auxTree->left = auxTree->right->left;
				auxTree->right = auxTree->right->right;
				free(aux);
			}
			
			if(auxTree->left && auxTree->right){
			bst* smaller;
			smaller = getSmallerNode(auxTree);
			auxTree->info = smaller->info;
			free(smaller);
			}
		}
		return 1;
	}
}
