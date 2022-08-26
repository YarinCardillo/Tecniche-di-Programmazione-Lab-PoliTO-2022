#include <stdio.h>
#include <math.h>

int main(){

	float cateto1, cateto2;
	fprintf(stdout, "Inserisci i 2 cateti.\n");
	fprintf(stdout, "Cateto 1: \n");
	fscanf(stdin, "%f", &cateto1);
	fprintf(stdout, "Cateto 2: \n");
	fscanf(stdin, "%f", &cateto2);
	fprintf(stdout, "Ipotenusa = %.3f", sqrt((cateto1*cateto1)+(cateto2*cateto2)));


	return 0;
}