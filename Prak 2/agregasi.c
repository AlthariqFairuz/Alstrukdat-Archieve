#include <stdlib.h>
#include "liststatik.h"
#include <stdio.h>
#include <math.h>

int main() {
    int i,tmax,tmin,idx,median;
    float sum;
    ListStatik l;
    ElType X;
    CreateListStatik(&l);
    readList(&l);
    sortList(&l,true);
    extremeValues(l,&tmax,&tmin);
    scanf("%d",&X);
    printList(l);
    printf("\n");

    for (i=0;i<listLength(l);i++){
        sum += ELMT(l,i);
    }

    printf("Average: %.2f\n",(float) (sum/listLength(l)));
    idx = indexOf(l,X);

    if (idx != IDX_UNDEF){
        printf("%d\n",idx);
    }
    else {
        printf("%d tidak ada\n", X);
    }

    if (X == tmax){
        printf("X maksimum\n");
    }
    
    if (X == tmin) {
        printf("X minimum\n");
    }

    if (listLength(l) % 2 == 0) {
        median =  (listLength(l) / 2) - 1 ;
    }

    else {
        median = (listLength(l) / 2);
    }

    if (X== ELMT(l,median)) {
        printf("X median\n");
    }
    return 0;
}