/**
 * CStruct (C) 2019-2021 https://github.com/henriquerubia/cstruct
 * 
 * @author Carlos Henrique Rubia Barbosa <carlos.h.barbosa@edu.ufes.br>
 * 
 * See LICENSE for terms and licensing notice.
 */


/**
 * Realiza ordenação de elementos em um vetor
 * 
 * Essa função realiza a ordenação dos elementos em um vetor
 * utilizando o algoritmo de ordenação Insertion Sort.
 * 
 * @param arr int pointer contendo vetor
 * @param n int do vetor arr
 */
void insertionsort(int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}