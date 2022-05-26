#include <stdio.h>
#include <string.h>
#define filein "sorgente.txt"
#define filein2 "dizionario.txt"
#define fileout "ricodificato.txt"

int main() {

    FILE *fin, *fin2, *fout;
    char parola[20], ch;
    char *trovato;
    int n;
    struct conversionTable{
        char crypted[20];
        char word[20];
    };

    if((fin = fopen(filein, "r"))==NULL){
        printf("Error opening file\n");
        return 1;
    }
    if((fin2 = fopen(filein2, "r"))==NULL){
        printf("Error opening file\n");
        return 2;
    }
    if((fout = fopen(fileout, "w"))==NULL){
        printf("Error opening file\n");
        return 3;
    }

    fscanf(fin2, "%d", &n);

    struct conversionTable array[n];

    for (int i = 0; i < n; ++i) {
        fscanf(fin2, "%s %s", array[i].crypted, array[i].word);
    }

    printf("\n");

    while(fscanf(fin, "%s", parola) != EOF){
        fscanf(fin, "%c", &ch);

        for (int i = 0; i < n; ++i) {
            trovato = strstr(parola, array[i].word);
           if(trovato != NULL) {
               strcpy(trovato, array[i].crypted);
               break;
           }
        }

        fprintf(fout, "%s", parola);
        fprintf(fout, "%c", ch);
    }
    fclose(fin);
    fclose(fin2);
    fclose(fout);
    return 0;
}