/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include "queue.h"

int main() {
    Queue *queue = createqueue();

    // Cria 3 elementos iniciais
    InfoQueue *info1 = queueinfo(33);
    insertqueue(queue, info1);

    InfoQueue *info2 = queueinfo(65);
    insertqueue(queue, info2);

    InfoQueue *info3 = queueinfo(122);
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