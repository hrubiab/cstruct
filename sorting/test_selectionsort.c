/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>

#include "selectionsort.c"

int main() {
    int n, i, j;

    // Identifica quantos elementos devem ser registrados para ordenação
    printf("Quantos elementos: ");
    scanf("%d", &n);

    // Recebe os elementos a serem ordenados
    int *arr = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        printf("%d: ", i);
        scanf("%d", &arr[i]);
    }

    // Realiza a ordenação por selection sort
    selectionsort(arr, n);

    // Imprime a lista já ordenada
    for (j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }
    return 0;
}