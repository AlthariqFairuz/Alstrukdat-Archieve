#include <stdlib.h>
#include <stdio.h>

int main(){
    int M;
    int N;
    int i;
    scanf("%d", &M);
    scanf("%d", &N);
    for (i=1; i<=M; i++){
        if(i%N==0 && i>1){
            printf("happy\n");
        }
        else {
            printf("%d\n",i);
        }
    }
    return 0;
}
