#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXL 14
#define MAXROWS 1000
#define filein "corse.txt"

typedef struct {
    char codice_tratta[30];
    char partenza[30];
    char destinazione[30];
    char data[30];
    char ora_partenza[30];
    char ora_arrivo[30];
    int ritardo;
} struttura;

typedef enum {r_date, r_partenza, r_capolinea, r_ritardo, r_ritardo_tot, r_fine} comando_e;

comando_e leggiComando () {
    comando_e c;
    char cmd[MAXL];
    char tabella[r_fine+1][14] = {"date","partenza","capolinea","ritardo", "ritardototale", "fine"};
    printf("\ncomando (date/partenza/capolinea/ritardo/ritardoTotale/fine):\n");
    fflush(stdout);
    scanf("%s",cmd);
    for (int i = 0; i < MAXL; ++i) {
        cmd[i] = tolower(cmd[i]);
    }
    c = r_date;
    while(c<r_fine+1 && strcmp(cmd,tabella[c])!=0)
        c++;
    return (c);
}
void menuParola(struttura corse2[], int nrows){
    comando_e comando;
    char riga[MAXL];
    int keep = 1, counter, delay;
    char startingDate[11], endDate[11], nomeStazione[30];

    do {
        comando = leggiComando();
        fgets(riga, MAXL, stdin);
        switch (comando) {
            case 0:
                printf("Date...\n");
                printf("Write starting date (YYYY/MM/DD):\n");
                scanf("%s", startingDate);
                printf("Write end date (YYYY/MM/DD):\n");
                scanf("%s", endDate);
                for (int i = 0; i < nrows; ++i) {
                    if(strcmp(startingDate, corse2[i].data)<=0){
                        if(strcmp(endDate, corse2[i].data)>0){
                            fprintf(stdout, "%s %s %s %s %s %s %d", corse2[i].codice_tratta,
                                    corse2[i].partenza, corse2[i].destinazione, corse2[i].data,
                                    corse2[i].ora_partenza, corse2[i].ora_arrivo, corse2[i].ritardo);
                            fprintf(stdout, "\n");
                            counter++;
                        }
                    }
                }
                if(counter == 0)
                    printf("No results");
                counter = 0;
                break;
            case 1:
                printf("Partenza...\n");
                fflush(stdout);
                printf("Inserire nome stazione di partenza:\n");
                fflush(stdout);
                fscanf(stdin, "%s", nomeStazione);
                fprintf(stdout, "%s\n", nomeStazione);
                fflush(stdout);
                nomeStazione[0] = toupper(nomeStazione[0]);
                for (int i = 1; i < MAXL; ++i) {
                    nomeStazione[i] = tolower(nomeStazione[i]);
                }
                for (int i = 0; i < nrows; ++i) {
                    if (strcmp(nomeStazione, corse2[i].partenza) == 0) {
                        fprintf(stdout, "%s %s %s %s %s %s %d", corse2[i].codice_tratta,
                                corse2[i].partenza, corse2[i].destinazione, corse2[i].data,
                                corse2[i].ora_partenza, corse2[i].ora_arrivo, corse2[i].ritardo);
                        fprintf(stdout, "\n");
                        counter++;
                    }
                }
                if(counter == 0)
                    printf("No results");
                fflush(stdout);
                counter = 0;
                break;
            case 2:
                printf("Capolinea...\n");
                fflush(stdout);
                printf("Inserire nome destinazione:\n");
                fflush(stdout);
                fscanf(stdin, "%s", nomeStazione);
                fprintf(stdout, "%s\n", nomeStazione);
                fflush(stdout);
                for (int i = 0; i < nrows; ++i) {
                    if (strcmp(nomeStazione, corse2[i].destinazione) == 0) {
                        fprintf(stdout, "%s %s %s %s %s %s %d", corse2[i].codice_tratta,
                                corse2[i].partenza, corse2[i].destinazione, corse2[i].data,
                                corse2[i].ora_partenza, corse2[i].ora_arrivo, corse2[i].ritardo);
                        fprintf(stdout, "\n");
                        counter++;
                    }
                }
                if(counter == 0)
                    printf("No results");
                fflush(stdout);
                counter = 0;
                break;
            case 3:
                printf("Ritardo...\n");
                printf("Write starting date (YYYY/MM/DD):\n");
                scanf("%s", startingDate);
                printf("Write end date (YYYY/MM/DD):\n");
                scanf("%s", endDate);
                for (int i = 0; i < nrows; ++i) {
                    if (corse2[i].ritardo != 0) {
                        if (strcmp(startingDate, corse2[i].data) <= 0) {
                            if (strcmp(endDate, corse2[i].data) > 0) {
                                fprintf(stdout, "%s %s %s %s %s %s %d", corse2[i].codice_tratta,
                                        corse2[i].partenza, corse2[i].destinazione, corse2[i].data,
                                        corse2[i].ora_partenza, corse2[i].ora_arrivo, corse2[i].ritardo);
                                fprintf(stdout, "\n");
                            }
                        }
                    }
                }
                break;
            case 4:
                delay = 0;
                printf("Ritardo totale...\n");
                fflush(stdout);
                printf("Inserire codice tratta:\n");
                fflush(stdout);
                fscanf(stdin, "%s", nomeStazione);
                fprintf(stdout, "%s\n", nomeStazione);
                fflush(stdout);
                for (int i = 0; i < nrows; ++i) {
                    if (strcmp(nomeStazione, corse2[i].codice_tratta) == 0) {
                        delay += corse2[i].ritardo;
                        counter++;
                    }
                }
                fprintf(stdout, "Ritardo totale di %s: %d", nomeStazione, delay);
                if(counter == 0)
                    printf("No results");
                fflush(stdout);
                counter = 0;
                break;
            case 5:
                printf("Exit\n");
                keep = 0;
                break;
            default:
                printf("Wrong input\n");
                break;

        }

    }while(keep == 1);
}
int main() {
    FILE *fin;

    int rows;
    struttura corse[MAXROWS];
    if((fin = fopen(filein, "r")) == NULL){
        printf("Error opening file");
        return -1;
    }
    fscanf(fin, "%d", &rows);

    for (int i = 0; i < rows; ++i) {

        fscanf(fin, "%s %s %s %s %s %s %d", corse[i].codice_tratta,
               corse[i].partenza, corse[i].destinazione, corse[i].data,
               corse[i].ora_partenza, corse[i].ora_arrivo, &corse[i].ritardo);
    }
    printf("File:\n");
    for (int i = 0; i < rows; ++i) {
        fprintf(stdout, "%s %s %s %s %s %s %d", corse[i].codice_tratta,
                corse[i].partenza, corse[i].destinazione, corse[i].data,
                corse[i].ora_partenza, corse[i].ora_arrivo, corse[i].ritardo);
        fprintf(stdout, "\n");
    }

    menuParola(corse, rows);
    return 0;
}