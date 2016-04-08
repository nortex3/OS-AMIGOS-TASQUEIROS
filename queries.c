#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/CatalogoProdutos.h"
#include "headers/CatalogoClientes.h"
#include "headers/Faturacao.h"
#include "headers/GestaoFilial.h"
#include "headers/avlF.h"
#include "headers/avl.h"
#include "headers/avlFilial.h"
#include "headers/leitura.h"

extern Clientes cli;
extern Produtos pro;
extern FaturacaoGlobal fg;
extern GF gf;
extern ConjProds prods;

void querie1Clientes(){
	cli = InicializaClientes();
	gf = InicializaGestFil();
	leituraCli(cli, gf, "Clientes.txt");
}

void querie1Produtos(){
	fg = InicializaTotalProdutos();
	pro = InicializaProdutos();
	leituraPro(fg, pro, "Produtos.txt");
}

void querie1Vendas(){
	leituraVendas(gf, fg, pro, cli, "Vendas_1M.txt");
}

void querie2(char c){
    int i;
    ConjClientes clientes = toArrayClientes(cli, c);
    for (i=0;i<(clientes.tamanho);i++)
	{
		printf("%s\n",clientes.lista[i]);
	}
     printf("%i\n",clientes.tamanho);

}

void querie3(int mes,char* codPro,int modo){

	double res[4];
	TotalVendasTotalFaturadoGlobal(fg,mes, codPro,res);
	printf("Total vendas em modo promoção: %f\n",res[0] );
	printf("Total vendas em modo normal: %f\n",res[1] );
	printf("Total faturado em modo promoção: %f\n",res[2] );
	printf("Total faturado em modo normal: %f\n",res[3] );



}
void querie4(){}
void querie5(char *s){}
void querie6(int mesi,int mesf){}
void querie7(){}
void querie8(char* s,int filial){}
void querie9(char* s,int filial){}
void querie10(){}
void querie11(char *s){}
void querie12(){}
/*
void querie6(char c){
	int i;
	ConjProds prods = (toArrayProdutos(pro,c));
	
	for (i=0;i<(prods.tamanho);i++)
	{
		printf("%s\n",prods.lista[i]);
	}
	printf("%i\n",prods.tamanho);
}*/


