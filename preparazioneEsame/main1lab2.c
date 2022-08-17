#include <stdio.h>

int main() {
//    Scrivere un programma C che, acquisiti 2 numeri interi positivi ne calcoli il massimo comune divisore
//    utilizzando la formula di Eulero.
//    Formula di Eulero o metodo dei resti:
//    si procede per divisioni successive del numero maggiore per
//    quello minore, sostituendo ad ogni passo il valore maggiore con il minore ed il minore
//    col resto della divisione. Il processo termina quando il resto è 0.
//    Esempio:
//    A = 34 , B = 18
//    passo 1: 34 % 18 = 16
//    passo 2: 18 % 16 = 2
//    passo 3: 16 % 2 = 0  stop!
//    Risultato: MCD = 2

    int n1, n2, res=1, mcd;
    fprintf(stdout, "Insert first number: \n", n1);
    fscanf(stdin, "%d", &n1);
    fprintf(stdout, "Insert second number: \n", n2);
    fscanf(stdin, "%d", &n2);

    while(res != 0){
        mcd = res;
        if(n1>n2)
        {
            res = n1%n2;
            n1 = n2;
            n2 = res;
        }
        else
        {
            res = n2%n1;
            n2 = n1;
            n1 = res;
        }
    }
    fprintf(stdout, "MCD = %d", mcd);
    return 0;
}
