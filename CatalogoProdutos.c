#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "avl.h"
#include "CatalogoProdutos.h"

struct produtos {
	int total[26];
 	Avl_tree AVLProdutos[26];
};


/* Catalogo de produtos */
int VeTotalP(Produtos p){

	int r=p->total[1]; 
	return r;
}

Produtos InicializaProdutos(){
	int i;
	Produtos tmp = (Produtos)malloc(sizeof(struct produtos));
	for(i = 0; i < 26; i++){
		tmp -> AVLProdutos[i] = createTree();
		tmp->total[i]=0;}
    return tmp;
}


void insereAVLProdutos(Produtos p,char *cod){
	int j=26;
	Avl node;
	if (cod[0]>=97 && cod[0]<=123) 
		j = ((int)cod[0])-97;
	else
		if (cod[0]>=64 && cod[0]<=90) 
			j = ((int)cod[0])-65;

	if(existe(cod, p -> AVLProdutos[j]) == 0){
			node = createNode(cod);
			avl_insert(p -> AVLProdutos[j], node);
			p->total[j]++;
			
		}
	
}


int ExisteProduto(char* cod, Produtos p){
	int r=0;
	int j=0;
	if (cod[0]>=97 && cod[0]<=123) 
        j = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            j = ((int)cod[0])-65;
    r=existe(cod,p->AVLProdutos[j]);
    return r;
}







