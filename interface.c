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
				if(initVendas == 1){
					printf("\033c");
					querie1Clientes();
					initCli = 1;
					initVendas = 0;
					inicializarMenu();
				}
				else{
					printf("\033c");
					querie1Clientes();
					initCli = 1;
					inicializarMenu();
				}
				break;
			case 2:
				if(initVendas == 1){
					printf("\033c");
					querie1Produtos();
					initPro = 1;
					initVendas = 0;
					inicializarMenu();
				}
				else{
					printf("\033c");
					querie1Produtos();
					initPro = 1;
					inicializarMenu();
				}
				break;
			case 3:
				if(initCli == 0 || initPro == 0){
					printf("\033c");
					printf("Tem que inicializar clientes e produtos primeiro.\n");
					inicializarMenu();					
				}
				else{
					printf("\033c");
					querie1Vendas();
					initVendas = 1;
					inicializarMenu();
				}
				break;
			case 4:
				printf("\033c");
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
					i = getchar();
                    if(i > 0){
                         if (c>=64 && c<=90){
					         printClientes(c);
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
					printf("Produtos não inicializados.\n");
				}
				imprimirMenu();
				break;
			case 0:
				printf("\033c");
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
	int r = 0, n = 0, aux = 0;
	int mes=0;
	int mesI=0,mesF=0;
	int filial=0;
	int modo=0;
	char c = '0';
	char s[6];
	char cliente[5];
    char tipo = '0';
	printf("################## GEREVENDAS ##################################################################\n"
		   "# 1.  Querie1 - Leitura dos ficheiros.                                                         #\n"
		   "# 2.  Querie2 - Lista de todos os produtos por determinada letra com navegação.                #\n"
		   "# 3.  Querie3 - Apresentar total vendas e faturado de um dado produto e mês.          	       #\n"
		   "# 4.  Querie4 - Lista de produtos que ninguém comprou.                                         #\n");
	printf("# 5.  Querie5 - Cria tabela com produtos comprados por um dado cliente                         #\n"
		   "# 6.  Querie6 - Determina total de vendas e faturado num dado intervalo de meses.              #\n"
		   "# 7.  Querie7 - Lista de clientes que realizaram compras em todas as filiais.                  #\n"
		   "# 8.  Querie8 - Apresentar clientes que compraram um dado produto, numa filial especifica.     #\n");
	printf("# 9.  Querie9 - Lista de clientes que mais compraram um dado produto, num dado mês.            #\n"
		   "# 10. Querie10 - Listar os N produtos mais vendidos.                                           #\n"
		   "# 11. Querie11 - Apresentar os 3 produtos em que um dado cliente gastou mais dinheiro          #\n");
	printf("# 12. Querie12 - Número de clientes que não registaram compras, e produtos que ninguém comprou.#\n"
		   "# 0.  Voltar ao menu inicial.                                                                  #\n"
		   "################################################################################################\n"
		   ">");
	n = scanf("%d",&r);
	c = getchar();
	if(n > 0){
		switch(r){
			case 1:
				printf("\033c");
				querie1Clientes();
				initCli = 1;
				querie1Produtos();
				initPro = 1;
				querie1Vendas();
				initVendas = 1;
				imprimirMenuQueries();
				break;
			case 2:
				if(initPro == 1){
					printf("\033c");
					printf("Insira uma letra maiúscula: ");
					aux = scanf("%c",&c);
					if(aux > 0){
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
					printf("Produtos não inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 3:
				if(initPro == 1 || initVendas==1){
					printf("\033c");
					printf("Insira um código de um produto: \n");
					aux = scanf("%s",s);
					printf("Insira um mês: \n");
					aux = scanf("%d",&mes);
				    printf("Insira 1 para resultados globais, Insira 2 para resultados filial a filial: \n");
				    aux = scanf("%d",&modo);
					    if(!isalpha(s[0])) printf("Insira código do produto no formato pedido\n");
					    else if(mes<1||mes>12){
					    	printf("Insira um mês entre 1 e 12\n");
					    }else if(modo==1 || modo==2) {
							querie3(mes,s,modo);
					}  
					else {
						printf("\033c");
						printf("Inseriu valor diferente 1 e 2.\n");
					}
				     
                    }
				else{
					printf("\033c");
					printf("Produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 4:
				if(initPro == 1 || initVendas==1){
					printf("\033c");
                    printf("Insira 1 para resultados globais, Insira 2 para resultados filial a filial: \n");
				    aux = scanf("%d",&modo);
                    if(modo==1 || modo==2){
                        if(modo==2){
                            printf("Insira a filial que pretende consultar: \n");
                            aux = scanf("%d",&filial);
                                while(filial!=1 && filial!=2 && filial!=3){
                                    printf("Filial incorrecta, introduza 1,2 ou 3.\n");
                                    aux = scanf("%d",&filial);
                                }
                            }
                            querie4(modo,filial); 
                        
                    }
					else {
						printf("\033c");
						printf("Inseriu valor diferente 1 e 2.\n");
					} 
           
                }
                else{
					printf("\033c");
					printf("Produtos ou vendas não inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 5:
				if(initCli==1 || initPro == 1 || initVendas==1){
					printf("\033c");
					printf("Insira um código de um cliente: \n");
					aux = scanf("%s",s);
					if(isalpha(s[0])!=0){
						querie5(s);        
					}
					else{
						printf("\033c");
						printf("Cliente inválido.\n");
					}
                }
				else{
					printf("\033c");
					printf("Produtos, clientes e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 6:
				if(initPro == 1 || initVendas==1){
					printf("\033c");
					printf("Insira mes inicial: \n");
					aux = scanf("%d",&mesI);
					printf("Insira mês final: \n");
					aux = scanf("%d",&mesF);
					if((mesI>=1 && mesI<=mesF)&&(mesF<=12 && mesF>=mesI))
						querie6(mesI,mesF);        
                    else {
						printf("\033c");
						printf("Conjunto de meses incorrectos.\n");
						}
                }
				else{
					printf("\033c");
					printf("Produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 7:
				if(initCli==1 || initPro == 1 || initVendas==1){
					printf("\033c");
					querie7();        
                }
				else{
					printf("\033c");
					printf("Produtos, clientes e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 8:
				if(initPro == 1 || initVendas==1){
					printf("Insira um código de um produto: \n");
					aux = scanf("%s",s);
					printf("Insira uma filial: \n");
					aux = scanf("%d",&filial);
                    while(filial!=1 && filial!=2 && filial!=3){
                                    printf("Filial incorrecta, introduza 1,2 ou 3.\n");
                                    aux = scanf("%d",&filial);
                    }
                    printf("Normal(N/n) ou Promocao(P/p): \n");
					aux = scanf(" %c",&tipo);
                    while(tipo!='N' && tipo!='n' && tipo!='P' && tipo!='p'){
                                        printf("Tipo incorrecto, introduza n/N ou p/P\n");
                                        aux = scanf("%c",&tipo);
                    }
                	if(isalpha(s[0])!=0){
						querie8(s,filial,tipo);        
                    }else{
                    	printf("\033c");
						printf("Insira produto no formato correto.\n");
                    }
                }
				else{
					printf("\033c");
					printf("Produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 9:
				if(initCli==1||initPro == 1 || initVendas==1){
					printf("Insira um código de um cliente: \n");
					aux = scanf("%s",s);
					if(isalpha(s[0])!=0){
						printf("Insira um mês: \n");
						aux = scanf("%d",&mes);
						if(mes<1||mes>12){
							printf("\033c");
							printf("Mes incorrecto\n");
						}
						else querie9(s,mes);
					}
					else{
						printf("\033c");
						printf("Cliente inválido.\n");
					}       
                }
				else{
					printf("\033c");
					printf("Clientes,produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 10:
				if(initCli==1||initPro == 1 || initVendas==1){
					querie10();        
                    }
				else{
					printf("\033c");
					printf("Clientes,produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 11:
				if(initCli==1||initPro == 1 || initVendas==1){
					printf("Insira um código de um cliente: \n");
					aux = scanf("%s",s);
					if(isalpha(s[0])!=0){
						querie11(s);        
                    }else{
                    	printf("\033c");
						printf("Cliente inválido\n");
                    }
                }
				else{
					printf("\033c");
					printf("Clientes,produtos e vendas nao inicializados.\n");
				}
				imprimirMenuQueries();
				break;
			case 12:
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
				printf("\033c");
				printMenu();
				break;
			default:
				printf("%d\n",aux );
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

