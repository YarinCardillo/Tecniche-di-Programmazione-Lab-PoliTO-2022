#include <stdio.h>

int main() {

	int a = 0, b = 1, f = 0, n, i;

	printf("Quanti numeri della serie vuoi visualizzare?\n");
	scanf("%d", &n);

	printf("\n%d %d ", a, b);

	for(i=0; i<n-2; i++){
		f = a + b;
		printf("%d ", f);
		a = b;
		b = f;
	}

	return 0;
}