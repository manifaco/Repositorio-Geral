#ifndef _LISTACIRCULAR_H
#define _LISTACIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct INFO{
	int value;
}info;

typedef struct NODE{
	info* info;
	struct NODE* next;
}node;

#endif
