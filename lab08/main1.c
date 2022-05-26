#include <stdio.h>
#define MAXR 50
#define MAXC 50
#define filein "mappa.txt"


int leggiMatrice(int matrix[][MAXC], int N, int *nrows, int *ncol) {
    FILE *fin;
    if ((fin = fopen(filein, "r")) == NULL) {
        printf("Error opening file");
        return 1;
    }
    fscanf(fin, "%d %d", nrows, ncol);
    if (*nrows > N) {
        printf("Exceeding rows limit\n");
        return 2;
    } else {
        for (int i = 0; i < *nrows; ++i) {
            for (int j = 0; j < *ncol; ++j) {
                fscanf(fin, "%d", &matrix[i][j]);
            }
        }
    }
    fclose(fin);
    return 3;
}


int riconosciRegione(int matrix[MAXR][MAXC], int nrows, int ncol, int rigaScelta, int colonnaScelta, int *base, int *altezza){
    int countBase, countAltezza;
    int trovato;

    if(matrix[rigaScelta][colonnaScelta] == 1){
        trovato = 1;
        countBase = 1;
        countAltezza = 0;
        for (int j = colonnaScelta+1; j <= ncol; ++j) {
            if (matrix[rigaScelta][j] == 1) {
                // conto base
                countBase++;
            } else {
                if (countBase != 0) {
                    for (int k = rigaScelta; k < nrows; ++k) {
                        // conto altezza
                        if (matrix[k][colonnaScelta] == 1) {
                            countAltezza++;
                        } else
                            break;
                    }
                    *base = countBase;
                    *altezza = countAltezza;
                    break;
                }
            }
        }
    }
    else
        trovato = 0;

    return trovato;
}


int main(){
    int nr, nc, r, c, b, h, esito;
    int M[MAXR][MAXC];

    leggiMatrice(M, MAXR, &nr, &nc);

    fprintf(stdout, "Matrice di partenza: \n");
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            fprintf(stdout, "%d ", M[i][j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");

    fprintf(stdout, "Inserire la coordinata di riga dell'estremo superiore sinistro (<%d):\n", nr);
    fscanf(stdin, "%d", &r);
    fprintf(stdout, "Inserire la coordinata di colonna dell'estremo superiore sinistro (<%d):\n", nc);
    fscanf(stdin, "%d", &c);

    if(r < nr && c < nc) {
        esito = riconosciRegione(M, nr, nc, r, c, &b, &h);
        if (esito)
            fprintf(stdout, "Trovato!\nBase: %d\nAltezza %d\n", b, h);
        else
            fprintf(stdout, "Nessun rettangolo trovato :(\n");
    }
    else
        fprintf(stdout, "Errore di input!\n");

    return 0;
}
