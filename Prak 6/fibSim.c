#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int fibo (int n) {
    if (n==0) {
        printf ("fibonacci(%d)\n",n);
        return 0;
    }
    else if (n==1){
        printf ("fibonacci(%d)\n",n);
        return 1;
    }
    else {
        printf ("fibonacci(%d)\n",n);
        return fibo(n-1) + fibo (n-2);
    }
}

int main () {
    int n,hasil=0;
    scanf("%d",&n);
    hasil = fibo(n);
    printf("%d\n",hasil);
    return 0;
}