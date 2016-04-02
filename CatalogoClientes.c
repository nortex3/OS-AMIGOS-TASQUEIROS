
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include  "avl.h"
#include "CatalogoClientes.h"

struct clientes{
	int total[26];
	Avl_tree AVLClientes[26];
};

/*
Inicia as AVLs dos Clientes
*/
Clientes InicializaClientes(){
	int i;
	Clientes tmp = (Clientes)malloc(sizeof(struct clientes));
	for(i = 0; i < 26; i++){
		tmp -> AVLClientes[i] = createTree();
		tmp->total[i]=0;}
    return tmp;
}


int VeTotalC(Clientes p){

	int r=p->total[1]; 
	return r;
}




/*
Insere os Clientes na Avl de Clientes
*/


void insereAvlClientes(Clientes c,char *cod){
	int j=26;
	Avl node;
	if (cod[0]>=97 && cod[0]<=123) 
		j = ((int)cod[0])-97;
	else
		if (cod[0]>=64 && cod[0]<=90) 
			j = ((int)cod[0])-65;

	if(existe(cod, c-> AVLClientes[j]) == 0){
			node = createNode(cod);
			avl_insert(c -> AVLClientes[j], node);
			c->total[j]++;
			
		}
	
}


int ExisteCliente(char* cod, Clientes p){
	int r=0;
	int j=0;
	if (cod[0]>=97 && cod[0]<=123) 
        j = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            j = ((int)cod[0])-65;
    r=existe(cod,p->AVLClientes[j]);
    return r;
}
