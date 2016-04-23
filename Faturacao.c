#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/Faturacao.h"
#include "headers/avlF.h"

#define NORMAL 0
#define PROMO 1



struct FatGlobal {

    int TotalVendas[12][2];
    double TotalFaturado[12][2];
    Avl_tree avl_produtos[26];
};


struct conjProdsF {
	char** lista;
	int tamanho;
};


/* Relacionado com ConjProds*/

ConjProdsF InicializaConjProdsF(){
	ConjProdsF tmp = (ConjProdsF)malloc(sizeof(struct conjProdsF));
	tmp->lista=NULL;
	tmp->tamanho=0;
	return tmp;
}

int retornaTamanhoProF(ConjProdsF cc){
	return cc->tamanho;
}

char* retornaElementoProF(ConjProdsF cc,int i){

	return cc->lista[i];
}

char retornaPrimeiraLetraProF(ConjProdsF cc,int i){
	char *a= cc->lista[i];
	char r=a[0];
	return r;
}


/* Apoio Querie 3 */

int TotalVendasTotalFaturadoGlobal(FaturacaoGlobal fg,int mes, char* cod, double array[], int modo ){
    int j=26;
    Avl_tree pro;
    Avl a;
    int r=0;
    
    if (cod[0]>=97 && cod[0]<=123) 
        j = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            j = ((int)cod[0])-65;
    pro= fg->avl_produtos[j];
    a= procuraTree(pro,cod);
    if(a!=NULL){
        if(modo==1) RecolheInfoNodo(a,mes,array);
        else RecolheInfoNodoFilial(a,mes,array);
        
    }else r=1;
    return r;
}

/* Apoio Querie 6 */

void  CalculaTotalVendasEFaturado(FaturacaoGlobal fg,int mesi,int mesf,double res[]){
    int i;
    double totalfaturado=0.0;
    int totalvendas=0;
    for(i=(mesi-1);i<=(mesf-1);i++){
        totalvendas = fg->TotalVendas[i][PROMO] + fg->TotalVendas[i][NORMAL];
        totalfaturado = fg->TotalFaturado[i][PROMO] + fg->TotalFaturado[i][NORMAL];
        res[0]+=totalvendas;
        res[1]+=totalfaturado;
    }
}


/*---------------------------------------------*/

/* Apoio Querie 4 */

/* RESULTADOS GLOBAIS */

ConjProdsF toArrayProdutosNaoVendidos(FaturacaoGlobal pro){
   int index = 0,i=0, size=0;
   char** aux;
   char** aux2;
   Avl_tree a;
   Avl b;
   ConjProdsF produtos=InicializaConjProdsF();
   for(i=0;i<26;i++){
     a = pro -> avl_produtos[i];
     b = createCharNodeF(a);
     size=size+contaNodos(b);
   }
    aux=malloc(sizeof(char*)*size);
    for(i=0;i<26;i++){
    a = pro -> avl_produtos[i];
    b = createCharNodeF(a);
    index=toArrayProdutosAuxNaoVendidos(b, index, aux);    
   }
   aux2=malloc(sizeof(char*)*index); 
   memcpy(aux2,aux,sizeof(char*)*index);
   free(aux);
   produtos->lista=aux2;
   produtos->tamanho=index;
   free(aux2);
   return produtos;
}

/* RESULTADOS FILIAL 1*/

ConjProdsF toArrayProdutosNaoVendidosF1(FaturacaoGlobal pro){
   int index = 0,i=0, size=0;
   char** aux;
   char** aux2;
   Avl_tree a;
   Avl b;
   ConjProdsF produtos=InicializaConjProdsF();
   for(i=0;i<26;i++){
     a = pro -> avl_produtos[i];
     b = createCharNodeF(a);
     size=size+contaNodos(b);
   }
    aux=malloc(sizeof(char*)*size);
    for(i=0;i<26;i++){
    a = pro -> avl_produtos[i];
    b = createCharNodeF(a);
    index=toArrayProdutosAuxNaoVendidosF1(b, index, aux);    
   }
   aux2=malloc(sizeof(char*)*index); 
   memcpy(aux2,aux,sizeof(char*)*index);
   free(aux);
   produtos->lista=aux2;
   produtos->tamanho=index;
   free(aux2);
   return produtos;
}

/* RESULTADOS FILIAL 2*/

ConjProdsF toArrayProdutosNaoVendidosF2(FaturacaoGlobal pro){
   int index = 0,i=0, size=0;
   char** aux;
   char** aux2;
   Avl_tree a;
   Avl b;
   ConjProdsF produtos=InicializaConjProdsF();
   for(i=0;i<26;i++){
     a = pro -> avl_produtos[i];
     b = createCharNodeF(a);
     size=size+contaNodos(b);
   }
    aux=malloc(sizeof(char*)*size);
    for(i=0;i<26;i++){
    a = pro -> avl_produtos[i];
    b = createCharNodeF(a);
    index=toArrayProdutosAuxNaoVendidosF2(b, index, aux);    
   }
   aux2=malloc(sizeof(char*)*index); 
   memcpy(aux2,aux,sizeof(char*)*index);
   free(aux);
   produtos->lista=aux2;
   produtos->tamanho=index;
     free(aux2);
   return produtos;
}

/* RESULTADOS FILIAL 3*/

ConjProdsF toArrayProdutosNaoVendidosF3(FaturacaoGlobal pro){
   int index = 0,i=0, size=0;
   char** aux;
   char** aux2;
   Avl_tree a;
   Avl b;
   ConjProdsF produtos=InicializaConjProdsF();
   for(i=0;i<26;i++){
     a = pro -> avl_produtos[i];
     b = createCharNodeF(a);
     size=size+contaNodos(b);
   }
    aux=malloc(sizeof(char*)*size);
    for(i=0;i<26;i++){
    a = pro -> avl_produtos[i];
    b = createCharNodeF(a);
    index=toArrayProdutosAuxNaoVendidosF3(b, index, aux);    
   }
   aux2=malloc(sizeof(char*)*index); 
   memcpy(aux2,aux,sizeof(char*)*index);
   free(aux);
   produtos->lista=aux2;
   produtos->tamanho=index;
     free(aux2);
   return produtos;
}


/* Apoio Query 12 */


int percorreProdutos12(FaturacaoGlobal pro){
   int i, total=0;
    Avl produtos ;

    for(i=0;i<26;i++){
        produtos = createCharNodeF(pro->avl_produtos[i]);
        total=calculaNaoComprados(produtos,total);
    }
    return total;
}







/*------------------------------------------------*/

FaturacaoGlobal InicializaTotalProdutos() {
    int i, j,k;
    FaturacaoGlobal res = (FaturacaoGlobal) malloc(sizeof (struct FatGlobal));
    
    for(k=0;k<26;k++){

    	res->avl_produtos[k] = createTreeF();
    }    
    for (i = 0; i < 12; i++)
        for (j = 0; j < 2; j++){
            res->TotalVendas[i][j] = 0;
            res->TotalFaturado[i][j] = 0;
        }
    
    return res;
}


/*
Insere os produtos vendidos na Avl de Faturacao
*/
void insereAvlFaturacao(FaturacaoGlobal c,char *cod, double preco,int quantidade,int mes,char tipo, int filial){
    int j=26;
    Avl node;
    if (cod[0]>=97 && cod[0]<=123) 
        j = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            j = ((int)cod[0])-65;

    if(existeF(cod, c-> avl_produtos[j])== 0){
            node = createNodeF(cod,preco,quantidade,mes,tipo,filial);
            avl_insertF(c -> avl_produtos[j], node);
            if(tipo=='N'){
                c->TotalVendas[mes-1][NORMAL]+=quantidade;
                c->TotalFaturado[mes-1][NORMAL]+=quantidade*preco;
            
             }else{

                 c->TotalVendas[mes-1][PROMO]+=quantidade;
                 c->TotalFaturado[mes-1][PROMO]+=quantidade*preco;
            
            }
    }else{

        avl_actualiza(cod,c->avl_produtos[j],preco,quantidade,mes,tipo,filial);
        if(tipo=='N'){
                c->TotalVendas[mes-1][NORMAL]+=quantidade;
                c->TotalFaturado[mes-1][NORMAL]+=quantidade*preco;
            
             }else{

                 c->TotalVendas[mes-1][PROMO]+=quantidade;
                 c->TotalFaturado[mes-1][PROMO]+=quantidade*preco;
            
            }
    }
    
}

