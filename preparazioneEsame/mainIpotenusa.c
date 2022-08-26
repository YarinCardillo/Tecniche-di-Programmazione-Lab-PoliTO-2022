#include <stdio.h>
#include <math.h>

int main(){

	float lato1, lato2, lato3;
	fprintf(stdout, "Inserisci i 3 lati.\n");
	fprintf(stdout, "Lato 1: \n");
	fscanf(stdin, "%f", &lato1);
	fprintf(stdout, "Lato 2: \n");
	fscanf(stdin, "%f", &lato2);
	fprintf(stdout, "Lato 3: \n");
	fscanf(stdin, "%f", &lato3);
	if(lato1 > lato2 && lato1 > lato3){
		if(lato1*lato1 == lato2*lato2 + lato3*lato3){
			fprintf(stdout, "Terna pitagorica.\n");
		}
		else{
			fprintf(stdout, "Terna non pitagorica.\n");
		}
	}
	else if(lato2 > lato1 && lato2 > lato3){
		if(lato2*lato2 == lato1*lato1 + lato3*lato3){
			fprintf(stdout, "Terna pitagorica.\n");
		}
		else{
			fprintf(stdout, "Terna non pitagorica.\n");
		}
	}
	else if(lato3 > lato1 && lato3 > lato2){
		if(lato3*lato3 == lato1*lato1 + lato2*lato2){
			fprintf(stdout, "Terna pitagorica.\n");
		}
		else{
			fprintf(stdout, "Terna non pitagorica.\n");
		}
	}
	else{
		fprintf(stdout, "I lati non sono validi.\n");
	}

	return 0;
}
