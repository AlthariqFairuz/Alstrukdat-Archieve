#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

// Prints word from Mesin Kata
void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

boolean compareWord(Word kata1, Word kata2) {
    int m, n;
    int len = kata1.Length;
    char temp;

    // sort karakter kata1
    for (m = 0; m < len; m++) {
        for (n = m; n < len; n++) {
            if (kata1.TabWord[m] < kata1.TabWord[n]) {
                temp = kata1.TabWord[m];
                kata1.TabWord[m] = kata1.TabWord[n];
                kata1.TabWord[n] = temp;
            }
        }
    }

    // sort karakter kata2
    for (m = 0; m < len; m++) {
        for (n = m; n < len; n++) {
            if (kata2.TabWord[m] < kata2.TabWord[n]) {
                temp = kata2.TabWord[m];
                kata2.TabWord[m] = kata2.TabWord[n];
                kata2.TabWord[n] = temp;
            }
        }
    }

    // bandingin
    for (m = 0; m < len; m++) {
        if (kata1.TabWord[m] != kata2.TabWord[m]) {
            return false;
        }
    }

    return true;
}


int main()
{
    int indexArWord = 0;
    int i, j, result = 0;
    boolean lanjut = true;
    Word arWord[100];

    STARTWORD();
    while (!EndWord & currentChar!= MARK) {
        arWord[indexArWord] = currentWord;
        indexArWord++;
        ADVWORD();
    }
    arWord[indexArWord] = currentWord;
    indexArWord++;

    for (i = 0; i < indexArWord; i++) {
        for (j = i+1; j < indexArWord; j++) {
            if (arWord[i].Length == arWord[j].Length) {
                if (compareWord(arWord[i], arWord[j])) {
                    result++;   
                }
            }
        }
    }

    printf("%d\n",result);
    return 0;
}