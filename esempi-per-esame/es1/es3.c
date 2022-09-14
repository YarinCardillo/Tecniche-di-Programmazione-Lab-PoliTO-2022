#include "stdio.h"
#include "stdlib.h"
#define DIM1 3
#define DIM2 4

void prodCartFilt(int *v1, int d1, int *v2, int d2){
    for (int i = 0; i < d1; ++i) {
        for (int j = 0; j < d2; ++j) {
            if(abs(v1[i] - v2[j]) > 1) {
                fprintf(stdout, "(%d, %d)\n", v1[i], v2[j]);
            }
        }
    }
}
int main(){
    int V1[DIM1] = {1, 2, 3};
    int V2[DIM2] = {3, 4, 5, 6};
    prodCartFilt(V1, DIM1, V2, DIM2);
    return 0;
}