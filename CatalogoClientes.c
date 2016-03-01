#include <stdlib.h>
#include <string.h>

#include  "avl.h"
#include "CatalogoClientes.h"

/* Compara códigos dos clientes, retornando
	< 0 se str1 for menor que str2
	> 0 se a str1 for maior que str2
	= 0 se forem iguais */ 
int comparaCod(struct Cliente a, struct Cliente b){
	int i = 0;

	i = strcmp( a-> codigo, b-> codigo );

	return i;
}

/* Inicialização de uma avl Clientes */
static struct avl_tree avlClientes[26];

/*
Inicia as AVLs dos Clientes
*/
int iniciaAlvClientes()
{
	int i=0;

	while(i<=25)
	{	
		avlClientes[i].compar=comparaCod;
		avlClientes[i].root=0;
		i++;
	}
	
	return i-25;
}

/*
Insere os Clientes na Avl de Clientes
*/
int insereAvlClientes(char Clientes[MAX_COD_CLIENTES])
{
	int j=25, n = 0;
	struct Cliente *insereClientes;	

	insereClientes = (struct Cliente *) malloc(sizeof(struct Cliente));
	memset(insereClientes->codigo, '\0', MAX_COD_CLIENTES);
	strcpy(insereClientes->nome, Clientes);
	
	if (Clientes[0]>=65 && Clientes[0]<=90) 
		j = ((int)Clientes[0])-65;
	else
		if (Clientes[0]>=65 && Clientes[0]<=90) 
			j = ((int)Clientes[0])-65;
	
			
	if( (n = avl_easySearch(&avlClientes[j], (struct avl*)insereClientes)) == 0 )
	{
		avl_insert(&avlClientes[j], (struct avl*)insereClientes);
	}
	else 
	{
		free(insereClientes);	
		return 0;
	}
	return 1;
}

/* FALTA MUITA COISA MAS DA TRABALHO */