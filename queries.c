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

void printQuerie2(ConjProds prods, int contador, int index);
void printClientesAux(ConjClientes clientes, int contador, int index);

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
    int aux = 0;
    ConjProds prods = toArrayProdutos(pro, c);
	printf("\033c");
    printQuerie2(prods, aux, aux);
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

void printQuerie2(ConjProds prods, int contador, int index){
	int n = 0, i,c = 0;

	printf("################## GEREVENDAS ##################\n");
    for (i=0;i < 20 && index < prods.tamanho; i++){
			printf("# %s                                       #\n",prods.lista[index]);
			contador++;
			index++;
	}
	printf("################################################\n");
	printf("# Número de linhas começadas por '%c': %d     #\n",prods.lista[0][0], prods.tamanho);
	printf("################################################\n");
	printf("# 1. Continuar.                                #\n");
	printf("# 2. Retroceder.                               #\n");
	printf("# 0. Sair.                                     #\n");
	printf("################################################\n");
	printf(">");
	n = scanf("%d",&c);
	if(n > 0){
		if(c == 1 && contador != prods.tamanho){
			printf("\033c");
			printQuerie2(prods, contador, index++);
		}
		else if(c == 1 && contador == prods.tamanho){
			printf("\033c");
			printf("Impossível continuar.\n");
			printQuerie2(prods, contador-20, index-20);
		}
		else if(c == 2 && (contador-40) >= 0){
			printf("\033c");
			printQuerie2(prods, contador-40, index-40);
		}
		else if(c == 2 && (contador-40) <= 0){
			printf("\033c");
			printf("Impossível retroceder.\n");
			printQuerie2(prods, contador-20, index-20);
		}
		else if(c == 0){
			printf("\033c");
		}
		else{
			printf("\033c");
			printf("Comando inválido\n");
			printQuerie2(prods, contador-20, index-20);
		}
	}
}

void printClientes(char c){
    int aux = 0;
    ConjClientes clientes = toArrayClientes(cli, c);
	printf("\033c");
    printClientesAux(clientes, aux, aux);
}

void printClientesAux(ConjClientes clientes, int contador, int index){
	int n = 0, i,c = 0;

	printf("################## GEREVENDAS ##################\n");
    for (i=0;i < 20 && index < clientes.tamanho; i++){
			printf("# %s                                        #\n",clientes.lista[index]);
			contador++;
			index++;
	}
	printf("################################################\n");
	printf("# Número de linhas começadas por '%c': %d      #\n",clientes.lista[0][0], clientes.tamanho);
	printf("################################################\n");
	printf("# 1. Continuar.                                #\n");
	printf("# 2. Retroceder.                               #\n");
	printf("# 0. Sair.                                     #\n");
	printf("################################################\n");
	printf(">");
	n = scanf("%d",&c);
	if(n > 0){
		if(c == 1 && contador != clientes.tamanho){
			printf("\033c");
			printClientesAux(clientes, contador, index++);
		}
		else if(c == 1 && contador == clientes.tamanho){
			printf("\033c");
			printf("Impossível continuar.\n");
			printClientesAux(clientes, contador-20, index-20);
		}
		else if(c == 2 && (contador-40) >= 0){
			printf("\033c");
			printClientesAux(clientes, contador-40, index-40);
		}
		else if(c == 2 && (contador-40) <= 0){
			printf("\033c");
			printf("Impossível retroceder.\n");
			printClientesAux(clientes, contador-20, index-20);
		}
		else if(c == 0){
			printf("\033c");
		}
		else{
			printf("\033c");
			printf("Comando inválido\n");
			printClientesAux(clientes, contador-20, index-20);
		}
	}
}