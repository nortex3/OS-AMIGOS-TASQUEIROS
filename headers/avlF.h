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


Avl procura(Avl p, char* cod);
int avl_actualiza(char* s, Avl_tree ptr,double preco,int quantidade,int mes,char tipo,int filial);
int existeF(char* s, Avl_tree ptr);
Avl createNodeF(char* s,double preco,int quantidade,int mes,char tipom,int filial);
Avl_tree createTreeF();
int contaNodos(Avl a);
Avl procuraTree(Avl_tree node, char* cod);
Avl createCharNodeF(Avl_tree a);
void RecolheInfoNodo(Avl p,int mes, double array[]);
void RecolheInfoNodoFilial(Avl p,int mes, double array[]);
int toArrayProdutosAuxNaoVendidos(Avl produtos, int index, char** aux);
int toArrayProdutosAuxNaoVendidosF1(Avl produtos, int index, char** aux);
int toArrayProdutosAuxNaoVendidosF2(Avl produtos, int index, char** aux);
int toArrayProdutosAuxNaoVendidosF3(Avl produtos, int index, char** aux);
int calculaNaoComprados(Avl pro,int total);


/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertF(Avl_tree t,Avl a);
#endif /* avl.h */
