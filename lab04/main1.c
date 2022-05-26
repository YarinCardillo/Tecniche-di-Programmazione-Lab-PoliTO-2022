#include <stdio.h>
#define M 7

void sottoSequenze(int v[], int N);

void sottoSequenze(int v[], int N){
    int arrayIndexStart, arrayIndexEnd, count = 0, max = 0;

    for (int i = 0; i < N; i++){
        if(v[i]!=0)
            count++;
        else {
            if(count>max)
                max = count;
            count = 0;
        }
    }

    if(count>max)
        max = count;
    printf("Max = %d\n\n", max);

    count = 0;

    for (int i = 0; i <= N; i++) {
        if(v[i]!=0 && i != N){
            if(count == 0)
                arrayIndexStart = i;
            count++;
        }
        else if(count == max){
            arrayIndexEnd = i-1;

            for (int i = arrayIndexStart; i <= arrayIndexEnd; i++)
                printf("v[%d]: %d\n", i, v[i]);

            printf("\n");
            count = 0;
        }
        else
            count = 0;
    }
}

int main() {
    int v[M];
    for (int i = 0; i < M; i++) {
        printf("v[%d]:", i);
        scanf("%d", &v[i]);
    }
    printf("\n\n");
    sottoSequenze(v, M);
    return 0;
}