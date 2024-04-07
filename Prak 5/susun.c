#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"
#include <stdlib.h>

// Prints word from Mesin Kata
void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

int bandingKata (Word W1, Word W2) {
    int i = 0;
    while (i < W1.Length && i < W2.Length) {
        if (W1.TabWord[i] < W2.TabWord[i]) {
            return -1;
        } else if (W1.TabWord[i] > W2.TabWord[i]) {
            return 1;
        }
        i++;
    }
    if (W1.Length < W2.Length) {
        return -1;
    } else if (W1.Length > W2.Length) {
        return 1;
    } else {
        return 0;
    }
}

void susun(int n, Word *x) {
    Word temp;
    int i, str;

    for(str = 0; str < n-1; ++str) {
        for(i = str+1; i < n; ++i) {
            if (bandingKata(x[str], x[i]) > 0) {
                temp = x[str];
                x[str] = x[i];
                x[i] = temp;
            }
        }
    }
}

int main() {
    Word *kata; // array of words
    kata = (Word *) malloc(100 * sizeof(Word));
    int banyakkata;

    STARTWORD();
    int i = 0;
    while (!EndWord) {
        kata[i] = currentWord;
        ADVWORD();
        i++;
    }
    banyakkata = i;

    susun(banyakkata, kata);
    
    for (int l = 0; l < i; l++) {
        printWord(kata[l]);
        printf("\n");
    }

    return 0;
}