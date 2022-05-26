#include <stdio.h>

int main() {
    int a = 8, b = 5, numOk;
    numOk = a > b;
    if(numOk)
        printf("TRUE numOk = %d", numOk);
    else
        printf("FALSE numOk = %d", numOk);
    
    return 0;
}
