/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

/**
 * Cria cabeça de lista.
 * 
 * Essa função aloca memória e inicializa campos da struct
 * para posterior utilização em lista encadeada.
 * 
 * @return Dlist* pointer para lista criada.
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
 * Verifica se lista está vazia.
 * 
 * @todo Realizar verificação sem depender da variável size.
 * @param lst ponteiro Dlist da lista encadeada.
 * @return int 1 caso vazia, 0 caso contrário.
 */
int isemptydlst(Dlist *lst) {
    return (!lst || lst->size == 0);
}

/**
 * Cria node.
 * 
 * Cria novo nó alocando memória e inicializando campos da
 * estrutura de dados para uso posterior.
 * 
 * @return Node* pointer para nó criado, ou NULL caso falhe.
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
 * Cria estrutura de informação.
 * 
 * Cria nova struct para armazenamento de informação,
 * alocando memória e definindo valor do nó de dados.
 * 
 * @param i valor inteiro a ser guardado na estrutura de informação.
 * @return Info* pointer, ou NULL caso falhe.
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
 * Insere nó no inicio da lista.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 * @param info ponteiro Info com informação a ser gravada em nó.
 * @return int 1 para sucesso, 0 caso contrário.
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
 * Remove primeiro elemento da lista.
 * 
 * @param lst ponteiro Dlist para lista encadeada.
 * @return Info* pointer do elemento removido, ou NULL caso falhe.
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
 * Insere nó em uma posição da lista.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 * @param info ponteiro Info com informação a ser gravada em nó.
 * @param pos posição para inserir o nó.
 * @return int 1 para sucesso, 0 caso contrário.
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
 * Remove elemento em uma posição da lista.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
 * @param pos inteiro com posição a ser removida.
 * @return Info* do elemento removido, ou NULL caso falhe.
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
 * Destroi lista.
 * 
 * Deleta uma lista encadeada liberando a memória alocada para
 * a cabeça da lista e todos os nós que estão ligados a ela.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
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
 * Inverte a lista encadeada.
 * 
 * @param lst ponteiro Dlist da lista encadeada.
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
 * Imprime elementos de lista.
 * 
 * Percorre uma lista encadeadaa e imprime todos os seus
 * elementos em linha.
 * 
 * @param lst ponteiro Dlist para lista encadeada.
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
 * Ver tamanho da lista.
 * 
 * Indica qual o tamanho da lista encadeada usando informações
 * contidas na cabeça da própria lista.
 * 
 * @todo Realizar verificação de tamanho sem depender a variável size.
 * @param lst ponteiro Dlist da lista encadeada.
 * @return int Número indicando tamanho da lista. -1 caso lista não exista.
 */
int lendlst(Dlist *lst) {
    if (!lst) return -1;
    return lst->size;
}

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
Info *finddlst(Dlist *lst, Info *info) {
    Node *ptr;

    if (isemptydlst(lst)) return NULL;
    
    for (ptr = lst->first; ptr; ptr = ptr->next) {
        if (ptr->info->value == info->value) return ptr->info;
    }
    return NULL;
}

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