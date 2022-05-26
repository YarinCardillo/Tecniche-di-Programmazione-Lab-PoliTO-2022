#include <stdio.h>

int main() {

    unsigned int a = 1, b = 2, f = 0, n, i;

    printf("Quanti numeri della serie vuoi visualizzare?\n");
    scanf("%d", &n);

    printf("\n%d %d ", a, b);

    for(i=0; i<n-2; i++){
    	f = a * b;
    	printf("%d ", f);
    	a = b;
    	b = f;
    }
    
    return 0;
}