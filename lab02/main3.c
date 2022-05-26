#include <stdio.h>

int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);

char charBack, charFront;
int printCount = 0;

int comprimi(FILE *fin, FILE *fout){
    int count = 0;
    while(fscanf(fin,"%c",&charFront) != EOF){
        if (charFront == charBack)
            count++;
        else{
            while (count!=0){
                if (count>9){

                    count=count-10;
                    fprintf(fout,"$9");
                    fprintf(fout,"%c",charBack);
                    printCount+=3;

                }
                else if(count==1){

                    fprintf(fout,"%c",charBack);
                    printCount++;

                    count=0;
                }
                else {

                    fprintf(fout,"$%d",count);
                    printCount++;

                    count=0;
                }
            }
            fprintf(fout,"%c",charFront);
            printCount++;
        }

        charBack = charFront;
    }

    fclose(fin);
    fclose(fout);

    return printCount;
}


int decomprimi(FILE *fin, FILE *fout){
    int i;
    while(fscanf(fin,"%c",&charFront) != EOF){
        if (charFront == '$'){

            fscanf(fin,"%1d",&i);
            for (int j = 0; j < i; j++) {
                fprintf(fout,"%c", charBack);
                printCount++;

            }
            fscanf(fin,"%c",&charFront);
        }
        fprintf(fout,"%c",charFront);
        printCount++;
        charBack = charFront;
    }

    fclose(fin);
    fclose(fout);

    return printCount;
}


int main() {

	FILE *fin, *fout;
    char choice;

    printf("Compressione (C) o decompressione (D)?\n");
    scanf("%c", &choice);

    switch(choice){


        case 'C':
        if ((fin = fopen("sorgente.txt", "r")) == NULL ) {
            printf("Error opening file\n");
            return 1;
        }
        if ((fout = fopen("compresso.txt", "w")) == NULL){
            printf("Error opening file\n");
            return 2;
        }
        comprimi(fin, fout);
        break;


        case 'D':
        if ((fin = fopen("compresso.txt", "r")) == NULL ) {
            printf("Error opening file\n");
            return 3;
        }
        if ((fout = fopen("decompresso.txt", "w")) == NULL){
            printf("Error opening file\n");
            return 4;
        }
        decomprimi(fin, fout);
        break;


        default:
        printf("Input error\n");

    }

    return 0;
}