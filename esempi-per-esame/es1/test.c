#include <stdio.h>
#define N 7

void countingSort(int *array, int n);

int main() {
    int A[N] = {1, 4, 1, 2, 7, 5, 2};

    for (int i = 0; i < N; ++i) {
        fprintf(stdout, "Unsorted array = %d\n", A[i]);
    }

    countingSort(A, N);

    fprintf(stdout, "\n");
    for (int i = 0; i < N; ++i) {
        fprintf(stdout, "Sorted array = %d\n", A[i]);
    }
    return 0;
}

void countingSort(int *array, int n){

    int sortedArray[n+1];
    int max = array[0];

    for (int i = 0; i < n; ++i) {
        if(array[i] > max)
            max = array[i];
    }
    max++;
    int occurrenciesArray[max];
    for (int i = 0; i < max; ++i) {
        occurrenciesArray[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        occurrenciesArray[array[i]]++;
    }

    for (int i = 1; i < max; ++i) {
        occurrenciesArray[i] = occurrenciesArray[i] + occurrenciesArray[i-1];
    }

    for (int i = 0; i < n; ++i) {
        sortedArray[occurrenciesArray[array[i]]] = array[i];
        occurrenciesArray[array[i]]--;
    }

    for (int i = 0; i < n; ++i) {
        array[i] = sortedArray[i+1];
    }
}