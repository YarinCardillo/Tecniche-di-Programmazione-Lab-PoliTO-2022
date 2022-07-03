#include <stdio.h>

int main() {
    int a = 8, b = 5, numOk;
    numOk = a > b;
    if(numOk)
        printf("TRUE numOk = %d\n", numOk);
    else
        printf("FALSE numOk = %d\n", numOk);
    
    return 0;
}
