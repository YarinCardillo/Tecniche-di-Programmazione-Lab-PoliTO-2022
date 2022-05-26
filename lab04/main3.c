#include <stdio.h>
#define R 20
#define C 20
int main() {

    FILE *fin;
    int matrice[R][C], matriceMax[R][C], nr, nc, dim, dimr, dimc, maxDim, maxK, maxH, sum = 0, max = 0, f, g;
    char filein[20];

    printf("Inserire nome file di input:\n");
    scanf("%s", filein);
    printf("\n");

    if((fin = fopen(filein, "r")) == NULL){
        printf("Error opening file");
        return 1;
    }

    fscanf(fin, "%d %d", &nr, &nc);

    if(nr < nc)
        maxDim = nr;
    else
        maxDim = nc;

    printf("Matrice di partenza:\n");
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j)
            fscanf(fin, "%d", &matrice[i][j]);
    }
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j)
            printf("%d ", matrice[i][j]);
        printf("\n");
    }
    printf("\n");

    do {
        printf("Inserire dimensione sottomatrici da trovare (1 <= dim <= %d, con dim intero):\n", maxDim);
        scanf("%d", &dim);
        printf("\n");
        if(dim >= 1 && dim <= maxDim) {
            dimr = dim;
            dimc = dim;
            maxK = nr - dim;
            maxH = nc - dim;
            for (int k = 0; k <= maxK; ++k) {
                for (int h = 0; h <= maxH; ++h) {
                    for (int i = k; i < dimr; ++i) {
                        for (int j = h; j < dimc; ++j) {
                            printf("%d ", matrice[i][j]);
                            sum += matrice[i][j];
                        }
                        printf("\n");
                    }
                    if (sum > max) {
                        max = sum;
                        f = 0;
                        g = 0;
                        for (int i = k; i < dimr; ++i) {
                            for (int j = h; j < dimc; ++j) {
                                matriceMax[f][g] = matrice[i][j];
                                g++;
                            }
                            f++;
                            g = 0;
                        }
                    }
                    sum = 0;

                    dimc++;
                    printf("\n");
                }
                dimc = dim;
                dimr++;
            }
            printf("La sottomatrice con somma degli elementi massima (%d) e':\n", max);
            for (int i = 0; i < dim; ++i) {
                for (int j = 0; j < dim; ++j) {
                    printf("%d ", matriceMax[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    } while (dim >= 1 && dim <= maxDim);

    fclose(fin);
    return 0;
}