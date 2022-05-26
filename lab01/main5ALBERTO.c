#include <stdio.h>

float a=0;
float b=0;
char op='Z';
float result=0;
int main() {
    //Calcolatrice che prenda da file e metta in file
    //Partiamo però da semplice calcolatrice
    printf("Che operazione si vuole fare?\n");
    scanf("%c",&op);
    printf("Inserire i due operandi:\n");
    scanf("%f %f",&a,&b);

    if(op=='+') result=a+b;
    else if(op=='-') result = a-b;
    else if(op=='/'&&b!=0) result=a/b;
    else if(op=='*') result=a*b;
    else printf("Operazione non valida\n");

    if(op=='/'&&b==0) printf("Il risultato dell'operazione e: infinito\n");
    else { printf("Il risultato dell'operazione e: %f", result); }


    return 0;
}
