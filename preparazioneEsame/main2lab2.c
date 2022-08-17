#include <stdio.h>

int main(){
    unsigned int num, x=1, sum=2, temp;

    fprintf(stdout, "How many Fibonacci numbers you want to display?\n");
    fscanf(stdin, "%d", &num);

    fprintf(stdout, "\n%d %d ", x, sum);
    for (int i = 0; i < num; ++i) {
        temp = sum;
        sum *= x;
        x = temp;
        fprintf(stdout, "%d ", sum);
    }



    return 0;
}