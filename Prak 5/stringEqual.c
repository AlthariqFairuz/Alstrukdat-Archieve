#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"
#include <math.h>
#include <string.h>

// Returns string length
int stringLength(char *s) {
   int result = 0;
   int i = 0;
   
   while (s[i] != '\0') {
      ++result;
      ++i;
   }

   return result;
}

int main() {

    STARTWORD();
    char N[1000];
    strcpy(N, currentWord.TabWord);

    ADVWORD();
    if (stringLength(currentWord.TabWord) == 6) {
        printf("Moving %s square upwards\n", N);
    } else if (stringLength(currentWord.TabWord) == 9) {
        printf("Moving %s square rightwards\n", N);
    } else {
        if (currentWord.TabWord[4] == 'D' || currentWord.TabWord[4] == 'd' ) {
            printf("Moving %s square downwards\n", N);
        } else {
            printf("Moving %s square leftwards\n", N);
        }
    }

    return 0;
}