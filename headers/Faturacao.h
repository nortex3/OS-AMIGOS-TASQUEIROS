#ifndef _Faturacao_H
#define _Faturacao_H

typedef struct FatGlobal* FaturacaoGlobal;
typedef struct conjProdsF* ConjProdsF;

FaturacaoGlobal InicializaTotalProdutos();
ConjProdsF InicializaConjProdsF();
int retornaTamanhoProF(ConjProdsF cc);
char* retornaElementoProF(ConjProdsF cc,int i);
char retornaPrimeiraLetraProF(ConjProdsF cc,int i);
void insereAvlFaturacao(FaturacaoGlobal c,char *cod, double preco,int quantidade,int mes,char tipo,int filial);
int VeTotalFG(FaturacaoGlobal p);
double totaldoproduto(FaturacaoGlobal p);
int TotalVendasTotalFaturadoGlobal(FaturacaoGlobal fg,int mes, char* cod,double array[],int modo );
void  CalculaTotalVendasEFaturado(FaturacaoGlobal fg,int mesi,int mesf,double res[]);
ConjProdsF toArrayProdutosNaoVendidos(FaturacaoGlobal pro);
ConjProdsF toArrayProdutosNaoVendidosF1(FaturacaoGlobal pro);
ConjProdsF toArrayProdutosNaoVendidosF2(FaturacaoGlobal pro);
ConjProdsF toArrayProdutosNaoVendidosF3(FaturacaoGlobal pro);

#endif
