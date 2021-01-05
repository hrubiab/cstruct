/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * Cria cabeça de uma fila, aloca memória e inicializa campos da struct.
 * 
 * Retorna pointer para fila criada.
 */
Queue *createqueue() {
    Queue *ptr;
    ptr = (Queue *) malloc(sizeof(Queue));
    if (ptr) {
        ptr->size = 0;
        ptr->first = ptr->last;
        return ptr;
    }
    return NULL;
}

/**
 * Deleta uma fila e libera memória alocada para todos os nós contidos na fila.
 */
void destroyqueue(Queue *queue) {
    Node *ptr;

    if (!queue) return;

    while (queue->first) {
        ptr = queue->first->next;
        free(queue->first->info);
        free(queue->first);
        queue->first = ptr;
    }
    free(queue);
}

/**
 * Cria nó, aloca memória e inicializa campos.
 * 
 * Retorna pointer para nó criado. NULL caso falhe.
 */
Node *createnode() {
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
 * Verifica se uma fila está vazia.
 * 
 * TODO: Realizar verificação sem depender da variável size.
 * 
 * Retorna int. 1 caso esteja vazia, 0 caso contrário.
 */
int isemptyqueue(Queue *queue) {
    return (!queue || queue->size == 0);
}

/**
 * Cria struct de informação, aloca memória e define valor.
 * 
 * Retorna pointer do Info criado. NULL caso falhe.
 */
Info *createinfo(int i) {
    Info *ptr;

    ptr = (Info *) malloc(sizeof(Info));
    if (ptr) {
        ptr->value = i;
        return ptr;
    }
    return NULL;
}

/**
 * Retorna int indicando tamanho da fila. -1 caso lista não exista.
 * 
 * TODO: Realizar verificação de tamanho sem depender a variável size.
 */
int lenqueue(Queue *queue) {
    if (!queue) return -1;
    return queue->size;
}

/**
 * Insere elemento ao fim de uma fila.
 * 
 * Retorna int. 1 em caso de sucesso, 0 caso contrário.
 */
int insertqueue(Queue *queue, Info *info) {
    Node *ptr;
    ptr = createnode();

    if (!queue || !ptr) return 0;

    ptr->info = info;
    ptr->next = NULL;

    if (lenqueue(queue) == 0) queue->first = ptr;
    else queue->last->next = ptr;

    queue->last = ptr;
    queue->size++;
    return 1;
}

/**
 * Remove um elemento no inicio da fila.
 * 
 * Retorna pointer para Info do elemento removido. NULL caso falhe.
 */
Info *removequeue(Queue *queue) {
    Node *ptr;
    Info *info;

    if (isemptyqueue(queue)) return NULL;

    ptr = queue->first;
    queue->first = ptr->next;
    info = ptr->info;

    free(ptr);
    queue->size--;
    return info;
}

/**
 * Verifica se uma determinada informação está contida na fila.
 * 
 * Retorna int. 1 caso esteja contido, 0 caso contrário.
 */
int isinqueue(Queue *queue, Info *info) {
    Node *ptr;

    if (isemptyqueue(queue)) return 0;

    ptr = queue->first;
    while (ptr != NULL) {
        if (ptr->info->value == info->value) return 1;
        ptr = ptr->next;
    }
    return 0;
}

/**
 * Imprime os elementos da fila.
 */
void printqueue(Queue *queue) {
    Node *ptr;

    if (isemptyqueue(queue)) return;

    printf("\n[ ");
    ptr = queue->first;

    while (ptr != NULL) {
        printf("(%d) ", ptr->info->value);
        ptr = ptr->next;
    }
    printf("]\n");
}

/**
 * Inverte a fila.
 */
void reversequeue(Queue *queue) {
    Node *prev = NULL;
    Node *current = queue->first;
    Node *next;

    if (isemptyqueue(queue)) return;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    queue->first = prev;
}