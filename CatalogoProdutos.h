#ifndef _CATALOGOPRODUTOS_H
#define _CATALOGOPRODUTOS_H

typedef struct produtos* Produtos;

Produtos InicializaProdutos();
void insereAVLProdutos(Produtos p,char *cod);
int VeTotalP(Produtos p);
int ExisteProduto(char* cod, Produtos p);
#endif
