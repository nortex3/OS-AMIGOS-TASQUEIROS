#ifndef _leitura_H
#define _leitura_H

int leituraPro(FaturacaoGlobal fb,Produtos pro, char* filename);
int leituraCli(Clientes cl, char* filename);
int leituraVendas(FaturacaoGlobal fb, Produtos p, Clientes c, char *filename);

#endif