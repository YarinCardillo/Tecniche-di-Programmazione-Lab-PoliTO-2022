#include <stdio.h>
#include <ctype.h>

#define filein "input.txt"
#define fileout "output.txt"

char ch='\n';
char chold=' ';
int counter = 0;
int flag=1;
int main(){
    FILE *fp_write, *fp_read;
    if((fp_read = fopen(filein,"r")) == NULL ){
        printf("Error opening file in\n");
        return 0;
    }

    if((fp_write= fopen(fileout,"w"))== NULL){
        printf("Error opening file out\n");
        return 0;
    }

    while(fscanf(fp_read,"%c",&ch)==1){
        if (isdigit(ch)) ch='*';
        else if ((chold==':'||chold==','||chold==';') && (ch != ' ' && ch!= '\n' )) {
            fprintf(fp_write," ");
            counter+=1;}
        else if(ch=='.'||ch=='!'||ch=='?'){
            fprintf(fp_write,"%c",ch);
            chold=ch;
            counter+=1;
            while(fscanf(fp_read,"%c",&ch )==1 && flag==1) {
                if(isspace(ch)) {
                    fprintf(fp_write, "%c", ch);
                    counter+=1;
                }
                else if (isalpha(ch) && isspace(chold)==0 ) {
                    fprintf(fp_write," %c", toupper(ch));
                    flag=0;
                counter+=2;}
                else {
                    fprintf(fp_write,"%c",toupper(ch));
                    counter+=1;
                    flag=0;
                }
                chold=ch;
            }
            //fprintf(fp_write,"%c", toupper(chold));
            flag=1;
        }

        if (!feof(fp_read)) fprintf(fp_write,"%c",ch);;
        chold=ch;
    }
    fclose(fp_write);
    fclose(fp_read);
    return 1;
}