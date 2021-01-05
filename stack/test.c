/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include "stack.h"

// dummy test
int main() {
    Stack *stack = createstack();

    //Adiciona 3 elementos iniciais.

    Info *info1 = createinfo(12);
    push(stack, info1);

    Info *info2 = createinfo(43);
    push(stack, info2);

    Info *info3 = createinfo(6);
    push(stack, info3);

    // Imprime elementos da pilha
    // Output: TOP [ (6) (43) (12) ] BOTTOM
    printstack(stack);

    // Remove um elemento da pilha
    // Output: TOP [ (43) (12) ] BOTTOM
    pop(stack);
    printstack(stack);

    // Verifica se elemento está na pilha
    if (isinstack(stack, info1)) printf("\nEstá contido na pilha.\n");
    else printf("\nNão está na pilha.\n");

    return 0;
}