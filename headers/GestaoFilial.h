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
ConjProdsGF percorreClientes9(GF gf, int mes, char* cod);
ConjClisGF percorreClientes11(GF gf, char* cod);
int percorreClientes12(GF gf);


ConjProdsGF InicializaConjProdsGF();
ConjProdsGF nProdutosMaisVendidosF1(GF gf, int N, int unidadesVendidas[]);
ConjProdsGF nProdutosMaisVendidosF2(GF gf, int N, int unidadesVendidas[]);
ConjProdsGF nProdutosMaisVendidosF3(GF gf, int N, int unidadesVendidas[]);
char* retornaLista(ConjProdsGF cp, int i);
int retornaUnidades(ConjProdsGF cp, int i);
int retornaTamanhoConjProdsGF(ConjProdsGF cp);

GF InicializaGestFil();
int retornaTamanhoConjClisGF(ConjClisGF cc);
char* retornaElementoConjClisGF(ConjClisGF cc,int i);
void insereAvlProd(GF c,char *cod,int quantidade,double preco, int mes,char tipo, int filial);
void insereAvlCli(GF c,char *cod, char* prod,int quantidade,double preco,int mes,char tipo, int filial);
int CalculaTotais(GF gf,char *cod,int *mes);
void insereCli(GF c,char *cod,char* prod,int quantidade,double preco,int mes,char tipo, int filial);
#endif
