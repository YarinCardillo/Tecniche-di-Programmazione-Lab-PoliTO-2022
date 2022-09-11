#include "stdio.h"
#include "string.h"
#define MAXM 5

int count(char A[][MAXM], int n, int m, char str[]);

int main(){

    char A[][MAXM]= {"xcatc", "waeca", "dtpat", "pcatf"};
    char substring[4] = "cat";

    fprintf(stdout, "Matches: %d", count(A, 4, 5, substring));

    return 0;
}

int count(char A[][MAXM], int n, int m, char str[]){

    int i,j, match=0;
    for (int k = 0; k < n; ++k) {
        i = 0;
        j = 0;
        while (i < m) {

            if (A[k][i] == str[j]) {
                j++;
                i++;
            } else {
                if (j != 0)
                    j = 0;
                else
                    i++;
            }

            if (j == strlen(str)) {
                match++;
                j = 0;
            }

        }
    }

    for (int k = 0; k < m; ++k) {
        i = 0;
        j = 0;
        while (i < n) {

            if (A[i][k] == str[j]) {
                j++;
                i++;
            } else {
                if (j != 0)
                    j = 0;
                else
                    i++;
            }

            if (j == strlen(str)) {
                match++;
                j = 0;
            }

        }
    }

    return match;
}