#include <stdio.h>
#include "string.h"

char* findSequence(char s[], char ch, int n);

int main() {
    char* p1 = findSequence("ciccioPasticcio", 'c', 3);
    fprintf(stdout, "%s", p1);
    return 0;
}

char* findSequence(char s[], char ch, int n){

    char *p;
    int flag=0;
    int counter=0;

    for (int i = 0; i < strlen(s) && counter != n; ++i) {
        if(s[i] == ch){
            counter++;
            if(counter == 1)
                p = &s[i];
        }
        else
            counter = 0;
    }
    if(counter == n)
        flag=1;
    if(flag==1)
        return p;
    else
        return NULL;
}
