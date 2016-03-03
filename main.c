#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 20000
#define MAXP 200000
#define MAXV 1500000

struct vendas{

    char produto[7];
    float preco;
    int unidades;
    char PouN[2];
    char cliente[7];
    int mes;
    int filial;
};

struct produtos {
     char codigo[7];
}pro[MAXP];


struct clientes {
     char codigo[7];
}cli[MAXC];


int ExisteCliente(struct clientes *cli,char *codigo){
    int i;
    int encontrou=0;
    int igual;
    for(i=0;i<MAXC && !encontrou;i++){
        igual = strcmp(cli[i].codigo,codigo);
        if(igual==0){
            encontrou=1;
        }
    }
    return encontrou;
}

int ExisteProduto(struct produtos *pro,char *codigo){
    int i;
    int encontrou=0;
    int igual;
    for(i=0;i<MAXP && !encontrou;i++){
        igual = strcmp(pro[i].codigo,codigo);
        if(igual==0){
            encontrou=1;
        }
    }
    return encontrou;
}

int leituraCli(struct clientes *cl, char* filename) {
    int nLinhas = 0;
    char linha[10];
    char *tok;
    int LinhasM=0;
    FILE* file = fopen(filename, "r");
    if (file) {
        while (fgets(linha, 10, file)) {

            tok = strtok(linha, "\r\n");
            if(strlen(tok)==5 && isalpha(tok[0]) && isdigit(tok[1])&& isdigit(tok[2])&& isdigit(tok[3])&& isdigit(tok[4])){
                strcpy(cl[nLinhas].codigo,tok);
            }else LinhasM++;
            nLinhas++;

        }
        printf("Nome do ficheiro: %s\n Linhas lidas: %d\n Linhas Mal: %d\n Linhas correcta:%d \n ", filename, nLinhas,LinhasM,nLinhas-LinhasM);
        fclose(file);
    } else printf("Não foi possível encontrar/abrir o ficheiro %s\n",filename);
    return nLinhas;

}

int leituraPro(struct produtos *pro, char* filename) {
    int nLinhas = 0;
    int LinhasM = 0;
    char linha[10];
    char *tok;
    FILE* file = fopen(filename, "r");
    if (file) {
        while (fgets(linha, 10, file)) {

            tok = strtok(linha, "\r\n");
            if(strlen(tok)==6 && isalpha(tok[0]) && isalpha(tok[1])&& isdigit(tok[2])&& isdigit(tok[3])&& isdigit(tok[4]) && isdigit(tok[5])){

                strcpy(pro[nLinhas].codigo,tok);
            } else LinhasM++;
            
            nLinhas++;

        }
    printf("Nome do ficheiro: %s\n Linhas lidas: %d\n Linhas Mal: %d\n Linhas correcta:%d \n ", filename, nLinhas,LinhasM,nLinhas-LinhasM);   
    fclose(file);
    } else printf("Não foi possível encontrar/abrir o ficheiro %s\n",filename);
    return nLinhas;

}

int leituraVendas(struct vendas *vd, char *filename){

    FILE* file = fopen(filename, "r");
    int nLinhas = 0;
    int LinhasM=0;
    char *linha=malloc(32*sizeof(char*));
    char *produto, *cliente, *PouN;
    float preco;
    int unidades, mes, filial;
    char *tok=malloc(32*sizeof(char*));
    int erro=0;

    if (file) {
       while (fgets(linha, 32, file)) {

            erro=0;
            produto = strtok(linha, " ");
            if(ExisteProduto(pro,produto)==0)erro=1;
          
            
            preco=atof(strtok(NULL, " "));
            if(preco<0||erro==1) erro=1;

            unidades=atoi(strtok(NULL, " "));
            if(unidades<0 || erro==1) erro =1;

            PouN = strtok(NULL, " ");
            if(!(strcmp(PouN,"P") || strcmp(PouN,"N")) || erro ==1)erro=1;

            cliente = strtok(NULL, " ");
            if(ExisteCliente(cli,cliente)==0 || erro==1) erro=1;

            mes= atoi(strtok(NULL, " "));
            if(mes<1 || mes>12 || erro==1) erro =1;

            filial=atoi(strtok(NULL, "\r\n"));
            if(filial<1 || filial>3 || erro ==1) erro=1;

            if(erro==0){
                strcpy(vd[nLinhas].produto,produto); 
                vd[nLinhas].preco = preco;
                vd[nLinhas].unidades = unidades;
                strcpy(vd[nLinhas].PouN,PouN);
                strcpy(vd[nLinhas].cliente,cliente);
                vd[nLinhas].mes = mes;
                vd[nLinhas].filial = filial;
                nLinhas++;

            }else LinhasM++;
            
        }
        printf("Nome do ficheiro: %s\n Linhas correctas: %d\n Linhas Mal: %d\n Linhas lidas:%d \n ", filename, nLinhas,LinhasM,nLinhas+LinhasM);   
        fclose(file);
    } else printf("Não foi possível encontrar/abrir o ficheiro %s\n",filename);
    return nLinhas;
}



int main() {
   static struct vendas vend[MAXV];
	leituraCli(cli,"Clientes.txt");
    leituraPro(pro,"Produtos.txt");
    leituraVendas(vend,"Vendas_1M.txt");
    printf("Linha de teste de clientes: %s\n", cli[1000].codigo);    
    printf("Linha de teste de produtos: %s\n", pro[1000].codigo);
    printf("Linha de teste das Vendas: \n produto: %s \n preco: %f \n unidades: %d \n P ou N: %s\n cliente: %s\n mes: %d\n filial: %d\n", vend[1000].produto,vend[1000].preco,vend[1000].unidades,vend[1000].PouN,vend[1000].cliente,vend[1000].mes,vend[1000].filial);

    return 0;
}