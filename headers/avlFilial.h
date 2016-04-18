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

/* Funções auxiliares das arvores */
AvlP procuraP(AvlP p, char* cod);
int avl_actualizaP(char* s, Avl_treeP ptr,int quantidade,int preco,int mes,char tipo,int filial);
int existeFP(char* s, Avl_treeP ptr);
AvlP createNodeP(char* s,int quantidade,double preco,int mes,char tipo, int filial);
Avl_treeP createTreeP();
int contaNodosGF(AvlC a);
int contaNodosPGF(AvlP a);
AvlP procuraTreeP(Avl_treeP node, char* cod);
AvlP createNodePro(Avl_treeP p);
AvlC createNodeCli(Avl_treeC c);

/*Queries*/
void calculaListaProdutos(AvlC a, int *mes);
void calculaVendas(AvlP p, int *tot);
int totalProdsVendidos(AvlP p);
int percorreProdutosClientes8(AvlC clientes, char* cod, int index,int flag, char** aux,int filial,char tipo);
int percorreProdutos8(AvlC c,char* cod,int index,int flag, char** aux,int filial,char tipo);
int percorre8(AvlP p, char* cod ,int flag,int filial,char tipo);
int percorreClientesAux(AvlC cli,int r[], char** aux, int index);
int percorreClientesAux9(AvlC cli,int mes, char** aux, int index);
int percorreProdutos10F1(AvlP p, char** lista, int uv[], int index, int n);
int percorreProdutos10F2(AvlP p, char** lista, int uv[], int index, int n);
int percorreProdutos10F3(AvlP p, char** lista, int uv[], int index, int n);
int percorreProdutosCliente11(AvlC c, char** aux);

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertP(Avl_treeP t,AvlP a);

/* AVLC*/


AvlC procuraC(AvlC p, char* cod);
int avl_actualizaC(char* s,char* pro, Avl_treeC ptr,int quantidade,double preco,int mes,char tipo,int filial);
int existeC(char* s, Avl_treeC ptr);
AvlC createNodeC(char* cli,char* pro,int quantidade,double preco,int mes,char tipo, int filial);
Avl_treeC createTreeC();
AvlC procuraTreeC(Avl_treeC node, char* cod);
int totalProdsComprados(AvlC c);

/* Public methods */

/* Insert element a into the AVL tree t
 * returns 1 if the depth of the tree has grown
 * Warning: do not insert elements already present
 */
int avl_insertC(Avl_treeC t,AvlC a);


#endif /* avlFilial.h */
