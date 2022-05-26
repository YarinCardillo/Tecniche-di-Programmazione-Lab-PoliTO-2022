#include <stdio.h>
#include <string.h>
#define maxN 30

void ruota(int matrix[maxN][maxN], int P, char dir[6], char select[7], int ind, int nrows, int mcolumns);

void ruota(int matrix[maxN][maxN], int P, char dir[6], char select[7], int ind, int nrows, int mcolumns){

    int temp;
    switch (strcmp(select, "row")) {

        case 0:
            switch (strcmp(dir, "left")) {
                case 0:
                    for (int i = 0; i < P; ++i) {
                        temp = matrix[ind][0];
                        for (int j = 0; j < mcolumns - 1; ++j) {
                            matrix[ind][j] = matrix[ind][j + 1];
                        }
                        matrix[ind][mcolumns - 1] = temp;
                    }
                    break;
                case 1:
                    for (int i = 0; i < P; ++i) {
                        temp = matrix[ind][mcolumns - 1];
                        for (int j = nrows - 1; j > 0; --j) {
                            matrix[ind][j] = matrix[ind][j - 1];
                        }
                        matrix[ind][0] = temp;
                    }
                    break;
                default:
                    printf("Wrong input\n");
            }
            break;

        case -1:
            switch (strcmp(dir, "left")) {
                case 1:
                    for (int i = 0; i < P; ++i) {
                        temp = matrix[0][ind];
                        for (int j = 0; j < nrows - 1; ++j) {
                            matrix[j][ind] = matrix[j + 1][ind];
                        }
                        matrix[nrows - 1][ind] = temp;
                    }
                    break;
                case -1:
                    for (int i = 0; i < P; ++i) {
                        temp = matrix[nrows - 1][ind];
                        for (int j = nrows - 1; j > 0; --j) {
                            matrix[j][ind] = matrix[j - 1][ind];
                        }
                        matrix[0][ind] = temp;
                    }
                    break;
                default:
                    printf("Wrong input\n");
            }
            break;
        default:
            printf("Wrong input\n");
    }
    printf("\n");
    printf("After shift:");
    for (int i = 0; i < nrows; ++i) {
        printf("\n");
        for (int j = 0; j < mcolumns; ++j) {
            printf("%d ", matrix[i][j]);
        }
    }
}

int main() {

    FILE *fin;
    int mat[maxN][maxN];
    int nPosiz, n, m, index;
    char selettore[7], direction[6], filein[20];

    printf("Insert file name:\n");
    scanf("%s", filein);

    if((fin = fopen(filein, "r"))==NULL) {
        printf("\nError opening file\n");
        return 1;
    }

    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fscanf(fin, "%d", &mat[i][j]);
        }
    }

    printf("\nBefore shift:");
    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = 0; j < m; ++j) {
            printf("%d ", mat[i][j]);
        }
    }

    do {
        printf("\n\nSpecify: <row/column> <index> <left/right | up/down)> <positions (<%d or <%d)>\n", m, n);
        printf("(type \"end 0 0 0\" to end):\n");
        scanf("%s %d %s %d", selettore, &index, direction, &nPosiz);
        index -= 1;
        if((strcmp(selettore, "end"))==0)
            break;
        ruota(mat, nPosiz, direction, selettore, index, n, m);

    } while ((strcmp(selettore, "end"))!=0 && ((strcmp(selettore, "row")==0 && nPosiz<m) || (strcmp(selettore, "column")==0 && nPosiz<n)));

    return 0;
}