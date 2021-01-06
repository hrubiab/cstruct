/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

/**
 * Cria cabeça da lista, aloca memória e inicializa campos da struct.
 * 
 * Returna pointer para lista criada.
 */
Dlist *createdlst() {
    Dlist *ptr;
    ptr = (Dlist *) malloc(sizeof(Dlist));

    if (ptr) {
        ptr->size = 0;
        ptr->first = NULL;
        return ptr;
    }
    return NULL;
}

/**
 * Verifica se a lista está vazia.
 * 
 * Retorna int. 1 se estiver vazia, 0 caso contrário.
 */
int isemptydlst(Dlist *lst) {
    return (!lst || lst->size == 0);
}

/**
 * Cria nó, aloca memória e inicializa campos.
 * 
 * Retorna pointer para nó criado. NULL caso falhe.
 */
Node *dlstnode() {
    Node *ptr;
    ptr = (Node *) malloc(sizeof(Node));

    if (ptr) {
        ptr->info = NULL;
        ptr->next = NULL;
        return ptr;
    }
    return NULL;
}

/**
 * Cria struct de informação, aloca memória e define valor.
 * 
 * Retorna pointer do Info criado. NULL caso falhe.
 */
Info *dlstinfo(int i) {
    Info *ptr;

    ptr = (Info *) malloc(sizeof(Info));
    if (ptr) {
        ptr->value = i;
        return ptr;
    }
    return NULL;
}

/**
 * Insere elemento na primeira posição da lista.
 * 
 * Retorna int. 1 para sucesso, 0 caso contrário.
 */
int insertfirstdlst(Dlist *lst, Info *info) {
    Node *ptr;
    ptr = dlstnode();

    if (!lst || !ptr) return 0;

    ptr->info = info;
    ptr->next = lst->first;
    if (ptr->next != NULL) ptr->next->prev = ptr;
    lst->first = ptr;

    lst->size++;
    return 1;
}

/**
 * Deleta primeiro elemento da lista.
 * 
 * Retorna pointer para Info do elemento removido. NULL caso falhe.
 */
Info *delfirstdlst(Dlist *lst) {
    Node *ptr;
    Info *info;

    if (isemptydlst(lst)) return NULL;

    ptr = lst->first;
    lst->first = ptr->next;
    if (lst->first != NULL) lst->first->prev = NULL;
    info = ptr->info;


    free(ptr);
    lst->size--;
    return info;
}

/**
 * Insere novo elemento na lista encadeada.
 * 
 * Retorna int. 1 para sucesso, 0 caso contrário.
 */
int insertposdlst(Dlist *lst, Info *info, int pos) {
    Node *ptr, *aux;
    aux = dlstnode();
    int i;

    if (!lst || !ptr) return 0;
    
    aux->info = info;

    if (lst->first == NULL) lst->first = aux;
    else {
        ptr = lst->first;
        for (i = 1; i < pos && ptr->next != NULL; i++, ptr = ptr->next);
        if (i < pos) {
            ptr->next = aux;
            aux->prev = ptr;
        }
        else {
            if (ptr->prev != NULL) {
                ptr->prev->next = aux;
                aux->prev = ptr->prev;
            }
            else lst->first = aux;
            aux->next = ptr;
            ptr->prev = aux;
        }
    }
    lst->size++;
    return 1;
}

/**
 * Deleta elemento em posição específica da lista.
 * 
 * Retorna pointer para Info do elemento removido. NULL caso falhe.
 */
Info *delposdlst(Dlist *lst, int pos) {
    Node *ptr;
    Info *info;
    int i;

    if (isemptydlst(lst) || pos > lst->size || pos <= 0) return NULL;

    ptr = lst->first;
    for (i = 1; i < pos; i++, ptr = ptr->next);
    if (ptr->prev != NULL) ptr->prev->next = ptr->next;
    else lst->first = ptr->next;
    if (ptr->next != NULL) ptr->next->prev = ptr->prev;
    info = ptr->info;

    free(ptr);
    lst->size--;
    return info;
}

/**
 * Deleta uma lista e libera memória alocada para seus nós.
 */
void destroydlst(Dlist *lst) {
    Node *ptr;
    if (!lst) return;
    while (lst->first) {
        ptr = lst->first->next;
        free(lst->first->info);
        free(lst->first);
        lst->first = ptr;
    }
    free(lst);
}

/**
 * Inverte a lista.
 */
void reversedlst(Dlist *lst) {
    Node *prev = NULL, *current, *next;

    if (isemptydlst(lst) || lst->size == 1) return;

    current = lst->first;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    lst->first = prev;
}

/**
 * Imprime elementos de uma lista.
 */
void printdlst(Dlist *lst) {
    Node *ptr;

    if (isemptydlst(lst)) return;

    printf("\n[ ");
    ptr = lst->first;

    while (ptr != NULL) {
        printf("(%d) ", ptr->info->value);
        ptr = ptr->next;
    }
    printf("]\n");
}

/**
 * Retorna int indicando tamanho da lista. -1 caso lista não exista.
 * 
 * TODO: Realizar verificação de tamanho sem depender a variável size.
 */
int lendlst(Dlist *lst) {
    if (!lst) return -1;
    return lst->size;
}

/** 
 * Encontra e retorna um elemento na lista.
 * 
 * Retorna pointer do nó encontrado. NULL caso não exista.
 */
Info *finddlst(Dlist *lst, Info *info) {
    Node *ptr;

    if (isemptydlst(lst)) return NULL;
    
    for (ptr = lst->first; ptr; ptr = ptr->next) {
        if (ptr->info->value == info->value) return ptr->info;
    }
    return NULL;
}

/**
 * Verifica se uma determinada informação está contida na lista.
 * 
 * Retorna int. 1 caso esteja contido, 0 caso contrário.
 */
int isindlst(Dlist *lst, Info *info) {
    Node *ptr;

    if (isemptydlst(lst)) return 0;
    ptr = lst->first;
    while (ptr != NULL) {
        if (ptr->info->value == info->value) return 1;
        ptr = ptr->next;
    }
    return 0;
}