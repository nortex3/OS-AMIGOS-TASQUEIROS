#ifndef _Faturacao_H
#define _Faturacao_H

typedef struct FatGlobal* FaturacaoGlobal;

FaturacaoGlobal InicializaTotalProdutos();
void insereAvlFaturacao(FaturacaoGlobal c,char *cod, double preco,int quantidade,int mes,char tipo,int filial);
int VeTotalFG(FaturacaoGlobal p);
double totaldoproduto(FaturacaoGlobal p);
int TotalVendasTotalFaturadoGlobal(FaturacaoGlobal fg,int mes, char* cod,double array[],int modo );
void  CalculaTotalVendasEFaturado(FaturacaoGlobal fg,int mesi,int mesf,double res[]);

#endif
