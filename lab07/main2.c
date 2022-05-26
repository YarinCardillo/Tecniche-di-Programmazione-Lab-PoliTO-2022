#include <stdio.h>
#define filein "sort.txt"
#define MAXL 100

void selectionSort(int A[], int N, int riga);
void insertionSort(int A[], int N, int riga);
void shellSort(int A[], int N, int riga);


void selectionSort(int A[], int N, int riga){
    int l=0, r=N-1, min, scambi = 0, iterazioniEsterno = 0, iterazioniInterno = 0;
    int temp;
    fprintf(stdout, "*** SELECTION SORT (%d)***\n", riga+1);
    for (int i = l; i < r; i++) {
        min = i;
        for (int j = i + 1; j <= r; j++) {
            if (A[j] < A[min])
                min = j;
            if (min != i) {
                temp = A[i];
                A[i] = A[min];
                A[min] = temp;
                scambi++;
                iterazioniInterno++;
            }
        }
        iterazioniEsterno++;
        fprintf(stdout, "IEst: %d, IInt: %d\n", iterazioniEsterno, iterazioniInterno);
    }
    fprintf(stdout, "TotScambi: %d, TotIEst: %d, TotI: %d\n", scambi, iterazioniEsterno, (iterazioniEsterno+iterazioniInterno));
    for (int i = 0; i < N; ++i)
        fprintf(stdout, "%d ", A[i]);
    fprintf(stdout, "\n\n");
}


void insertionSort(int A[], int N, int riga){
    int j, l, r, x, scambi = 0, iterazioniEsterno = 0, iterazioniInterno = 0;
    l = 0;
    r = N - 1;
    fprintf(stdout, "*** INSERTION SORT (%d)***\n", riga+1);
    for (int i = l+1; i <= r; ++i)
    {
        x = A[i];
        j = i - 1;
        while(j >= l && x < A[j]){
            A[j+1] = A[j];
            scambi++;
            iterazioniInterno++;
            j--;
        }
        A[j+1] = x;
        scambi++;
        iterazioniEsterno++;
        fprintf(stdout, "IEst: %d, IInt: %d\n", iterazioniEsterno, iterazioniInterno);
    }
    fprintf(stdout, "TotScambi: %d, TotIEst: %d, TotI: %d\n", scambi, iterazioniEsterno, (iterazioniEsterno+iterazioniInterno));
    for (int i = 0; i < N; ++i)
        fprintf(stdout, "%d ", A[i]);
    fprintf(stdout, "\n\n");
}


void shellSort(int A[], int N, int riga){
    int j, x, l=0, h=1, r=N-1, scambi=0, iterazioniInterno=0, iterazioniEsterno=0;
    fprintf(stdout, "*** SHELL SORT (%d)***\n", riga+1);
    while(h < N/3)
        h = 3*h+1;
    while(h >= 1) {
        for (int i = l + h; i <= r; i++) {
            j = i;
            x = A[i];
            while (j >= l + h && x < A[j - h]) {
                A[j] = A[j - h];
                j -= h;
                scambi++;
                iterazioniInterno++;
            }
            A[j] = x;
            iterazioniInterno++;

        }
        h = h/3;
        iterazioniEsterno++;
        fprintf(stdout, "IEst: %d, IInt: %d\n", iterazioniEsterno, iterazioniInterno);
    }
    fprintf(stdout, "TotScambi: %d, TotIEst: %d, TotI: %d\n", scambi, iterazioniEsterno, (iterazioniEsterno+iterazioniInterno));
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
    int array[MAXL], selectionArray[MAXL], insertionArray[MAXL], shellArray[MAXL];
    fscanf(fin, "%d", &lunghezzaFile);

    fprintf(stdout, "LEGENDA\n"
                    "IEst = Iterazioni ciclo esterno\n"
                    "IInt = Iterazioni ciclo interno\n"
                    "TotScambi = Totale scambi effettuati\n"
                    "TotIEst = Totale iterazioni ciclo esterno\n"
                    "TotI = Totale iterazioni\n\n");

    for (int i = 0; i < lunghezzaFile; ++i)
    {
        fscanf(fin, "%d", &lunghezzaRiga);
        for (int j = 0; j < lunghezzaRiga; ++j)
            fscanf(fin, "%d", &array[j]);

        // SELECTION SORT
        for (int j = 0; j < lunghezzaRiga; ++j) {
            selectionArray[j] = array[j];
        }
        selectionSort(selectionArray, lunghezzaRiga, i);

        // INSERTION SORT
        for (int j = 0; j < lunghezzaRiga; ++j) {
            insertionArray[j] = array[j];
        }
        insertionSort(insertionArray, lunghezzaRiga, i);

        // SHELL SORT
        for (int j = 0; j < lunghezzaRiga; ++j) {
            shellArray[j] = array[j];
        }
        shellSort(shellArray, lunghezzaRiga, i);
    }
    return 0;
}