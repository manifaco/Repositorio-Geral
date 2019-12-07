#ifndef _LISTACIRCULAR_H
#define _LISTACIRCULAR_H

typedef struct INFO{
	int value;
}info;

typedef struct NODE{
	info* info;
	struct NODE* next;
}node;

info* createInfo(int value);
node* createNode(int value);
node* insertB(int value, node* first, node** last);
node* insertE(int value, node* first, node** last);
node* removeB(node* first, node** last);
node* removeE(node* first, node** last);
node* removeP(int value, node* first, node** last);
void print(node* first);


#endif
