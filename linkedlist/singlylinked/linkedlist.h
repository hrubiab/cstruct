/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
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
} InfoList;

typedef struct tnode {
    struct tnode *next;
    InfoList *info;
} NodeList;

typedef struct {
    int size;
    NodeList *first;
} List;

/**
 * Cria cabeça de lista.
 * 
 * Essa função aloca memória e inicializa campos da struct
 * para posterior utilização em lista encadeada.
 * 
 * @return List* pointer para lista criada.
 */
List *createlst();

/**
 * Destroi lista.
 * 
 * Deleta uma lista encadeada liberando a memória alocada para
 * a cabeça da lista e todos os nós que estão ligados a ela.
 * 
 * @param lst ponteiro List da lista encadeada.
 */
void destroylst(List *lst);

/**
 * Verifica se lista está vazia.
 * 
 * @todo Realizar verificação sem depender da variável size.
 * @param lst ponteiro List da lista encadeada.
 * @return int 1 caso vazia, 0 caso contrário.
 */
int isemptylst(List *lst);

/**
 * Verifica posição de informação.
 * 
 * Percorre a lista encadeada para determinar em qual posição
 * está contida uma daterminada informação, caso exista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser buscada.
 * @return int Número positivo indicando qual posição da informação. 
 *             -1 caso não seja encontrada.
 */
int positionlst(List *lst, InfoList *info);

/**
 * Verifica presença de informação na lista.
 * 
 * Percorre a lista encadeada para determinar se uma determinada
 * informação está contida em algum ponto da lista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser buscada.
 * @return int 1 caso exista na lista, 0 caso contrário.
 */
int isinlst(List *lst, InfoList *info);

/** 
 * 
 * Encontra informação na lista.
 * 
 * Percorre a lista encadeada para encontrar e retornar um
 * elemento da lista compatível com os dados solicitados,
 * caso exista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser buscada. 
 * @return InfoList* pointer contendo nó encontrado, ou NULL caso não exista.
 */
InfoList *findlst(List *lst, InfoList *info);

/**
 * Ver tamanho da lista.
 * 
 * Indica qual o tamanho da lista encadeada usando informações
 * contidas na cabeça da própria lista.
 * 
 * @todo Realizar verificação de tamanho sem depender a variável size.
 * @param lst ponteiro List da lista encadeada.
 * @return int Número indicando tamanho da lista. -1 caso lista não exista.
 */
int lenlst(List *lst);

/**
 * Imprime elementos de lista.
 * 
 * Percorre uma lista encadeadaa e imprime todos os seus
 * elementos em linha.
 */
void printlst(List *lst);

/**
 * Cria node.
 * 
 * Cria novo nó alocando memória e inicializando campos da
 * estrutura de dados para uso posterior.
 * 
 * @return NodeList* pointer para nó criado, ou NULL caso falhe.
 */
NodeList *lstnode();

/**
 * Cria estrutura de informação.
 * 
 * Cria nova struct para armazenamento de informação,
 * alocando memória e definindo valor do nó de dados.
 * 
 * @param i valor inteiro a ser guardado na estrutura de informação.
 * @return InfoList* pointer, ou NULL caso falhe.
 */
InfoList *lstinfo(int i);

/**
 * Insere nó no inicio da lista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser gravada em nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int insertfirstlst(List *lst, InfoList *info);

/**
 * Insere nó no fim da lista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser gravado em nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int insertlastlst(List *lst, InfoList *info);

/**
 * Remove primeiro elemento da lista.
 * 
 * @return InfoList* pointer do elemento removido, ou NULL caso falhe.
 */
InfoList *delfirstlst(List *lst);

/**
 * Remove elemento da lista a partir de informação armazenada.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser gravada em nó.
 * @return InfoList* do elemento removido, ou NULL caso falhe.
 */
InfoList *delinfolst(List *lst, InfoList *info);

/**
 * Remove elemento em uma posição da lista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param pos inteiro com posição a ser removida.
 * @return InfoList* do elemento removido, ou NULL caso falhe.
 */
InfoList *delpositionlst(List *lst, int pos);

/**
 * Inverte a lista encadeada.
 * 
 * @param lst ponteiro List da lista encadeada.
 */
void reverselst(List *lst);

/**
 * Ordena lista.
 * 
 * Realiza ordenação da lista utilizando o algoritmo de
 * ordenação bubble sort.
 * 
 * @param lst ponteiro List da lista encadeada.
 */
void sortlst(List *lst);

/**
 * Remove elemento na última posição da lista.
 *
 * @param lst ponteiro List da lista encadeada.s
 * @return InfoList* pointer do elemento removido, ou NULL caso falhe.
 */
InfoList *dellastlst(List *lst);

#endif