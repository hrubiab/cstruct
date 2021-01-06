/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**
 * Cria cabeça de uma lista, aloca memória e inicializa campos da struct.
 * 
 * Retorna pointer para lista criada.
 */
List *createlst() {
    List *ptr;
    ptr = (List *) malloc(sizeof(List));

    if (ptr) {
        ptr->size = 0;
        ptr->first = NULL;
        return ptr;
    }
    return NULL;
}


/**
 * Deleta uma lista e libera memória alocada para todos os nós na lista.
 */
void destroylst(List *lst) {
    Node *ptr;

    if (!lst) return;

    while (lst->first) {
        ptr = lst->first->next;
        free(lst->first->info);
        free(lst->first);
        lst->first = ptr;
    }
    free(ptr);
}

/**
 * Verifica se uma lista está vazia.
 * 
 * TODO: Realizar verificação sem depender da variável size.
 * 
 * Retorna int. 1 caso esteja vazia, 0 caso contrário.
 */
int isemptylst(List *lst) {
    return (!lst || lst->size == 0);
}

/**
 * Retorna em qual posiçãop da lista está uma daterminada informação.
 * 
 * Retorna int positivo indicando posição. -1 caso não exista.
 */
int positionlst(List *lst, Info *info) {
    int pos;
    Node *ptr;

    if (isemptylst(lst)) return -1;
    pos = 0;
    ptr = lst->first;

    while (ptr != NULL) {
        if (ptr->info->value == info->value) return pos;
        pos++;
        ptr = ptr->next;
    }
    return -1;
}

/**
 * Verifica se uma determinada informação está contida na lista.
 * 
 * Retorna int. 1 caso esteja contido, 0 caso contrário.
 */
int isinlst(List *lst, Info *info) {
    Node *ptr;

    if (isemptylst(lst)) return 0;
    ptr = lst->first;
    while (ptr != NULL) {
        if (ptr->info->value == info->value) return 1;
        ptr = ptr->next;
    }
    return 0;
}

/** 
 * Encontra e retorna um elemento na lista.
 * 
 * Retorna pointer do nó encontrado. NULL caso não exista.
 */
Info *findlst(List *lst, Info *info) {
    Node *ptr;

    if (isemptylst(lst)) return NULL;
    
    for (ptr = lst->first; ptr; ptr=ptr->next) {
        if (ptr->info->value == info->value) return ptr->info;
    }
    return NULL;
}

/**
 * Retorna int indicando tamanho da lista. -1 caso lista não exista.
 * 
 * TODO: Realizar verificação de tamanho sem depender a variável size.
 */
int lenlst(List *lst) {
    if (!lst) return -1;
    return lst->size;
}

/**
 * Imprime elementos de uma dada lista.
 */
void printlst(List *lst) {
    Node *ptr;

    if (isemptylst(lst)) return;

    printf("\n[ ");
    ptr = lst->first;

    while (ptr != NULL) {
        printf("(%d) ", ptr->info->value);
        ptr = ptr->next;
    }
    printf("]\n");
}

/**
 * Cria nó, aloca memória e inicializa campos.
 * 
 * Retorna pointer para nó criado. NULL caso falhe.
 */
Node *lstnode() {
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
Info *lstinfo(int i) {
    Info *ptr;

    ptr = (Info *) malloc(sizeof(Info));
    if (ptr) {
        ptr->value = i;
        return ptr;
    }
    return NULL;
}

/**
 * Insere nó no começo da lista.
 * 
 * Retorna int. 1 para sucesso, 0 caso contrário.
 */
int insertfirstlst(List *lst, Info *info) {
    Node *ptr;
    ptr = lstnode();

    if (!lst || !ptr) return 0;

    ptr->info = info;
    ptr->next = lst->first;
    lst->first = ptr;
    lst->size++;
    return 1;
}

/**
 * Insere nó no fim da lista.
 * 
 * Retorna int. 1 para sucesso, 0 caso contrário.
 */
int insertlastlst(List *lst, Info *info) {
    Node *ptr, *aux;
    ptr = lstnode();

    if (!lst || !ptr) return 0;
    
    ptr->info = info;

    if (lst->first == NULL) lst->first = ptr;
    else {
        aux = lst->first;
        while (aux->next != NULL) aux = aux->next;
        aux->next = ptr;
    }

    lst->size++;
    return 1;
}

/**
 * Remove o elemento na primeira posição da lista.
 * 
 * Retorna Info do elemento removido. NULL caso falhe.
 */
Info *delfirstlst(List *lst) {
    Node *ptr;
    Info *info;

    if (isemptylst(lst)) return NULL;

    ptr = lst->first;
    lst->first = ptr->next;
    info = ptr->info;

    free(ptr);
    lst->size--;

    return info;
}

/**
 * Remove elemento da lista que contém determinada informação.
 * 
 * Retorna Info do elemento removido. NULL caso falhe.
 */
Info *delinfolst(List *lst, Info *info) {
    Node *ptr, *aptr;
    Info *ainfo;

    ptr = lst->first;

    while (ptr->info->value != ainfo->value) {
        if (ptr->next == NULL) return NULL;
        else {
            aptr = ptr;
            ptr = ptr->next;
        }
    }

    if (ptr == lst->first) lst->first = ptr->next;
    else aptr->next = ptr->next;

    ainfo = ptr->info;
    free(ptr);
    lst->size--;
    return ainfo;
}

/**
 * Remove da lista o elemento em determinada posição.
 * 
 * Retorna Info do elemento removido. NULL caso falhe.
 */
Info *delpositionlst(List *lst, int pos) {
    Node *aptr, *ptr;
    Info *info;
    int count = 1;

    if (isemptylst(lst) || pos > lst->size || pos <= 0) {
        printf("\nImpossivel retirar elemento!\n");
        return NULL;
    }

    if (pos == 1) {
        ptr = lst->first;
        lst->first = ptr->next;
    }
    else {
        aptr = lst->first;
        for (count = 1; count < pos-1; count++, aptr = aptr->next);
        ptr = aptr->next;
        aptr->next = ptr->next;
    }

    info = ptr->info;
    free(ptr);
    lst->size--;
    return info;
}

/**
 * Inverte a lista encadeada.
 */
void reverselst(List *lst) {
    Node *prev = NULL;
    Node *current = lst->first;
    Node *next;

    if (isemptylst(lst)) return;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    lst->first = prev;
}

/**
 * Realiza ordenação da lista usando algoritmo de ordenação bubble sort.
 */
void sortlst(List *lst) {
    int i, j, k;
    Info *tempInfo;
    Node *current;
    Node *next;

    k = lst->size;
    if (isemptylst(lst)) return;

    for (i = 0; i < (lst->size - 1); i++, k--) {
        current = lst->first;
        next = lst->first->next;
        for (j = 1; j < k; j++) {
            if (current->info->value > next->info->value) {
                tempInfo = current->info;
                current->info = next->info;
                next->info = tempInfo;
            }
            current = current->next;
            next = next->next;
        }
    }
}

/**
 * Remove o elemento na última posição da lista.
 *
 * Retorna Info do elemento removido. NULL caso falhe.
 */
Info *dellastlst(List *lst) {
    Node *ptr, *aptr;
    Info *info;

    if (isemptylst(lst)) return NULL;

    ptr = lst->first;

    if (lst->size == 1) lst->first = ptr->next;
    else {
        aptr = ptr;
        ptr = ptr->next;

        while (ptr->next != NULL) {
            aptr = ptr;
            ptr = ptr->next;
        }
        aptr->next = ptr->next;
    }
    info = ptr->info;

    free(ptr);
    lst->size--;
    return info;
}