#include <stdio.h>
#include <ctype.h>

int main() {

    FILE *fin, *fout;
    char charFront, charBack;

    if ((fin = fopen("input.txt", "r")) == NULL ) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fout = fopen("testo.txt", "w")) == NULL){
        printf("Error opening file\n");
        return 2;
    }

    while(fscanf(fin, "%c", &charFront) != EOF){

        if(ispunct(charBack) && charFront != ' ' && charFront != '\n' && charBack != '\'' && charBack != '(')
            fprintf(fout, " ");


        if(charBack == '.' || charBack == '!' || charBack == '?'){
            if(charFront != ' ')
                charFront = toupper(charFront);
            fprintf(fout, "%c", charFront);

            charBack = charFront;
            while(fscanf(fin, "%c", &charFront) == ' ' || charFront == ('\n') && charFront != EOF){
                fprintf(fout, "%c", charFront);
            }

            if(charFront != ' ' && !isupper(charBack))
                charFront = toupper(charFront);
        }


        if(isdigit(charFront)){
            fprintf(fout, "*");
        }
        else
            fprintf(fout,"%c", charFront);


        charBack = charFront;


    }

    fclose(fin);
    fclose(fout);

    return 0;
}
