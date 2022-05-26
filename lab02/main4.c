#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fin, *fout;
    char charFront, charBack, charNew;
    int num, count = 0, h, iter = 0;

    if ((fin = fopen("noncrittato.txt", "r")) == NULL ) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fout = fopen("crittato.txt", "w")) == NULL){
        printf("Error opening file\n");
        return 2;
    }


    while(fscanf(fin, "%c", &charFront) != EOF){

        if (iter != 0 && charFront != ' ' && charFront != '\n') {
            if (isdigit(charFront)) {
                charFront -= '0';
                num = charFront + count;
                if (h > 9){
                    fprintf(fout, "0");
                    printf("0");
                    fflush(stdout);}


                else{
                    fprintf(fout, "%d", h);
                    printf("%d", h);
                    fflush(stdout);
                }
                count++;
            } else {
                if (isupper(charBack)) {
                    h = charBack - 'A';
                    if (h > 26) {
                        charFront -= 'Z';
                    }else{
                        // shifto charFront

                        charNew = charFront + h;
                    }




                } else {
                    h = charBack - 'a';
                    if (h > 26) {
                        charFront -= 'z';
                    }else{
                        // shifto charFront
                        charNew = charFront + h;
                    }

                    if(charNew > 122 || charNew < 97){

                    }





                }


            }
        }

        fprintf(fout, "%c", charFront);
        printf("%c", charFront);
        fflush(stdout);
        charBack = charFront;
        iter++;


    }
    return 0;
}
