/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include "dlinkedlist.h"

// dummy test
int main() {
    Dlist *lst = createdlst();

    // Adiciona 3 elementos iniciais.

    Info *info1 = dlstinfo(21);
    insertfirstdlst(lst, info1);

    Info *info2 = dlstinfo(22);
    insertfirstdlst(lst, info2);

    Info *info3 = dlstinfo(24);
    insertfirstdlst(lst, info3);

    // Imprime os elementos da lista
    // Output: [ (24) (22) (21) ]
    printdlst(lst);

    // Deleta primeiro elemento da lista
    // Output: [ (22) (21) ]
    delfirstdlst(lst);
    printdlst(lst);

    return 0;
}