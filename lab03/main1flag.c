#include <stdio.h>
#include <ctype.h>

int main() {

    FILE *fin, *fout;
    char charFront, charBack;
//    int flag = 0;

    if ((fin = fopen("input.txt", "r")) == NULL ) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fout = fopen("testo.txt", "w")) == NULL){
        printf("Error opening file\n");
        return 2;
    }

    while(fscanf(fin, "%c", &charFront) != EOF){
        if(isdigit(charFront)){
            charFront = '*';
        }
        else if((charBack == ',' || charBack == ':' || charBack == ';')  && (charFront != ' ' && charFront != '\n'))
            fprintf(fout, " ");
        else if(charBack == '.' || charBack == '!' || charBack == '?'){
            if(charFront != ' ' && charFront != '\n')
                fprintf(fout, " ");
//            else
//                flag = 1;
            while(charFront == ' ' || charFront == '\n' && charFront != EOF) {
                fprintf(fout, "%c", charFront);
                charBack = charFront;
                fscanf(fin, "%c", &charFront);
            }
            if(charFront != ' ' && !isupper(charBack))
                charFront = (char)toupper(charFront);
        }
//        if(flag == 1 && charFront != '\n'){
//            charFront = (char)toupper(charFront);
//            flag = 0;
//        }
        fprintf(fout, "%c", charFront);
        charBack = charFront;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}