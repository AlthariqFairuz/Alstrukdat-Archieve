#include "listdin.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h> 
#include <math.h>

int main () {
    ListDin l;
    ElType val;
    int tipe,query;
    int i;
    CreateListDin(&l,0);
    scanf("%d",&query);
    for (i=1;i<=query;i++) {
        scanf("%d",&tipe);
        if(tipe==1){
            int x;
            scanf("%d",&x);
            if (isEmpty(l)){
                expandList(&l,1);
                insertLast(&l,x);
            }
            else if (isFull(l)){
                expandList(&l,CAPACITY(l));
                insertLast(&l,x);
            }
            else{
                insertLast(&l,x);
            }

        }else if(tipe==2){
            int size;
            deleteLast(&l,&val);
            size = round(CAPACITY(l)/2);
            if (listLength(l) <= size){
                compressList(&l);
            }

        }else{
            printf("%d ", CAPACITY(l));
            printList(l);
            printf("\n");
        }
    }
    return 0;
}