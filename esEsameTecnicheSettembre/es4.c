#include "stdio.h"
void printDate(char *date);
int main(){
    printDate("10-05-2002");
    return 0;
}

void printDate(char *date){
    int day, month, year;
    if(sscanf(date, "%d-%d-%d", &day, &month, &year) != 3){
        fprintf(stdout, "Format error\n");
        return;
    }
    if(day < 1 || day > 30 || month < 1 || month > 30){
        fprintf(stdout, "Date error\n");
        return;
    }

    switch (month) {
        case 1:
            printf("%d Gennaio %d\n", day, year);
            break;
        case 2:
            printf("%d Febbraio %d\n", day, year);
            break;
        case 3:
            printf("%d Marzo %d\n", day, year);
            break;
        case 4:
            printf("%d Aprile %d\n", day, year);
            break;
        case 5:
            printf("%d Maggio %d\n", day, year);
            break;
        case 6:
            printf("%d Giugno %d\n", day, year);
            break;
        case 7:
            printf("%d Luglio %d\n", day, year);
            break;
        case 8:
            printf("%d Agosto %d\n", day, year);
            break;
        case 9:
            printf("%d Settembre %d\n", day, year);
            break;
        case 10:
            printf("%d Ottobre %d\n", day, year);
            break;
        case 11:
            printf("%d Novembre %d\n", day, year);
            break;
        case 12:
            printf("%d Dicembre %d\n", day, year);
            break;
        default:
            printf("Error\n");
    }
}
