#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/interface.h"
#include "headers/CatalogoProdutos.h"
#include "headers/CatalogoClientes.h"
#include "headers/Faturacao.h"
#include "headers/GestaoFilial.h"
#include "headers/avlF.h"
#include "headers/avl.h"
#include "headers/avlFilial.h"
#include "headers/leitura.h"
#include "headers/queries.h"


void printInicializar();
void imprimirMenu();
void inicializarMenu();
int printMenu();

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
				printf("\033c");
				imprimirMenu();
				break;
			case 0:
				printf("Programa terminado com sucesso.\n");
				return r;
				break;
			default:
				printf("\033c");
				printf("Opção inválida.\n");
				printMenu();
		}
	}
	else{
		printf("%c\n", c);
		printf("\033c");
		printf("Opção inválida.\n");
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
				querie1Clientes();
				initCli = 1;
				inicializarMenu();
				break;
			case 2:
				printf("\033c");
				querie1Produtos();
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
					querie1Vendas();
					initVendas = 1;
					inicializarMenu();
				}
				break;
			case 4:
				querie1Clientes();
				initCli = 1;
				querie1Produtos();
				initPro = 1;
				querie1Vendas();
				initVendas = 1;
				inicializarMenu();
				break;
			case 0:
				printf("\033c");
				printMenu();
				r = 0;
				break;
			default:
				printf("\033c");
				printf("Opção inválida.\n");
				inicializarMenu();
		}
	}
	else{
		printf("%c\n", c);
		printf("\033c");
		printf("Opção inválida.\n");
		inicializarMenu();
	}

}

void imprimirMenu(){
	int r = 0, n = 0, i = 0;
	char c = '0';

	printf("################## GEREVENDAS ##################\n"
		   "# 1. Imprimir clientes.                        #\n"
		   "# 2. Imprimir produtos.                        #\n"
		   "# 0. Voltar ao menu inicial.                   #\n"
		   "################################################\n"
		   ">");
	n = scanf("%d",&r);
	c = getchar();
	if(n > 0){
		switch(r){
			case 1:
				if(initCli == 1){
					printf("Insira uma letra maiúscula: ");
					i = scanf("%c",&c);
                    if(i > 0){
                         if (c>=64 && c<=90){
					         querie2(c);
                         }
                         else{
                                printf("\033c");
                                printf("Letra inválida.\n");
                            }
                       }
                    }
				else{
					printf("\033c");
					printf("Clientes não inicializados.\n");
				}
				imprimirMenu();
				break;
			case 2:
				if(initPro == 1){
					printf("Insira uma letra maiúscula: ");
					i = scanf("%c",&c);
					if(i > 0){
                         if (c>=64 && c<=90){
					         querie6(c);
                         }
                         else{
                                printf("\033c");
                                printf("Letra inválida.\n");
                            }
                       }
                }
                else{
					printf("\033c");
					printf("Produtos não inicializados.\n");
				}
				imprimirMenu();
				break;
			case 0:
				printMenu();
				break;
			default:
				printf("\033c");
				printf("Opção inválida.\n");
				imprimirMenu();
		}
	}
	else{
		printf("%c\n", c);
		printf("\033c");
		printf("Opção inválida.\n");
		imprimirMenu();
	}
}

void printInicializar(){
	if(initPro == 1 && initCli == 1 && initVendas == 1){
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Reinicializar clientes.                   #\n"
			   "# 2. Reinicializar produtos.                   #\n"
			   "# 3. Reinicializar vendas.                     #\n"
			   "# 4. Reinicializar tudo.                       #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
		
	}
	else if(initPro == 1 && initCli == 1){
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Reinicializar clientes.                   #\n"
			   "# 2. Reinicializar produtos.                   #\n"
			   "# 3. Inicializar vendas.                       #\n"
			   "# 4. Inicializar tudo.                         #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
	}
	else if(initPro == 1){
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Inicializar clientes.                     #\n"
			   "# 2. Reinicializar produtos.                   #\n"
			   "# 3. Inicializar vendas. (Não disponivel)      #\n"
			   "# 4. Inicializar tudo.                         #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
		
	}
	else if(initCli == 1){
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Reinicializar clientes.                   #\n"
			   "# 2. Inicializar produtos.                     #\n"
			   "# 3. Inicializar vendas. (Não disponivel)      #\n"
			   "# 4. Inicializar tudo.                         #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
	}
	else{
		printf("################## GEREVENDAS ##################\n"
			   "# 1. Inicializar clientes.                     #\n"
			   "# 2. Inicializar produtos.                     #\n"
			   "# 3. Inicializar vendas. (Não disponivel)      #\n"
			   "# 4. Inicializar tudo.                         #\n"
			   "# 0. Voltar ao menu inicial.                   #\n"
			   "################################################\n"
			   ">");
	}

}



