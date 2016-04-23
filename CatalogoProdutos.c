#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/avl.h"
#include "headers/CatalogoProdutos.h"

struct produtos {
	int total[26];
 	Avl_tree AVLProdutos[26];
};


struct conjProds {
	char** lista;
	int tamanho;
};


/* Relacionado com ConjProds*/

ConjProds InicializaConjProds(){
	ConjProds tmp = (ConjProds)malloc(sizeof(struct conjProds));
	tmp->lista=NULL;
	tmp->tamanho=0;
	return tmp;
}

int retornaTamanhoPro(ConjProds cc){
	return cc->tamanho;
}

char* retornaElementoPro(ConjProds cc,int i){

	return cc->lista[i];
}

char retornaPrimeiraLetraPro(ConjProds cc,int i){
	char *a= cc->lista[i];
	char r=a[0];
	return r;
}



/* Catalogo de produtos */


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

ConjProds toArrayProdutos(Produtos pro, char c){
   int index = 0, size = 0, n = 0;
   char** aux;
   Avl_tree a;
   Avl b;
   ConjProds prods = InicializaConjProds();
   
   n = c-65;
   size = pro->total[n];
   aux = malloc(sizeof(char*)*size);
   a = pro -> AVLProdutos[n];
   b = createCharNode(a);
   index=toArrayProdutosAux(b, index, aux);
   prods->lista=aux;
   prods->tamanho=index;
   free(aux);
   return prods;
}







