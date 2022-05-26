#include <stdio.h>

int main() {

	int a, b, mcd, remainder = 1;

	printf("a: ");
	scanf("%d", &a);  
	printf("\nb: ");
	scanf("%d", &b);

	/* Se volessi conservare i valori iniziali
	int x = a;
	int y = b; */

	while(remainder != 0){

		if(a >= b){
			remainder = a%b;
			mcd = b;
			a = b;
			b = remainder;
		}
		else{ 
			remainder = b%a;
			mcd = a;
			b = a;
			a = remainder;
		}
		
	}

	printf("\nMCD = %d\n", mcd);

	return 0;
}
