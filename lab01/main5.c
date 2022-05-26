#include <stdio.h>

int main() {

	float op1, op2, result = 0;
	char operator;

	printf("Choose operator (+ - * /)\n");
	operator = getchar();
	getchar();

	printf("\nChoose operand 1\n");
	scanf("%f", &op1);
	printf("\nChoose operand 2\n");
	scanf("%f", &op2);

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
		printf("\nInvalid operation\n");
	else
		printf("\nResult of (%.2f)%c(%.2f) is %.2f\n", op1, operator, op2, result);

	return 0;
}