#ifndef _GESTAOFILIAL_H
#define _GESTAOFILIAL_H

typedef struct conjProdsGF* ConjProdsGF;
typedef struct conjClisGF* ConjClisGF;
typedef struct GestFil* GF;

ConjClisGF InicializaConjClisGF();
int retornaTamanhoConjClisGF(ConjClisGF cc);
char* retornaElementoConjClisGF(ConjClisGF cc,int i);
ConjClisGF percorreClientes(GF gf);
ConjClisGF percorreClientes8(GF gf, char* cod,int filia,char tipo);
ConjClisGF percorreClientes9(GF gf, int mes, char* cod);
ConjClisGF percorreClientes11(GF gf, char* cod);

ConjProdsGF nProdutosMaisVendidos(GF gf, int N);
char* retornaListaF1(ConjProdsGF cp, int i);
int retornaUnidadesF1(ConjProdsGF cp, int i);

GF InicializaGestFil();
int retornaTamanhoConjClisGF(ConjClisGF cc);
char* retornaElementoConjClisGF(ConjClisGF cc,int i);
void insereAvlProd(GF c,char *cod,int quantidade,double preco, int mes,char tipo, int filial);
void insereAvlCli(GF c,char *cod, char* prod,int quantidade,double preco,int mes,char tipo, int filial);
int CalculaTotais(GF gf,char *cod,int *mes);
void insereCli(GF c,char *cod,char* prod,int quantidade,double preco,int mes,char tipo, int filial);
#endif
