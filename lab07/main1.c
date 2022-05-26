#include <stdio.h>
#define filein "mappa.txt"
#define MAXR 50
#define MAXC 50

int main(){

    FILE *fin;

    typedef struct maxData{
        int estrSupR;
        int estrSupC;
        int b;
        int h;
        int area;
    } maxData;

    maxData dati[3];

    int nr, nc, estrSupRiga, estrSupColonna, countBase, countAltezza, countArea;
    int maxBase = 0, maxAltezza = 0, maxArea = 0;
    int matrix[MAXR][MAXC];
    if((fin=fopen(filein,"r"))==NULL){
        printf("Error opening file");
        return 1;
    }

    fscanf(fin, "%d %d", &nr, &nc);
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }
    fprintf(stdout, "Matrice di partenza: \n");
    for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
            fprintf(stdout, "%d ", matrix[i][j]);
        }
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "\n");


    for (int i = 0; i < nr; ++i) {

        countBase = 0;
        countAltezza = 0;

        for (int j = 0; j <= nc; ++j) {

            if(matrix[i][j] == 1){
                // conto lunghezza base
                if(countBase == 0){
                    // fisso la cella di partenza della regione nera
                    estrSupRiga = i;
                    estrSupColonna = j;
                }
                countBase++;
            }
            else{
                if(countBase != 0){
                    for (int k = estrSupRiga; k < nr; ++k)
                    {
                        // conto altezza partendo dalla cella fissata
                        if(matrix[k][estrSupColonna] == 1){
                            countAltezza++;
                        }
                        else
                            break;
                    }
                    countArea = countBase*countAltezza;

                    if(countBase > maxBase){
                        maxBase = countBase;
                        dati[0].estrSupR = estrSupRiga;
                        dati[0].estrSupC = estrSupColonna;
                        dati[0].b = countBase;
                        dati[0].h = countAltezza;
                        dati[0].area = countArea;
                    }
                    if(countAltezza > maxAltezza){
                        maxAltezza = countAltezza;
                        dati[1].estrSupR = estrSupRiga;
                        dati[1].estrSupC = estrSupColonna;
                        dati[1].b = countBase;
                        dati[1].h = countAltezza;
                        dati[1].area = countArea;
                    }
                    if(countArea > maxArea){
                        maxArea = countArea;
                        dati[2].estrSupR = estrSupRiga;
                        dati[2].estrSupC = estrSupColonna;
                        dati[2].b = countBase;
                        dati[2].h = countAltezza;
                        dati[2].area = countArea;
                    }
                    countBase = 0;
                    countAltezza = 0;
                }
            }
        }
    }

    fprintf(stdout, "Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", dati[0].estrSupR, dati[0].estrSupC, dati[0].b, dati[0].h, dati[0].area);
    fprintf(stdout, "Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", dati[2].estrSupR, dati[2].estrSupC, dati[2].b, dati[2].h, dati[2].area);
    fprintf(stdout, "Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", dati[1].estrSupR, dati[1].estrSupC, dati[1].b, dati[1].h, dati[1].area);

    fclose(fin);

    return 0;
}
