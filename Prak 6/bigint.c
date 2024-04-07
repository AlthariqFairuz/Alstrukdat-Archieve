#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"
#include <stdio.h>

int convertToInt(char c) {
    return c - '0';
}

void subtract(Stack stack1, Stack stack2, Stack* stack3){
    int num1, num2;
    boolean borrow = false;
    while(!IsEmpty(stack1) && !IsEmpty(stack2)){
        Pop(&stack1, &num1);
        Pop(&stack2, &num2);
        if(borrow) num1--;
        if(num1 >= num2){
            num1 -= num2;
            borrow = false;
        } else {
            num1 += 10 - num2;
            borrow = true;
        }
        Push(stack3, num1);
    }
    while(!IsEmpty(stack1)){
        Pop(&stack1, &num1);
        if(borrow) num1--;
        if(num1 < 0){
            num1 += 10;
            borrow = true;
        } else {
            borrow = false;
        }
        Push(stack3, num1);
    }
}

int main()
{
    Stack stack1, stack2, stack3;
    Word wordArray[100];
    infotype value;
    int wordCount = 0, i;

    CreateEmpty(&stack1);
    CreateEmpty(&stack2);
    CreateEmpty(&stack3);
    START();
    while(currentChar != MARK){
        ADVWORD();
        
        wordArray[wordCount] = currentWord;
        wordCount++;
    }

    for (i = 0; i < wordArray[0].Length; i++) {
        Push(&stack1, convertToInt(wordArray[0].TabWord[i]));
    }

    for (i = 0; i < wordArray[1].Length; i++) {
        Push(&stack2, convertToInt(wordArray[1].TabWord[i]));
    }

    subtract(stack1, stack2, &stack3);

    int count = 0;
    while(!IsEmpty(stack3)){
        Pop(&stack3, &i);
        if(!(i == 0 && count == 0)){
            printf("%d", i);
            count++;
        }
    }
    if(count == 0){
        printf("%d", i);
    }
    printf("\n");

    return 0;
}
