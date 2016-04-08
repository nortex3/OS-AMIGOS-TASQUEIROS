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

/* Funçoes de teste */

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


int VeTotalFG(FaturacaoGlobal p){

    int r=p->TotalVendas[1][1]; 
    return r;
}

double totaldoproduto(FaturacaoGlobal p){
    Avl_tree b = p->avl_produtos[13]; 
    double r;
    Avl a = procuraTree(b,"NR1091");
    r= total(a);
    return r;
}

/*---------------------------------------------*/


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

