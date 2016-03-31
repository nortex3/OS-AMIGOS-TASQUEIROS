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

#include "avl.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

 /* Data structures */

/* One element of the AVL tree */
typedef struct avl
{
   char* codigo;
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
void avl_swl(avl** root){
   Avl a=*root;
   Avl b=a->right;
   *root=b;
   a->right=b->left;
   b->left=a;
}

/* Swing to the right
 * Warning: no balance maintainance
 */
void avl_swr(avl** root){
   Avl a=*root;
   Avl b=a->left;
   *root=b;
   a->left=b->right;
   b->right=a;
}

/* Balance maintainance after especially nasty swings
 */
void avl_nasty(Avl root){
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

int existe(char* s, Avl_tree ptr){
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

Avl createNode(char* s){
   Avl tmp = (Avl)malloc(sizeof(avl));
   char* c = (char*)malloc((strlen(s)+1)*sizeof(char));
   strcpy(c, s);
   tmp -> codigo = c;
   return tmp;
}

Avl_tree createTree(){
   Avl_tree tmp = (Avl_tree)malloc(sizeof(avl_tree));
   tmp -> root = NULL;
   return tmp;
}

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insert(Avl_tree t,Avl a)
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
	 if(avl_insert(&left_subtree,a)){
	    switch(t->root->balance--){
	     case 1: return 0;
	     case 0:	return 1;
	    }
	    if(t->root->left->balance<0){
	       avl_swr(&(t->root));
	       t->root->balance=0;
	       t->root->right->balance=0;
	    }else{
	       avl_swl(&(t->root->left));
	       avl_swr(&(t->root));
	       avl_nasty(t->root);
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
	 if(avl_insert(&right_subtree,a)){
	    switch(t->root->balance++){
	     case -1: return 0;
	     case 0: return 1;
	    }
	    if(t->root->right->balance>0){
	       avl_swl(&(t->root));
	       t->root->balance=0;
	       t->root->left->balance=0;
	    }else{
	       avl_swr(&(t->root->right));
	       avl_swl(&(t->root));
	       avl_nasty(t->root);
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

/*list* inorderTraversal(Avl r){
   list* aux, *pr, *fst;
   char* c;
   aux = (list*)malloc(sizeof(list));
   aux -> next = NULL;
   fst = aux;
   if(r != NULL){
      inorderTraversal(r -> left);
      pr = (list*)malloc(sizeof(list));
      c = (char*)malloc((strlen(r->autor)+1)*sizeof(char));
      strcpy(c, r->autor);
      pr -> name = c;
      aux -> next = pr;
      aux = pr;
      printf("%s\n", r->autor);
      inorderTraversal(r -> right);
   }
   fst = fst -> next;
   aux -> next = NULL;
   return fst;
}*/

list* inorderTraversal(Avl a, list* l){
   list* r;
   char* c;
   if(a == NULL) r = l;
   else{
      r = (list*)malloc(sizeof(list));
      c = (char*)malloc((strlen(a->codigo)+1)*sizeof(char));
      strcpy(c, a->codigo);
      r -> name = c;
      r -> next = inorderTraversal(a -> right, l);
      r = inorderTraversal(a -> left, r);
   }
   return r;
}

list* copy(Avl_tree a){
   list* p, *tmp = NULL;
   p = inorderTraversal(a -> root, tmp);
   /*tmp = p;
   while(tmp){
      printf("%s\n", tmp->name);
      tmp = tmp -> next;
   }*/
   return p;
}

int length(Avl a){
   if(!a) return 0;
   return strlen(a -> codigo) + length(a -> left) + length(a -> right);
   
}

int namesLength(Avl_tree a){
    return length(a -> root);
}
