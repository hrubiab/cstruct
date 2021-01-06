/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#ifndef STACK_H
#define STACK_H

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
} Stack;

/**
 * Cria cabeça de uma pilha, aloca memória e inicializa campos da struct.
 * 
 * Retorna pointer para pilha criada.
 */
Stack *createstack();

/**
 * Deleta uma pilha e libera memória alocada de todos os nós contidos nela.
 */
void destroystack(Stack *stack);

/**
 * Cria struct de informação, aloca memória e define valor.
 * 
 * Retorna pointer do Info criado. NULL caso falhe.
 */
Info *stackinfo(int i);

/**
 * Cria nó, aloca memória e inicializa campos.
 * 
 * Retorna pointer para nó criado. NULL caso falhe.
 */
Node *stacknode();

/**
 * Verifica se uma pilha está vazia.
 * 
 * TODO: Realizar verificação sem depender da variável size.
 * 
 * Retorna int. 1 caso esteja vazia, 0 caso contrário.
 */
int isemptystack(Stack *stack);

/**
 * Imprime os elementos da fila.
 */
void printstack(Stack *stack);

/**
 * Empilha novo elemento.
 */
int pushstack(Stack *stack, Info *info);

/**
 * Desempilha elemento mais recente da pilha.
 */
Info *popstack(Stack *stack);

/**
 * Retorna int indicando tamanho da pilha. -1 caso lista não exista.
 * 
 * TODO: Realizar verificação de tamanho sem depender a variável size.
 */
int lenstack(Stack *stack);

/**
 * Verifica se uma determinada informação está contida na pilha.
 * 
 * Retorna int. 1 caso esteja contido, 0 caso contrário.
 */
int isinstack(Stack *stack, Info *info);

#endif