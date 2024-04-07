#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"


// Prints word from Mesin Kata
void printWord(Word word) {

   int i;

   for (i = 0; i < word.Length; i++) {

      printf("%c", word.TabWord[i]);

   }

}

int main () {
    Word input;
    START();
    IgnoreBlanks();
    int i=0;
    while (currentChar != MARK && i < NMax)
   {
      input.TabWord[i] = currentChar;
      i++;
      ADV();
   }
   input.Length = i;

    printWord(input);
    printf("\n");
    printf("%d",input.Length);
    printf("\n");
    return 0;
}