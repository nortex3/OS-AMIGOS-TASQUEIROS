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

void querie6(char c){
	int i;
	ConjProds prods = (toArrayProdutos(pro,c));
	
	for (i=0;i<(prods.tamanho);i++)
	{
		printf("%s\n",prods.lista[i]);
	}
	printf("%i\n",prods.tamanho);
}


