#ifndef _GESTAOFILIAL_H
#define _GESTAOFILIAL_H

typedef struct conjClisGF* ConjClisGF;
typedef struct GestFil* GF;

ConjClisGF InicializaConjClisGF();
int retornaTamanhoConjClisGF(ConjClisGF cc);
char* retornaElementoConjClisGF(ConjClisGF cc,int i);
ConjClisGF percorreClientes(GF gf);
ConjClisGF percorreClientes9(GF gf, int mes, char* cod);
GF InicializaGestFil();
int retornaTamanhoConjClisGF(ConjClisGF cc);
char* retornaElementoConjClisGF(ConjClisGF cc,int i);
void insereAvlProd(GF c,char *cod,int quantidade,int mes,char tipo, int filial);
void insereAvlCli(GF c,char *cod, char* prod,int quantidade,int mes,char tipo, int filial);
int CalculaTotais(GF gf,char *cod,int *mes);
void insereCli(GF c,char *cod,char* prod,int quantidade,int mes,char tipo, int filial);
#endif
