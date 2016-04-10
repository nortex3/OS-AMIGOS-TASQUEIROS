#ifndef _GESTAOFILIAL_H
#define _GESTAOFILIAL_H

typedef struct GestFil* GF;

GF InicializaGestFil();
void insereAvlProd(GF c,char *cod,int quantidade,int mes,char tipo, int filial);
void insereAvlCli(GF c,char *cod, char* prod,int quantidade,int mes,char tipo, int filial);
int CalculaTotais(GF gf,char *cod,int *mes);
void insereCli(GF c,char *cod,char* prod,int quantidade,int mes,char tipo, int filial);
#endif
