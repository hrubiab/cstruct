/**
 * CStruct (2019) https://github.com/henriquerubia/cstruct
 * 
 * Copyright (C) Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include "linkedlist.h"

// dummy test
int main() {
    List *lst = createlst();

    // Cria 3 nós.
    Info *info1 = createinfo(87);
    insertlastlst(lst, info1);

    Info *info2 = createinfo(23);
    insertlastlst(lst, info2);

    Info *info3 = createinfo(543);
    insertlastlst(lst, info3);

    // Imprime lista com elementos adicionados.
    // Output: [ (87) (23) (543) ]
    printlst(lst);

    // Inverte elementos da lista.
    // Output: [ (543) (23) (87) ]
    reverselst(lst);
    printlst(lst);

    // Ordena elementos da lista.
    // Output: [ (23) (87) (543) ]
    sortlst(lst);
    printlst(lst);

    // Remove elemento na primeira posição da lista.
    // Output: [ (87) (543) ]
    delfirstlst(lst);
    printlst(lst);

    return 0;
}