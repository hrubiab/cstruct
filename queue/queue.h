/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
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
 * Cria cabeça de fila.
 * 
 * Essa função aloca memória e inicializa campos da struct
 * para posterior utilização em fila.
 * 
 * @return Queue* pointer para lista criada.
 */
Queue *createqueue();

/**
 * Destroi fila.
 * 
 * Deleta umafila liberando a memória alocada para a cabeça
 * da fila e todos os nós que estão ligados a ela.
 * 
 * @param queue ponteiro Queue da fila.
 */
void destroyqueue(Queue *queue);

/**
 * Cria node.
 * 
 * Cria novo nó alocando memória e inicializando campos da
 * estrutura de dados para uso posterior.
 * 
 * @return Node* pointer para nó criado, ou NULL caso falhe.
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
 * Cria estrutura de informação.
 * 
 * Cria nova struct para armazenamento de informação,
 * alocando memória e definindo valor do nó de dados.
 * 
 * @param i valor inteiro a ser guardado na estrutura de informação.
 * @return Info* pointer, ou NULL caso falhe.
 */
Info *queueinfo(int i);

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
int lenqueue(Queue *queue);

/**
 * Insere elemento na fila.
 * 
 * @param queue ponteiro Queue da fila.
 * @param info ponteiro Info com informação a ser gravada em nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int insertqueue(Queue *queue, Info *info);

/**
 * Remove elemento da fila.
 * 
 * @param queue ponteiro Queue para fila.
 * @return Info* pointer do elemento removido, ou NULL caso falhe.
 */
Info *removequeue(Queue *queue);

/**
 * Verifica presença de informação na fila.
 * 
 * Percorre a fila para determinar se uma dada
 * informação está contida em algum ponto da fila.
 * 
 * @param queue ponteiro Queue da fila.
 * @param info ponteiro Info com informação a ser buscada.
 * @return int 1 caso exista na lista, 0 caso contrário.
 */
int isinqueue(Queue *queue, Info *info);

/**
 * Imprime elementos de fila.
 * 
 * Percorre uma fila e imprime todos os seus
 * elementos em linha.
 * 
 * @param queue ponteirro Queue para fila.
 */
void printqueue(Queue *queue);

/**
 * Inverte a fila.
 * 
 * @param queue ponteiro Queue da fila.
 */
void reversequeue(Queue *queue);

#endif