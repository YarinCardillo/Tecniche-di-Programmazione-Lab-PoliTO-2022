#include <stdio.h>
#define N 5

int main(){

	int array[N] = {4, 7, 3, 2, 5};
	int temp, indexMin;

	for (int i = 0; i < N; ++i)
	{
		fprintf(stdout, "%d ", array[i]);
	}
	fprintf(stdout, "\n");

	for (int i = 0; i < N; ++i)
	{
		indexMin = i;
		for (int j = i+1; j < N; ++j)
		{
			if(array[j] < array[indexMin]){
				indexMin = j;
			}
		}
		if(indexMin != i){
			temp = array[i];
			array[i] = array[indexMin];
			array[indexMin] = temp;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		fprintf(stdout, "%d ", array[i]);
	}

	return 0;
}