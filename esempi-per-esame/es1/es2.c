#include "stdio.h"
#define DIM 10


void maxOdd(int v[], int N) {

    int max = 0, count = 0, breakpoint = 0;
    for (int i = 0; i < N; ++i) {
        if(v[i]%2 != 0){
            count++;
        }
        else {
            if(count > max)
                max = count;
            count = 0;
        }
    }
    count = 0;
    for (int i = 0; i < N; ++i) {
        if(v[i]%2 != 0){
            count++;
            if(count == 1)
                breakpoint = i;
        }
        else {
            if(count == max){
                for (int j = breakpoint; j < breakpoint+max; ++j) {
                    fprintf(stdout, "%d ", v[j]);
                }
                fprintf(stdout, "  ");
            }
            count = 0;
        }
    }


}

int main(){
    int V[DIM];

    for (int i = 0; i < DIM; ++i) {
        fprintf(stdout, "Input V[%d]: ", i);
        fscanf(stdin, "%d", &V[i]);
        fprintf(stdout, "\n");
    }
    maxOdd(V, DIM);

    return 0;
}