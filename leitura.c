#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "headers/CatalogoProdutos.h"
#include "headers/CatalogoClientes.h"
#include "headers/Faturacao.h"
#include "headers/GestaoFilial.h"
#include "headers/avl.h"
#include "headers/avlF.h"
#include "headers/avlFilial.h"
#include "headers/leitura.h"

struct leitura{
    int linhasM;
    int linhasB;
    int linhasLidas;
    char* nomeFile;
};

Leitura inicializaLeitura(){
    Leitura tmp = (Leitura)malloc(sizeof(struct leitura));
    tmp->linhasM = 0;
    tmp->linhasB = 0;
    tmp->linhasLidas = 0;
    tmp->nomeFile=NULL;
    return tmp;
}

Leitura leituraPro(FaturacaoGlobal fb,Produtos pro, char* filename) {
    Leitura tmp = inicializaLeitura();
    char linha[10];
    char *tok;
   
    FILE* file = fopen(filename, "r");
    tmp->nomeFile = strdup(filename);
    if (file) {
        while (fgets(linha, 10, file)) {

            tok = strtok(linha, "\r\n");
            if(strlen(tok)==6 && isalpha(tok[0]) && isalpha(tok[1])&& isdigit(tok[2])&& isdigit(tok[3])&& isdigit(tok[4]) && isdigit(tok[5])){
            	insereAVLProdutos(pro,tok);
                insereAvlFaturacao(fb,tok,0.0,0,0,'A',0);
                tmp->linhasB++;
            } else tmp->linhasM++;
            
            tmp->linhasLidas++;

        }
    fclose(file);
    }
    return tmp;

}

Leitura leituraCli(Clientes cl,GF gf , char* filename) {
    Leitura tmp = inicializaLeitura();
    char linha[10];
    char *tok;
    
    FILE* file = fopen(filename, "r");
    tmp->nomeFile = strdup(filename);
    if (file) {
        while (fgets(linha, 10, file)) {

            tok = strtok(linha, "\r\n");
            if(strlen(tok)==5 && isalpha(tok[0]) && isdigit(tok[1])&& isdigit(tok[2])&& isdigit(tok[3])&& isdigit(tok[4])){
                insereAvlClientes(cl,tok);
                insereCli(gf,tok,NULL,0,0,'A',0);
                tmp->linhasB++;
            }else tmp->linhasM++;
            
            tmp->linhasLidas++;

        }
        fclose(file);
    }
    return tmp;

}


/* LEITURA QUE VERIFICAVA AS LINHAS VALIDAS */
Leitura leituraVendas(GF gf,FaturacaoGlobal fb, Produtos p, Clientes c, char *filename){
    Leitura tmp = inicializaLeitura();

    FILE* file = fopen(filename, "r");
    tmp->nomeFile = strdup(filename);
    char *linha=malloc(32*sizeof(char*));
    char *produto, *cliente, *PouN;
    float preco;
    int unidades, mes, filial;
    int erro=0;
    char *linhaValida=malloc(32*sizeof(char*));

    if (file) {
       while (fgets(linha, 32, file)) {
            strcpy(linhaValida,linha); 
            erro=0;

            produto = strtok(linha, " ");
            if(ExisteProduto(produto,p)==0)erro=1;
          
            preco=atof(strtok(NULL, " "));
            if(preco<0||erro==1) erro=1;

            unidades=atoi(strtok(NULL, " "));
            if(unidades<0 || erro==1) erro =1;

            PouN = strtok(NULL, " ");
            if(!(strcmp(PouN,"P") || strcmp(PouN,"N")) || erro ==1)erro=1;

            cliente = strtok(NULL, " ");
            if(ExisteCliente(cliente,c)==0 || erro==1) erro=1;

            mes= atoi(strtok(NULL, " "));
            if(mes<1 || mes>12 || erro==1) erro =1;

            filial=atoi(strtok(NULL, "\r\n"));
            if(filial<1 || filial>3 || erro ==1) erro=1;


            if(erro==0){
                insereAvlFaturacao(fb,produto,preco,unidades,mes,PouN[0],filial);
                insereAvlCli(gf,cliente,produto,unidades,mes,PouN[0], filial);
                tmp->linhasB++;;

            }else tmp->linhasM++;

            tmp->linhasLidas++;
        }
        fclose(file);
    }
    return tmp;
}

int getLinhasLidas(Leitura ler){
    int r = ler->linhasLidas;
    return r;
}

int getLinhasMal(Leitura ler){
    int r = ler->linhasM;
    return r;
}

int getLinhasBem(Leitura ler){
    int r = ler->linhasB;
    return r;
}

char* getNomeFile(Leitura ler){
   return ler->nomeFile;
}