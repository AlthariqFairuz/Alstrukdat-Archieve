#include "listdin.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h> 

int main () {
    ListDin l;
    ElType max,min,selisih;
    CreateListDin(&l,100);
    readList(&l);
    extremeValues(l,&max,&min);
    if (listLength(l) == 0 || listLength(l) == 1 ) {
        printf("%d\n",0);
    }
    else {
        selisih = (max+1)-min;
        printf("%d\n",selisih);
    }
    return 0;
}