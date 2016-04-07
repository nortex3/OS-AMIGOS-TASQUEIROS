#ifndef _CATALOGOCLIENTES_H
#define _CATALOGOCLIENTES_H


typedef struct clientes* Clientes;

/* Funções */
Clientes InicializaClientes();
int ExisteCliente(char* cod, Clientes p);
int VeTotalC(Clientes c);
void insereAvlClientes(Clientes p,char *cod);
void toArrayClientes(Clientes cli, char c);

#endif
