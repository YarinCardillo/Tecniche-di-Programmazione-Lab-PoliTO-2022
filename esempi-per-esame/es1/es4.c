#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "ctype.h"
#define S 11
bool isvowel(char x);
void countAndPrint(char str[], int n);

bool isvowel(char x){
    x = (char)tolower(x);
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;
    else
        return false;
}

void countAndPrint(char str[], int n){
    int countVowels = 0, countSubstring = 0, countN = 0;

    for (int i = 0; i <= strlen(str); ++i) {

        if(countN <= n) {
            if (isvowel(str[i]))
                countVowels++;
            if (countVowels == 2)
                countSubstring++;
            countN++;
        }
        else{
            countVowels = 0;
            countN = 0;
        }
    }

    if(countSubstring == 1)
        fprintf(stdout, "There is 1 substring in of 2 vowel/s in '%s'.\n", str);
    else if(countSubstring > 1)
        fprintf(stdout, "There are %d substrings of 2 vowel/s in '%s'.\n", countSubstring, str);
    else
        fprintf(stdout, "There are no substrings of 2 vowel/s in '%s'.\n", str);

}

int main(){
    char stringa[S] = "forExample";
    int n = 4;
    countAndPrint(stringa, n);
    return 0;
}