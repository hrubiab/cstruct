/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include "queue.h"

int main() {
    Queue *queue = createqueue();

    // Cria 3 elementos iniciais
    Info *info1 = createinfo(33);
    insertqueue(queue, info1);

    Info *info2 = createinfo(65);
    insertqueue(queue, info2);

    Info *info3 = createinfo(122);
    insertqueue(queue, info3);

    // Imprime elementos na fila
    // Output: [ (33) (65) (122) ]
    printqueue(queue);

    // Remove um elemento da fila
    // Output: [ (65) (122) ]
    removequeue(queue);
    printqueue(queue);

    // Inverte a fila
    // Output: [ (122) (65) ]
    reversequeue(queue);
    printqueue(queue);

    return 0;
}