#include <stdio.h>
#include <ctype.h>
#define filein "input.txt"
#define fileout "testo.txt"

char stampa(char charStampa);
FILE *fin, *fout;
int counter = 0;

char stampa(char charStampa){
    int counter2;
    if(counter > 24){
        fprintf(fout, " | c:%d\n", counter);
        counter = 0;
    }
    if (charStampa != '\n') {
        fprintf(fout, "%c", charStampa);
        counter++;
    }
    else {
        counter ++;
        counter2 = counter;
        while (counter2 < 25) {
            fprintf(fout, " ");
            counter2 ++;
        }
        charStampa = ' ';
        fprintf(fout, "%c", charStampa);
        fprintf(fout, " | c:%d \n", counter);
        counter = 0;
    }
    return charStampa;
}

int main() {

    char charFront, charBack;

    if ((fin = fopen(filein, "r")) == NULL ) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fout = fopen(fileout, "w")) == NULL){
        printf("Error opening file\n");
        return 2;
    }

    while(fscanf(fin, "%c", &charFront) != EOF){
        if(isdigit(charFront))
            charFront = '*';
        else if((charBack == ',' || charBack == ':' || charBack == ';')  && (charFront != ' ' && charFront != '\n')) {
            fprintf(fout, " ");
            counter++;
        }
        else if(charBack == '.' || charBack == '!' || charBack == '?')
        {
            if(charFront != ' ' && charFront != '\n') {
                fprintf(fout, " ");
                counter++;
            }
            while(charFront == ' ' || charFront == '\n' && charFront != EOF) {
                stampa(charFront);
                charBack = charFront;
                fscanf(fin, "%c", &charFront);
            }
            if(charFront != ' ' && !isupper(charBack))
                charFront = (char)toupper(charFront);
        }
        stampa(charFront);
        charBack = charFront;
    }
    if(feof(fin)){
        while (counter < 25) {
            fprintf(fout, " ");
            counter ++;
        }
        fprintf(fout, " | c:%d", counter);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}