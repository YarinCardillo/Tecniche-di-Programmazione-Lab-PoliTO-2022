#include <stdio.h>
#define N 20
#define M 20
#define filein "mat.txt"
int main() {
    int campionato[N][M], capo[N];
    FILE *fin;
    int n, m, max=0, maxCapo = 0;
    if((fin = fopen(filein, "r"))==NULL){
        printf("Error opening file\n");
        return 1;
    }
    // Acquisisco il numero righe n e il numero colonne m della matrice
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);
    printf("Tabella punti:\n");

    // Acquisisco e in seguito stampo la matrice di punti
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fscanf(fin, "%d", &campionato[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = 0; j < m; ++j) {
            printf("%d  ", campionato[i][j]);
            fflush(stdout);
        }
    }
    // Inizializzo a zeri il vettore per tenere traccia di ciascuna capolista per giornata
    for (int i = 0; i < n; ++i) {
        capo[i] = 0;
    }
    printf("\n");

    // Calcolo e stampo capolista di ciascuna giornata
    for (int i = 0; i < m; ++i) {
        printf("\n");
        for (int j = 0; j < n; ++j) {
            capo[j] += campionato[j][i];
        }
        for (int j = 0; j < n; ++j) {
            if(capo[j] > maxCapo) {
                max = j;
                maxCapo = capo[j];
            }
        }
        printf("Capolista giornata n.%d = squadra %d", i+1, max+1);
        max = 0;
    }
    return 0;
}
