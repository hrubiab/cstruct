/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include "stack.h"

// dummy test
int main() {
    Stack *stack = createstack();

    // Adiciona 3 elementos iniciais.

    InfoStack *info1 = stackinfo(12);
    pushstack(stack, info1);

    InfoStack *info2 = stackinfo(43);
    pushstack(stack, info2);

    InfoStack *info3 = stackinfo(6);
    pushstack(stack, info3);

    // Imprime elementos da pilha
    // Output: TOP [ (6) (43) (12) ] BOTTOM
    printstack(stack);

    // Remove um elemento da pilha
    // Output: TOP [ (43) (12) ] BOTTOM
    popstack(stack);
    printstack(stack);

    // Verifica se elemento está na pilha
    if (isinstack(stack, info1)) printf("\nEstá contido na pilha.\n");
    else printf("\nNão está na pilha.\n");

    return 0;
}