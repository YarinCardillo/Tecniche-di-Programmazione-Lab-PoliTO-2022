#include <stdio.h>

int comprimi(FILE *fin, FILE *fout){
    char charFront, charBack;
    int count=0;
    while(fscanf(fin,"%c", &charFront) != EOF){

        if(charBack == charFront)
            count++;
        else{
            if(count != 0){
                if(count==1){
                    fprintf(fout, "%c", charBack);
                    fprintf(stdout, "%c", charBack);
                    fflush(stdout);
                }
                else if(count > 9){
                    if((count-10) > 1){
                    fprintf(fout, "%c$9%c$%d", charBack, charBack, count-10);
                    fprintf(stdout, "%c$%d", charBack, count);
                    fflush(stdout);
                        }
                    else{
                        fprintf(fout, "%c$9%c", charBack, charBack);
                        fprintf(stdout, "%c$%d", charBack, count);
                        fflush(stdout);
                    }
                }
                else{
                    fprintf(fout, "%c$%d", charBack, count);
                    fprintf(stdout, "%c$%d", charBack, count);
                    fflush(stdout);
                }
                count=0;
            }
            fprintf(fout, "%c", charFront);
            fprintf(stdout, "%c", charFront);
            fflush(stdout);


        }
        charBack=charFront;
    }
    return 3;
}
int decomprimi(FILE *fin, FILE *fout){



    return 2;
}

int main(){
    FILE *fin, *fout;
    char choice;
    fprintf(stdout, "Compressione (C) o Decompressione (D)?\n");
    fflush(stdout);
    fscanf(stdin, "%c", &choice);
    switch(choice){
        case 'C':
            fin = fopen("sorgente.txt", "r");
            if(fin == NULL){
                fprintf(stdin, "Error opening file\n");
                return -1;
            }
            fout = fopen("compresso.txt", "w");
            if(fout == NULL){
                fprintf(stdin, "Error opening file\n");
                return -2;
            }
            comprimi(fin, fout);
            break;

        case 'D':
            fin = fopen("compresso.txt", "r");
            if(fin == NULL){
                fprintf(stdin, "Error opening file\n");
                return -3;
            }
            fout = fopen("decompresso.txt", "w");
            if(fout == NULL){
                fprintf(stdin, "Error opening file\n");
                return -4;
            }
            decomprimi(fin, fout);
            break;

        default:
            fprintf(stdout, "Wrong input\n");
    }
    return 0;
}


//#include <stdio.h>
//
//int comprimi(FILE *fin, FILE *fout);
//int decomprimi(FILE *fin, FILE *fout);
//
//char charBack, charFront;
//int printCount = 0;

//int comprimi(FILE *fin, FILE *fout){
//    int count = 0;
//    while(fscanf(fin,"%c",&charFront) != EOF){
//        if (charFront == charBack)
//            count++;
//        else{
//            while (count!=0){
//                if (count>9){
//
//                    count=count-10;
//                    fprintf(fout,"$9");
//                    fprintf(fout,"%c",charBack);
//                    printCount+=3;
//
//                }
//                else if(count==1){
//
//                    fprintf(fout,"%c",charBack);
//                    printCount++;
//
//                    count=0;
//                }
//                else {
//
//                    fprintf(fout,"$%d",count);
//                    printCount++;
//
//                    count=0;
//                }
//            }
//            fprintf(fout,"%c",charFront);
//            printCount++;
//        }
//
//        charBack = charFront;
//    }
//
//    fclose(fin);
//    fclose(fout);
//
//    return printCount;
//}


//int decomprimi(FILE *fin, FILE *fout){
//    int i;
//    while(fscanf(fin,"%c",&charFront) != EOF){
//        if (charFront == '$'){
//
//            fscanf(fin,"%1d",&i);
//            for (int j = 0; j < i; j++) {
//                fprintf(fout,"%c", charBack);
//                printCount++;
//
//            }
//            fscanf(fin,"%c",&charFront);
//        }
//        fprintf(fout,"%c",charFront);
//        printCount++;
//        charBack = charFront;
//    }
//
//    fclose(fin);
//    fclose(fout);
//
//    return printCount;
//}
//
//
//int main() {
//
//    FILE *fin, *fout;
//    char choice;
//
//    printf("Compressione (C) o decompressione (D)?\n");
//    scanf("%c", &choice);
//
//    switch(choice){
//
//
//        case 'C':
//            if ((fin = fopen("sorgente.txt", "r")) == NULL ) {
//                printf("Error opening file\n");
//                return 1;
//            }
//            if ((fout = fopen("compresso.txt", "w")) == NULL){
//                printf("Error opening file\n");
//                return 2;
//            }
//            comprimi(fin, fout);
//            break;
//
//
//        case 'D':
//            if ((fin = fopen("compresso.txt", "r")) == NULL ) {
//                printf("Error opening file\n");
//                return 3;
//            }
//            if ((fout = fopen("decompresso.txt", "w")) == NULL){
//                printf("Error opening file\n");
//                return 4;
//            }
//            decomprimi(fin, fout);
//            break;
//
//
//        default:
//            printf("Input error\n");
//
//    }
//
//    return 0;
//}