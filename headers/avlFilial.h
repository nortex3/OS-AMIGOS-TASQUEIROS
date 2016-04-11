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

#ifndef _AVLFILIAL_H
#define _AVLFILIAL_H 1

typedef struct avl_treeP* Avl_treeP;
typedef struct avl_treeC* Avl_treeC;

typedef struct avlP* AvlP;
typedef struct avlC* AvlC;


AvlP procuraP(AvlP p, char* cod);
int avl_actualizaP(char* s, Avl_treeP ptr,int quantidade,int mes,char tipo,int filial);
int existeFP(char* s, Avl_treeP ptr);
AvlP createNodeP(char* s,int quantidade,int mes,char tipo, int filial);
Avl_treeP createTreeP();
AvlP procuraTreeP(Avl_treeP node, char* cod);
void calculaListaProdutos(AvlC a, int *mes);
void calculaVendas(AvlP p, int *tot);
int percorreClientesAux(AvlC cli,int r[], char** aux, int index);
AvlP createNodePro(Avl_treeP p);
AvlC createNodeCli(Avl_treeC c);

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertP(Avl_treeP t,AvlP a);

/* AVLC*/


AvlC procuraC(AvlC p, char* cod);
int avl_actualizaC(char* s,char* pro, Avl_treeC ptr,int quantidade,int mes,char tipo,int filial);
int existeC(char* s, Avl_treeC ptr);
AvlC createNodeC(char* cli,char* pro,int quantidade,int mes,char tipo, int filial);
Avl_treeC createTreeC();
AvlC procuraTreeC(Avl_treeC node, char* cod);

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertC(Avl_treeC t,AvlC a);


#endif /* avlFilial.h */
