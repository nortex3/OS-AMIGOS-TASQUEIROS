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
	free(cli);
	free(gf);
	Leitura ler = inicializaLeitura();
	cli = InicializaClientes();
	gf = InicializaGestFil();
	ler = leituraCli(cli, gf, "Clientes.txt");
	printf("Nome do ficheiro: %s\n"
		   " Número de linhas lidas: %d\n"
		   " Número de linhas correctas: %d\n"
		   " Número de linhas erradas: %d\n",getNomeFile(ler), getLinhasLidas(ler), getLinhasBem(ler), getLinhasMal(ler));
	free(ler);
}

void querie1Produtos(){
	free(fg);
	free(pro);
	Leitura ler = inicializaLeitura();
	fg = InicializaTotalProdutos();
	pro = InicializaProdutos();
	ler = leituraPro(fg, pro, "Produtos.txt");
	printf("Nome do ficheiro: %s\n"
		   " Número de linhas lidas: %d\n"
		   " Número de linhas correctas: %d\n"
		   " Número de linhas erradas: %d\n",getNomeFile(ler), getLinhasLidas(ler), getLinhasBem(ler), getLinhasMal(ler));
	free(ler);
}

void querie1Vendas(){
	Leitura ler = inicializaLeitura();
	ler = leituraVendas(gf, fg, pro, cli, "Vendas_1M.txt");
	printf("Nome do ficheiro: %s\n"
		   " Número de linhas lidas: %d\n"
		   " Número de linhas correctas: %d\n"
		   " Número de linhas erradas: %d\n",getNomeFile(ler), getLinhasLidas(ler), getLinhasBem(ler), getLinhasMal(ler));
	free(ler);
}

void querie2(char c){
    int aux = 0;
    ConjProds prods = toArrayProdutos(pro, c);
	printf("\033c");
    printQuerie2(prods, aux, aux);
}


void querie3(int mes,char* codPro,int modo){

	double res[4];
	double resF[12];
	int r=0;
	if(modo==1){
		r=TotalVendasTotalFaturadoGlobal(fg,mes, codPro,res,modo);
		if(r==1) printf("Codigo Inexistente\n");
		else{
		printf("Total vendas em modo promoção: %d\n",(int)res[0] );
		printf("Total vendas em modo normal: %d\n",(int)res[1] );
		printf("Total faturado em modo promoção: %f\n",res[2] );
		printf("Total faturado em modo normal: %f\n",res[3] );
	}
	}else{

		r=TotalVendasTotalFaturadoGlobal(fg,mes, codPro,resF,modo);
		if(r==1) printf("Codigo Inexistente\n");
		else{
		printf("-----------------Filial 1------------------------\n");

		printf("Total vendas em modo promoção na filial1: %d\n",(int)resF[0] );
		printf("Total vendas em modo normal na filial1: %d\n",(int)resF[1] );
		printf("Total faturado em modo promoção na filial1: %f\n",resF[6] );
		printf("Total faturado em modo normal na filial1: %f\n\n",resF[7] );
		printf("-----------------Filial 2------------------------\n");
		printf("Total vendas em modo promoção na filial2: %d\n",(int)resF[2] );
		printf("Total vendas em modo normal na filial2: %d\n",(int)resF[3] );
		printf("Total faturado em modo promoção na filial2: %f\n",resF[8] );
		printf("Total faturado em modo normal na filial2: %f\n\n",resF[9] );

		printf("-----------------Filial 3------------------------\n");

		printf("Total vendas em modo promoção na filial3: %d\n",(int)resF[5] );
		printf("Total vendas em modo normal na filial3: %d\n",(int)resF[6] );
		printf("Total faturado em modo promoção na filial3: %f\n",resF[10] );
		printf("Total faturado em modo normal na filial3: %f\n",resF[11] );
	}
}


}
void querie4(){}
void querie5(char *s){
	//int tot[36][3];
	//int **tot=NULL;
	int mes[36];
	int i=0,j=0;

	for(i=0;i<36;i++){
		mes[i]=0;
	}

	CalculaTotais(gf,s,mes);
	printf("######################################################\n");
	printf("##     Mês          |    Total        | 	Filial  ##\n");
	printf("######################################################\n");
	printf("##      1           |     %d          |       %d    ##\n",mes[0],1);
	printf("##      1           |     %d          |       %d    ##\n",mes[1],2);
	printf("##      1           |     %d          |       %d    ##\n",mes[2],3);
	printf("##      2           |     %d          |       %d    ##\n",mes[3],1);
	printf("##      2           |     %d          |       %d    ##\n",mes[4],2);
	printf("##      2           |     %d          |       %d    ##\n",mes[5],3);
	printf("##      3           |     %d          |       %d    ##\n",mes[6],1);
	printf("##      3           |     %d          |       %d    ##\n",mes[7],2);
	printf("##      3           |     %d          |       %d    ##\n",mes[8],3);
	printf("##      4           |     %d          |       %d    ##\n",mes[9],1);
	printf("##      4           |     %d          |       %d    ##\n",mes[10],2);
	printf("##      4           |     %d          |       %d    ##\n",mes[11],3);
	printf("##      5           |     %d          |       %d    ##\n",mes[12],1);
	printf("##      5           |     %d          |       %d    ##\n",mes[13],2);
	printf("##      5           |     %d          |       %d    ##\n",mes[14],3);
	printf("##      6           |     %d          |       %d    ##\n",mes[15],1);
	printf("##      6           |     %d          |       %d    ##\n",mes[16],2);
	printf("##      6           |     %d          |       %d    ##\n",mes[17],3);
	printf("##      7           |     %d          |       %d    ##\n",mes[18],1);
	printf("##      7           |     %d          |       %d    ##\n",mes[19],2);
	printf("##      7           |     %d          |       %d    ##\n",mes[20],3);
	printf("##      8           |     %d          |       %d    ##\n",mes[21],1);
	printf("##      8           |     %d          |       %d    ##\n",mes[22],2);
	printf("##      8           |     %d          |       %d    ##\n",mes[23],3);
	printf("##      9           |     %d          |       %d    ##\n",mes[24],1);
	printf("##      9           |     %d          |       %d    ##\n",mes[25],2);
	printf("##      9           |     %d          |       %d    ##\n",mes[26],3);
	printf("##     10           |     %d          |       %d    ##\n",mes[27],1);
	printf("##     10           |     %d          |       %d    ##\n",mes[28],2);
	printf("##     10           |     %d          |       %d    ##\n",mes[29],3);
	printf("##     11           |     %d          |       %d    ##\n",mes[30],1);
	printf("##     11           |     %d          |       %d    ##\n",mes[31],2);
	printf("##     11           |     %d          |       %d    ##\n",mes[32],3);
	printf("##     12           |     %d          |       %d    ##\n",mes[33],1);
	printf("##     12           |     %d          |       %d    ##\n",mes[34],2);
	printf("##     12           |     %d          |       %d    ##\n",mes[35],3);	
	printf("######################################################\n");

}

void querie6(int mesi,int mesf){
	double res[2];
	CalculaTotalVendasEFaturado(fg,mesi,mesf,res);
	printf("Total de vendas, entre mês %d e mês %d : %d\n",mesi, mesf,(int)res[0] );
	printf("Total faturado, entre mês %d e mês %d : %f\n",mesi, mesf,res[1] );


}

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
    for (i=0;i < 20 && index < retornaTamanhoPro(prods); i++){
			printf("# %s                                       #\n",retornaElementoPro(prods,index));
			contador++;
			index++;
	}
	printf("################################################\n");
	printf("# Número de linhas começadas por '%c': %d     #\n",retornaPrimeiraLetraPro(prods,0), retornaTamanhoPro(prods));
	printf("################################################\n");
	printf("# 1. Continuar.                                #\n");
	printf("# 2. Retroceder.                               #\n");
	printf("# 0. Sair.                                     #\n");
	printf("################################################\n");
	printf(">");
	n = scanf("%d",&c);
	if(n > 0){
		if(c == 1 && contador != retornaTamanhoPro(prods)){
			printf("\033c");
			printQuerie2(prods, contador, index++);
		}
		else if(c == 1 && contador == retornaTamanhoPro(prods)){
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
    for (i=0;i < 20 && index < retornaTamanho(clientes); i++){
			printf("# %s                                        #\n",retornaElemento(clientes,index));
			contador++;
			index++;
	}
	printf("################################################\n");
	printf("# Número de linhas começadas por '%c': %d      #\n",retornaPrimeiraLetra(clientes,1), retornaTamanho(clientes));
	printf("################################################\n");
	printf("# 1. Continuar.                                #\n");
	printf("# 2. Retroceder.                               #\n");
	printf("# 0. Sair.                                     #\n");
	printf("################################################\n");
	printf(">");
	n = scanf("%d",&c);
	if(n > 0){
		if(c == 1 && contador != retornaTamanho(clientes)){
			printf("\033c");
			printClientesAux(clientes, contador, index++);
		}
		else if(c == 1 && contador == retornaTamanho(clientes)){
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

