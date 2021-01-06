/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * Estruturas de dados
 */

typedef struct {
    int value;
} Info;

typedef struct tnode {
    struct tnode *next;
    Info *info;
} Node;

typedef struct {
    int size;
    Node *first;
} List;

/**
 * Cria cabeça de uma lista, aloca memória e inicializa campos da struct.
 * 
 * Retorna pointer para lista criada.
 */
List *createlst();

/**
 * Deleta uma lista e libera memória alocada para todos os nós na lista.
 */
void destroylst(List *lst);

/**
 * Verifica se uma lista está vazia.
 * 
 * TODO: Realizar verificação sem depender da variável size.
 * 
 * Retorna int. 1 caso esteja vazia, 0 caso contrário.
 */
int isemptylst(List *lst);

/**
 * Retorna em qual posiçãop da lista está uma daterminada informação.
 * 
 * Retorna int positivo indicando posição. -1 caso não exista.
 */
int positionlst(List *lst, Info *info);

/**
 * Verifica se uma determinada informação está contida na lista.
 * 
 * Retorna int. 1 caso esteja contido, 0 caso contrário.
 */
int isinlst(List *lst, Info *info);

/** 
 * Encontra e retorna um elemento na lista.
 * 
 * Retorna pointer do nó encontrado. NULL caso não exista.
 */
Info *findlst(List *lst, Info *info);

/**
 * Retorna int indicando tamanho da lista. -1 caso lista não exista.
 * 
 * TODO: Realizar verificação de tamanho sem depender a variável size.
 */
int lenlst(List *lst);

/**
 * Imprime elementos de uma dada lista.
 */
void printlst(List *lst);

/**
 * Cria nó, aloca memória e inicializa campos.
 * 
 * Retorna pointer para nó criado. NULL caso falhe.
 */
Node *lstnode();

/**
 * Cria struct de informação, aloca memória e define valor.
 * 
 * Retorna pointer do Info criado. NULL caso falhe.
 */
Info *lstinfo(int i);

/**
 * Insere nó no começo da lista.
 * 
 * Retorna int. 1 para sucesso, 0 caso contrário.
 */
int insertfirstlst(List *lst, Info *info);

/**
 * Insere nó no fim da lista.
 * 
 * Retorna int. 1 para sucesso, 0 caso contrário.
 */
int insertlastlst(List *lst, Info *info);

/**
 * Remove o elemento na primeira posição da lista.
 * 
 * Retorna Info do elemento removido. NULL caso falhe.
 */
Info *delfirstlst(List *lst);

/**
 * Remove elemento da lista que contém determinada informação.
 * 
 * Retorna Info do elemento removido. NULL caso falhe.
 */
Info *delinfolst(List *lst, Info *info);

/**
 * Remove da lista o elemento em determinada posição.
 * 
 * Retorna Info do elemento removido. NULL caso falhe.
 */
Info *delpositionlst(List *lst, int pos);

/**
 * Inverte a lista encadeada.
 */
void reverselst(List *lst);

/**
 * Realiza ordenação da lista usando algoritmo de ordenação bubble sort.
 */
void sortlst(List *lst);

/**
 * Remove o elemento na última posição da lista.
 *
 * Retorna Info do elemento removido. NULL caso falhe.
 */
Info *dellastlst(List *lst);

#endif