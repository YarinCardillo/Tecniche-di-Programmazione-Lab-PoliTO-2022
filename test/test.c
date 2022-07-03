#include <stdio.h>
#define DIM 6

void InsertionSort(int A[], int N)
{
    int j, l = 0, r = N - 1, x;
    for (int i = l + 1; i <= r; i++)
    {
        x = A[i];
        j = i-1;
        while(j>=l && x< A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main()
{

    int array[DIM] = {6, 3, 5, 1, 7, 21};
    for (int i = 0; i < DIM; ++i) {
        fprintf(stdout, "array[%d] = %d\n", i, array[i]);
    }
    InsertionSort(array, DIM);
    fprintf(stdout, "\n");
    for (int i = 0; i < DIM; ++i) {
        fprintf(stdout, "array[%d] = %d\n", i, array[i]);
    }

    return 0;
}