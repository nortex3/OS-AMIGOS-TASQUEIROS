#ifndef _leitura_H
#define _leitura_H

struct leitura{
    int linhasM;
    int linhasB;
    int linhasLidas;
    char* nomeFile;
}Leitura;

Leitura leituraPro(FaturacaoGlobal fb,Produtos pro, char* filename);
Leitura leituraCli(Clientes cl,GF gf , char* filename);
Leitura leituraVendas(GF gf,FaturacaoGlobal fb, Produtos p, Clientes c, char *filename);

#endif
