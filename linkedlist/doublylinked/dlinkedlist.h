/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

/**
 * Estruturas de dados
 */

typedef struct {
    int value;
} Info;

typedef struct tnode {
    struct tnode *next, *prev;
    Info *info;
} Node;

typedef struct {
    int size;
    Node *first;
} Dlist;

/**
 * Cria cabeça de lista.
 * 
 * Essa função aloca memória e inicializa campos da struct
 * para posterior utilização em lista encadeada.
 * 
 * @return Dlist* pointer para lista criada.
 */
Dlist *createdlst();

/**
 * Verifica se lista está vazia.
 * 
 * @todo Realizar verificação sem depender da variável size.
 * @param lst ponteiro Dlist da lista encadeada.
 * @return int 1 caso vazia, 0 caso contrário.
 */
int isemptydlst(Dlist *lst);

/**
 * Cria node.
 * 
 * Cria novo nó alocando memória e inicializando campos da
 * estrutura de dados para uso posterior.
 * 
 * @return Node* pointer para nó criado, ou NULL caso falhe.
 */
Node *dlstnode();

/**
 * Cria estrutura de informação.
 * 
 * Cria nova struct para armazenamento de informação,
 * alocando memória e definindo valor do nó de dados.
 * 
 * @param i valor inteiro a ser guardado na estrutura de informação.
 * @return Info* pointer, ou NULL caso falhe.
 */
Info *dlstinfo(int i);

/**
 * Insere nó no inicio da lista.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 * @param info ponteiro Info com informação a ser gravada em nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int insertfirstdlst(Dlist *lst, Info *info);

/**
 * Remove primeiro elemento da lista.
 * 
 * @param lst ponteiro Dlist para lista encadeada.
 * @return Info* pointer do elemento removido, ou NULL caso falhe.
 */
Info *delfirstdlst(Dlist *lst);

/**
 * Insere nó em uma posição da lista.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 * @param info ponteiro Info com informação a ser gravada em nó.
 * @param pos posição para inserir o nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int insertposdlst(Dlist *lst, Info *info, int pos);

/**
 * Remove elemento em uma posição da lista.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 * @param pos inteiro com posição a ser removida.
 * @return Info* do elemento removido, ou NULL caso falhe.
 */
Info *delposdlst(Dlist *lst, int pos);

/**
 * Destroi lista.
 * 
 * Deleta uma lista encadeada liberando a memória alocada para
 * a cabeça da lista e todos os nós que estão ligados a ela.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 */
void destroydlst(Dlist *lst);

/**
 * Inverte a lista encadeada.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 */
void reversedlst(Dlist *lst);

/**
 * Imprime elementos de lista.
 * 
 * Percorre uma lista encadeadaa e imprime todos os seus
 * elementos em linha.
 * 
 * @param lst ponteiro Dlist para lista encadeada.
 */
void printdlst(Dlist *lst);

/**
 * Ver tamanho da lista.
 * 
 * Indica qual o tamanho da lista encadeada usando informações
 * contidas na cabeça da própria lista.
 * 
 * @todo Realizar verificação de tamanho sem depender a variável size.
 * @param lst ponteiro Dlist da lista encadeada.
 * @return int Número indicando tamanho da lista. -1 caso lista não exista.
 */
int lendlst(Dlist *lst);

/** 
 * Encontra informação na lista.
 * 
 * Percorre a lista encadeada para encontrar e retornar um
 * elemento da lista compatível com os dados solicitados,
 * caso exista.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 * @param info ponteiro Info com informação a ser buscada. 
 * @return Info* pointer contendo nó encontrado, ou NULL caso não exista.
 */
Info *finddlst(Dlist *lst, Info *info);

/**
 * Verifica presença de informação na lista.
 * 
 * Percorre a lista encadeada para determinar se uma determinada
 * informação está contida em algum ponto da lista.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 * @param info ponteiro Info com informação a ser buscada.
 * @return int 1 caso exista na lista, 0 caso contrário.
 */
int isindlst(Dlist *lst, Info *info);

#endif