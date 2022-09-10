#include "stdio.h"
#define N1 3
#define N2 4

int main(){

    int v1[N1] = {2, 1, 3};
    int v2[N2] = {6, 4, 3, 5};
    int i, temp, flag =1;

    typedef struct coppieSomma{
        int elementoArray1;
        int elementoArray2;
        int somma;
    }coppie;

    coppie array[N1*N2];

    for (int j = 0; j < N1 -1 && flag == 1; ++j) {
        flag = 0;
        for (int k = 0; k < N1 -1 -j; ++k) {
            if(v1[k] > v1[k+1]){
                temp = v1[k];
                v1[k] = v1[k+1];
                v1[k+1] = temp;
            }
        }
    }
    flag = 1;
    for (int j = 0; j < N2 -1 && flag == 1; ++j) {
        flag = 0;
        for (int k = 0; k < N2 -1 -j; ++k) {
            if(v2[k] > v2[k+1]){
                temp = v2[k];
                v2[k] = v2[k+1];
                v2[k+1] = temp;
            }
        }
    }

    i=0;
    for (int j = 0; j < N1; ++j) {
        for (int k = 0; k < N2; ++k) {
            array[i].elementoArray1 = v1[j];
            array[i].elementoArray2 = v2[k];
            array[i].somma = v1[j] + v2[k];
            i++;
        }
    }

    flag = 1;
    for (int j = 0; j < N1*N2-1 && flag==1; ++j) {
        flag = 0;
        for (int k = 0; k < N1*N2-j-1; ++k) {
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

    for (i = 0; i < N1*N2; ++i) {
        fprintf(stdout, "(%d, %d) %d\n", array[i].elementoArray1, array[i].elementoArray2, array[i].somma);
    }

    return 0;
}