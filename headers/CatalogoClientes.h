#ifndef _CATALOGOCLIENTES_H
#define _CATALOGOCLIENTES_H


typedef struct clientes* Clientes;
typedef struct conjClientes {
	char** lista;
	int tamanho;
}ConjClientes;

/* Funções */
Clientes InicializaClientes();
int ExisteCliente(char* cod, Clientes p);
int VeTotalC(Clientes c);
void insereAvlClientes(Clientes p,char *cod);
ConjClientes toArrayClientes(Clientes cli, char c);

#endif
