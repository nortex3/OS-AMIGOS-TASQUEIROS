#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "headers/CatalogoProdutos.h"
#include "headers/CatalogoClientes.h"
#include "headers/Faturacao.h"
#include "headers/GestaoFilial.h"
#include "headers/interface.h"

Clientes cli;
Produtos pro;
FaturacaoGlobal fg;
GF gf;

int main() {
    interfaceMain();

    free(cli);
    free(pro);
    free(fg);
    free(gf);
    return 0;
}
