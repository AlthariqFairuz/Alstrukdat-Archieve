#include "wordmachine.h"
#include "charmachine.h"
#include "stack.h"
#include <stdio.h>

void readInput(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

int main()
{
    Stack stack;
    Word word;
    int i, depth;
    char temp;

    CreateEmpty(&stack);
    readInput(&word);

    int stackSize = 0;
    depth = 0;
    i = 0;
    while(i != word.Length) {
        if (word.TabWord[i] == '(') {
            Push(&stack, '(');
            stackSize++;
        } else if (word.TabWord[i] == ')'){
            if (depth < stackSize) {
                depth = stackSize;
            }
            Pop(&stack, &temp);
            stackSize--;
        }
        i++;
    }

    if (!IsEmpty(stack)) {
        printf("%d\n", (-1));
    } else {
        printf("%d\n" , depth);
    }

    return 0;
}
