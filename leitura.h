#ifndef _leitura_H
#define _leitura_H

int leituraPro(FaturacaoGlobal fb,Produtos pro, char* filename);
int leituraCli(Clientes cl, GF gf, char* filename);
int leituraVendas(GF gf,FaturacaoGlobal fb, Produtos p, Clientes c, char *filename);

#endif
