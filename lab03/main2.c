#include <stdio.h>

int main() {
    int a = 5, b = 8, numOk;
    numOk = a > b;
    if(numOk)
        printf("TRUE numOk = %d", numOk);
    else
        printf("FALSE numOk = %d", numOk);
    
    return 0;
}
