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

int existe(char* s, Avl_tree ptr);
Avl createNode(char* s);
Avl_tree createTree();
Avl createCharNode(Avl_tree a);
int toArrayClientesAux(Avl clientes, int index, char** aux);
int toArrayProdutosAux(Avl produtos, int index, char** aux);


/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insert(Avl_tree t,Avl a);

#endif /* avl.h */
