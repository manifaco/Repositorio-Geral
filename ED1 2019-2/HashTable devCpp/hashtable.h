#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "BST.h"
#include "math.h"
#include <conio.h>

#define TAM 11

typedef struct hash {
	int size;
	key** table;
}hash;

hash* createHash();
int insertHash(info insertKey, hash** hashTable);
int deleteHash(info deleteKey, hash** hashTable);
int searchHash(hash* hashTable, key** keyFound, info searchKey);
void printHash(hash* hashTable);
void printTable(hash* hashTable, int position);
int hashing(hash* hashTable, info info);

#endif // !HASHTABLE_H

