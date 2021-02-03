void selectionsort(int *arr, int n) {
    int i, j, min, tmp;

    for (i = 0; i < n-1; i++) {
        min = i;

        // Encontro o elemento mínimo em um vetor
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        // Encontrado o valor minimo, realizo o swap de posições
        tmp = arr[min]; 
        arr[min] = arr[i]; 
        arr[i] = tmp;
    }
}