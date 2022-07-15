#include <stdio.h>
#define filein "sort.txt"
#define MAXL 100

void insertionSort(int A[], int N, int riga){
    int j, x;
    fprintf(stdout, "*** INSERTION SORT (%d)***\n", riga+1);
    for (int i = 1; i < N; ++i)
    {
        x = A[i];
        j = i;
        while(j >= 0 && x < A[j-1]){
            A[j] = A[j-1];
            j--;
        }
        A[j] = x;
    }
    for (int i = 0; i < N; ++i)
        fprintf(stdout, "%d ", A[i]);
    fprintf(stdout, "\n\n");
}

void bubbleSort(int A[], int N, int riga){
    int temp;
    fprintf(stdout, "*** BUBBLE SORT (%d)***\n", riga+1);
    for (int i = 0; i < N-1; ++i)
    {
        for (int j = 0; j < N-1 - i; ++j) {
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < N; ++i)
        fprintf(stdout, "%d ", A[i]);
    fprintf(stdout, "\n\n");
}

void selectionSort(int A[], int N, int riga){
    int temp, min;
    fprintf(stdout, "*** SELECTION SORT (%d)***\n", riga+1);
    for (int i = 0; i < N-1; i++) {
        min = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
    for (int i = 0; i < N; ++i)
        fprintf(stdout, "%d ", A[i]);
    fprintf(stdout, "\n\n");
}

int main(){

    FILE *fin;
    if((fin = fopen(filein, "r")) == NULL){
        fprintf(stdout, "Error opening file\n");
        return -1;
    }
    int lunghezzaFile, lunghezzaRiga;
    int array[MAXL], insertionArray[MAXL], bubbleArray[MAXL], selectionArray[MAXL];
    fscanf(fin, "%d", &lunghezzaFile);

    for (int i = 0; i < lunghezzaFile; ++i) {
        fscanf(fin, "%d", &lunghezzaRiga);
        for (int j = 0; j < lunghezzaRiga; ++j)
            fscanf(fin, "%d", &array[j]);


        // INSERTION SORT
        for (int j = 0; j < lunghezzaRiga; ++j) {
            insertionArray[j] = array[j];
        }
        insertionSort(insertionArray, lunghezzaRiga, i);

        // BUBBLE SORT
        for (int j = 0; j < lunghezzaRiga; ++j) {
            bubbleArray[j] = array[j];
        }
        bubbleSort(bubbleArray, lunghezzaRiga, i);

        // SELECTION SORT
        for (int j = 0; j < lunghezzaRiga; ++j) {
            selectionArray[j] = array[j];
        }
        selectionSort(selectionArray, lunghezzaRiga, i);

    }

    return 0;
}