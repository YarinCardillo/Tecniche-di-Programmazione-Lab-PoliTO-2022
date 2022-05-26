#include <stdio.h>
#include <string.h>
#define DIZIONARIO "dizionario.txt"
#define SORGENTE "sorgente.txt"
#define OUTPUT "ricodificato.txt"
#define MAXRIGA 199


int main() {


    char parolaSorgente[MAXRIGA],ch;

    char TabellaCript[30][30],TabellaDecript[30][30];

    char* found;

    int nDiz=0;

    FILE* fin= fopen(SORGENTE, "r");
    FILE* dizionario= fopen(DIZIONARIO,"r");
    FILE* fout= fopen(OUTPUT,"w");

    fscanf(dizionario, "%d " ,&nDiz);

    for (int i = 0; i < nDiz; ++i) {
        fscanf(dizionario,"%s %s ",TabellaCript[i],TabellaDecript[i]);
    }


    while (fscanf(fin,"%s" , parolaSorgente) != EOF){


        for (int i = 0;  i < nDiz  ;i++ ) {

            found = strstr(parolaSorgente,TabellaDecript[i]);
            if (found!=NULL){
                strcpy(found,TabellaCript[i]);
                i=nDiz;
            }

        }

        fscanf(fin,"%c",&ch);



        fprintf(fout,"%s%c",parolaSorgente,ch);
        printf("%s%c",parolaSorgente,ch);
        fflush(stdout);



    }
    return 0;
}

