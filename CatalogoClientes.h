#ifndef _CATALOGOCLIENTES_H
#define _CATALOGOCLIENTES_H


typedef struct clientes* Clientes;

/* Funções */
Clientes InicializaClientes();
int VeTotalC(Clientes c);
void insereAvlClientes(Clientes p,char *cod);
int ExisteCliente(char* cod, Clientes p);
#endif
