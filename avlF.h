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

#ifndef _AVL_H
#define _AVL_H 1

typedef struct avl_tree* Avl_tree;
typedef struct avl* Avl;

typedef struct list{
	char* name;
	struct list* next;
}list;
Avl procura(Avl p, char* cod);
int avl_actualiza(char* s, Avl_tree ptr,double preco,int quantidade,int mes,char tipo,int filial);
double  total(Avl a);
int existeF(char* s, Avl_tree ptr);
Avl createNodeF(char* s,double preco,int quantidade,int mes,char tipom,int filial);
Avl_tree createTreeF();
Avl procuraTree(Avl_tree node, char* cod);

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertF(Avl_tree t,Avl a);
/*
list* inorderTraversalF(Avl a, list* l);
list* copyF(Avl_tree a);
int lengthF(Avl a);
int namesLengthF(Avl_tree a);
*/
#endif /* avl.h */
