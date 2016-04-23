#ifndef _CATALOGOCLIENTES_H
#define _CATALOGOCLIENTES_H


typedef struct clientes* Clientes;
typedef struct conjClientes* ConjClientes;

/* Funções */
Clientes InicializaClientes();
int ExisteCliente(char* cod, Clientes p);
void insereAvlClientes(Clientes p,char *cod);
ConjClientes toArrayClientes(Clientes cli, char c);

ConjClientes InicializaConjClientes();
int retornaTamanho(ConjClientes cc);
char retornaPrimeiraLetra(ConjClientes cc,int i);
char* retornaElemento(ConjClientes cc,int i);
#endif
