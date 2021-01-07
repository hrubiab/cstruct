/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/**
 * Cria cabeça de fila.
 * 
 * Essa função aloca memória e inicializa campos da struct
 * para posterior utilização em fila.
 * 
 * @return Queue* pointer para lista criada.
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
 * Destroi fila.
 * 
 * Deleta umafila liberando a memória alocada para a cabeça
 * da fila e todos os nós que estão ligados a ela.
 * 
 * @param queue ponteiro Queue da fila.
 */
void destroyqueue(Queue *queue) {
    NodeQueue *ptr;

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
 * Cria node.
 * 
 * Cria novo nó alocando memória e inicializando campos da
 * estrutura de dados para uso posterior.
 * 
 * @return NodeQueue* pointer para nó criado, ou NULL caso falhe.
 */
NodeQueue *queuenode() {
    NodeQueue *ptr;
    ptr = (NodeQueue *) malloc(sizeof(NodeQueue));

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
 * Cria estrutura de informação.
 * 
 * Cria nova struct para armazenamento de informação,
 * alocando memória e definindo valor do nó de dados.
 * 
 * @param i valor inteiro a ser guardado na estrutura de informação.
 * @return InfoQueue* pointer, ou NULL caso falhe.
 */
InfoQueue *queueinfo(int i) {
    InfoQueue *ptr;

    ptr = (InfoQueue *) malloc(sizeof(InfoQueue));
    if (ptr) {
        ptr->value = i;
        return ptr;
    }
    return NULL;
}

/**
 * Ver tamanho da fila.
 * 
 * Indica qual o tamanho da fila usando informações
 * contidas na cabeça da própria fila.
 * 
 * @todo Realizar verificação de tamanho sem depender a variável size.
 * @param queue ponteiro Queue da fila.
 * @return int Número indicando tamanho da fila. -1 caso fila não exista.
 */
int lenqueue(Queue *queue) {
    if (!queue) return -1;
    return queue->size;
}

/**
 * Insere elemento na fila.
 * 
 * @param queue ponteiro Queue da fila.
 * @param info ponteiro InfoQueue com informação a ser gravada em nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int insertqueue(Queue *queue, InfoQueue *info) {
    NodeQueue *ptr;
    ptr = queuenode();

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
 * Remove elemento da fila.
 * 
 * @param queue ponteiro Queue para fila.
 * @return InfoQueue* pointer do elemento removido, ou NULL caso falhe.
 */
InfoQueue *removequeue(Queue *queue) {
    NodeQueue *ptr;
    InfoQueue *info;

    if (isemptyqueue(queue)) return NULL;

    ptr = queue->first;
    queue->first = ptr->next;
    info = ptr->info;

    free(ptr);
    queue->size--;
    return info;
}

/**
 * Verifica presença de informação na fila.
 * 
 * Percorre a fila para determinar se uma dada
 * informação está contida em algum ponto da fila.
 * 
 * @param queue ponteiro Queue da fila.
 * @param info ponteiro InfoQueue com informação a ser buscada.
 * @return int 1 caso exista na lista, 0 caso contrário.
 */
int isinqueue(Queue *queue, InfoQueue *info) {
    NodeQueue *ptr;

    if (isemptyqueue(queue)) return 0;

    ptr = queue->first;
    while (ptr != NULL) {
        if (ptr->info->value == info->value) return 1;
        ptr = ptr->next;
    }
    return 0;
}

/**
 * Imprime elementos de fila.
 * 
 * Percorre uma fila e imprime todos os seus
 * elementos em linha.
 * 
 * @param queue ponteirro Queue para fila.
 */
void printqueue(Queue *queue) {
    NodeQueue *ptr;

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
 * 
 * @param queue ponteiro Queue da fila.
 */
void reversequeue(Queue *queue) {
    NodeQueue *prev = NULL;
    NodeQueue *current = queue->first;
    NodeQueue *next;

    if (isemptyqueue(queue)) return;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    queue->first = prev;
}