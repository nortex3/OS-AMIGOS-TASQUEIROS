#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "CatalogoProdutos.h"
#include "CatalogoClientes.h"
#include "Faturacao.h"
#include "GestaoFilial.h"
#include "avlF.h"
#include "avl.h"
#include "avlFilial.h"
#include "leitura.h"
#include "interface.h"

Clientes cli;
Produtos pro;
FaturacaoGlobal fg;
GF gf;

int main() {
    interfaceMain();
    /*
    leituraPro(fb,pro,"Produtos.txt");
    leituraCli(cli,gf,"Clientes.txt");
    leituraVendas(gf,fb,pro,cli,"Vendas_1M.txt");
    
    printf("Total de vendas em fevereiro em modo promocao: %d\n",VeTotalFG(fb) );
    printf("Total faturado do produto NR1091, na filial 2, mes 8, modo PROMO: %f\n",totaldoproduto(fb) );
    printf("Produtos começados por B: %d\n",VeTotalP(pro) );
    printf("Clientes começado por B: %d\n",VeTotalC(cli) );*/

    return 0;
}
