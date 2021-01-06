/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#ifndef QUEUE_H
#define QUEUE_H

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
    Node *first, *last;
} Queue;

/**
 * Cria cabeça de uma fila, aloca memória e inicializa campos da struct.
 * 
 * Retorna pointer para fila criada.
 */
Queue *createqueue();

/**
 * Deleta uma fila e libera memória alocada para todos os nós contidos na fila.
 */
void destroyqueue(Queue *queue);

/**
 * Cria nó, aloca memória e inicializa campos.
 * 
 * Retorna pointer para nó criado. NULL caso falhe.
 */
Node *queuenode();

/**
 * Verifica se uma fila está vazia.
 * 
 * TODO: Realizar verificação sem depender da variável size.
 * 
 * Retorna int. 1 caso esteja vazia, 0 caso contrário.
 */
int isemptyqueue(Queue *queue);

/**
 * Cria struct de informação, aloca memória e define valor.
 * 
 * Retorna pointer do Info criado. NULL caso falhe.
 */
Info *queueinfo(int i);

/**
 * Retorna int indicando tamanho da fila. -1 caso lista não exista.
 * 
 * TODO: Realizar verificação de tamanho sem depender a variável size.
 */
int lenqueue(Queue *queue);

/**
 * Insere elemento ao fim de uma fila.
 * 
 * Retorna int. 1 em caso de sucesso, 0 caso contrário.
 */
int insertqueue(Queue *queue, Info *info);

/**
 * Remove um elemento no inicio da fila.
 * 
 * Retorna pointer para Info do elemento removido. NULL caso falhe.
 */
Info *removequeue(Queue *queue);

/**
 * Verifica se uma determinada informação está contida na fila.
 * 
 * Retorna int. 1 caso esteja contido, 0 caso contrário.
 */
int isinqueue(Queue *queue, Info *info);

/**
 * Imprime os elementos da fila.
 */
void printqueue(Queue *queue);

/**
 * Inverte a fila.
 */
void reversequeue(Queue *queue);

#endif