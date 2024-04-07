#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
    int len,input;
    float ops,ratio;
    // l4 for miss/hit, l3 for input
    List l,l3,l4;
    Address p,q;
    int count=0;

    scanf("%d", &len);
    scanf("%f", &ops);

    CreateList(&l);
    CreateList(&l3);
    CreateList(&l4);
    int i;

    for (i = 0 ; i<ops ; i ++ ){
        scanf("%d", &input);
        if (isEmpty(l)){
            insertFirst(&l,input);
            insertLast(&l3,input);
        }
        else if ((indexOf(l,input) == IDX_UNDEF)&&(length(l) == len)){
            int val;
            deleteLast(&l,&val);
            insertFirst(&l,input);
            insertLast(&l3,input);

        }
        else if ((indexOf(l,input) != IDX_UNDEF)){
            int val3;
            deleteAt(&l,indexOf(l,input),&val3);
            insertFirst(&l,input);
            insertLast(&l3,input);
            ratio += 1;
        }
        
        else {
            insertFirst(&l,input);
            insertLast(&l3,input);
        }
    }
    
    q = l3;
    int val2;

    for (int j =0 ; j < ops ; j ++) {
        if (isEmpty(l4)) {
            insertFirst(&l4,INFO(q));
            printf("miss [%d]\n",INFO(q));
            deleteFirst(&q,&val2);
        }
        else if ((indexOf(l4,INFO(q)) == IDX_UNDEF)&&(length(l4) == len)) {
            deleteLast(&l4,&val2);
            insertFirst(&l4,INFO(q));
            printf("miss ");
            displayList(l4);
            printf("\n");
            deleteFirst(&q,&val2);
        }

        else if ((indexOf(l4,INFO(q)) != IDX_UNDEF)){
            deleteAt(&l4,indexOf(l4,INFO(q)),&val2);
            insertFirst(&l4,INFO(q));
            printf("hit ");
            displayList(l4);
            printf("\n");
            deleteFirst(&q,&val2);
        }

        else {
            insertFirst(&l4,INFO(q));
            deleteFirst(&q,&val2);
            printf("miss ");
            displayList(l4);
            printf("\n");
        }

        }
    
    if (ops == 0){
        printf("hit ratio: 0.00\n");
    }
    else {
        float totalratio= ratio/ops;
        printf("hit ratio: %.2f\n",totalratio);
    }
    return 0;
}
