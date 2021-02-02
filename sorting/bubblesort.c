/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Realiza ordenação de elementos em um vetor
 * 
 * Essa função realiza a ordenação dos elementos em um vetor
 * utilizando o algoritmo de ordenação Bubble Sort.
 * 
 * @param arr int pointer contendo vetor
 * @param n int do vetor arr
 */
void bubblesort(int *arr, int n) {
    int i, j, tmp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}