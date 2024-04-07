#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin list1, list2, finalList;
    int index1;
    int index2;

    index1 = 0;
    index2 = 0;

    CreateListDin(&list1, 1000);
    readList(&list1);
    CreateListDin(&list2, 1000);
    readList(&list2);

    CreateListDin(&finalList, 2000);
    while ((index1 != NEFF(list1)) && (index2 != NEFF(list2))) {
        if (ELMT(list1, index1) >= ELMT(list2, index2)) {
            insertLast(&finalList, ELMT(list1, index1));
            index1 += 1;
        } else {
            insertLast(&finalList, ELMT(list2, index2));
            index2 += 1;
        }
    }

    while (index1 != NEFF(list1)) {
        insertLast(&finalList, ELMT(list1, index1));
        index1 += 1;
    }

    while (index2 != NEFF(list2)) {
        insertLast(&finalList, ELMT(list2, index2));
        index2 += 1;
    }

    printList(finalList);
    printf("\n");

    return 0;
}
