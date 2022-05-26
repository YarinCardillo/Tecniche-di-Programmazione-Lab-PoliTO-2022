#include <stdio.h>
#include <string.h>
#define maxN 30
#define filein "mat1.txt"

int main() {

    FILE *fin;
    int mat[maxN][maxN], temp;
    int nPosiz=1, n, m, index;
    char selettore[7], direction[6];

    if((fin = fopen(filein, "r"))==NULL) {
        printf("Error opening file\n");
        fflush(stdout);
        return 1;
    }

    // Acquisisco il numero righe n e il numero colonne m della matrice
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);

    // Acquisisco e in seguito stampo la matrice di punti
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fscanf(fin, "%d", &mat[i][j]);
        }
    }
    printf("\nBefore shift:");
    for (int i = 0; i < n; ++i) {
        printf("\n");
        fflush(stdout);
        for (int j = 0; j < m; ++j) {
            printf("%d ", mat[i][j]);
            fflush(stdout);
        }
    }
    printf("\nSpecify: <row/column/end> <index> <up/down | left/right)> <positions (<%d or <%d)>\n", n, m);
    scanf("%s %d %s %d", selettore, &index, direction, &nPosiz);
    index -= 1;
    switch (strcmp(selettore, "row")) {

        case 0:
            switch (strcmp(direction, "left")) {
                case 0:
                    for (int i = 0; i < nPosiz; ++i) {
                        temp = mat[index][0];
                        for (int j = 0; j < m - 1; ++j) {
                            mat[index][j] = mat[index][j + 1];
                        }
                        mat[index][m - 1] = temp;
                    }
                    break;

                case 1:
                    for (int i = 0; i < nPosiz; ++i) {
                        temp = mat[index][m - 1];
                        for (int j = n - 1; j > 0; --j) {
                            mat[index][j] = mat[index][j - 1];
                        }
                        mat[index][0] = temp;
                    }
                    break;
                default:
                    printf("Wrong input\n");
                    fflush(stdout);
            }
            break;
        case -1:
            switch (strcmp(direction, "left")) {
                case 1:
                    for (int i = 0; i < nPosiz; ++i) {
                        temp = mat[0][index];
                        for (int j = 0; j < n - 1; ++j) {
                            mat[j][index] = mat[j + 1][index];
                        }
                        mat[n - 1][index] = temp;
                    }
                    break;

                case -1:
                    for (int i = 0; i < nPosiz; ++i) {
                        temp = mat[n - 1][index];
                        for (int j = n - 1; j > 0; --j) {
                            mat[j][index] = mat[j - 1][index];
                        }
                        mat[0][index] = temp;
                    }
                    break;
                default:
                    printf("Wrong input\n");
                    fflush(stdout);
            }
            break;
        default:
            printf("Wrong input\n");
            fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
    printf("After shift:");
    fflush(stdout);
    for (int i = 0; i < n; ++i) {
        printf("\n");
        fflush(stdout);
        for (int j = 0; j < m; ++j) {
            printf("%d ", mat[i][j]);
            fflush(stdout);
        }
    }

    return 0;
}