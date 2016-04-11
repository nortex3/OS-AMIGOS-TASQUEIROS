#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/Faturacao.h"
#include "headers/avlFilial.h"
#include "headers/GestaoFilial.h"

#define NORMAL 0
#define PROMO 1



struct GestFil {
	Avl_treeP avlProdutos[26];
	Avl_treeC avlClientes[26];
};

struct conjClisGF {
    char** lista;
    int tamanho;
};


/* Relacionado com ConjClisGF*/

ConjClisGF InicializaConjClisGF(){
    ConjClisGF tmp = (ConjClisGF)malloc(sizeof(struct conjClisGF));
    tmp->lista=NULL;
    tmp->tamanho=0;
    return tmp;
}

int retornaTamanhoConjClisGF(ConjClisGF cc){
    return cc->tamanho;
}

char* retornaElementoConjClisGF(ConjClisGF cc,int i){

    return cc->lista[i];
}


/*Apoio Querie 5 */

ConjClisGF percorreClientes(GF gf){
    int i, index=0;
    int r[3];
    AvlC cli;
    char** aux;
    char** aux2;
    ConjClisGF clientes = InicializaConjClisGF();
    aux=malloc(sizeof(char*)*16384);
    for(i=0;i<26;i++){
        Avl_treeC tmp = gf->avlClientes[i];
        cli = createNodeCli(tmp);
        index=percorreClientesAux(cli,r, aux, index);
    }
    aux2=malloc(sizeof(char*)*index);
    memcpy(aux2,aux,sizeof(char*)*index);
    free(aux);
    clientes -> lista = aux2;
    clientes -> tamanho = index;
    return clientes;

}

int CalculaTotais(GF gf,char* cod,int *mes){

    int j=26;
    Avl_treeC cli;
    AvlC cliente;
    int Nexiste=0;
    if (cod[0]>=97 && cod[0]<=123) 
        j = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            j = ((int)cod[0])-65;
    cli=gf->avlClientes[j];
    cliente = procuraTreeC(cli, cod);
    if(cliente==NULL) Nexiste=1;
    else calculaListaProdutos(cliente,mes);
return Nexiste;
}




GF InicializaGestFil() {
    int k;
    GF res = (GF)malloc(sizeof (struct GestFil));
    
    for(k=0;k<26;k++){
    	res->avlProdutos[k] = createTreeP();
	   	res->avlClientes[k] = createTreeC();

    }   
    
    return res;
}


/*
Insere na Avl de Produtos
*/
void insereAvlProd(GF c,char *cod,int quantidade,int mes,char tipo, int filial){
    int j=26;
    AvlP node;
    if (cod[0]>=97 && cod[0]<=123) 
        j = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            j = ((int)cod[0])-65;

    if(existeFP(cod, c-> avlProdutos[j])== 0){
            node = createNodeP(cod,quantidade,mes,tipo,filial);
            avl_insertP(c -> avlProdutos[j], node);
           
    }else{

      avl_actualizaP(cod,c->avlProdutos[j],quantidade,mes,tipo,filial);
      
    }
    
}

/*Insere na avl de clientes*/

void insereCli(GF c,char *cod,char* prod,int quantidade,int mes,char tipo, int filial){
    int j=26;
    AvlC node;
    if (cod[0]>=97 && cod[0]<=123) 
        j = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            j = ((int)cod[0])-65;

     node = createNodeC(cod,NULL,quantidade,mes,tipo,filial);
     avl_insertC(c -> avlClientes[j], node);  
}


/*
Insere na Avl de Clientes
*/
void insereAvlCli(GF c,char *cod,char* prod,int quantidade,int mes,char tipo, int filial){
    int j=26;
    AvlC node;
    if (cod[0]>=97 && cod[0]<=123) 
        j = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            j = ((int)cod[0])-65;

      avl_actualizaC(cod,prod,c->avlClientes[j],quantidade,mes,tipo,filial);
      
    
}
