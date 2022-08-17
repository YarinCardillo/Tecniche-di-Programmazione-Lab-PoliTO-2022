#include <stdio.h>

int main(){

	int a = 10;
	int *p;

	p = &a;

	fprintf(stdout, "a = %d\n*p = %d\n&a = %d\np = %d\n", a, *p, &a, p);

	// fprintf(stdout, "Ridefinisci a:\n");
	// fscanf(stdin, "%d", p);

	// fprintf(stdout, "\na = %d\n*p = %d\n&a = %d\np = %d\n", a, *p, &a, p);
	fprintf(stdout, "\n\n");
	*p=*p + 1;

	fprintf(stdout, "a = %d\n*p = %d\n&a = %d\np = %d\n", a, *p, &a, p);


	return 0;
}