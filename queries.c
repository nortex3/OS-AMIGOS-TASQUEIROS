#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/CatalogoProdutos.h"
#include "headers/CatalogoClientes.h"
#include "headers/Faturacao.h"
#include "headers/GestaoFilial.h"
#include "headers/avlF.h"
#include "headers/avl.h"
#include "headers/avlFilial.h"
#include "headers/leitura.h"

extern Clientes cli;

void querie2(char i){
 if(i > 0){
 if (i>=64 && i<=90){ 
     toArrayClientes(cli, i);
 }
 else{
     printf("\033c");
     printf("Letra inválida.\n");
 }
}
}

