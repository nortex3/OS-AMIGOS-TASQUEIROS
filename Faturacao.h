#ifndef _Faturacao_H
#define _Faturacao_H

typedef struct FatGlobal* FaturacaoGlobal;

FaturacaoGlobal InicializaTotalProdutos();
void insereAvlFaturacao(FaturacaoGlobal c,char *cod, double preco,int quantidade,int mes,char tipo);
int VeTotalFG(FaturacaoGlobal p);
double totaldoproduto(FaturacaoGlobal p);
#endif
