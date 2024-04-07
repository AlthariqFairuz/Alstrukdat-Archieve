#include <stdlib.h>
#include "liststatik.h"
#include <stdio.h>

int main() {
    int i;
    ListStatik l1,l2,l3;
    CreateListStatik(&l3);
    readList(&l1);
    readList(&l2);
    for (i=0;i<listLength(l1);i++){
        insertFirst(&l3,ELMT(l1,i));
    }
    for (i=0;i<listLength(l2);i++){
        insertFirst(&l3,ELMT(l2,i));
    }
    sortList(&l3,true);
    printList(l3);
    printf("\n");
    return 0;
}