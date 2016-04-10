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





/* Apoio a Queries*/

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

AvlP createNodeP(char* s,int quantidade,int mes,char tipo, int filial){
    AvlP tmp = (AvlP)malloc(sizeof(avlP));
   char* c = (char*)malloc((strlen(s)+1)*sizeof(char));
   c=strdup(s);
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
  char *c = strdup(s);
  char *produto = strdup(pro);
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
   c = strdup(cli);
   tmp -> codigo = c;
   tmp->TotalComprados=quantidade; 

   if (c[0]>=97 && c[0]<=123) 
        j = ((int)c[0])-97;
    else
        if (c[0]>=64 && c[0]<=90) 
            j = ((int)c[0])-65;

   if(produto!=NULL){
      produto= (char*)malloc((strlen(pro)+1)*sizeof(char));
      produto=strdup(pro);


     if (produto[0]>=97 && produto[0]<=123) 
          k = ((int)produto[0])-97;
      else
          if (produto[0]>=64 && produto[0]<=90) 
              k = ((int)produto[0])-65;

     //for(i=0;i<26;i++) tmp->ListaProdutos[i]=createTreeP();

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



