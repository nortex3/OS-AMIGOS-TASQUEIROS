#ifndef _leitura_H
#define _leitura_H

typedef struct leitura* Leitura;

Leitura inicializaLeitura();
int getLinhasLidas(Leitura ler);
int getLinhasMal(Leitura ler);
int getLinhasBem(Leitura ler);
char* getNomeFile(Leitura ler);
Leitura leituraPro(FaturacaoGlobal fb,Produtos pro, char* filename);
Leitura leituraCli(Clientes cl,GF gf , char* filename);
Leitura leituraVendas(GF gf,FaturacaoGlobal fb, Produtos p, Clientes c, char *filename);

#endif
