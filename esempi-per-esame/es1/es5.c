#include "stdio.h"
#define N1 3
#define N2 4

void prodCartOrd(int *v1, int d1, int *v2, int d2){

    int i, temp, flag =1;

    typedef struct coppieSomma{
        int elementoArray1;
        int elementoArray2;
        int somma;
    }coppie;

    coppie array[d1*d2];

    for (int j = 0; j < d1 -1 && flag == 1; ++j) {
        flag = 0;
        for (int k = 0; k < d1 -1 -j; ++k) {
            if(v1[k] > v1[k+1]){
                temp = v1[k];
                v1[k] = v1[k+1];
                v1[k+1] = temp;
            }
        }
    }
    flag = 1;
    for (int j = 0; j < d2 -1 && flag == 1; ++j) {
        flag = 0;
        for (int k = 0; k < d2 -1 -j; ++k) {
            if(v2[k] > v2[k+1]){
                temp = v2[k];
                v2[k] = v2[k+1];
                v2[k+1] = temp;
            }
        }
    }

    i=0;
    for (int j = 0; j < d1; ++j) {
        for (int k = 0; k < d2; ++k) {
            array[i].elementoArray1 = v1[j];
            array[i].elementoArray2 = v2[k];
            array[i].somma = v1[j] + v2[k];
            i++;
        }
    }

    flag = 1;
    for (int j = 0; j < d1*d2-1 && flag==1; ++j) {
        flag = 0;
        for (int k = 0; k < d1*d2-j-1; ++k) {
            if(array[k].somma > array[k+1].somma){
                flag = 1;

                temp = array[k].elementoArray1;
                array[k].elementoArray1 = array[k+1].elementoArray1;
                array[k+1].elementoArray1 = temp;

                temp = array[k].elementoArray2;
                array[k].elementoArray2 = array[k+1].elementoArray2;
                array[k+1].elementoArray2 = temp;

                temp = array[k].somma;
                array[k].somma = array[k+1].somma;
                array[k+1].somma = temp;
            }
        }
    }

    for (i = 0; i < d1*d2; ++i) {
        fprintf(stdout, "(%d, %d) %d\n", array[i].elementoArray1, array[i].elementoArray2, array[i].somma);
    }
}

int main(){

    int V1[N1] = {2, 1, 3};
    int V2[N2] = {6, 4, 3, 5};

    prodCartOrd(V1, N1, V2, N2);

    return 0;
}