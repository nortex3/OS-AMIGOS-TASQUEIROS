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
void imprimirMenuQueries();
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
		   "# 3. Queries.                                  #\n"
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
			case 3:
				printf("\033c");
				imprimirMenuQueries();
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
					       /* querie6(c);*/
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



void imprimirMenuQueries(){
	int r = 0, n = 0;
	int mes=0;
	int mesI=0,mesF=0;
	int filial=0;
	int modo=0;
	char c = '0';
	char s[6];
	printf("################## GEREVENDAS ##################################################################\n"
		   "# 1.  Querie3 - Apresentar total vendas e faturado de um dado produto e mês.          	       #\n"
		   "# 2.  Querie4 - Lista de produtos que ninguém comprou.                                         #\n"
		   "# 3.  Querie5 - Cria tabela com produtos comprados por um dado cliente                         #\n"
		   "# 4.  Querie6 - Determina total de vendas e faturado num dado intervalo de meses.              #\n"
		   "# 5.  Querie7 - Lista de clientes que realizaram compras em todas as filiais.                  #\n"
		   "# 6.  Querie8 - Apresentar clientes que compraram um dado produto, numa filial especifica.     #\n"
		   "# 7.  Querie9 - Lista de clientes que mais compraram um dado produto, num dado mês.            #\n"
		   "# 8.  Querie10 - Listar os N produtos mais vendidos.                                           #\n"
		   "# 9.  Querie11 - Apresentar os 3 produtos em que um dado cliente gastou mais dinheiro          #\n"
		   "# 10. Querie12 - Número de clientes que não registaram compras, e produtos que ninguém comprou.#\n"
		   "# 0.  Voltar ao menu inicial.                												   #\n"
		   "################################################################################################\n"
		   ">");
	n = scanf("%d",&r);
	c = getchar();
	if(n > 0){
		switch(r){
			case 1:
				if(initPro == 1 || initVendas==1){
					printf("Insira um código de um produto: \n");
					scanf("%s",s);
					printf("Insira um mês: \n");
					scanf("%d",&mes);
				    printf("Insira 1 para resultados globais, Insira 2 para resultados filial a filial: \n");
				    scanf("%d",&modo);
					if(modo==1 ) {
						printf("%d\n",modo );
						querie3(mes,s,modo);}  
						else {
								printf("\033c");
								printf("Inseriu valor diferente 1 e 2.\n");
							}
				imprimirMenuQueries();     
                    }
				else{
					printf("\033c");
					printf("Produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 2:
				if(initPro == 1 || initVendas==1){
					querie4();                         
                }
                else{
					printf("\033c");
					printf("Produtos ou vendas não inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 3:
				if(initCli==1 || initPro == 1 || initVendas==1){
					printf("Insira um código de um cliente: \n");
					scanf("%s",s);
					querie5(s);        
                    }
				else{
					printf("\033c");
					printf("Produtos, clientes e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 4:
				if(initPro == 1 || initVendas==1){
					printf("Insira mes inicial: \n");
					scanf("%d",&mesI);
					printf("Insira mês final: \n");
					scanf("%d",&mesF);
					querie6(mesI,mesF);        
                    }
				else{
					printf("\033c");
					printf("Produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 5:
				if(initCli==1 || initPro == 1 || initVendas==1){
					querie7();        
                    }
				else{
					printf("\033c");
					printf("Produtos, clientes e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 6:
				if(initPro == 1 || initVendas==1){
					printf("Insira um código de um produto: \n");
					scanf("%s",s);
					printf("Insira uma filial: \n");
					scanf("%d",&filial);
					querie8(s,filial);        
                    }
				else{
					printf("\033c");
					printf("Produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 7:
				if(initCli==1||initPro == 1 || initVendas==1){
					printf("Insira um código de um cliente: \n");
					scanf("%s",s);
					printf("Insira um mês: \n");
					scanf("%d",&mes);
					querie9(s,mes);        
                    }
				else{
					printf("\033c");
					printf("Clientes,produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 8:
				if(initCli==1||initPro == 1 || initVendas==1){
					querie10();        
                    }
				else{
					printf("\033c");
					printf("Clientes,produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 9:
				if(initCli==1||initPro == 1 || initVendas==1){
					printf("Insira um código de um cliente: \n");
					scanf("%s",s);
					querie11(s);        
                    }
				else{
					printf("\033c");
					printf("Clientes,produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 10:
				if(initCli==1||initPro == 1 || initVendas==1){
					querie12();        
                    }
				else{
					printf("\033c");
					printf("Produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 0:
				printMenu();
				break;
			default:
				printf("\033c");
				printf("Opção inválida.\n");
				imprimirMenuQueries();
		}
	}
	else{
		printf("%c\n", c);
		printf("\033c");
		printf("Opção inválida.\n");
		imprimirMenuQueries();
	}
}

