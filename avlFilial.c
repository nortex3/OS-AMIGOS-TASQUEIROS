/*
 * ANSI C Library for maintainance of AVL Balanced Trees
 *
 * ref.:
 *  G. M. Adelson-Velskij & E. M. Landis
 *  Doklady Akad. Nauk SSSR 146 (1962), 263-266
 *
 * see also:
 *  D. E. Knuth: The Art of Computer Programming Vol.3 (Sorting and Searching)
 *
 * (C) 2000 Daniel Nagy, Budapest University of Technology and Economics
 * Released under GNU General Public License (GPL) version 2
 *
 */

#include "headers/avlFilial.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define NORMAL 0
#define PROMO 1

 /* Data structures */

/* One element of the AVL tree */
typedef struct avlP  /* Avl dos Produtos*/
{
   char* codigo;
   int UnidadesVendidas;
   int ComprasFilial1[12][2];
   int ComprasFilial2[12][2];
   int ComprasFilial3[12][2];
   struct avlP* left;
   struct avlP* right;
   signed char balance;
} avlP;

typedef struct avlC /* Avl dos Clientes*/
{
   char* codigo;
   int TotalComprados;
   Avl_treeP ListaProdutos[26];
   struct avlC* left;
   struct avlC* right;
   signed char balance;
} avlC;

/* An AVL tree */
typedef struct avl_treeP
{
   avlP* root;
} avl_treeP;


typedef struct avl_treeC
{
   avlC* root;
} avl_treeC;

/* Private methods */
int percorreProdutosClientes(AvlC c, int r[], char** aux, int index);
void percorreProdutos(AvlP pro, int r[]);
void comprasFiliaisTodas(AvlP p, int r[]);
int percorreProdutosClientes9(AvlC c, int mes, char** aux);
int percorreProdutos9(AvlP p, int mes, char** codigos, int* quantidades,int j);
int calculaValores(AvlP p,int mes,char** codigos,int* quantidades, int j);
void insereOrdem(int total,char** codigos,int* quantidades,int j);
void TrocaPosQuant(int* arrayTot,int origem,int destino);
void TrocaPosCod(char** arrayProd,int origem,int destino);
int percorreProdutos8(AvlC c,char* cod,int index,int flag, char** aux,int filial,char tipo);



/* Apoio Query 8 */

int percorreProdutosClientes8(AvlC clientes, char* cod, int index,int flag, char** aux, int filial, char tipo){
     int i;
    
      if(clientes == NULL){
      return index;
   }
   if (clientes->left)
      index = percorreProdutosClientes8(clientes->left,cod,index,flag,aux,filial,tipo);
    
   
     index = percorreProdutos8(clientes,cod,index,flag,aux,filial,tipo);


   if (clientes->right)
      index = percorreProdutosClientes8(clientes->right,cod,index,flag,aux,filial,tipo);
    
   return index;  
}
 
  

    
int percorreProdutos8(AvlC c,char* cod,int index,int flag, char** aux, int filial, char tipo){
    int i=0,n=0;
    flag = 0;
     if (cod[0]>=97 && cod[0]<=123) 
        n = ((int)cod[0])-97;
    else
        if (cod[0]>=64 && cod[0]<=90) 
            n = ((int)cod[0])-65;
    Avl_treeP tmp;
    AvlP p;
    tmp = c -> ListaProdutos[n];
    p = createNodePro(tmp);
    flag=percorre8(p, cod,flag,filial,tipo);
    if (flag==1){
        aux[index]=c->codigo;
        index++;
    }
    
    
  return index;
}
  

int percorre8(AvlP p, char* cod,int flag,int filial,char tipo){
     switch(filial){
			case 1:
             if(tipo=='N' || tipo=='n')
				flag=percorre8F1Normal(p,cod,flag);
             else
                flag=percorre8F1Promo(p,cod,flag);
				break;
			case 2:
                 if(tipo=='N' || tipo=='n')
				flag=percorre8F2Normal(p,cod,flag);
             else
                flag=percorre8F2Promo(p,cod,flag);
				break;
            case 3:
                if(tipo=='N' || tipo=='n')
				flag=percorre8F3Normal(p,cod,flag);
             else
                flag=percorre8F3Promo(p,cod,flag);
				break;
            default:;
     }
    return flag;
}

int percorre8F1Normal(AvlP p, char* cod, int flag){
    int comprasfilial=0; 
    int i=0;
    
  if(p == NULL){
    flag=0;
    return flag;
  }
   if (p->left)
      flag=percorre8F1Normal(p->left,cod,flag);
    
    for (i=0,comprasfilial=0;i<12;i++){
        comprasfilial=comprasfilial+p->ComprasFilial1[i][NORMAL];
    }
    

   if(strcmp(p->codigo,cod)==0 && comprasfilial!=0) {flag=1;}

   if (p->right)
      flag=percorre8F1Normal(p->right,cod,flag);  
    
return flag;
}

int percorre8F1Promo(AvlP p, char* cod, int flag){
    int comprasfilial=0; 
    int i=0;
    
  if(p == NULL){
    flag=0;
    return flag;
  }
   if (p->left)
      flag=percorre8F1Promo(p->left,cod,flag);
    
    for (i=0,comprasfilial=0;i<12;i++){
        comprasfilial=comprasfilial+p->ComprasFilial1[i][PROMO];
    }
    

   if(strcmp(p->codigo,cod)==0 && comprasfilial!=0) {flag=1;}

   if (p->right)
      flag=percorre8F1Promo(p->right,cod,flag);  
    
return flag;
}

int percorre8F2Normal(AvlP p, char* cod, int flag){
    int comprasfilial=0; 
    int i=0;
    
  if(p == NULL){
    flag=0;
    return flag;
  }
   if (p->left)
      flag=percorre8F2Normal(p->left,cod,flag);
    
    for (i=0,comprasfilial=0;i<12;i++){
        comprasfilial=comprasfilial+p->ComprasFilial2[i][NORMAL];
    }
    

   if(strcmp(p->codigo,cod)==0 && comprasfilial!=0) {flag=1;}

   if (p->right)
      flag=percorre8F2Normal(p->right,cod,flag);  
    
return flag;
}

int percorre8F2Promo(AvlP p, char* cod, int flag){
    int comprasfilial=0; 
    int i=0;
    
  if(p == NULL){
    flag=0;
    return flag;
  }
   if (p->left)
      flag=percorre8F2Promo(p->left,cod,flag);
    
    for (i=0,comprasfilial=0;i<12;i++){
        comprasfilial=comprasfilial+p->ComprasFilial2[i][PROMO];
    }
    

   if(strcmp(p->codigo,cod)==0 && comprasfilial!=0) {flag=1;}

   if (p->right)
      flag=percorre8F2Promo(p->right,cod,flag);  
    
return flag;
}


int percorre8F3Normal(AvlP p, char* cod, int flag){
    int comprasfilial=0; 
    int i=0;
    
  if(p == NULL){
    flag=0;
    return flag;
  }
   if (p->left)
      flag=percorre8F3Normal(p->left,cod,flag);
    
    for (i=0,comprasfilial=0;i<12;i++){
        comprasfilial=comprasfilial+p->ComprasFilial3[i][NORMAL];
    }
    

   if(strcmp(p->codigo,cod)==0 && comprasfilial!=0) {flag=1;}

   if (p->right)
      flag=percorre8F3Normal(p->right,cod,flag);  
    
return flag;
}


int percorre8F3Promo(AvlP p, char* cod, int flag){
    int comprasfilial=0; 
    int i=0;
    
  if(p == NULL){
    flag=0;
    return flag;
  }
   if (p->left)
      flag=percorre8F3Promo(p->left,cod,flag);
    
    for (i=0,comprasfilial=0;i<12;i++){
        comprasfilial=comprasfilial+p->ComprasFilial3[i][PROMO];
    }
    

   if(strcmp(p->codigo,cod)==0 && comprasfilial!=0) {flag=1;}

   if (p->right)
      flag=percorre8F3Promo(p->right,cod,flag);  
    
return flag;
}


/*Apoio Query 9 */
int percorreProdutosClientes9(AvlC c, int mes, char** aux){
  int i,k, tamanho;
  Avl_treeP tmp;
  AvlP p;
  char** codigos=NULL;
  int* quantidades;
  int index=0;

  tamanho = c->TotalComprados;
  quantidades=(int*) malloc(tamanho*sizeof(int));
  codigos=(char**) malloc(tamanho*sizeof(char*));
  
 for(i=0;i<26;i++){

    tmp = c -> ListaProdutos[i];
    p = createNodePro(tmp);
    index=percorreProdutos9(p, mes,codigos,quantidades,index);
   
  }
/*MAnda pra lista*/
  for(k=0;codigos[k]!=NULL;k++){
    aux[k] =codigos[k];
  }
  return k;
}

int percorreProdutos9(AvlP p, int mes, char** codigos, int* quantidades,int pos){
  if(p == NULL){
    return pos;
  }
   if (p->left)
      pos=percorreProdutos9(p->left,mes,codigos,quantidades,pos);

   pos=calculaValores(p,mes,codigos,quantidades,pos);

   if (p->right)
      pos=percorreProdutos9(p->right,mes,codigos,quantidades,pos); 
  return pos;
 
}



int calculaValores(AvlP p,int mes,char** codigos,int* quantidades, int pos){
  int i, tamanho = 1;
  int compradosNormais=0;
  int compradosPromo=0;
  int total=0;
  char* c;
  if(p!=NULL){

    compradosPromo=p->ComprasFilial1[mes-1][PROMO]+p->ComprasFilial2[mes-1][PROMO]+p->ComprasFilial3[mes-1][PROMO];
    compradosNormais=p->ComprasFilial1[mes-1][NORMAL]+p->ComprasFilial2[mes-1][NORMAL]+p->ComprasFilial3[mes-1][NORMAL];
    total=compradosNormais+compradosPromo;

    if(total>0){
      codigos[pos] = (char*)malloc(strlen(p->codigo)+1*sizeof(char));
      strcpy(codigos[pos], p->codigo);
      quantidades[pos]=total;      
      insereOrdem(total,codigos,quantidades,pos+1);
      pos++;
      
    }
  }
  return pos;
}

void insereOrdem(int total,char** codigos,int* quantidades,int pos){

  int aux=pos-1;
    while(aux>0){
        if(total>quantidades[aux-1]){
            TrocaPosQuant(quantidades,aux,aux-1);
            TrocaPosCod(codigos,aux,aux-1);
            aux--;
        }
        else{
            aux=0;
        }
    }   

}

void TrocaPosQuant(int* quantidades,int origem,int destino){
    
    int aux;
    aux=quantidades[origem];
    quantidades[origem]=quantidades[destino];
    quantidades[destino]=aux;
}

void TrocaPosCod(char** codigos,int origem,int destino){
    char* aux;
    if(codigos[destino]!=NULL){
     
        aux= (char*)malloc((strlen(codigos[origem])+1)*sizeof(char));
        strcpy(aux,codigos[origem]);
        strcpy(codigos[origem],codigos[destino]);
        strcpy(codigos[destino],aux);
    }else{
        strcpy(codigos[destino],codigos[origem]);
        codigos[origem]=NULL;
    }
}

int totalProdsVendidos(AvlP p){
  return p->UnidadesVendidas;
}

int totalProdsComprados(AvlC c){
  return c->TotalComprados;
}


/* Apoio a Queries*/

int percorreClientesAux(AvlC cli,int r[], char** aux, int index){
  if(cli == NULL){
    return index;
  }
   if (cli->left)
      index = percorreClientesAux(cli->left,r, aux, index);

    index = percorreProdutosClientes(cli,r, aux, index);

   if (cli->right)
      index = percorreClientesAux(cli->right,r, aux, index);

  return index;

}
    
int percorreProdutosClientes(AvlC c, int r[], char** aux, int index){
  int i;
  Avl_treeP tmp;
  AvlP p;
  for(i=0;i<26;i++){
    tmp = c -> ListaProdutos[i];
    p = createNodePro(tmp);
    percorreProdutos(p, r);
  }

  if(r[0] == 1 && r[1] == 1 && r[2] == 1){
    aux[index] = c->codigo;
    index++;
  }
  r[0] = r[1] = r[2] = 0;
  return index;
}

void percorreProdutos(AvlP p, int r[]){
  if(p == NULL){
    return;
  }
   if (p->left)
      percorreProdutos(p->left,r);

   comprasFiliaisTodas(p,r);

   if (p->right)
      percorreProdutos(p->right,r);  
}


void comprasFiliaisTodas(AvlP p,int r[]){
  int i, j, aux = 0;
  for(i = 0; i < 2; i++){
    for(j = 0; j < 12; j++){
      aux = p->ComprasFilial1[j][i];
      if(aux > 0){
        r[0] = 1;
        i=2;
        j=12;
      }
    }
  }
  for(i = 0; i < 2; i++){
    for(j = 0; j < 12; j++){
      aux = p->ComprasFilial2[j][i];
      if(aux > 0){
        r[1] =1;
        i=2;
        j=12;
      }
    }
  }
  for(i = 0; i < 2; i++){
    for(j = 0; j < 12; j++){
      aux = p->ComprasFilial3[j][i];
      if(aux > 0){
        r[2]=1;
        i=2;
        j=12;
      }
    }
  }


}

void calculaVendas(AvlP p, int *mes){
  int j=0,i=0;
  if(p!=NULL){
    while(j<36){  
       mes[j] +=p->ComprasFilial1[i][NORMAL]+p->ComprasFilial1[i][PROMO];
       j++;
       mes[j]+=p->ComprasFilial2[i][NORMAL]+p->ComprasFilial2[i][PROMO];
       j++;
       mes[j]+=p->ComprasFilial3[i][NORMAL]+p->ComprasFilial3[i][PROMO];
       j++;
       i++;
     }
     calculaVendas(p->right,mes);
     calculaVendas(p->left,mes);
  }

}

void calculaListaProdutos(AvlC a, int *mes){
  AvlC cli;
  Avl_treeP prod;
  AvlP p;
  int i;
 

  for(i=0;i<26;i++){
       prod= a->ListaProdutos[i];
       p=prod->root;
       calculaVendas(p,mes);
  }
}

int contaNodosGF(AvlC a){ 
    int count=0;
    if (a!=NULL){
    count = 1+contaNodosGF(a->left)+contaNodosGF(a->right);
    }
    return count;
}
/*----------------------*/


/* Swing to the left
 * Warning: no balance maintainance
 */
void avl_swlFP(avlP** root){
   AvlP a=*root;
   AvlP b=a->right;
   *root=b;
   a->right=b->left;
   b->left=a;
}

/* Swing to the right
 * Warning: no balance maintainance
 */
void avl_swrFP(avlP** root){
   AvlP a=*root;
   AvlP b=a->left;
   *root=b;
   a->left=b->right;
   b->right=a;
}

/* Balance maintainance after especially nasty swings
 */
void avl_nastyFP(AvlP root){
   switch(root->balance){
    case -1:root->left->balance=0;
      root->right->balance=1;
      break;
    case 1:	root->left->balance=-1;
      root->right->balance=0;
      break;
    case 0:	root->left->balance=0;
      root->right->balance=0;
   }
   root->balance=0;
}

int existeFP(char* s, Avl_treeP ptr){
   AvlP p = ptr -> root;
   int r = 1;
   if(!p) return 0;
   while(p && r){
      r = strcmp(s, p -> codigo);
      if(r < 0) p = p -> left;
      else if(r > 0) p = p -> right;
      else r = 0;
   }
   if(r == 0) return 1;
   return 0;
}

int avl_actualizaP(char* s, Avl_treeP ptr,int quantidade,int mes,char tipo,int filial){
   AvlP tmp = ptr->root;
   AvlP p = procuraP(tmp,s);
   if(!p) return 0;
   else{

      p->UnidadesVendidas+=quantidade;
      
      if(tipo=='N'){
         if(filial==1){
            p->ComprasFilial1[mes-1][NORMAL] +=quantidade;
          }else{
              if(filial==2){

                p->ComprasFilial2[mes-1][NORMAL] +=quantidade;
              } else {

                  if(filial==3){

                    p->ComprasFilial3[mes-1][NORMAL] +=quantidade;
                  }
                }
              }

       }else{
      
         
          if(filial==1){
            p->ComprasFilial1[mes-1][PROMO] +=quantidade;
          }else{
          
              if(filial==2){

                p->ComprasFilial2[mes-1][PROMO] +=quantidade;
               
              }else{
                  p->ComprasFilial3[mes-1][PROMO] +=quantidade;
                
                }
              }
            }
   }
   return 1;

}

AvlP procuraTreeP(Avl_treeP p, char* cod){
   AvlP node = p -> root;
   if(node == NULL) return 0;
   if (strcmp(cod,node->codigo) == 0) return node;
    else if (strcmp(cod,node->codigo) < 0) return procuraP(node->left, cod);
    else return procuraP(node->right, cod);
}


AvlP procuraP(AvlP node, char* cod){
   if(node == NULL) return 0;
   if (strcmp(cod,node->codigo) == 0) return node;
    else if (strcmp(cod,node->codigo) < 0) return procuraP(node->left, cod);
    else return procuraP(node->right, cod);
}

AvlP createNodePro(Avl_treeP p){
  AvlP tmp;
  tmp = p->root;
  return tmp;
}

AvlC createNodeCli(Avl_treeC c){
  AvlC tmp;
  tmp = c->root;
  return tmp;
}

AvlP createNodeP(char* s,int quantidade,int mes,char tipo, int filial){
    AvlP tmp = (AvlP)malloc(sizeof(avlP));
   char* c = (char*)malloc((strlen(s)+1)*sizeof(char));
   strcpy(c,s);
   tmp -> codigo = c;
   tmp->UnidadesVendidas=quantidade; 

   if(tipo=='N'){

      if(filial==1){
        tmp->ComprasFilial1[mes-1][NORMAL] =quantidade;
      } 
        if(filial==2){

        tmp->ComprasFilial2[mes-1][NORMAL] =quantidade;
      }
     

      if(filial==3){

        tmp->ComprasFilial3[mes-1][NORMAL] =quantidade;
      }
    

     }else{
      
        if(filial==1){
          tmp->ComprasFilial1[mes-1][PROMO] =quantidade;
        }
        if(filial==2){

          tmp->ComprasFilial2[mes-1][PROMO] =quantidade;
        }

        if(filial==3){

          tmp->ComprasFilial3[mes-1][PROMO] =quantidade;
        }
      }
   return tmp;
}

Avl_treeP createTreeP(){
   Avl_treeP tmp = (Avl_treeP)malloc(sizeof(avl_treeP));
   tmp -> root = NULL;
   return tmp;
}

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertP(Avl_treeP t,AvlP a)
{
   /* initialize */
   a->left=0;
   a->right=0;
   a->balance=0;
   /* insert into an empty tree */
   if(!t->root){
      t->root=a;
      return 1;
   }
   
   if(strcmp(t->root->codigo,a->codigo)>0){
      /* insert into the left subtree */
      if(t->root->left){
	 avl_treeP left_subtree;
	 left_subtree.root=t->root->left;
	 if(avl_insertP(&left_subtree,a)){
	    switch(t->root->balance--){
	     case 1: return 0;
	     case 0:	return 1;
	    }
	    if(t->root->left->balance<0){
	       avl_swrFP(&(t->root));
	       t->root->balance=0;
	       t->root->right->balance=0;
	    }else{
	       avl_swlFP(&(t->root->left));
	       avl_swrFP(&(t->root));
	       avl_nastyFP(t->root);
	    }
	 }else t->root->left=left_subtree.root;
	 return 0;
      }else{
	 t->root->left=a;
	 if(t->root->balance--) return 0;
	 return 1;
      }
   }else{
      /* insert into the right subtree */
      if(t->root->right){
	 avl_treeP right_subtree;
	 right_subtree.root=t->root->right;
	 if(avl_insertP(&right_subtree,a)){
	    switch(t->root->balance++){
	     case -1: return 0;
	     case 0: return 1;
	    }
	    if(t->root->right->balance>0){
	       avl_swlFP(&(t->root));
	       t->root->balance=0;
	       t->root->left->balance=0;
	    }else{
	       avl_swrFP(&(t->root->right));
	       avl_swlFP(&(t->root));
	       avl_nastyFP(t->root);
	    }
	 }else t->root->right=right_subtree.root;
	 return 0;
      }else{
	 t->root->right=a;
	 if(t->root->balance++) return 0;
	 return 1;
      }
   }
}

/* ---- AVLC ----- */


/* Private methods */

/* Swing to the left
 * Warning: no balance maintainance
 */
void avl_swlFC(avlC** root){
   AvlC a=*root;
   AvlC b=a->right;
   *root=b;
   a->right=b->left;
   b->left=a;
}

/* Swing to the right
 * Warning: no balance maintainance
 */
void avl_swrFC(avlC** root){
   AvlC a=*root;
   AvlC b=a->left;
   *root=b;
   a->left=b->right;
   b->right=a;
}

/* Balance maintainance after especially nasty swings
 */
void avl_nastyFC(AvlC root){
   switch(root->balance){
    case -1:root->left->balance=0;
      root->right->balance=1;
      break;
    case 1: root->left->balance=-1;
      root->right->balance=0;
      break;
    case 0: root->left->balance=0;
      root->right->balance=0;
   }
   root->balance=0;
}

int existeC(char* s, Avl_treeC ptr){
   AvlC p = ptr -> root;
   int r = 1;
   if(!p) return 0;
   while(p && r){
      r = strcmp(s, p -> codigo);
      if(r < 0) p = p -> left;
      else if(r > 0) p = p -> right;
      else r = 0;
   }
   if(r == 0) return 1;
   return 0;
}


int avl_actualizaC(char* s,char* pro, Avl_treeC ptr,int quantidade,int mes,char tipo,int filial){
  char *c;
  char *produto;
  c = (char*)malloc(strlen(s)+1*sizeof(char));
  strcpy(c, s);
  produto = (char*)malloc(strlen(pro)+1*sizeof(char));
  strcpy(produto, pro);

   AvlC p = procuraTreeC(ptr,c);
   Avl_treeP ora;
   AvlP t,a,head;

   int j=26;
   if(!p) return 0;
   else{

   if (produto[0]>=97 && produto[0]<=123) 
        j = ((int)produto[0])-97;
    else
        if (produto[0]>=64 && produto[0]<=90) 
            j = ((int)produto[0])-65;

      p->TotalComprados+=quantidade;

      ora = p->ListaProdutos[j];
      t=ora->root;
      a=procuraP(t,produto);
      if(a==NULL){
      head=createNodeP(produto,quantidade,mes,tipo,filial);
      avl_insertP(p->ListaProdutos[j],head); 
      } 
      else
       avl_actualizaP(produto,p->ListaProdutos[j],quantidade,mes,tipo,filial);

     }
   return 1;

}

AvlC procuraTreeC(Avl_treeC p, char* cod){
   AvlC node = p -> root;
   if(node == NULL) return 0;
   if (strcmp(cod,node->codigo) == 0) return node;
    else if (strcmp(cod,node->codigo) < 0) return procuraC(node->left, cod);
    else return procuraC(node->right, cod);
}


AvlC procuraC(AvlC node, char* cod){
   if(node == NULL) return 0;
   if (strcmp(cod,node->codigo) == 0) return node;
    else if (strcmp(cod,node->codigo) < 0) return procuraC(node->left, cod);
    else return procuraC(node->right, cod);
}

AvlC createNodeC(char* cli,char* pro,int quantidade,int mes,char tipo, int filial){
    AvlC tmp = (AvlC)malloc(sizeof(avlC));
    AvlP head;
    int i=0,j=26,k=26;
   char* c = (char*)malloc((strlen(cli)+1)*sizeof(char));
   char* produto; 
   strcpy(c, cli);
   tmp -> codigo = c;
   tmp->TotalComprados=quantidade; 

   if (c[0]>=97 && c[0]<=123) 
        j = ((int)c[0])-97;
    else
        if (c[0]>=64 && c[0]<=90) 
            j = ((int)c[0])-65;

   if(produto!=NULL){
      produto= (char*)malloc((strlen(pro)+1)*sizeof(char));
      strcpy(produto,pro);


     if (produto[0]>=97 && produto[0]<=123) 
          k = ((int)produto[0])-97;
      else
          if (produto[0]>=64 && produto[0]<=90) 
              k = ((int)produto[0])-65;

     /*for(i=0;i<26;i++) tmp->ListaProdutos[i]=createTreeP();*/

     head=createNodeP(produto,quantidade,mes,tipo,filial);
     avl_insertP(tmp->ListaProdutos[k],head);

    }else{
      for(i=0;i<26;i++) tmp->ListaProdutos[i]=createTreeP();
    }
   return tmp;
}

Avl_treeC createTreeC(){
   Avl_treeC tmp = (Avl_treeC)malloc(sizeof(avl_treeC));
   tmp -> root = NULL;
   return tmp;
}

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertC(Avl_treeC t,AvlC a)
{
   /* initialize */
   a->left=0;
   a->right=0;
   a->balance=0;
   /* insert into an empty tree */
   if(!t->root){
      t->root=a;
      return 1;
   }
   
   if(strcmp(t->root->codigo,a->codigo)>0){
      /* insert into the left subtree */
      if(t->root->left){
   avl_treeC left_subtree;
   left_subtree.root=t->root->left;
   if(avl_insertC(&left_subtree,a)){
      switch(t->root->balance--){
       case 1: return 0;
       case 0:  return 1;
      }
      if(t->root->left->balance<0){
         avl_swrFC(&(t->root));
         t->root->balance=0;
         t->root->right->balance=0;
      }else{
         avl_swlFC(&(t->root->left));
         avl_swrFC(&(t->root));
         avl_nastyFC(t->root);
      }
   }else t->root->left=left_subtree.root;
   return 0;
      }else{
   t->root->left=a;
   if(t->root->balance--) return 0;
   return 1;
      }
   }else{
      /* insert into the right subtree */
      if(t->root->right){
   avl_treeC right_subtree;
   right_subtree.root=t->root->right;
   if(avl_insertC(&right_subtree,a)){
      switch(t->root->balance++){
       case -1: return 0;
       case 0: return 1;
      }
      if(t->root->right->balance>0){
         avl_swlFC(&(t->root));
         t->root->balance=0;
         t->root->left->balance=0;
      }else{
         avl_swrFC(&(t->root->right));
         avl_swlFC(&(t->root));
         avl_nastyFC(t->root);
      }
   }else t->root->right=right_subtree.root;
   return 0;
      }else{
   t->root->right=a;
   if(t->root->balance++) return 0;
   return 1;
      }
   }
}



