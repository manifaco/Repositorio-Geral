#ifndef  _LISTAPOLINOMIAL_H
#define  _LISTAPOLINOMIAL_H


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	int coeficiente;
	int potencia;
}info;

typedef struct _node{
	info* info;
	struct _node* next;
}node;

#endif
