#ifndef _CATALOGOPRODUTOS_H
#define _CATALOGOPRODUTOS_H

typedef struct produtos* Produtos;
typedef struct conjProds* ConjProds;


Produtos InicializaProdutos();
ConjProds InicializaConjProds();
void insereAVLProdutos(Produtos p,char *cod);
int VeTotalP(Produtos p);
int ExisteProduto(char* cod, Produtos p);
ConjProds toArrayProdutos(Produtos pro, char c);
int retornaTamanhoPro(ConjProds cc);
char retornaPrimeiraLetraPro(ConjProds cc,int i);
char* retornaElementoPro(ConjProds cc,int i);
#endif
