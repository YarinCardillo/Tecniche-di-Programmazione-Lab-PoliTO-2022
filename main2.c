#include <stdio.h>
#include <time.h>
#define filein "sort.txt"
#define MAXL 100

void insertionSort(int *array, int *lunghezzaFile, FILE *fin){

	int k, l, r, x;
	int lunghezzaRiga;

	for (int i = 0; i < lunghezzaFile; ++i)
	{
		fscanf(fin, "%d", &lunghezzaRiga);
		for (int j = 0; j < lunghezzaRiga; ++j)
			fscanf(fin, "%d", &array[j]);


		l = 0;
		r = lunghezzaRiga - 1;
		for (int j = l+1; j <= r; ++j)
		{
			x = array[j];
			k = j - 1;
			while(k >= l && x < array[k]){
				array[k+1] = array[k];
				k--;
			}
			array[k+1] = x;
		}
		for (int j = 0; j < lunghezzaRiga; ++j)
			fprintf(stdout, "%d ", array[j]);
		fprintf(stdout, "\n");
	}

}

int main(){

	FILE *fin;
	if((fin = fopen(filein, "r")) == NULL){
		fprintf(stdout, "Error opening file\n");
		return -1;
	}
	int lunghezza;
	int vettore[MAXL];


	fscanf(fin, "%d", &lunghezza);
	//Insertion Sort
	fprintf(stdout, "Insertion Sort Algorithm:\n");
	clock_t start = clock();
	clock_t end;

	insertionSort(&vettore[MAXL], &lunghezza, fin);

	end = clock();
	fprintf(stdout, "Runtime (s): %f~", (double)((end - start)/(double)100));

	

	return 0;
}