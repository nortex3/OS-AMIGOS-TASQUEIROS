#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "interface.h"

void printInicializar();

extern Clientes cli;
extern Produtos pro;
extern FaturacaoGlobal fg;
extern GF gf;

static int initCli = 0;
static int initPro = 0;
static int initVendas = 0;

void interfaceMain(){
	int menu = 1;
	printf("\033c");
	while(menu!=0){
		menu = printMenu();
	}
}

void imprimirMenu();

int printMenu(){
	int r = 0, n = 0;
	char c = '0';

	printf("################## GEREVENDAS ##################\n"
		   "# 1. Inicializar estruturas.                   #\n"
		   "# 2. Imprimir estruturas.                      #\n"
		   "# 0. Sair                                      #\n"
		   "################################################\n"
		   ">");

	n = scanf("%d",&r);
	c = getchar();
	if(n > 0){
		switch(r){
			case 1:
				printf("\033c");
				inicializarMenu();
				break;
			case 2:
				break;
			case 0:
				printf("Programa terminado com sucesso.\n");
				r = 0;
				break;
			default:
				printf("\033c");
				printf("Não inseriu nenhum número.\n");
				printMenu();
		}
	}
	else{
		printf("%c\n", c);
		printf("\033c");
		printf("Não inseriu nenhum número.\n");
		printMenu();
	}
	return 0;
}

void inicializarMenu(){
	int r = 0, n = 0;
	char c = '0';

	printInicializar();
	n = scanf("%d",&r);
	c = getchar();
	if(n > 0){
		switch(r){
			case 1:
				printf("\033c");
				cli = InicializaClientes();
				gf = InicializaGestFil();
				leituraCli(cli, gf, "Clientes.txt");
				initCli = 1;
				inicializarMenu();
				break;
			case 2:
				printf("\033c");
				fg = InicializaTotalProdutos();
				pro = InicializaProdutos();
				leituraPro(fg, pro, "Produtos.txt");
				initPro = 1;
				inicializarMenu();
				break;
			case 3:
				if(initCli == 0 || initPro == 0){
					printf("\033c");
					printf("Tem que inicializar clientes e produtos primeiro.\n");
					inicializarMenu();					
				}
				else{
					leituraVendas(gf, fg, pro, cli, "Vendas_1M.txt");
					initVendas = 1;
					inicializarMenu();
				}
				break;
			case 0:
				printf("\033c");
				printMenu();
				r = 0;
				break;
			default:
				printf("\033c");
				printf("Não inseriu nenhum número.\n");
				inicializarMenu();
		}
	}
	else{
		printf("%c\n", c);
		printf("\033c");
		printf("Não inseriu nenhum número.\n");
		inicializarMenu();
	}

}

void printInicializar(){
	if(initPro == 1 && initCli == 1 && initVendas == 1){
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Reinicializar clientes.                   #\n"
			   "# 2. Reinicializar produtos.                   #\n"
			   "# 3. Reinicializar vendas.                     #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
		
	}
	else if(initPro == 1 && initCli == 1){
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Reinicializar clientes.                   #\n"
			   "# 2. Reinicializar produtos.                   #\n"
			   "# 3. Inicializar vendas.                       #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
	}
	else if(initPro == 1){
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Inicializar clientes.                     #\n"
			   "# 2. Reinicializar produtos.                   #\n"
			   "# 3. Inicializar vendas. (Não disponivel)      #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
		
	}
	else if(initCli == 1){
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Reinicializar clientes.                   #\n"
			   "# 2. Inicializar produtos.                     #\n"
			   "# 3. Inicializar vendas. (Não disponivel)      #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
	}
	else{
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Inicializar clientes.                     #\n"
			   "# 2. Inicializar produtos.                     #\n"
			   "# 3. Inicializar vendas. (Não disponivel)      #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
	}

}
