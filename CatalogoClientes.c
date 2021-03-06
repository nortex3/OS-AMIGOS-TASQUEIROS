#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/avl.h"
#include "headers/CatalogoClientes.h"

struct clientes{
	int total[26];
	Avl_tree AVLClientes[26];
};


struct conjClientes {
	char** lista;
	int tamanho;
};

/* Relacionado com ConjClientes*/

ConjClientes InicializaConjClientes(){
	ConjClientes tmp = (ConjClientes)malloc(sizeof(struct conjClientes));
	tmp->lista=NULL;
	tmp->tamanho=0;
	return tmp;
}

int retornaTamanho(ConjClientes cc){
	return cc->tamanho;
}

char* retornaElemento(ConjClientes cc,int i){

	return cc->lista[i];
}

char retornaPrimeiraLetra(ConjClientes cc,int i){
	char *a= cc->lista[i];
	char r=a[0];
	return r;
}

/*
Inicia as AVLs dos Clientes
*/
Clientes InicializaClientes(){
	int i;
	Clientes tmp = (Clientes)malloc(sizeof(struct clientes));
	for(i = 0; i < 26; i++){
		tmp -> AVLClientes[i] = createTree();
		tmp->total[i]=0;
	}
    return tmp;
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

ConjClientes toArrayClientes(Clientes cli, char c){
   int index = 0, size = 0, n = 0;
   char** aux;
   Avl_tree a;
   Avl b;
   ConjClientes clientes=InicializaConjClientes();
   
   n = c-65;
   size = cli->total[n];
   aux = malloc(sizeof(char*)*size);
   a = cli -> AVLClientes[n];
   b = createCharNode(a);
   index=toArrayClientesAux(b, index, aux);
   clientes->lista=aux;
   clientes->tamanho=index;
   free(aux);
   return clientes;
}





