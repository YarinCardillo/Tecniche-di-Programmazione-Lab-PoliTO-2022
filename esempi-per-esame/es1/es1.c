#include <stdio.h>
#include <string.h>

int charErase(char str[], const int pos[]);

int main(){
    char stringa[14]={"ThisIsAString"}; int array[6] = {7, 4, 2, 0, 11, -1};

    charErase(stringa,array);

    return 0;
}

int charErase(char str[], const int pos[]){
    int i = 0, counter = 0;
    fprintf(stdout, "str = %s\n", str);

    while(pos[i] != -1){
        for (int j = pos[i]; j < (strlen(str)); ++j) {
            str[j]=str[j+1];
        }
        i++;
        counter++;
    }

    fprintf(stdout, "str = %s\n", str);
    fprintf(stdout, "counter = %d", counter);

    return counter;
}

