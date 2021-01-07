/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**
 * Cria cabeça de lista.
 * 
 * Essa função aloca memória e inicializa campos da struct
 * para posterior utilização em lista encadeada.
 * 
 * @return List* pointer para lista criada.
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
 * Destroi lista.
 * 
 * Deleta uma lista encadeada liberando a memória alocada para
 * a cabeça da lista e todos os nós que estão ligados a ela.
 * 
 * @param lst ponteiro List da lista encadeada.
 */
void destroylst(List *lst) {
    NodeList *ptr;

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
 * Verifica se lista está vazia.
 * 
 * @todo Realizar verificação sem depender da variável size.
 * @param lst ponteiro List da lista encadeada.
 * @return int 1 caso vazia, 0 caso contrário.
 */
int isemptylst(List *lst) {
    return (!lst || lst->size == 0);
}

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
int positionlst(List *lst, InfoList *info) {
    int pos;
    NodeList *ptr;

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
 * Verifica presença de informação na lista.
 * 
 * Percorre a lista encadeada para determinar se uma determinada
 * informação está contida em algum ponto da lista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser buscada.
 * @return int 1 caso exista na lista, 0 caso contrário.
 */
int isinlst(List *lst, InfoList *info) {
    NodeList *ptr;

    if (isemptylst(lst)) return 0;
    ptr = lst->first;
    while (ptr != NULL) {
        if (ptr->info->value == info->value) return 1;
        ptr = ptr->next;
    }
    return 0;
}

/** 
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
InfoList *findlst(List *lst, InfoList *info) {
    NodeList *ptr;

    if (isemptylst(lst)) return NULL;
    
    for (ptr = lst->first; ptr; ptr=ptr->next) {
        if (ptr->info->value == info->value) return ptr->info;
    }
    return NULL;
}

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
int lenlst(List *lst) {
    if (!lst) return -1;
    return lst->size;
}

/**
 * Imprime elementos de lista.
 * 
 * Percorre uma lista encadeada e imprime todos os seus
 * elementos em linha.
 * 
 * @param lst ponteirro List para lista encadeada.
 */
void printlst(List *lst) {
    NodeList *ptr;

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
 * Cria node.
 * 
 * Cria novo nó alocando memória e inicializando campos da
 * estrutura de dados para uso posterior.
 * 
 * @return NodeList* pointer para nó criado, ou NULL caso falhe.
 */
NodeList *lstnode() {
    NodeList *ptr;
    ptr = (NodeList *) malloc(sizeof(NodeList));

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
 * @return InfoList* pointer, ou NULL caso falhe.
 */
InfoList *lstinfo(int i) {
    InfoList *ptr;

    ptr = (InfoList *) malloc(sizeof(InfoList));
    if (ptr) {
        ptr->value = i;
        return ptr;
    }
    return NULL;
}

/**
 * Insere nó no inicio da lista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser gravada em nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int insertfirstlst(List *lst, InfoList *info) {
    NodeList *ptr;
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
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser gravado em nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int insertlastlst(List *lst, InfoList *info) {
    NodeList *ptr, *aux;
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
 * Remove primeiro elemento da lista.
 * 
 * @param lst ponteiro List para lista encadeada.
 * @return InfoList* pointer do elemento removido, ou NULL caso falhe.
 */
InfoList *delfirstlst(List *lst) {
    NodeList *ptr;
    InfoList *info;

    if (isemptylst(lst)) return NULL;

    ptr = lst->first;
    lst->first = ptr->next;
    info = ptr->info;

    free(ptr);
    lst->size--;

    return info;
}

/**
 * Remove elemento da lista a partir de informação armazenada.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param info ponteiro InfoList com informação a ser gravada em nó.
 * @return InfoList* do elemento removido, ou NULL caso falhe.
 */
InfoList *delinfolst(List *lst, InfoList *info) {
    NodeList *ptr, *aptr;
    InfoList *ainfo;

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
 * Remove elemento em uma posição da lista.
 * 
 * @param lst ponteiro List da lista encadeada.
 * @param pos inteiro com posição a ser removida.
 * @return InfoList* do elemento removido, ou NULL caso falhe.
 */
InfoList *delpositionlst(List *lst, int pos) {
    NodeList *aptr, *ptr;
    InfoList *info;
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
 * 
 * @param lst ponteiro List da lista encadeada.
 */
void reverselst(List *lst) {
    NodeList *prev = NULL;
    NodeList *current = lst->first;
    NodeList *next;

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
 * Ordena lista.
 * 
 * Realiza ordenação da lista utilizando o algoritmo de
 * ordenação bubble sort.
 * 
 * @param lst ponteiro List da lista encadeada.
 */
void sortlst(List *lst) {
    int i, j, k;
    InfoList *tempInfo;
    NodeList *current;
    NodeList *next;

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
 * Remove elemento na última posição da lista.
 *
 * @param lst ponteiro List da lista encadeada.s
 * @return InfoList* pointer do elemento removido, ou NULL caso falhe.
 */
InfoList *dellastlst(List *lst) {
    NodeList *ptr, *aptr;
    InfoList *info;

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