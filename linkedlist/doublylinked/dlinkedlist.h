/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

/**
 * Estruturas de dados
 */

typedef struct {
    int value;
} Info;

typedef struct tnode {
    struct tnode *next, *prev;
    Info *info;
} Node;

typedef struct {
    int size;
    Node *first;
} Dlist;

/**
 * Cria cabeça da lista, aloca memória e inicializa campos da struct.
 * 
 * Returna pointer para lista criada.
 */
Dlist *createdlst();

/**
 * Verifica se a lista está vazia.
 * 
 * Retorna int. 1 se estiver vazia, 0 caso contrário.
 */
int isemptydlst(Dlist *lst);

/**
 * Cria nó, aloca memória e inicializa campos.
 * 
 * Retorna pointer para nó criado. NULL caso falhe.
 */
Node *dlstnode();

/**
 * Cria struct de informação, aloca memória e define valor.
 * 
 * Retorna pointer do Info criado. NULL caso falhe.
 */
Info *dlstinfo(int i);

/**
 * Insere elemento na primeira posição da lista.
 * 
 * Retorna int. 1 para sucesso, 0 caso contrário.
 */
int insertfirstdlst(Dlist *lst, Info *info);

/**
 * Deleta primeiro elemento da lista.
 * 
 * Retorna pointer para Info do elemento removido. NULL caso falhe.
 */
Info *delfirstdlst(Dlist *lst);

/**
 * Insere novo elemento na lista encadeada.
 * 
 * Retorna int. 1 para sucesso, 0 caso contrário.
 */
int insertposdlst(Dlist *lst, Info *info, int pos);

/**
 * Deleta elemento em posição específica da lista.
 * 
 * Retorna pointer para Info do elemento removido. NULL caso falhe.
 */
Info *delposdlst(Dlist *lst, int pos);

/**
 * Deleta uma lista e libera memória alocada para seus nós.
 */
void destroydlst(Dlist *lst);

/**
 * Inverte a lista.
 */
void reversedlst(Dlist *lst);

/**
 * Imprime elementos de uma lista.
 */
void printdlst(Dlist *lst);

/**
 * Retorna int indicando tamanho da lista. -1 caso lista não exista.
 * 
 * TODO: Realizar verificação de tamanho sem depender a variável size.
 */
int lendlst(Dlist *lst);

/** 
 * Encontra e retorna um elemento na lista.
 * 
 * Retorna pointer do nó encontrado. NULL caso não exista.
 */
Info *finddlst(Dlist *lst, Info *info);

/**
 * Verifica se uma determinada informação está contida na lista.
 * 
 * Retorna int. 1 caso esteja contido, 0 caso contrário.
 */
int isindlst(Dlist *lst, Info *info);

#endif