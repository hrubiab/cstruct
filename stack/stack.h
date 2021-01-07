/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
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
} InfoStack;

typedef struct tnode {
    struct tnode *next;
    InfoStack *info;
} NodeStack;

typedef struct {
    int size;
    NodeStack *first;
} Stack;

/**
 * Cria cabeça de pilha.
 * 
 * Essa função aloca memória e inicializa campos da struct
 * para posterior utilização em pilha.
 * 
 * @return Stack* pointer para pilha criada.
 */
Stack *createstack();

/**
 * Destroi pilha.
 * 
 * Deleta uma pilha liberando a memória alocada para
 * a cabeça da pilha e todos os nós que estão ligados a ela.
 * 
 * @param stack ponteiro Stack da pilha.
 */
void destroystack(Stack *stack);

/**
 * Cria estrutura de informação.
 * 
 * Cria nova struct para armazenamento de informação,
 * alocando memória e definindo valor do nó de dados.
 * 
 * @param i valor inteiro a ser guardado na estrutura de informação.
 * @return InfoStack* pointer, ou NULL caso falhe.
 */
InfoStack *stackinfo(int i);

/**
 * Cria node.
 * 
 * Cria novo nó alocando memória e inicializando campos da
 * estrutura de dados para uso posterior.
 * 
 * @return NodeStack* pointer para nó criado, ou NULL caso falhe.
 */
NodeStack *stacknode();

/**
 * Verifica se pilha está vazia.
 * 
 * @todo Realizar verificação sem depender da variável size.
 * @param stack ponteiro Stack da pilha.
 * @return int 1 caso vazia, 0 caso contrário.
 */
int isemptystack(Stack *stack);

/**
 * Imprime elementos de pilha.
 * 
 * Percorre uma pilha e imprime todos os seus
 * elementos em linha.
 * 
 * @param stack ponteirro Stack para pilha.
 */
void printstack(Stack *stack);

/**
 * Empilha novo elemento.
 * 
 * @param stack ponteiro Stack da pilha.
 * @param info ponteiro InfoStack com informação a ser gravada em nó.
 * @return int 1 para sucesso, 0 caso contrário.
 */
int pushstack(Stack *stack, InfoStack *info);

/**
 * Desempilha elemento.
 * 
 * @param stack ponteiro Stack da pilha.
 * @return InfoStack* pointer do elemento removido, ou NULL caso falhe.
 */
InfoStack *popstack(Stack *stack);

/**
 * Ver tamanho da pilha.
 * 
 * Indica qual o tamanho da pilha usando informações
 * contidas na cabeça da própria lista.
 * 
 * @todo Realizar verificação de tamanho sem depender a variável size.
 * @param stack ponteiro Stack da pilha.
 * @return int Número indicando tamanho da pilha. -1 caso pilha não exista.
 */
int lenstack(Stack *stack);

/**
 * Verifica presença de informação na pilha.
 * 
 * Percorre a pilha para determinar se uma determinada
 * informação está contida em algum ponto da pilha.
 * 
 * @param stack ponteiro Stack da pilha.
 * @param info ponteiro InfoStack com informação a ser buscada.
 * @return int 1 caso exista na lista, 0 caso contrário.
 */
int isinstack(Stack *stack, InfoStack *info);

#endif