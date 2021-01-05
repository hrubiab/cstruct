/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * Cria cabeça de uma pilha, aloca memória e inicializa campos da struct.
 * 
 * Retorna pointer para pilha criada.
 */
Stack *createstack() {
    Stack *ptr;
    ptr = (Stack *) malloc(sizeof(Stack));

    if (ptr) {
        ptr->size = 0;
        ptr->first = NULL;
        return ptr;
    }
    return NULL;
}

/**
 * Deleta uma pilha e libera memória alocada de todos os nós contidos nela.
 */
void destroystack(Stack *stack) {
    Node *ptr;

    if (!stack) return;

    while (stack->first) {
        ptr = stack->first->next;
        free(stack->first->info);
        free(stack->first);
        stack->first = ptr;
    }
    free(stack);
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
 * Verifica se uma pilha está vazia.
 * 
 * TODO: Realizar verificação sem depender da variável size.
 * 
 * Retorna int. 1 caso esteja vazia, 0 caso contrário.
 */
int isemptystack(Stack *stack) {
    return (!stack || stack->size == 0);
}

/**
 * Imprime os elementos da fila.
 */
void printstack(Stack *stack) {
    Node *ptr;

    if (isemptystack(stack)) return;

    printf("\n TOP [ ");
    ptr = stack->first;

    while (ptr != NULL) {
        printf("(%d) ", ptr->info->value);
        ptr = ptr->next;
    }
    printf("] BOTTOM\n");
}

/**
 * Empilha novo elemento.
 */
int push (Stack *stack, Info *info) {
    Node *ptr;
    ptr = createnode();

    if (!stack || !ptr) return 0;

    ptr->info = info;
    ptr->next = stack->first;
    stack->first = ptr;
    
    stack->size++;
    return 1;
}

/**
 * Desempilha elemento mais recente da pilha.
 */
Info *pop(Stack *stack) {
    Node *ptr;
    Info *info;

    if (isemptystack(stack)) return NULL;

    ptr = stack->first;
    stack->first = ptr->next;
    info = ptr->info;

    free(ptr);
    stack->size--;
    return info;

}

/**
 * Retorna int indicando tamanho da pilha. -1 caso lista não exista.
 * 
 * TODO: Realizar verificação de tamanho sem depender a variável size.
 */
int lenstack(Stack *stack) {
    if (!stack) return -1;
    return stack->size;
}

/**
 * Verifica se uma determinada informação está contida na pilha.
 * 
 * Retorna int. 1 caso esteja contido, 0 caso contrário.
 */
int isinstack(Stack *stack, Info *info) {
    Node *ptr;

    if (isemptystack(stack)) return 0;

    ptr = stack->first;
    while (ptr != NULL) {
        if (ptr->info->value == info->value) return 1;
        ptr = ptr->next;
    }
    return 0;
}