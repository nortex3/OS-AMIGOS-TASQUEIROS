#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "CatalogoProdutos.h"
#include "CatalogoClientes.h"
#include "Faturacao.h"
#include "avlF.h"
#include "avl.h"


int leituraPro(Produtos pro, char* filename) {
    int nLinhas = 0;
    int LinhasM = 0;
    char linha[10];
    char *tok;
    FILE* file = fopen(filename, "r");
    if (file) {
        while (fgets(linha, 10, file)) {

            tok = strtok(linha, "\r\n");
            if(strlen(tok)==6 && isalpha(tok[0]) && isalpha(tok[1])&& isdigit(tok[2])&& isdigit(tok[3])&& isdigit(tok[4]) && isdigit(tok[5])){
            	insereAVLProdutos(pro,tok);
            } else LinhasM++;
            
            nLinhas++;

        }
    printf("Nome do ficheiro: %s\n Linhas lidas: %d\n Linhas Mal: %d\n Linhas correcta:%d \n ", filename, nLinhas,LinhasM,nLinhas-LinhasM);   
    fclose(file);
    } else printf("Não foi possível encontrar/abrir o ficheiro %s\n",filename);
    return nLinhas;

}

int leituraCli(Clientes cl, char* filename) {
    int nLinhas = 0;
    char linha[10];
    char *tok;
    int LinhasM=0;
    FILE* file = fopen(filename, "r");
    if (file) {
        while (fgets(linha, 10, file)) {

            tok = strtok(linha, "\r\n");
            if(strlen(tok)==5 && isalpha(tok[0]) && isdigit(tok[1])&& isdigit(tok[2])&& isdigit(tok[3])&& isdigit(tok[4])){
                insereAvlClientes(cl,tok);
            }else LinhasM++;
            nLinhas++;

        }
        printf("Nome do ficheiro: %s\n Linhas lidas: %d\n Linhas Mal: %d\n Linhas correcta:%d \n ", filename, nLinhas,LinhasM,nLinhas-LinhasM);
        fclose(file);
    } else printf("Não foi possível encontrar/abrir o ficheiro %s\n",filename);
    return nLinhas;

}


/* LEITURA QUE VERIFICAVA AS LINHAS VALIDAS */
int leituraVendas(FaturacaoGlobal fb, Produtos p, Clientes c, char *filename){

    FILE* file = fopen(filename, "r");
    int nLinhas = 0;
    int LinhasM=0;
    char *linha=malloc(32*sizeof(char*));
    char *produto, *cliente, *PouN;
    float preco;
    int unidades, mes, filial;
    int erro=0;
    char *linhaValida=malloc(32*sizeof(char*));
    if (file) {
       while (fgets(linha, 32, file)) {
            strcpy(linhaValida,linha); 
            erro=0;
            produto = strtok(linha, " ");
            if(ExisteProduto(produto,p)==0)erro=1;
          
            
            preco=atof(strtok(NULL, " "));
            if(preco<0||erro==1) erro=1;

            unidades=atoi(strtok(NULL, " "));
            if(unidades<0 || erro==1) erro =1;

            PouN = strtok(NULL, " ");
            if(!(strcmp(PouN,"P") || strcmp(PouN,"N")) || erro ==1)erro=1;

            cliente = strtok(NULL, " ");
            if(ExisteCliente(cliente,c)==0 || erro==1) erro=1;

            mes= atoi(strtok(NULL, " "));
            if(mes<1 || mes>12 || erro==1) erro =1;

            filial=atoi(strtok(NULL, "\r\n"));
            if(filial<1 || filial>3 || erro ==1) erro=1;


            if(erro==0){
                insereAvlFaturacao(fb,produto,preco,unidades,mes,PouN[0]);
                /* Falta inserir no modulo filial*/
                nLinhas++;

            }else LinhasM++;
            
        }
        printf("Nome do ficheiro: %s\n Linhas correctas: %d\n Linhas Mal: %d\n Linhas lidas:%d \n ", filename, nLinhas,LinhasM,nLinhas+LinhasM);   
        fclose(file);
    } else printf("Não foi possível encontrar/abrir o ficheiro %s\n",filename);
    return nLinhas;
}


int main() {
	Clientes cli = InicializaClientes();
    Produtos pro = InicializaProdutos();
    FaturacaoGlobal fb = InicializaTotalProdutos();

    leituraPro(pro,"Produtos.txt");
    leituraCli(cli,"Clientes.txt");
    leituraVendas(fb,pro,cli,"Vendas_1M.txt");
    
    printf("Total de vendas em fevereiro em modo promocao: %d\n",VeTotalFG(fb) );
    printf("Total faturado do produto AF1184: %f\n",totaldoproduto(fb) );
    printf("Produtos começados por B: %d\n",VeTotalP(pro) );
    printf("Clientes começado por B: %d\n",VeTotalC(cli) );

    return 0;
}
