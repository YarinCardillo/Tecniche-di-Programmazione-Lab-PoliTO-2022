#include <stdio.h>
#define P 3.14

int main() {

	float valore_inserito, area;
	char choice;
	printf("\n");
	printf("Calcolare area del cerchio (C) o del quadrato (Q)?\n");
	choice = getchar();
	getchar();
	/* oppure 
	fflush(stdin); ma non e' buona pratica,
	su sitemi linux non worka */

	if(choice == 'Q'){
		printf("Utilizzare la diagonale (D) o il lato (L)?\n");
		choice = getchar();

		switch(choice){

			case 'D':
			printf("\nInserire valore diagonale\n");
			scanf("%f", &valore_inserito);
			area = (float)(valore_inserito*valore_inserito)/2;
			break;

			case 'L':
			printf("\nInserire valore lato\n");
			scanf("%f", &valore_inserito);
			area = (float)(valore_inserito*valore_inserito);
			break;

			default: 
			printf("Errore di input\n");
			break;
		}
		printf("\nArea Quadrato: %.1f", area);
	}
	else if(choice == 'C'){
		printf("Utilizzare il diametro (D) o il raggio (R)?\n");
		choice = getchar();

		switch(choice){

			case 'D':
			printf("\nInserire valore diametro\n");
			scanf("%f", &valore_inserito);
			area = (float)(valore_inserito*valore_inserito*P);
			break;

			case 'R':
			printf("\nInserire valore raggio\n");
			scanf("%f", &valore_inserito);
			area = (float)(valore_inserito*valore_inserito*P)/4;
			break;

			default: 
			printf("Errore di input\n");
			break;
		}
		printf("\nArea Cerchio: %.1f", area);

	}
	else printf("Errore di input\n");

	return 0;
}