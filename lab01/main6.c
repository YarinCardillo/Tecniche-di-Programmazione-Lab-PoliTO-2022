#include <stdio.h>

int main() {

	FILE *fp_read, *fp_write;

	float op1, op2, result = 0;
	char operator;

	if ((fp_read = fopen("Operations.txt", "r")) == NULL) {
		printf("Error opening file\n");
		return 1;
	}
	if ((fp_write = fopen("Results.txt", "w")) == NULL) {
		printf("Error opening file\n");
		return 2;
	}

	while(!feof(fp_read)){

		fscanf(fp_read, "%c %f %f ", &operator, &op1, &op2);

		// tutte le operazioni sono castate in (float) per sicurezza
		switch(operator){
			case '+':
			result = (float)(op1 + op2);
			break;

			case '-':
			result = (float)(op1 - op2);
			break;

			case '*':
			result = (float)(op1 * op2);
			break;

			case '/':
			if(op2 == 0)
				break;
			else
				result = (float)(op1 / op2);
			break;

			default:
			printf("\nInvalid operation\n");
			break;
		}

		if(operator == '/' && op2 == 0)
			fprintf(fp_write, "Invalid operation");
		else
			fprintf(fp_write, "%c %.2f\n", operator, result);

	}

	fclose(fp_read);
	fclose(fp_write);

	return 0;
}