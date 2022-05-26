#include <stdio.h>
#define filein "numeri.txt"

int main() {

    FILE *fin;
    int a, b, c, counter = 0;
    int min, max;

    if ((fin = fopen(filein, "r")) == NULL ) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(fin, "%d", &a);
    fscanf(fin, "%d", &b);

    if(a > b) {
        max = a;
        min = b;
    }
    else{
        max = b;
        min = a;
    }

    while(fscanf(fin, "%d", &c) != EOF){

        if((c == a+b) || (c == a-b) || (c == a*b) || (b != 0 && c == a/b)){

            if(c < min)
                min = c;
            if(c > max)
                max = c;
            a = b;
            b = c;

        }
        else
            counter++;
    }

    printf("Numero minimo: %d\n", min);
    printf("Numero massimo: %d\n", max);
    printf("Numeri scartati: %d\n", counter);

    fclose(fin);

    return 0;
}