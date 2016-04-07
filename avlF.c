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

#include "headers/avlF.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define NORMAL 0
#define PROMO 1

 /* Data structures */

/* One element of the AVL tree */
typedef struct avl
{
   char* codigo;
   int TotalVendidas; /* Total de unidades vendidas de cada produto*/
   int UnidadesVendidas[12][2]; /* Unidades vendidas cada mes de cada tipo*/
   double Faturacao[12][2]; /*valor de cada mes e tipo*/
   double TotalFaturado; /*preco*quant*/

   double TotalFatFilial1[12][2];
   double TotalFatFilial2[12][2];
   double TotalFatFilial3[12][2];

   int TotalUniFilial1[12][2];
   int TotalUniFilial2[12][2];
   int TotalUniFilial3[12][2];

   struct avl* left;
   struct avl* right;
   signed char balance;
} avl;


/* An AVL tree */
typedef struct avl_tree
{
   avl* root;
} avl_tree;

/* Private methods */

/* Swing to the left
 * Warning: no balance maintainance
 */
void avl_swlF(avl** root){
   Avl a=*root;
   Avl b=a->right;
   *root=b;
   a->right=b->left;
   b->left=a;
}

/* Swing to the right
 * Warning: no balance maintainance
 */
void avl_swrF(avl** root){
   Avl a=*root;
   Avl b=a->left;
   *root=b;
   a->left=b->right;
   b->right=a;
}

/* Balance maintainance after especially nasty swings
 */
void avl_nastyF(Avl root){
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

int existeF(char* s, Avl_tree ptr){
   Avl p = ptr -> root;
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

int avl_actualiza(char* s, Avl_tree ptr,double preco,int quantidade,int mes,char tipo,int filial){
   Avl tmp = ptr->root;
   Avl p = procura(tmp,s);
   if(!p) return 0;
   else{

      p->TotalVendidas+=quantidade;
      p->TotalFaturado+= quantidade*preco; 

      if(tipo=='N'){
         p->UnidadesVendidas[mes-1][NORMAL] +=quantidade;
         p->Faturacao[mes-1][NORMAL]+= quantidade*preco;

         if(filial==1){
            p->TotalUniFilial1[mes-1][NORMAL] +=quantidade;
            p->TotalFatFilial1[mes-1][NORMAL] +=quantidade*preco;
          }else{
              if(filial==2){

                p->TotalUniFilial2[mes-1][NORMAL] +=quantidade;
                p->TotalFatFilial2[mes-1][NORMAL] +=quantidade*preco;
              } else {

                  if(filial==3){

                    p->TotalUniFilial3[mes-1][NORMAL] +=quantidade;
                    p->TotalFatFilial3[mes-1][NORMAL] +=quantidade*preco;
                  }
                }
              }

       }else{
      
          p->UnidadesVendidas[mes-1][PROMO] +=quantidade;
          p->Faturacao[mes-1][PROMO]+= quantidade*preco;

          if(filial==1){
            p->TotalUniFilial1[mes-1][PROMO] +=quantidade;
            p->TotalFatFilial1[mes-1][PROMO] +=quantidade*preco;
          }else{
          
              if(filial==2){

                p->TotalUniFilial2[mes-1][PROMO] +=quantidade;
                p->TotalFatFilial2[mes-1][PROMO] +=quantidade*preco;
              }else{
                  p->TotalUniFilial3[mes-1][PROMO] +=quantidade;
                  p->TotalFatFilial3[mes-1][PROMO] +=quantidade*preco;
                }
              }
            }
   }
   return 1;

}

Avl procuraTree(Avl_tree p, char* cod){
   Avl node = p -> root;
   if(node == NULL) return 0;
   if (strcmp(cod,node->codigo) == 0) return node;
    else if (strcmp(cod,node->codigo) < 0) return procura(node->left, cod);
    else return procura(node->right, cod);
}

/* Funcao de teste*/

double total(Avl a){
  double r = a->TotalFatFilial2[7][PROMO];
printf("%d\n",a->TotalVendidas );
printf("%f\n",a->TotalFaturado );
   return r;
}

/*----------------------*/


Avl procura(Avl node, char* cod){
   if(node == NULL) return 0;
   if (strcmp(cod,node->codigo) == 0) return node;
    else if (strcmp(cod,node->codigo) < 0) return procura(node->left, cod);
    else return procura(node->right, cod);
}

Avl createNodeF(char* s,double preco,int quantidade,int mes,char tipo, int filial){
    Avl tmp = (Avl)malloc(sizeof(avl));
   char* c = (char*)malloc((strlen(s)+1)*sizeof(char));
   strcpy(c, s);
   tmp -> codigo = c;
   tmp->TotalVendidas=quantidade; 
   tmp->TotalFaturado=quantidade*preco; 

   if(tipo=='N'){
      tmp->UnidadesVendidas[mes-1][NORMAL]= quantidade;
      tmp->Faturacao[mes-1][NORMAL]= quantidade*preco;

      if(filial==1){
        tmp->TotalUniFilial1[mes-1][NORMAL] =quantidade;
        tmp->TotalFatFilial1[mes-1][NORMAL] =quantidade*preco;
      } 
        if(filial==2){

        tmp->TotalUniFilial2[mes-1][NORMAL] =quantidade;
        tmp->TotalFatFilial2[mes-1][NORMAL] =quantidade*preco;
      }
     

      if(filial==3){

        tmp->TotalUniFilial3[mes-1][NORMAL] =quantidade;
        tmp->TotalFatFilial3[mes-1][NORMAL] =quantidade*preco;
      }
    

     }else{
      
        tmp->UnidadesVendidas[mes-1][PROMO] = quantidade;
        tmp->Faturacao[mes-1][PROMO]= quantidade*preco;

        if(filial==1){
          tmp->TotalUniFilial1[mes-1][PROMO] =quantidade;
          tmp->TotalFatFilial1[mes-1][PROMO] =quantidade*preco;
        }
        if(filial==2){

          tmp->TotalUniFilial2[mes-1][PROMO] =quantidade;
          tmp->TotalFatFilial2[mes-1][PROMO] =quantidade*preco;
        }

        if(filial==3){

          tmp->TotalUniFilial3[mes-1][PROMO] =quantidade;
          tmp->TotalFatFilial3[mes-1][PROMO] =quantidade*preco;
        }
      }
   return tmp;
}

Avl_tree createTreeF(){
   Avl_tree tmp = (Avl_tree)malloc(sizeof(avl_tree));
   tmp -> root = NULL;
   return tmp;
}

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertF(Avl_tree t,Avl a)
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
	 avl_tree left_subtree;
	 left_subtree.root=t->root->left;
	 if(avl_insertF(&left_subtree,a)){
	    switch(t->root->balance--){
	     case 1: return 0;
	     case 0:	return 1;
	    }
	    if(t->root->left->balance<0){
	       avl_swrF(&(t->root));
	       t->root->balance=0;
	       t->root->right->balance=0;
	    }else{
	       avl_swlF(&(t->root->left));
	       avl_swrF(&(t->root));
	       avl_nastyF(t->root);
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
	 avl_tree right_subtree;
	 right_subtree.root=t->root->right;
	 if(avl_insertF(&right_subtree,a)){
	    switch(t->root->balance++){
	     case -1: return 0;
	     case 0: return 1;
	    }
	    if(t->root->right->balance>0){
	       avl_swlF(&(t->root));
	       t->root->balance=0;
	       t->root->left->balance=0;
	    }else{
	       avl_swrF(&(t->root->right));
	       avl_swlF(&(t->root));
	       avl_nastyF(t->root);
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

