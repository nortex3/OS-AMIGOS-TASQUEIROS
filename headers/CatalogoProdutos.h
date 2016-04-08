#ifndef _CATALOGOPRODUTOS_H
#define _CATALOGOPRODUTOS_H

typedef struct produtos* Produtos;
typedef struct conjProds {
	char** lista;
	int tamanho;
}ConjProds;

Produtos InicializaProdutos();
void insereAVLProdutos(Produtos p,char *cod);
int VeTotalP(Produtos p);
int ExisteProduto(char* cod, Produtos p);
ConjProds toArrayProdutos(Produtos pro, char c);

#endif
