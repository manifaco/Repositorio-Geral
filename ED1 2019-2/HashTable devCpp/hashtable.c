#include "hashtable.h"


hash* createHash() {
	hash* newHash = (hash*)calloc(1, sizeof(hash));
	if (!newHash) return newHash;
	newHash->table = (key**)calloc(TAM, sizeof(key*));
	return newHash;
}

int insertHash(info insertKey, hash** hashTable) {
	if (!(*hashTable)) return 0;
	int position = 0;
	position = hashing((*hashTable),insertKey);
	insertBST(&((*hashTable)->table[position]),insertKey);
	return 1;
}

int deleteHash(info deleteKey, hash** hashTable) {
	if (!(*hashTable)) return 0;
	int position = 0;
	position = hashing((*hashTable), deleteKey);
	return removeBST(&((*hashTable)->table[position]), deleteKey);
}

int searchHash(hash* hashTable, key** keyFound, info searchKey) {
	int position = 0;
	position = hashing((hashTable), searchKey);
	*keyFound = searchBST(hashTable->table[position], searchKey);
	if (*keyFound) return 1;
	return 0;
}

void printHash(hash* hashTable) {
	int i=0;
	for (i = 0; i < TAM; i++) {
		printf("Posicao %i:", i+1);
		printBST(hashTable->table[i]);
		puts("");
	}
}

void printTable(hash* hashTable, int position) {
	printf("Posicao %i", position);
	printBST(hashTable->table[position - 1]);
	puts("");
}

int hashing(hash* hashTable, info info) {
	int i = 1, j = 0, valuePosition = 0, pow1, pow2, result = 0;
	while ((info.value) >= i) {
		i *= 10;
		j++;
	}
	while (j > 0) {
		pow1 = pow(10, j);
		valuePosition = info.value % pow1;
		double J = j;
		pow2 = pow(10, J-1);
		valuePosition = valuePosition / pow2;
		result += valuePosition;
		j--;
	}
	if(result<0) result*=-1;
	if((result % TAM)-1 >=0) return (result % TAM)+1;
	else return 0;
}
