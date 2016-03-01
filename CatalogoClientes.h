#ifndef _CATALOGOCLIENTES_H
#define _CATALOGOCLIENTES_H

#define MAX_COD_CLIENTES 5

/* Definição da struct de array de clientes */
struct Cliente{
	struct avl avl;
	char codigo[MAX_COD_CLIENTES];
};

/* Funções */

int comparaCod(struct Cliente a, struct Cliente b);
int iniciaAlvClientes();

#endif