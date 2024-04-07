#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "listdin.h"
#include <math.h>

int main()
{
    int cap, rep, input, angka;
    ListDin list1, list2;

    scanf("%d", &cap);
    CreateListDin(&list1, cap);

    scanf("%d", &rep);
    for (int j = 1; j <= rep; j++)
    {
        CreateListDin(&list2, cap);
        scanf("%d", &input);
        if (input == 1)
        {
            scanf("%d", &angka);
            insertLast(&list1, angka);
            for (int i = 0; i < NEFF(list1); i++)
            {
                if (ELMT(list1, i) >= angka)
                {
                    ELMT(list2, NEFF(list2)) = ELMT(list1, i);
                    NEFF(list2)
                    ++;
                }
            }
            list1 = list2;
        }
        if (input == 2)
        {
            printf("%d\n", NEFF(list1));
            printList(list1);
            printf("\n");
        }
    }
}
