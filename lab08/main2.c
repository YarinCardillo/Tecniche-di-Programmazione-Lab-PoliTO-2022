#include <stdio.h>

void stampaCodifica(void *p, int size, int bigEndian);

void stampaCodifica(void *p, int size, int bigEndian){
	fprintf(stdout, "Mo non fa ancora 1 cazzo\n");
}

int main(){

	float af = 50.02;
	double ad = 244.04;
	int bigEndian;

	fprintf(stdout, "af = %f\nad = %f\n", af, ad);

	stampaCodifica((void *)&af, sizeof(af), bigEndian);
	stampaCodifica((void *)&af, sizeof(ad), bigEndian);

    double a = 8, b = 4;

	fprintf(stdout, "sizeof(b) = %d\nsizeof(b) = %d\n", sizeof(a), sizeof(b));



	return 0;
}